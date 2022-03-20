#include "BoundsBox.h"

namespace GDX
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    BoundsBox::BoundsBox()
    {
        m_left      = 0;
        m_right     = 0;
        m_top       = 0;
        m_bottom    = 0;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    BoundsBox::BoundsBox(float left, float top, float right, float bottom)
    {
        m_left      = left;
        m_right     = right;
        m_top       = top;
        m_bottom    = bottom;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    BoundsBox::BoundsBox(const Box& box)
    {
        m_left      = box.m_x;
        m_right     = (box.m_x + box.m_width);
        m_top       = box.m_y;
        m_bottom    = (box.m_y + box.m_height);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    float BoundsBox::GetX() const
    {
        return m_left;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    float BoundsBox::GetY() const
    {
        return m_top;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    float BoundsBox::GetWidth() const
    {
        return m_right - m_left;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    float BoundsBox::GetHeight() const
    {
        return m_bottom - m_top;
    }
}



