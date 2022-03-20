#include "SimpleVec2F.h"

namespace GDX
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    SimpleVec2F::SimpleVec2F() : SimpleVec2F(0, 0)
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    SimpleVec2F::SimpleVec2F(float x, float y)
    {
        m_x = x;
        m_y = y;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    SimpleVec2F::SimpleVec2F(SimpleVec2F const& vec2)
    {
        m_x = vec2.m_x;
        m_y = vec2.m_y;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SimpleVec2F::Add(float x, float y)
    {
        m_x += x;
        m_y += y;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SimpleVec2F::AddX(float x)
    {
        m_x += x;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SimpleVec2F::AddY(float y)
    {
        m_y += y;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SimpleVec2F::Sub(float x, float y)
    {
        m_x -= x;
        m_y -= y;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SimpleVec2F::SubX(float x)
    {
        m_x -= x;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SimpleVec2F::SubY(float y)
    {
        m_y -= y;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SimpleVec2F::Set(float x, float y)
    {
        m_x = x;
        m_y = y;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SimpleVec2F::Set(const SimpleVec2F &vec2)
    {
        m_x = vec2.m_x;
        m_y = vec2.m_y;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SimpleVec2F::Mul(float x, float y)
    {
        m_x *= x;
        m_y *= y;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SimpleVec2F::Mul(const SimpleVec2F &vec2)
    {
        m_x *= vec2.m_x;
        m_y *= vec2.m_y;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    bool SimpleVec2F::IsEmpty() const
    {
        return ((m_x == 0) && (m_y == 0));
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void SimpleVec2F::SetEmpty()
    {
        m_x = 0;
        m_y = 0;
    }
}


