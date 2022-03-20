#ifndef SFMLTEST_SPRITEDESCRIPTOR_H
#define SFMLTEST_SPRITEDESCRIPTOR_H

#include <string>

#include "Enums/GraphicID.h"
#include "Enums/TileID.h"

#include "GDX/Graphics/Animation.h"
#include "GDX/Maths/SimpleVec2F.h"
#include "GDX/Maths/Vec2.h"
#include "GDX/Maths/Vec3.h"
#include "GDX/Physics/Direction.h"

namespace Game
{
    class SpriteDescriptor
    {
    public:
        SpriteDescriptor();
        SpriteDescriptor(const std::string& objectName,
                         Enums::GraphicID graphicID,
                         Enums::GraphicID type,
                         Enums::TileID tileID,
                         const std::string& asset,
                         int frames,
                         GDX::Vec2<int> assetSize,
                         GDX::Animation::PlayMode playMode);
        ~SpriteDescriptor() = default;

        void SetToDefault();
        void Debug();

        Enums::GraphicID            m_gid;        // ID. See GraphicID class for options.
        Enums::TileID               m_tile;       // The associated marker tile.
        Enums::GraphicID            m_type;       // _MAIN, _INTERACTIVE, _PICKUP etc
        GDX::Vec3<int>              m_position;   // X, Y Pos of tile, in TileWidth units, Z-Sort value.
        GDX::Vec2<int>              m_size;       // Width and Height.
        GDX::Animation::PlayMode    m_playmode;   // Animation playmode for the asset frames above.
        GDX::Direction              m_dir;        // Initial direction of travel.
        GDX::SimpleVec2F            m_dist;       // Initial travel distance. Useful for moving blocks etc.
        GDX::SimpleVec2F            m_speed;      // Initial speed.
        std::string                 m_name;       // MUST Match the name assigned in TiledMap.
        std::string                 m_asset;      // The initial image asset.
        int                         m_frames;     // Number of frames in the asset above.
        int                         m_index;      // This entities position in the entity map.
        int                         m_link;       // Linked GDXSprite (if applicable) (Index into entityMap).
        float                       m_anim_rate;  // Animation speed
    };
}

#endif //SFMLTEST_SPRITEDESCRIPTOR_H
