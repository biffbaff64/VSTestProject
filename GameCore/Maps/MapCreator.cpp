//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include <iostream>

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include <Enums/TileID.h>
#include <TMX/TileLayer.hpp>
#include <GDX/Utils/Trace.h>

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Entities/Components/EntityManagerComponent.h"
#include "Entities/EntityUtils.h"
#include "Core/App.h"
#include "MapCreator.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

namespace Game
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void MapCreator::CreateMapData()
    {
        pApp->m_pMapData->m_placementTiles.clear();
        pApp->m_pEntityManager->m_entityMap.clear();

        ParseMarkerTiles();

        if (pApp->m_pMapData->m_collisionBoxData.size() == 0)
        {
            AddDummyCollisionObject();
        }  

        CreateCollisionBoxes();
    }

    //------------------------------------------------------------------------------------------------------
    // 'Marker Tiles' are objects defined in an ObjectLayer in the TiledMap .tmx file.
    // They indicate positions for sprites, trigger points, etc.
    // Some Marker Tiles will have properties which will apply to sprites or other objects.
    //------------------------------------------------------------------------------------------------------
    void MapCreator::ParseMarkerTiles()
    {
        TraceFileFunc();

        const std::vector<tmx::Layer::Ptr> &layers = pApp->m_pMapData->m_map.getLayers();
        const auto& tileLayer = layers[MARKER_TILES_LAYER]->getLayerAs<tmx::TileLayer>();
        const auto& layerIDs = tileLayer.getTiles();

        int width_in_tiles  = pApp->m_pMapData->m_map.getMapWidth();
        int height_in_tiles = pApp->m_pMapData->m_map.getMapHeight();
        int arrayIndex      = 0;
        int index           = 0;
        bool isIgnoreTile   = false;

        for (int row = 0; row < height_in_tiles; row++)
        {
            for (int column = 0; column < width_in_tiles; column++)
            {
                int tileID = layerIDs.at(index).ID;

                if (tileID > 0)
                {
                    switch ((TileID) tileID)
                    {
                        case TileID::DefaultTile:
                        case TileID::NorthTile:
                        case TileID::EastTile:
                        case TileID::SouthTile:
                        case TileID::WestTile:
                        case TileID::PlayerTile:
                        // ----------------------
                        case TileID::ArrowTile:
                        case TileID::GemTile:
                        case TileID::KeyTile:
                        case TileID::CoinTile:
                        case TileID::ShieldTile:
                        case TileID::ChestTile:
                        case TileID::MysteryCoin:
                        case TileID::MysteryChestTile:
                        case TileID::HiddenCoinTile:
                        case TileID::GlowEyesTile:
                        case TileID::PlantPotTile:
                        case TileID::PotTile:
                        case TileID::SacksTile:
                        case TileID::TurretTile:
                        case TileID::StormDemonTile:
                        case TileID::ScorpionTile:
                        case TileID::BouncerTile:
                        case TileID::LeverTile:
                        case TileID::DoorTile:
                        case TileID::EscalatorUpTile:
                        case TileID::EscalatorDownTile:
                        case TileID::EscalatorLeftTile:
                        case TileID::EscalatorRightTile:
                        case TileID::FlameThrowUpTile:
                        case TileID::FlameThrowDownTile:
                        case TileID::FlameThrowLeftTile:
                        case TileID::FlameThrowRightTile:
                        // ----------------------
                        {
                            isIgnoreTile = true;
                        }
                        break;

                        //case TileID::ArrowTile:
                        //case TileID::GemTile:
                        //case TileID::KeyTile:
                        //case TileID::CoinTile:
                        //case TileID::ShieldTile:
                        //case TileID::ChestTile:
                        //case TileID::MysteryCoin:
                        //case TileID::MysteryChestTile:
                        //case TileID::HiddenCoinTile:
                        //{
                        //    SetMapEntityPlaceable(GraphicID::Pickup, true);
                        //    isIgnoreTile = false;
                        //}
                        //break;

                        case TileID::AlcoveTorchTile:
                        case TileID::BarrelTile:
                        case TileID::CrateTile:
                        {
                            SetMapEntityPlaceable(GraphicID::Decoration, true);
                            isIgnoreTile = false;
                        }
                        break;

                        case TileID::VillagerTile:
                        {
                            SetMapEntityPlaceable(GraphicID::Villager, true);
                            isIgnoreTile = false;
                        }
                        break;

                        case TileID::SoldierTile:
                        {
                            SetMapEntityPlaceable(GraphicID::Soldier, true);
                            isIgnoreTile = false;
                        }
                        break;

                        case TileID::PrisonerTile:
                        {
                            SetMapEntityPlaceable(GraphicID::Prisoner, true);
                            isIgnoreTile = false;
                        }
                        break;

                        case TileID::SpikeBallTile:
                        case TileID::SpikeBlockUpTile:
                        case TileID::SpikeBlockDownTile:
                        case TileID::SpikeBlockLeftTile:
                        case TileID::SpikeBlockRightTile:
                        {
                            SetMapEntityPlaceable(GraphicID::Blocks, true);
                            isIgnoreTile = false;
                        }
                        break;

                        //case TileID::TurretTile:
                        //{
                        //    SetMapEntityPlaceable(GraphicID::Turret, true);
                        //    isIgnoreTile = false;
                        //}
                        //break;

                        //case TileID::StormDemonTile:
                        //case TileID::ScorpionTile:
                        //case TileID::BouncerTile:
                        //{
                        //    SetMapEntityPlaceable(GraphicID::Monster, true);
                        //    isIgnoreTile = false;
                        //}
                        //break;

                        //case TileID::LeverTile:
                        //case TileID::DoorTile:
                        //case TileID::EscalatorUpTile:
                        //case TileID::EscalatorDownTile:
                        //case TileID::EscalatorLeftTile:
                        //case TileID::EscalatorRightTile:
                        //{
                        //    SetMapEntityPlaceable(GraphicID::Interactive, true);
                        //    isIgnoreTile = false;
                        //}
                        //break;

                        default:
                        {
                            trace->Dbg(" - Unknown tile: %s", GET_TILE_NAME(tileID));
                            isIgnoreTile = true;
                        }
                        break;
                    }

                    if (!isIgnoreTile)
                    {
                        m_spriteDescriptor.SetToDefault();
                        m_spriteDescriptor = pApp->m_pEntityUtils->GetDescriptor((TileID) tileID);

                        m_spriteDescriptor.m_position.m_x   = column;
                        m_spriteDescriptor.m_position.m_y   = row;
                        m_spriteDescriptor.m_index          = arrayIndex++;

                        pApp->m_pMapData->m_placementTiles.push_back(m_spriteDescriptor);
                    }
                }

                index++;
            }
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void MapCreator::ParseObjectTiles()
    {
        TraceFileFunc();

        const std::vector<tmx::Layer::Ptr> &layers = pApp->m_pMapData->m_map.getLayers();
        const auto &objectLayer = layers[OBJECT_TILES_LAYER]->getLayerAs<tmx::ObjectGroup>();
        const auto &objectsGroup = objectLayer.getObjects();

        for (tmx::MapObject object : objectsGroup)
        {
            for (int i = 0; i < pApp->m_pEntityUtils->GetEntityListSize(); i++)
            {
                m_spriteDescriptor.SetToDefault();
                m_spriteDescriptor = pApp->m_pEntityUtils->GetDescriptor(i);

                if (!object.getName().empty() && (m_spriteDescriptor.m_gid != GraphicID::NoID))
                {
                    CreatePlacementTile(object, &m_spriteDescriptor);

                    pApp->m_pMapData->m_placementTiles.push_back(m_spriteDescriptor);
                }
            }
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void MapCreator::CreateCollisionBoxes()
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void MapCreator::CreatePlacementTile(const tmx::MapObject &mapObject, SpriteDescriptor* descriptor)
    {
        descriptor->m_position.m_x = (int) (mapObject.getPosition().x / pApp->m_pMapData->m_tileWidth);
        descriptor->m_position.m_y = (int) (mapObject.getPosition().y / pApp->m_pMapData->m_tileHeight);
        descriptor->m_dist.SetEmpty();
        descriptor->m_dir.StandStill();
        descriptor->m_speed.SetEmpty();

        ObjectTileProperties properties = SetObjectTileProperties(descriptor);

        std::vector<tmx::Property> mapProperties = mapObject.getProperties();

        if (properties.m_hasDistance)
        {
        //    descriptor.m_dist.Set
        //        (
        //            ((int) mapObject.getProperties().get("xdistance")),
        //            ((int) mapObject.getProperties().get("ydistance"))
        //        );
        }
        
        if (properties.m_hasDirection)
        {
        //    descriptor.m_dir.Set
        //        (
        //            mapObject.getProperties().get("xdirection")
        //                .equals("right") ? Movement._DIRECTION_RIGHT :
        //            mapObject.getProperties().get("xdirection")
        //                .equals("left") ? Movement._DIRECTION_LEFT : Movement._DIRECTION_STILL,
        //
        //            mapObject.getProperties().get("ydirection")
        //                .equals("up") ? Movement._DIRECTION_UP :
        //            mapObject.getProperties().get("ydirection")
        //                .equals("down") ? Movement._DIRECTION_DOWN : Movement._DIRECTION_STILL
        //        );
        }
        
        if (properties.m_hasSpeed)
        {
        //    descriptor.m_speed.Set
        //        (
        //            ((float) mapObject.getProperties().get("xspeed")),
        //            ((float) mapObject.getProperties().get("yspeed"))
        //        );
        }
        
        if (properties.m_isLinked)
        {
        //    //
        //    // Fetch the link ID of the attached entity
        //    if (mapObject.getProperties().get("connection") != null)
        //    {
        //        descriptor.m_link = (int) mapObject.getProperties().get("connection");
        //    }
        }
        
        descriptor->m_index = pApp->m_pMapData->m_placementTiles.size();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    
    ObjectTileProperties MapCreator::SetObjectTileProperties(const SpriteDescriptor* descriptor)
    {
        ObjectTileProperties properties = ObjectTileProperties();

        switch (descriptor->m_tile)
        {
            case TileID::FloorButtonTile:
            case TileID::LeverTile:
            {
                properties.m_isLinked = true;
            }
            break;

            case TileID::BigBlockTile:
            case TileID::LoopBlockHorizontalTile:
            case TileID::LoopBlockVerticalTile:
            case TileID::SpikeBallTile:
            case TileID::SpikeBlockDownTile:
            case TileID::SpikeBlockUpTile:
            case TileID::SpikeBlockLeftTile:
            case TileID::SpikeBlockRightTile:
            {
                properties.m_hasDirection = true;
                properties.m_hasDistance = true;
                properties.m_hasSpeed = true;
            }
            break;

            default:
                break;
        }

        return properties;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void MapCreator::SetMapEntityPlaceable(GraphicID gid, bool placeable)
    {
        for (size_t i = 0; i < pApp->m_pEntityManager->m_managerList.size(); i++)
        {
            if (pApp->m_pEntityManager->m_managerList.at(i)->m_graphicID == gid)
            {
                pApp->m_pEntityManager->m_managerList.at(i)->m_isPlaceable = placeable;
            }
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void MapCreator::AddDummyCollisionObject()
    {
        // TODO: Add a new, empty, collision object to the collison box array.
    }
}

