
#include <iostream>

#include <TMX/detail/Log.hpp>

#include "OrthoMapLayer.h"

namespace tmx
{
    OrthoMapLayer::OrthoMapLayer(const tmx::Map &map, std::size_t index)
    {
        Set(map, index);
    }

    void OrthoMapLayer::Set(const tmx::Map &map, std::size_t index)
    {
        const auto& layers = map.getLayers();

        if (map.getOrientation() == Orientation::Orthogonal
            && index < layers.size()
            && layers[index]->getType() == Layer::Type::Tile)
        {
            // round the chunk size to the nearest tile
            const auto tileSize = map.getTileSize();

            m_chunkSize.x = std::floor(m_chunkSize.x / tileSize.x) * tileSize.x;
            m_chunkSize.y = std::floor(m_chunkSize.y / tileSize.y) * tileSize.y;
            m_MapTileSize.x = map.getTileSize().x;
            m_MapTileSize.y = map.getTileSize().y;

            const auto& layer = layers[index]->getLayerAs<TileLayer>();

            CreateChunks(map, layer);

            m_layerName = layer.getName();

            auto mapSize = map.getBounds();

            m_globalBounds.width = mapSize.width;
            m_globalBounds.height = mapSize.height;
        }
        else
        {
            std::cout << "Not a valid orthogonal layer, nothing will be drawn." << "[" << index << "]" << std::endl;
        }
    }

    std::string OrthoMapLayer::GetName()
    {
        return m_layerName;
    }

    const sf::FloatRect &OrthoMapLayer::GetGlobalBounds() const
    {
        return m_globalBounds;
    }

    void OrthoMapLayer::SetTile(int tileX, int tileY, TileLayer::Tile tile, bool refresh)
    {
        sf::Vector2u chunkLocale;

        const auto& selectedChunk = GetChunkAndTransform(tileX, tileY, chunkLocale);
        selectedChunk->SetTile(chunkLocale.x, chunkLocale.y, tile, refresh);
    }

    TileLayer::Tile OrthoMapLayer::GetTile(int tileX, int tileY)
    {
        sf::Vector2u chunkLocale;
        const auto& selectedChunk = GetChunkAndTransform(tileX, tileY, chunkLocale);
        return selectedChunk->GetTile(chunkLocale.x, chunkLocale.y);
    }

    void OrthoMapLayer::SetColor(int tileX, int tileY, sf::Color color, bool refresh)
    {
        sf::Vector2u chunkLocale;
        const auto& selectedChunk = GetChunkAndTransform(tileX, tileY, chunkLocale);
        selectedChunk->SetColor(chunkLocale.x, chunkLocale.y, color, refresh);
    }

    sf::Color OrthoMapLayer::GetColor(int tileX, int tileY)
    {
        sf::Vector2u chunkLocale;
        const auto& selectedChunk = GetChunkAndTransform(tileX, tileY, chunkLocale);
        return selectedChunk->GetColor(chunkLocale.x, chunkLocale.y);
    }

    void OrthoMapLayer::Update(sf::Time elapsed)
    {
        for (auto& c : m_visibleChunks)
        {
            for (AnimationState& as : c->GetActiveAnimations())
            {
                as.currentTime += elapsed;

                TileLayer::Tile tile;
                tile.ID = as.animTile.animation.frames[0].tileID;
                tile.flipFlags = 0; // TODO: get flipFlags from original TileLayer::Tile

                std::int32_t animTime = 0;

                for (const auto& frame : as.animTile.animation.frames)
                {
                    animTime += frame.duration;

                    if (as.currentTime.asMilliseconds() >= animTime)
                    {
                        tile.ID = frame.tileID;

                        if (frame == as.animTile.animation.frames.back())
                        {
                            as.currentTime = sf::milliseconds(0);
                        }
                    }
                }

                SetTile(as.tileCords.x, as.tileCords.y, tile);
            }
        }
    }

    OrthoMapLayer::Chunk::Ptr &OrthoMapLayer::GetChunkAndTransform(int x, int y, sf::Vector2u &chunkRelative)
    {
        uint32_t chunkX = (uint32_t) floor((x * m_MapTileSize.x) / m_chunkSize.x);
        uint32_t chunkY = (uint32_t) floor((y * m_MapTileSize.y) / m_chunkSize.y);
        chunkRelative.x = (uint32_t) (((x * m_MapTileSize.x) - chunkX * m_chunkSize.x ) / m_MapTileSize.x);
        chunkRelative.y = (uint32_t) (((y * m_MapTileSize.y) - chunkY * m_chunkSize.y ) / m_MapTileSize.y);

        return  m_chunks[chunkX + chunkY * m_chunkCount.x];
    }

