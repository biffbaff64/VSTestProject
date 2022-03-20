
#include "Enums/Translations.h"
#include "SharedData/GlobalDefines.h"
#include "Core/App.h"
#include "SpriteDescriptor.h"

namespace Game
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    SpriteDescriptor::SpriteDescriptor()
        :
        m_gid(Enums::GraphicID::NoID),
        m_type(Enums::GraphicID::NoID),
        m_tile(Enums::TileID::Unknown),
        m_playmode(GDX::Animation::PlayMode::Normal),
        m_dir(),
        m_index(0),
        m_frames(0),
        m_anim_rate(1.0f / 6.0f),
        m_link(0)
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    SpriteDescriptor::SpriteDescriptor(const std::string& objectName,
                                       Enums::GraphicID graphicID, Enums::GraphicID type, Enums::TileID tileID,
                                       const std::string& asset, int frames,
                                       GDX::Vec2<int> assetSize,
                                       GDX::Animation::PlayMode playMode)
    {
        m_name     = objectName;
        m_gid      = graphicID;
        m_type     = type;
        m_tile     = tileID;
        m_asset    = asset;
        m_frames   = frames;
        m_size     = assetSize;
        m_playmode = playMode;

        m_index     = 0;
        m_link      = 0;
        m_anim_rate = (1.0f / 6.0f);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SpriteDescriptor::SetToDefault()
    {
        m_gid       = Enums::GraphicID::NoID;
        m_tile      = Enums::TileID::Unknown;
        m_type      = Enums::GraphicID::NoID;

        m_position.m_x = 0;
        m_position.m_y = 0;
        m_position.m_z = 0;

        m_size.m_x = 0;
        m_size.m_y = 0;

        m_playmode  = GDX::Animation::PlayMode::Normal;

        m_dir.StandStill();
        m_dist.SetEmpty();
        m_speed.SetEmpty();
        
        m_name      = "";
        m_asset     = "";
        m_frames    = 0;
        m_index     = 0;
        m_link      = 0;
        m_anim_rate = 0;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SpriteDescriptor::Debug()
    {
        trace->Divider();
        TraceFileFunc();

        trace->Dbg("_GID      : %s", GET_GID_NAME((int) m_gid));
        trace->Dbg("_TYPE     : %s", GET_GID_NAME((int) m_type));
        trace->Dbg("_POSITION : %d, %d",m_position.m_x, m_position.m_y);
        trace->Dbg("_SIZE     : %d, %d",m_size.m_x, m_size.m_y);
        trace->Dbg("_INDEX    : %d", m_index);
        trace->Dbg("_FRAMES   : %d", m_frames);
        trace->Dbg("_PLAYMODE : %d", m_playmode);
        trace->Dbg("_ANIM_RATE: %f", m_anim_rate);
        trace->Dbg("_NAME     : %s", m_name.c_str());
        trace->Dbg("_ASSET    : %s", m_asset.c_str());
        trace->Dbg("_LINK     : %d", m_link);
        trace->Dbg("_TILE     : %s", GET_TILE_NAME((int) m_tile));
        trace->Dbg("_PARENT   : %s", "TO DO");
        trace->Dbg("_DIR      : %s", "TO DO");
        trace->Dbg("_DIST     : %s", "TO DO");
        trace->Dbg("_SPEED    : %s", "TO DO");
    }
}
