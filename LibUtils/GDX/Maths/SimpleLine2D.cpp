#include "SimpleLine2D.h"

namespace GDX
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    SimpleLine2D::SimpleLine2D(float x1, float y1, float x2, float y2)
    {
        m_x1 = x1;
        m_y1 = y1;
        m_x2 = x2;
        m_y2 = y2;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    bool SimpleLine2D::Intersects(SimpleLine2D line2D) const
    {
        float s1_x = m_x2 - m_x1;
        float s1_y = m_y2 - m_y1;
        float s2_x = line2D.m_x2 - line2D.m_x1;
        float s2_y = line2D.m_y2 - line2D.m_y1;

        float v = (-s2_x * s1_y) + (s1_x * s2_y);

        float s = ((-s1_y * (m_x1 - line2D.m_x1)) + (s1_x * (m_y1 - line2D.m_y1))) / v;
        float t = ((s2_x * (m_y1 - line2D.m_y1)) - (s2_y * (m_x1 - line2D.m_x1))) / v;

        return ((s >= 0) && (s <= 1) && (t >= 0) && (t <= 1));
    }
}