    void OrthoMapLayer::CreateChunks(const Map &map, const TileLayer &layer)
    {
        //look up all the tile sets and load the textures
        const auto& tileSets = map.getTilesets();
        const auto& layerIDs = layer.getTiles();
        std::uint32_t maxID = std::numeric_limits<std::uint32_t>::max();
        std::vector<const Tileset*> usedTileSets;

        for (auto i = tileSets.rbegin(); i != tileSets.rend(); ++i)
        {
            for (const auto& tile : layerIDs)
            {
                if (tile.ID >= i->getFirstGID() && tile.ID < maxID)
                {
                    usedTileSets.push_back(&(*i));
                    break;
                }
            }
            maxID = i->getFirstGID();
        }

        sf::Image fallback;
        fallback.create(2, 2/*, sf::Color::Magenta */ );
        for (const auto& ts : usedTileSets)
        {
            const auto& path = ts->getImagePath();
            //std::unique_ptr<sf::Texture> newTexture = std::make_unique<sf::Texture>();
            std::unique_ptr<sf::Texture> newTexture = std::make_unique<sf::Texture>();
            sf::Image img;
            if (!img.loadFromFile(path))
            {
                newTexture->loadFromImage(fallback);
            }
            else
            {
                if (ts->hasTransparency())
                {
                    auto transparency = ts->getTransparencyColour();
                    img.createMaskFromColor({ transparency.r, transparency.g, transparency.b, transparency.a });
                }
                newTexture->loadFromImage(img);
            }
            m_textureResource.insert(std::make_pair(path, std::move(newTexture)));
        }

        //calculate the number of chunks in the layer
        //and create each one
        const auto bounds = map.getBounds();
        m_chunkCount.x = static_cast<sf::Uint32>(std::ceil(bounds.width / m_chunkSize.x));
        m_chunkCount.y = static_cast<sf::Uint32>(std::ceil(bounds.height / m_chunkSize.y));

        sf::Vector2u tileSize(map.getTileSize().x, map.getTileSize().y);

        for (auto y = 0u; y < m_chunkCount.y; ++y)
        {
            sf::Vector2f tileCount(m_chunkSize.x / tileSize.x, m_chunkSize.y / tileSize.y);
            for (auto x = 0u; x < m_chunkCount.x; ++x)
            {
                // calculate size of each Chunk (clip against map)
                if ((x + 1) * m_chunkSize.x > bounds.width)
                {
                    tileCount.x = (bounds.width - x * m_chunkSize.x) /  map.getTileSize().x;
                }
                if ((y + 1) * m_chunkSize.y > bounds.height)
                {
                    tileCount.y = (bounds.height - y * m_chunkSize.y) /  map.getTileSize().y;
                }
                //m_chunks.emplace_back(std::make_unique<Chunk>(layer, usedTileSets,
                //    sf::Vector2f(x * m_chunkSize.x, y * m_chunkSize.y), tileCount, map.getTileCount().x, m_textureResource));
                m_chunks.emplace_back(std::make_unique<Chunk>(layer, usedTileSets,
                                                              sf::Vector2f(x * m_chunkSize.x, y * m_chunkSize.y), tileCount, tileSize, map.getTileCount().x, m_textureResource, map.getAnimatedTiles()));
            }
        }
    }

    void OrthoMapLayer::UpdateVisibility(const sf::View &view) const
    {
        sf::Vector2f viewCorner = view.getCenter();
        viewCorner -= view.getSize() / 2.f;

        int posX = static_cast<int>(std::floor(viewCorner.x / m_chunkSize.x));
        int posY = static_cast<int>(std::floor(viewCorner.y / m_chunkSize.y));
        int posX2 = static_cast<int>(std::ceil((viewCorner.x + view.getSize().x) / m_chunkSize.x));
        int posY2 = static_cast<int>(std::ceil((viewCorner.y + view.getSize().x)/ m_chunkSize.y));

        std::vector<Chunk*> visible;
        for (auto y = posY; y < posY2; ++y)
        {
            for (auto x = posX; x < posX2; ++x)
            {
                std::size_t idx = y * int(m_chunkCount.x) + x;
                if (idx >= 0u && idx < m_chunks.size() && !m_chunks[idx]->Empty())
                {
                    visible.push_back(m_chunks[idx].get());
                }
            }
        }

        std::swap(m_visibleChunks, visible);
    }

