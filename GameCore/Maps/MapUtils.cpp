
#include <iostream>

#include <GDX/Physics/Movement.h>

#include "MapUtils.h"
#include "../Core/App.h"
#include "../Graphics/Gfx.h"

namespace Game
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    
    MapUtils::MapUtils()
    {
        m_direction.StandStill();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void MapUtils::PositionAt(int x, int y)
    {
        pApp->m_pMapData->m_previousMapPos.Set(pApp->m_pMapData->m_mapPosition);

        int tempX = std::max(pApp->m_pMapData->m_minScrollX, x);
        tempX = std::min(tempX, pApp->m_pMapData->m_maxScrollX);

        int tempY = std::max(pApp->m_pMapData->m_minScrollY, y);
        tempY = std::min(tempY, pApp->m_pMapData->m_maxScrollY);

        pApp->m_pMapData->m_mapPosition.Set(tempX, tempY);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void MapUtils::DemoScroll()
    {
        if (m_direction.HasDirection())
        {
            if (m_direction.GetX() == DIRECTION_UP)
            {
                if (pApp->m_pMapData->m_mapPosition.m_x <= pApp->m_pMapData->m_minScrollX)
                {
                    pApp->m_pMapData->m_mapPosition.m_x = pApp->m_pMapData->m_minScrollX;
                    m_direction.SetX(DIRECTION_RIGHT);
                }
            }
            else if (m_direction.GetX() == DIRECTION_RIGHT)
            {
                if (pApp->m_pMapData->m_mapPosition.m_x >= pApp->m_pMapData->m_maxScrollX)
                {
                    pApp->m_pMapData->m_mapPosition.m_x = pApp->m_pMapData->m_maxScrollX;
                    m_direction.SetX(DIRECTION_LEFT);
                }
            }

            pApp->m_pMapData->m_mapPosition.m_x += (DEMO_SCROLL_XSPEED * m_direction.GetX());

            if (m_direction.GetY() == DIRECTION_UP)
            {
                if (pApp->m_pMapData->m_mapPosition.m_y <= pApp->m_pMapData->m_minScrollY)
                {
                    pApp->m_pMapData->m_mapPosition.m_y = pApp->m_pMapData->m_minScrollY;
                    m_direction.SetY(DIRECTION_DOWN);
                }
            }
            else if (m_direction.GetY() == DIRECTION_DOWN)
            {
                if (pApp->m_pMapData->m_mapPosition.m_y >= pApp->m_pMapData->m_maxScrollY)
                {
                    pApp->m_pMapData->m_mapPosition.m_y = pApp->m_pMapData->m_maxScrollY;
                    m_direction.SetY(DIRECTION_UP);
                }
            }

            pApp->m_pMapData->m_mapPosition.m_y += (DEMO_SCROLL_YSPEED * m_direction.GetY());
        }
        else
        {
            m_direction.Set(DIRECTION_RIGHT, DIRECTION_DOWN);
        }
    }
}

