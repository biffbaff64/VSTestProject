#ifndef SFMLTEST_MAPDATA_H
#define SFMLTEST_MAPDATA_H

#include "SFML/Graphics.hpp"
#include "GDX/Maths/BoundsBox.h"
#include "GDX/Maths/Box.h"
#include "GDX/Maths/SimpleVec2.h"
#include "TMX/OrthoMapLayer.h"
#include "TMX/Map.hpp"

#include "Physics/CollisionObject.h"

namespace Game
{
#define GAME_TILES_LAYER        0
#define EXTRA_GAME_TILES_LAYER  1
#define MARKER_TILES_LAYER      2
#define OBJECT_TILES_LAYER      3
#define COLLISION_LAYER         4
#define NAVIGATION_LAYER        5
#define NUM_LAYERS              6

    class MapData
    {
    public:
        MapData();
        ~MapData() = default;

        void LoadMap();
        void UpdateMap();
        void Render() const;

        tmx::TileLayer::Tile GetMarkerTile(int x, int y);
        tmx::TileLayer GetMarkerTilesLayer() const;

        [[nodiscard]] int GetWidthInTiles() const;
        [[nodiscard]] int GetHeightInTiles() const;

        int m_maxScrollX;
        int m_maxScrollY;
        int m_minScrollX;
        int m_minScrollY;
        int m_scrollXDirection;
        int m_scrollYDirection;

        int m_mapWidth;
        int m_mapHeight;
        int m_tileWidth;
        int m_tileHeight;

        GDX::SimpleVec2 m_mapPosition;
        GDX::SimpleVec2 m_previousMapPos;
        GDX::SimpleVec2 m_checkPoint;

        GDX::Box        m_viewportBox;
        GDX::Box        m_entityWindow;
        GDX::BoundsBox  m_mapBox;

        tmx::Map                        m_map;
        tmx::OrthoMapLayer              m_orthoLayers[NUM_LAYERS];
        std::vector<CollisionObject>    m_collisionBoxData;
        std::vector<SpriteDescriptor>   m_placementTiles;

    private:
        void SetGameLevelMap();
        void DebugMap() const;

        const char * m_currentMapName;
    };
}

#endif // SFMLTEST_MAPDATA_H