    void OrthoMapLayer::draw(sf::RenderTarget &rt, sf::RenderStates states) const
    {
        //calc view coverage and draw nearest chunks
        UpdateVisibility(rt.getView());
        for (const auto& c : m_visibleChunks)
        {
            rt.draw(*c, states);
        }
    }

    OrthoMapLayer::Chunk::Chunk(const TileLayer &layer,
                                std::vector<const Tileset *> tilesets,
                                const sf::Vector2f &position,
                                const sf::Vector2f &tileCount,
                                const sf::Vector2u &tileSize,
                                std::size_t rowSize,
                                OrthoMapLayer::TextureResource &tr,
                                const std::map<std::uint32_t, Tileset::Tile> &animTiles)
        : m_animTiles(animTiles)
    {
        setPosition(position);

        layerOpacity = static_cast<sf::Uint8>(layer.getOpacity() /  1.f * 255.f);

        sf::Color vertColour = sf::Color(200 ,200, 200, layerOpacity);
        auto offset = layer.getOffset();

        layerOffset.x = offset.x;
        layerOffset.x = offset.y;
        chunkTileCount.x = tileCount.x;
        chunkTileCount.y = tileCount.y;
        mapTileSize = tileSize;

        const auto& tileIDs = layer.getTiles();

        //go through the tiles and create all arrays (for latter manipulation)
        for (const auto& ts : tilesets)
        {
            if(ts->getImagePath().empty())
            {
                Logger::log("This example does not support Collection of Images tilesets", Logger::Type::Info);
                Logger::log("Chunks using " + ts->getName() + " will not be created", Logger::Type::Info);
                continue;
            }

            m_chunkArrays.emplace_back(std::make_unique<ChunkArray>(*tr.find(ts->getImagePath())->second, *ts));
        }

        std::size_t xPos = static_cast<std::size_t>(position.x / tileSize.x);
        std::size_t yPos = static_cast<std::size_t>(position.y / tileSize.y);

        for (auto y=yPos; y<yPos + tileCount.y; ++y)
        {
            for (auto x=xPos; x<xPos + tileCount.x; ++x)
            {
                auto idx = (y * rowSize + x);

                m_chunkTileIDs.emplace_back(tileIDs[idx]);
                m_chunkColors.emplace_back(vertColour);
            }
        }

        GenerateTiles(true);
    }

    void OrthoMapLayer::Chunk::GenerateTiles(bool registerAnimation)
    {
        if (registerAnimation)
        {
            m_activeAnimations.clear();
        }

        for (const auto& ca : m_chunkArrays)
        {
            sf::Uint32 idx = 0;
            std::size_t xPos = static_cast<std::size_t>(getPosition().x / mapTileSize.x);
            std::size_t yPos = static_cast<std::size_t>(getPosition().y / mapTileSize.y);

            for (auto y=yPos; y<yPos + chunkTileCount.y; ++y)
            {
                for (auto x=xPos; x<xPos + chunkTileCount.x; ++x)
                {
                    if (idx < m_chunkTileIDs.size()
                        && m_chunkTileIDs[idx].ID >= ca->m_firstGID
                        && m_chunkTileIDs[idx].ID <= ca->m_lastGID)
                    {
                        if (registerAnimation && m_animTiles.find(m_chunkTileIDs[idx].ID) != m_animTiles.end())
                        {
                            AnimationState as;

                            as.animTile = m_animTiles[m_chunkTileIDs[idx].ID];
                            as.startTime = sf::milliseconds(0);
                            as.tileCords = sf::Vector2u(x,y);

                            m_activeAnimations.push_back(as);
                        }

                        sf::Vector2f tileOffset(x * mapTileSize.x, (float)y * mapTileSize.y + mapTileSize.y - ca->tileSetSize.y);

                        auto idIndex = m_chunkTileIDs[idx].ID - ca->m_firstGID;

                        sf::Vector2f tileIndex(idIndex % ca->tsTileCount.x, idIndex / ca->tsTileCount.x);
                        tileIndex.x *= ca->tileSetSize.x;
                        tileIndex.y *= ca->tileSetSize.y;

                        Tile tile =
                                 {
                                     sf::Vertex(tileOffset - getPosition(), m_chunkColors[idx], tileIndex),
                                     sf::Vertex(tileOffset - getPosition() + sf::Vector2f(ca->tileSetSize.x, 0.f), m_chunkColors[idx], tileIndex + sf::Vector2f(ca->tileSetSize.x, 0.f)),
                                     sf::Vertex(tileOffset - getPosition() + sf::Vector2f(ca->tileSetSize.x, ca->tileSetSize.y), m_chunkColors[idx], tileIndex + sf::Vector2f(ca->tileSetSize.x, ca->tileSetSize.y)),
                                     sf::Vertex(tileOffset - getPosition() + sf::Vector2f(0.f, ca->tileSetSize.y), m_chunkColors[idx], tileIndex + sf::Vector2f(0.f, ca->tileSetSize.y))
                                 };

                        DoFlips(m_chunkTileIDs[idx].flipFlags, &tile[0].texCoords, &tile[1].texCoords,
                                &tile[2].texCoords, &tile[3].texCoords);
                        ca->AddTile(tile);
                    }

                    idx++;
                }
            }
        }
    }

