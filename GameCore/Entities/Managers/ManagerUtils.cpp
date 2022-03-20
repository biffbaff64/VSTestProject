//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Core/App.h"
#include "ManagerUtils.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

namespace Game
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    
    std::vector<SpriteDescriptor> ManagerUtils::GetDescriptorList(const Enums::GraphicID targetGID)
    {
        m_descriptors.clear();

        for (SpriteDescriptor marker : pApp->m_pMapData->m_placementTiles)
        {
            if (marker.m_gid == targetGID)
            {
                m_descriptors.push_back(marker);
            }
        }

        return m_descriptors;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    std::vector<GDX::Vec3Int> ManagerUtils::FindMultiCoordinates(const Enums::GraphicID targetGID)
    {
        for (SpriteDescriptor marker : pApp->m_pMapData->m_placementTiles)
        {
            if (marker.m_gid == targetGID)
            {
                m_coords.push_back(Vec3Int(marker.m_position.m_x, marker.m_position.m_y, 0));
            }
        }

        return m_coords;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    GDX::Vec3Int ManagerUtils::FindCoordinates(const Enums::GraphicID targetGID)
    {
        for (SpriteDescriptor marker : pApp->m_pMapData->m_placementTiles)
        {
            if (marker.m_gid == targetGID)
            {
                m_coord.m_x = marker.m_position.m_x;
                m_coord.m_y = marker.m_position.m_y;
                m_coord.m_z = 0;

                break;
            }
        }

        return m_coord;
    }
}

