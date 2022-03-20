#ifndef __ENTITY_UTILS_H
#define __ENTITY_UTILS_H

#include <vector>

#include "Enums/GraphicID.h"
#include "GDX/Graphics/Animation.h"
#include "Entities/Objects/GdxSprite.h"

using namespace Enums;
using namespace GDX;

namespace Game
{
    struct EntityDef
    {
        char *m_objectName;
        char *m_asset;
        int         m_frames;
        GraphicID   m_graphicID;
        GraphicID   m_type;
        TileID      m_tileID;
    };

    struct ActionSpeed
    {
        ActionStates    m_action;
        float           m_speed;
    };

    struct AnimSpeed
    {
        GraphicID   m_graphicID;
        float       m_speed;
    };

    struct EntityCounts
    {
        GraphicID   m_graphicID;
        int         m_currentTotal;
        int         m_maxTotal;
    };

    class EntityUtils
	{
	public:
		EntityUtils() = default;
		virtual ~EntityUtils() = default;

		void ResetAllPositions();
        void Update();
		void SetAllEnemyStatuses();
        void RemoveEntity(int index);

        [[nodiscard]] int GetEntityListSize();
		[[nodiscard]] SpriteDescriptor GetDescriptor(GraphicID gid) const;
		[[nodiscard]] SpriteDescriptor GetDescriptor(TileID tile) const;
        [[nodiscard]] SpriteDescriptor GetDescriptor(int index) const;
		[[nodiscard]] Vec2<int> GetAssetSize(GraphicID gid) const;
		[[nodiscard]] int GetDescriptorIndex(GraphicID gid) const;
		[[nodiscard]] int GetDescriptorIndex(TileID tileID) const;
		[[nodiscard]] int GetInitialZPosition(GraphicID gid) const;
		[[nodiscard]] GDXSprite FindFirstOf(GraphicID gid) const;
		[[nodiscard]] GDXSprite FindLastOf(GraphicID gid) const;
		[[nodiscard]] GDXSprite GetRandomSprite(GraphicID gid) const;
		[[nodiscard]] GDXSprite FindNearestSprite(GraphicID gid) const;
		[[nodiscard]] GDXSprite GetDistantSprite(GraphicID gid) const;
		[[nodiscard]] bool IsOnScreen(GDXSprite gdxSprite) const;
	};
}

#endif // __ENTITY_UTILS_H