    std::vector<OrthoMapLayer::AnimationState> &OrthoMapLayer::Chunk::GetActiveAnimations()
    {
        return m_activeAnimations;
    }

    TileLayer::Tile OrthoMapLayer::Chunk::GetTile(int x, int y) const
    {
        return TileLayer::Tile();
    }

    void OrthoMapLayer::Chunk::SetTile(int x, int y, TileLayer::Tile tile, bool refresh)
    {
        m_chunkTileIDs[CalcIndexFrom(x, y)] = tile;
        MaybeRegenerate(refresh);
    }

    sf::Color OrthoMapLayer::Chunk::GetColor(int x, int y) const
    {
        return m_chunkColors[CalcIndexFrom(x, y)];
    }

    void OrthoMapLayer::Chunk::SetColor(int x, int y, sf::Color color, bool refresh)
    {
        m_chunkColors[CalcIndexFrom(x, y)] = color;
        MaybeRegenerate(refresh);
    }

    void OrthoMapLayer::Chunk::MaybeRegenerate(bool refresh)
    {
        if (refresh)
        {
            for (const auto& ca : m_chunkArrays)
            {
                ca->Reset();
            }

            GenerateTiles();
        }
    }

    int OrthoMapLayer::Chunk::CalcIndexFrom(int x, int y) const
    {
        return x + y * chunkTileCount.x;
    }

    bool OrthoMapLayer::Chunk::Empty() const
    {
        return m_chunkArrays.empty();
    }

    void OrthoMapLayer::Chunk::FlipY(sf::Vector2f *v0, sf::Vector2f *v1, sf::Vector2f *v2, sf::Vector2f *v3)
    {
        //Flip Y
        sf::Vector2f tmp = *v0;
        v0->y = v2->y;
        v1->y = v2->y;
        v2->y = tmp.y ;
        v3->y = v2->y  ;
    }

    void OrthoMapLayer::Chunk::FlipX(sf::Vector2f *v0, sf::Vector2f *v1, sf::Vector2f *v2, sf::Vector2f *v3)
    {
        //Flip X
        sf::Vector2f tmp = *v0;
        v0->x = v1->x;
        v1->x = tmp.x;
        v2->x = v3->x;
        v3->x = v0->x ;
    }

    void OrthoMapLayer::Chunk::FlipD(sf::Vector2f *v0, sf::Vector2f *v1, sf::Vector2f *v2, sf::Vector2f *v3)
    {
        //Diagonal flip
        sf::Vector2f tmp = *v1;
        v1->x = v3->x;
        v1->y = v3->y;
        v3->x = tmp.x;
        v3->y = tmp.y;
    }

