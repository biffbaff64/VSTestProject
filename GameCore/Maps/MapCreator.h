#ifndef SFMLTEST_MAPCREATOR_H
#define SFMLTEST_MAPCREATOR_H

#include "Enums/GraphicID.h"
#include "TMX/MapObject.hpp"
#include "ObjectTileProperties.h"
#include "Entities/SpriteDescriptor.h"

using namespace Enums;

namespace Game
{
    class MapCreator
    {
    public:
        MapCreator() = default;
        ~MapCreator() = default;

        void CreateMapData();

    private:
        void ParseMarkerTiles();
        void ParseObjectTiles();
        void CreateCollisionBoxes();

        ObjectTileProperties SetObjectTileProperties(const SpriteDescriptor* descriptor);
        void CreatePlacementTile(const tmx::MapObject& mapObject, SpriteDescriptor* descriptor);
        void SetMapEntityPlaceable(GraphicID gid, bool placeable);
        void AddDummyCollisionObject();

        SpriteDescriptor m_spriteDescriptor;
    };
}

#endif //SFMLTEST_MAPCREATOR_H
