//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Graphics/GameResources.h"
#include "Graphics/Gfx.h"
#include "Core/App.h"
#include "EntityUtils.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

namespace Game
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    const SpriteDescriptor entityList[] =
    {
        //
        // Main Character
        SpriteDescriptor
        (
            "Player",
            GraphicID::Player, GraphicID::Main, TileID::PlayerTile,
            IDLE_DOWN_ASSET, PLAYER_STAND_FRAMES,
            Vec2<int>(192, 192),
            Animation::PlayMode::Loop
        ),

        //
        // Other Characters
        SpriteDescriptor
        (
            "Prisoner",
            GraphicID::Prisoner, GraphicID::Main, TileID::PrisonerTile,
            PRISONER_IDLE_DOWN_ASSET, PRISONER_IDLE_FRAMES,
            Vec2<int>(128, 128),
            Animation::PlayMode::Loop
        ),
        SpriteDescriptor
        (
            "Villager",
            GraphicID::Villager, GraphicID::Main, TileID::VillagerTile,
            VILLAGER_IDLE_DOWN_ASSET, VILLAGER_IDLE_FRAMES,
            Vec2<int>(128, 128),
            Animation::PlayMode::Loop
        ),

        //
        // Lasers, Bullets, Explosions etc

        //
        // Pickup Items

        //
        // Decorations
        SpriteDescriptor
        (
            "Alcove Torch",
            GraphicID::AlcoveTorch, GraphicID::Decoration, TileID::AlcoveTorchTile,
            ALCOVE_TORCH_ASSET, ALCOVE_TORCH_FRAMES,
            Vec2<int>(64, 192),
            Animation::PlayMode::Loop
        ),
        SpriteDescriptor
        (
            "Barrel",
            GraphicID::Barrel, GraphicID::Decoration, TileID::BarrelTile,
            BARREL_1_ASSET, BARREL_FRAMES,
            Vec2<int>(90, 152),
            Animation::PlayMode::Normal
        ),
        SpriteDescriptor
        (
            "Crate",
            GraphicID::Crate, GraphicID::Decoration, TileID::CrateTile,
            CRATE_ASSET, CRATE_FRAMES,
            Vec2<int>(98, 120),
            Animation::PlayMode::Normal
        ),

        //
        // Interactive

        //
        // Stationary Enemies

        //
        // Mobile Enemies
        SpriteDescriptor
        (
            "Spike Ball",
            GraphicID::Spike_Ball, GraphicID::Enemy, TileID::SpikeBallTile,
            SPIKE_BALL_1_ASSET, SPIKE_BALL_FRAMES,
            Vec2<int>(128, 128),
            Animation::PlayMode::Loop
        ),
        SpriteDescriptor
        (
            "Spike Block",
            GraphicID::Spike_Block_Horizontal, GraphicID::Enemy, TileID::SpikeBlockRightTile,
            SPIKE_BLOCK_ASSET, SPIKE_BLOCK_HORIZONTAL_FRAMES,
            Vec2<int>(147, 256),
            Animation::PlayMode::Loop
        ),

        //
        // Miscellaneous Enemy Related

        //
        // Background Sprites
    };

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    int EntityUtils::GetEntityListSize()
    {
        return sizeof(entityList) / sizeof(SpriteDescriptor);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void EntityUtils::Update()
    {
        //
        // Scan through the entity map and update the
        // number of active entities for each type.
        // int thisCount;

        /*
        for (EntityManagerComponent managerComponent : m_managerList)
        {
            thisCount = 0;

            for (GDXSprite baseEntity : new Array.ArrayIterator<>(entityMap))
            {
                if (baseEntity.gid == managerComponent.getGID())
                {
                    thisCount++;
                }
            }

            managerComponent.setActiveCount(thisCount);
        }
        */
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    SpriteDescriptor EntityUtils::GetDescriptor(GraphicID gid) const
    {
        // TODO: Needs error checking

        return entityList[GetDescriptorIndex(gid)];
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    SpriteDescriptor EntityUtils::GetDescriptor(TileID tile) const
    {
        // TODO: Needs error checking
        return entityList[GetDescriptorIndex(tile)];
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    SpriteDescriptor EntityUtils::GetDescriptor(int index) const
    {
        // TODO: Needs error checking
        return entityList[index];
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    Vec2<int> EntityUtils::GetAssetSize(GraphicID gid) const
    {
        int index = GetDescriptorIndex(gid);

        Vec2<int> vec2;

        if (index == -1)
        {
            vec2.m_x = 0;
            vec2.m_y = 0;
        }
        else
        {
            vec2 = entityList[GetDescriptorIndex(gid)].m_size;
        }

        return vec2;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    // TODO: Can GetDescriptorIndex(GraphicID gid) and GetDescriptorIndex(TileID tileID) be combined into one??

    int EntityUtils::GetDescriptorIndex(GraphicID gid) const
    {
        int  index = 0;
        int  defsIndex = 0;
        bool foundIndex = false;

        for (const SpriteDescriptor& descriptor : entityList)
        {
            if ((descriptor.m_gid == gid) && !foundIndex)
            {
                defsIndex = index;
                foundIndex = true;
            }

            index++;
        }

        if (!foundIndex)
        {
            trace->Dbg("INDEX FOR %s NOT FOUND!!!", GET_GID_NAME((int)gid));

            defsIndex = -1;
        }

        return defsIndex;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    int EntityUtils::GetDescriptorIndex(TileID tileID) const
    {
        int  index = 0;
        int  defsIndex = 0;
        bool foundIndex = false;

        for (const SpriteDescriptor& descriptor : entityList)
        {
            if ((descriptor.m_tile == tileID) && !foundIndex)
            {
                defsIndex = index;
                foundIndex = true;
            }

            index++;
        }

        if (!foundIndex)
        {
            trace->Dbg("INDEX FOR %s NOT FOUND!!!", GET_GID_NAME((int)tileID));

            defsIndex = -1;
        }

        return defsIndex;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void EntityUtils::RemoveEntity(int index)
    {
        // TODO:
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    GDXSprite EntityUtils::FindFirstOf(GraphicID gid) const
    {
        // TODO:
        return GDXSprite();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    GDXSprite EntityUtils::FindLastOf(GraphicID gid) const
    {
        // TODO:
        return GDXSprite();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    GDXSprite EntityUtils::GetRandomSprite(GraphicID gid) const
    {
        // TODO:
        return GDXSprite();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    GDXSprite EntityUtils::FindNearestSprite(GraphicID gid) const
    {
        // TODO:
        return GDXSprite();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    GDXSprite EntityUtils::GetDistantSprite(GraphicID gid) const
    {
        // TODO:
        return GDXSprite();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    bool EntityUtils::IsOnScreen(GDXSprite gdxSprite) const
    {
        return pApp->m_pMapData->m_viewportBox.Overlaps(gdxSprite.GetSprite().getGlobalBounds());
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    int EntityUtils::GetInitialZPosition(GraphicID gid) const
	{
        int zed;

        switch (gid)
        {
            case GraphicID::Selection_Ring:
            {
                zed = MAXIMUM_Z_DEPTH;
            }
            break;

            case GraphicID::Floor_Button:
            case GraphicID::Lever_Switch:
            case GraphicID::Teleporter:
            case GraphicID::Escalator:
            case GraphicID::Escalator_Left:
            case GraphicID::Escalator_Right:
            case GraphicID::Escalator_Up:
            case GraphicID::Escalator_Down:
            {
                zed = 10;
            }
            break;

            case GraphicID::Door:
            case GraphicID::Locked_Door:
            case GraphicID::Open_Door:
            case GraphicID::Floating_Platform:
            {
                zed = 9;
            }
            break;

            case GraphicID::AlcoveTorch:
            case GraphicID::Pot:
            case GraphicID::Crate:
            case GraphicID::Barrel:
            case GraphicID::GlowEyes:
            case GraphicID::Spikes:
            case GraphicID::Treasure_Chest:
            case GraphicID::Mystery_Chest:
            case GraphicID::Turret:
            case GraphicID::Sacks:
            case GraphicID::PlantPot:
            {
                zed = 8;
            }
            break;

            case GraphicID::Arrow:
            case GraphicID::Gem:
            case GraphicID::Coin:
            case GraphicID::SpecialCoin:
            case GraphicID::HiddenCoin:
            case GraphicID::Key:
            case GraphicID::Sheild:
            case GraphicID::Document:
            case GraphicID::Litter:
            case GraphicID::Rune:
            case GraphicID::Book:
            {
                zed = 7;
            }
            break;

            case GraphicID::Question_Mark:
            {
                zed = 6;
            }
            break;

            case GraphicID::Enemy_Bullet:
            {
                zed = 5;
            }
            break;

            case GraphicID::Soldier:
            case GraphicID::Spike_Ball:
            case GraphicID::Scorpion:
            {
                zed = 4;
            }
            break;

            case GraphicID::Spike_Block_Horizontal:
            case GraphicID::Spike_Block_Vertical:
            case GraphicID::Loop_Block_Horizontal:
            case GraphicID::Loop_Block_Vertical:
            case GraphicID::Big_Block_Horizontal:
            case GraphicID::Big_Block_Vertical:
            {
                zed = 3;
            }
            break;

            case GraphicID::Laser:
            case GraphicID::Player:
            case GraphicID::Villager:
            case GraphicID::Prisoner:
            {
                zed = 2;
            }
            break;

            case GraphicID::Laser_Beam:
            case GraphicID::Laser_Beam_Horizontal:
            case GraphicID::Laser_Beam_Vertical:
            case GraphicID::Flame_Thrower:
            {
                zed = 1;
            }
            break;

            case GraphicID::Storm_Demon:
            case GraphicID::Bouncer:
            case GraphicID::Prize_Balloon:
            case GraphicID::Message_Bubble:
            case GraphicID::Help_Bubble:
            case GraphicID::Explosion12:
            case GraphicID::Explosion32:
            case GraphicID::Explosion64:
            case GraphicID::Explosion128:
            case GraphicID::Explosion256:
            {
                zed = 0;
            }
            break;

            default:
            {
                zed = MAXIMUM_Z_DEPTH + 1;
            }
            break;
        }

        return zed;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void EntityUtils::ResetAllPositions()
    {
        for (int i = 0; i < (int)pApp->m_pEntityManager->m_entityMap.size(); i++)
        {
            GDXSprite gdxSprite = *pApp->m_pEntityManager->m_entityMap.at(i);

            gdxSprite.GetSprite().setPosition(gdxSprite.m_initXY.m_x, gdxSprite.m_initXY.m_y);
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void EntityUtils::SetAllEnemyStatuses()
    {
        TraceFileFunc();

        bool isEnemy;

        for (auto& entity : pApp->m_pEntityManager->m_entityMap)
        {
            switch (entity->m_gid)
            {
            case GraphicID::Prize_Balloon:
            case GraphicID::Message_Bubble:
            case GraphicID::Laser:
            case GraphicID::Player:
            case GraphicID::Explosion12:
            case GraphicID::Explosion32:
            case GraphicID::Explosion64:
            case GraphicID::Explosion128:
            case GraphicID::Explosion256:

                isEnemy = false;
                break;

            default:

                isEnemy = true;
                break;
            }

            if (entity->m_type == GraphicID::Entity)
            {
                entity->m_properties->m_isEnemy = isEnemy;
            }
        }
    }
}