    void OrthoMapLayer::Chunk::DoFlips(std::uint8_t bits, sf::Vector2f *v0, sf::Vector2f *v1, sf::Vector2f *v2, sf::Vector2f *v3)
    {
        //0000 = no change
        //0100 = vertical = swap y axis
        //1000 = horizontal = swap x axis
        //1100 = horiz + vert = swap both axes = horiz+vert = rotate 180 degrees
        //0010 = diag = rotate 90 degrees right and swap x axis
        //0110 = diag+vert = rotate 270 degrees right
        //1010 = horiz+diag = rotate 90 degrees right
        //1110 = horiz+vert+diag = rotate 90 degrees right and swap y axis
        if(!(bits & TileLayer::FlipFlag::Horizontal)
           && !(bits & TileLayer::FlipFlag::Vertical)
           && !(bits & TileLayer::FlipFlag::Diagonal) )
        {
            //Shortcircuit tests for nothing to do
            return;
        }
        else if(!(bits & TileLayer::FlipFlag::Horizontal)
                && (bits & TileLayer::FlipFlag::Vertical)
                && !(bits & TileLayer::FlipFlag::Diagonal) )
        {
            //0100
            FlipY(v0, v1, v2, v3);
        }
        else if((bits & TileLayer::FlipFlag::Horizontal)
                && !(bits & TileLayer::FlipFlag::Vertical)
                && !(bits & TileLayer::FlipFlag::Diagonal) )
        {
            //1000
            FlipX(v0, v1, v2, v3);
        }
        else if((bits & TileLayer::FlipFlag::Horizontal)
                && (bits & TileLayer::FlipFlag::Vertical)
                && !(bits & TileLayer::FlipFlag::Diagonal) )
        {
            //1100
            FlipY(v0, v1, v2, v3);
            FlipX(v0, v1, v2, v3);
        }
        else if(!(bits & TileLayer::FlipFlag::Horizontal)
                && !(bits & TileLayer::FlipFlag::Vertical)
                && (bits & TileLayer::FlipFlag::Diagonal) )
        {
            //0010
            FlipD(v0, v1, v2, v3);
        }
        else if(!(bits & TileLayer::FlipFlag::Horizontal)
                && (bits & TileLayer::FlipFlag::Vertical)
                && (bits & TileLayer::FlipFlag::Diagonal) )
        {
            //0110
            FlipX(v0, v1, v2, v3);
            FlipD(v0, v1, v2, v3);
        }
        else if((bits & TileLayer::FlipFlag::Horizontal)
                && !(bits & TileLayer::FlipFlag::Vertical)
                && (bits & TileLayer::FlipFlag::Diagonal) )
        {
            //1010
            FlipY(v0, v1, v2, v3);
            FlipD(v0, v1, v2, v3);
        }
        else if((bits & TileLayer::FlipFlag::Horizontal)
                && (bits & TileLayer::FlipFlag::Vertical)
                && (bits & TileLayer::FlipFlag::Diagonal) )
        {
            //1110
            FlipY(v0, v1, v2, v3);
            FlipX(v0, v1, v2, v3);
            FlipD(v0, v1, v2, v3);
        }
    }

    void OrthoMapLayer::Chunk::draw(sf::RenderTarget &rt, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        for (const auto& a : m_chunkArrays)
        {
            rt.draw(*a, states);
        }
    }

    OrthoMapLayer::Chunk::ChunkArray::ChunkArray(const sf::Texture &t, const Tileset &ts)
        : m_texture(t)
    {
        auto texSize = GetTextureSize();
        tileSetSize = ts.getTileSize();
        tsTileCount.x = texSize.x / tileSetSize.x;
        tsTileCount.y = texSize.y / tileSetSize.y;
        m_firstGID = ts.getFirstGID();
        m_lastGID = ts.getLastGID();
    }

    void OrthoMapLayer::Chunk::ChunkArray::Reset()
    {
        m_vertices.clear();
    }

    void OrthoMapLayer::Chunk::ChunkArray::AddTile(const Chunk::Tile& tile)
    {
        for (const auto& v : tile)
        {
            m_vertices.push_back(v);
        }
    }

    sf::Vector2u OrthoMapLayer::Chunk::ChunkArray::GetTextureSize() const
    {
        return m_texture.getSize();
    }

    void OrthoMapLayer::Chunk::ChunkArray::draw(sf::RenderTarget &rt, sf::RenderStates states) const
    {
        states.texture = &m_texture;
        rt.draw(m_vertices.data(), m_vertices.size(), sf::Quads, states);
    }
}
