#include <iostream>

#include <GDX/Physics/Movement.h>

#include "Graphics/BaseRenderer.h"
#include "Graphics/Gfx.h"
#include "Core/App.h"

#include "MapData.h"

namespace Game
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    MapData::MapData()
    {
        m_mapPosition.Set(0, 0);
        m_currentMapName = nullptr;

        m_mapWidth   = 0;
        m_mapHeight  = 0;
        m_tileWidth  = 0;
        m_tileHeight = 0;

        m_maxScrollX = 0;
        m_maxScrollY = 0;
        m_minScrollX = 0;
        m_minScrollY = 0;

        m_scrollXDirection = DIRECTION_STILL;
        m_scrollYDirection = DIRECTION_STILL;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void MapData::LoadMap()
    {
        TraceFileFunc();

        m_currentMapName = pApp->m_pRoomManager->GetCurrentMapNameWithPath();

        if (!m_map.load(m_currentMapName))
        {
            trace->Dbg("MAP PARSE FAILURE");
        }

        SetGameLevelMap();

        m_scrollXDirection = DIRECTION_STILL;
        m_scrollYDirection = DIRECTION_STILL;

        DebugMap();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void MapData::SetGameLevelMap()
    {
        m_orthoLayers[GAME_TILES_LAYER].Set(m_map, GAME_TILES_LAYER);
        m_orthoLayers[EXTRA_GAME_TILES_LAYER].Set(m_map, EXTRA_GAME_TILES_LAYER);
        m_orthoLayers[MARKER_TILES_LAYER].Set(m_map, MARKER_TILES_LAYER);
        m_orthoLayers[OBJECT_TILES_LAYER].Set(m_map, OBJECT_TILES_LAYER);
        m_orthoLayers[COLLISION_LAYER].Set(m_map, COLLISION_LAYER);
        m_orthoLayers[NAVIGATION_LAYER].Set(m_map, NAVIGATION_LAYER);

        m_tileWidth     = (int) m_map.getTileSize().x;
        m_tileHeight    = (int) m_map.getTileSize().y;
        m_mapWidth      = m_map.getMapWidth() * m_tileWidth;
        m_mapHeight     = m_map.getMapHeight() * m_tileHeight;

        m_minScrollX = 0;
        m_minScrollY = 0;
        m_maxScrollX = m_mapWidth - (Gfx::inst().m_viewWidth / 2);
        m_maxScrollY = m_mapHeight - (Gfx::inst().m_viewHeight / 2);

        m_mapBox.m_left     = 0;
        m_mapBox.m_top      = 0;
        m_mapBox.m_right    = (float) m_mapWidth;
        m_mapBox.m_bottom   = (float) m_mapHeight;

        m_collisionBoxData.clear();
    }

    //------------------------------------------------------------------------------------------------------
    // Update the screen virtual window. This box is used for checking
    // that entities are visible on screen.
    // An extended virtual window is also updated, which is larger than
    // the visible screen, and can be used for tracking entities that
    // are nearby.
    // These windows will NOT be updated if the MainPlayer has
    // not been initialised, as they use its map position.
    //------------------------------------------------------------------------------------------------------

    void MapData::UpdateMap()
    {
        if (pApp->m_pEntityManager->m_playerReady)
        {
            GDXSprite *sprite = &pApp->GetEntity(pApp->GetPlayerIndex());

            m_viewportBox.Set
            (
                (int) (sprite->GetPosition().m_x - (Gfx::inst().m_viewWidth / 2)),
                (int) (sprite->GetPosition().m_y - (Gfx::inst().m_viewHeight / 2)),
                Gfx::inst().m_viewWidth,
                Gfx::inst().m_viewHeight
            );

            m_entityWindow.Set
            (
                (int) (sprite->GetPosition().m_x - (Gfx::inst().m_viewWidth + (Gfx::inst().m_viewWidth / 2))),
                (int) (sprite->GetPosition().m_y - (Gfx::inst().m_viewHeight + (Gfx::inst().m_viewHeight / 2))),
                Gfx::inst().m_viewWidth * 3,
                Gfx::inst().m_viewHeight * 3
            );
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    //#define DEBUG_MARKER_LAYER

    void MapData::Render() const
    {
        pApp->m_pBaseRenderer->m_renderWindow.draw
        (
            m_orthoLayers[GAME_TILES_LAYER],
            pApp->m_pBaseRenderer->m_renderStates
        );

        pApp->m_pBaseRenderer->m_renderWindow.draw
        (
            m_orthoLayers[EXTRA_GAME_TILES_LAYER],
            pApp->m_pBaseRenderer->m_renderStates
        );

        #ifdef DEBUG_MARKER_LAYER
        pApp->m_pBaseRenderer->m_renderWindow.draw
        (
            m_orthoLayers[MARKER_TILES_LAYER],
            pApp->m_pBaseRenderer->m_renderStates
        );
        #endif
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    tmx::TileLayer::Tile MapData::GetMarkerTile(int x, int y)
    {
        return m_orthoLayers[MARKER_TILES_LAYER].GetTile(x, y);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    tmx::TileLayer MapData::GetMarkerTilesLayer() const
    {
        return m_map.getLayers().at(MARKER_TILES_LAYER)->getLayerAs<tmx::TileLayer>();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    int MapData::GetWidthInTiles() const
    {
        return (m_mapWidth / m_tileWidth);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    int MapData::GetHeightInTiles() const
    {
        return (m_mapHeight / m_tileHeight);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void MapData::DebugMap() const
    {
        TraceFileFunc();

        // TODO: print out the map name
        trace->Dbg("Map Width  : %d [%d]", m_mapWidth, GetWidthInTiles());
        trace->Dbg("Map Height : %d [%d]", m_mapHeight, GetHeightInTiles());
        trace->Dbg("Tile Width : %d", m_tileWidth);
        trace->Dbg("Tile Height: %d", m_tileHeight);
    }
}
