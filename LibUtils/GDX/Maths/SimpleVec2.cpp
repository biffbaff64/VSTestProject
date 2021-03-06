#include "SimpleVec2.h"

namespace GDX
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    SimpleVec2::SimpleVec2() : SimpleVec2(0, 0)
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    SimpleVec2::SimpleVec2(int x, int y)
    {
        m_x = x;
        m_y = y;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    SimpleVec2::SimpleVec2(SimpleVec2 const& vec2)
    {
        m_x = vec2.m_x;
        m_y = vec2.m_y;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SimpleVec2::Add(int x, int y)
    {
        m_x += x;
        m_y += y;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SimpleVec2::AddX(int x)
    {
        m_x += x;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SimpleVec2::AddY(int y)
    {
        m_y += y;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SimpleVec2::Sub(int x, int y)
    {
        m_x -= x;
        m_y -= y;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SimpleVec2::SubX(int x)
    {
        m_x -= x;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SimpleVec2::SubY(int y)
    {
        m_y -= y;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SimpleVec2::Set(int x, int y)
    {
        m_x = x;
        m_y = y;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SimpleVec2::Set(const SimpleVec2 &vec2)
    {
        m_x = vec2.m_x;
        m_y = vec2.m_y;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SimpleVec2::Mul(int x, int y)
    {
        m_x *= x;
        m_y *= y;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SimpleVec2::Mul(const SimpleVec2 &vec2)
    {
        m_x *= vec2.m_x;
        m_y *= vec2.m_y;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    bool SimpleVec2::IsEmpty() const
    {
        return ((m_x == 0) && (m_y == 0));
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SimpleVec2::SetEmpty()
    {
        m_x = 0;
        m_y = 0;
    }
}


