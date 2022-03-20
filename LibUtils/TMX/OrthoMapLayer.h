#ifndef SFMLTEST_ORTHOMAPLAYER_H
#define SFMLTEST_ORTHOMAPLAYER_H

#include <string>

#include "SFML/Graphics.hpp"
#include "TMX/Map.hpp"
#include "TMX/TileLayer.hpp"

namespace tmx
{
    class OrthoMapLayer final : public sf::Drawable
    {
    public:
        OrthoMapLayer() = default;
        OrthoMapLayer(const Map &map, std::size_t index);
        ~OrthoMapLayer() override = default;

        OrthoMapLayer(const OrthoMapLayer &) = delete;
        OrthoMapLayer &operator=(const OrthoMapLayer &) = delete;

        [[nodiscard]] const sf::FloatRect &GetGlobalBounds() const;
        [[nodiscard]] sf::Color GetColor(int tileX, int tileY);

        void Set(const Map &map, std::size_t index);
        void SetTile(int tileX, int tileY, TileLayer::Tile tile, bool refresh = true);
        void SetColor(int tileX, int tileY, sf::Color color, bool refresh = true);
        void Update(sf::Time elapsed);
        TileLayer::Tile GetTile(int tileX, int tileY);

        std::string GetName();

    private:
        sf::FloatRect m_globalBounds;
        sf::Vector2f  m_chunkSize = sf::Vector2f(512.0f, 512.0f);
        sf::Vector2u  m_chunkCount;
        sf::Vector2u  m_MapTileSize;

        std::string m_layerName;

        using TextureResource = std::map<std::string, std::unique_ptr<sf::Texture>>;
        TextureResource m_textureResource;

        struct AnimationState
        {
            sf::Vector2u  tileCords;
            sf::Time      startTime;
            sf::Time      currentTime;
            Tileset::Tile animTile;
            std::uint8_t  flipFlags{ };
        };

        // ---------------------------------------------------------------------------
        class Chunk final : sf::Transformable, public sf::Drawable
        {
        public:
            using Ptr = std::unique_ptr<Chunk>;
            using Tile = std::array<sf::Vertex, 4u>;

            Chunk(const TileLayer &layer,
                  std::vector<const Tileset *> tilesets,
                  const sf::Vector2f &position,
                  const sf::Vector2f &tileCount,
                  const sf::Vector2u &tileSize,
                  std::size_t rowSize,
                  TextureResource &tr,
                  const std::map<std::uint32_t, Tileset::Tile> &animTiles);

            Chunk(const Chunk &) = delete;
            ~Chunk() override = default;

            Chunk &operator=(const Chunk &) = delete;

            [[nodiscard]] std::vector<AnimationState> &GetActiveAnimations();
            [[nodiscard]] TileLayer::Tile GetTile(int x, int y) const;
            [[nodiscard]] sf::Color GetColor(int x, int y) const;
            [[nodiscard]] int CalcIndexFrom(int x, int y) const;
            [[nodiscard]] bool Empty() const;

            void GenerateTiles(bool registerAnimation = false);
            void SetTile(int x, int y, TileLayer::Tile tile, bool refresh);
            void SetColor(int x, int y, sf::Color color, bool refresh);
            void MaybeRegenerate(bool refresh);
            void FlipY(sf::Vector2f *v0, sf::Vector2f *v1, sf::Vector2f *v2, sf::Vector2f *v3);
            void FlipX(sf::Vector2f *v0, sf::Vector2f *v1, sf::Vector2f *v2, sf::Vector2f *v3);
            void FlipD(sf::Vector2f *v0, sf::Vector2f *v1, sf::Vector2f *v2, sf::Vector2f *v3);
            void DoFlips(std::uint8_t bits, sf::Vector2f *v0, sf::Vector2f *v1, sf::Vector2f *v2, sf::Vector2f *v3);

        private:
            // ---------------------------------------------------------------------------
            class ChunkArray final : public sf::Drawable
            {
            public:
                using Ptr = std::unique_ptr<ChunkArray>;

                Vector2u      tileSetSize;
                sf::Vector2u  tsTileCount;
                std::uint32_t m_firstGID, m_lastGID;
                explicit ChunkArray(const sf::Texture &t, const Tileset &ts);

                ~ChunkArray() override = default;
                ChunkArray(const ChunkArray &) = delete;
                ChunkArray &operator=(const ChunkArray &) = delete;

                void Reset();
                void AddTile(const Chunk::Tile &tile);
                [[nodiscard]] sf::Vector2u GetTextureSize() const;

            private:
                const sf::Texture &m_texture;
                std::vector<sf::Vertex> m_vertices;

                void draw(sf::RenderTarget &rt, sf::RenderStates states) const override;
            };
            // ---------------------------------------------------------------------------

            sf::Uint8    layerOpacity;      // opacity of the layer
            sf::Vector2f layerOffset;       // Layer offset
            sf::Vector2u mapTileSize;       // general Tilesize of Map
            sf::Vector2f chunkTileCount;    // chunk tilecount

            std::vector<TileLayer::Tile>           m_chunkTileIDs;          // stores all tiles in this chunk for later manipulation
            std::vector<sf::Color>                 m_chunkColors;           // stores colors for extended color effects
            std::map<std::uint32_t, Tileset::Tile> m_animTiles;             // animation catalogue
            std::vector<AnimationState>            m_activeAnimations;      // Animations to be done in this chunk
            std::vector<ChunkArray::Ptr>           m_chunkArrays;

            void draw(sf::RenderTarget &rt, sf::RenderStates states) const override;
        };
        // ---------------------------------------------------------------------------

        std::vector<Chunk::Ptr>      m_chunks;
        mutable std::vector<Chunk *> m_visibleChunks;

        Chunk::Ptr &GetChunkAndTransform(int x, int y, sf::Vector2u &chunkRelative);
        void CreateChunks(const Map &map, const TileLayer &layer);
        void UpdateVisibility(const sf::View &view) const;

        void draw(sf::RenderTarget &rt, sf::RenderStates states) const override;
    };
}

#endif // SFMLTEST_ORTHOMAPLAYER_H
