#include "ItemF.h"

namespace GDX
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    ItemF::ItemF() : ItemF(0, 100, 0)
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    ItemF::ItemF(float min, float max) : ItemF(min, max, min)
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    ItemF::ItemF(float max) : ItemF(0, max, 0)
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    ItemF::ItemF(float min, float max, float tot)
    {
        m_Minimum      = min;
        m_Maximum      = max;
        m_Total        = tot;
        m_RefillAmount = m_Minimum;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void ItemF::Add(float amount)
    {
        if ((m_Total += amount) < m_Minimum)
        {
            m_Total = m_Minimum;
        }
        else
        {
            if (m_Total > m_Maximum)
            {
                m_Total = m_Minimum;
            }
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void ItemF::Add(float amount, float wrap)
    {
        if ((m_Total += amount) > wrap)
        {
            m_Total -= wrap;
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void ItemF::Sub(float amount)
    {
        if ((m_Total -= amount) < m_Minimum)
        {
            m_Total = m_Minimum;
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void ItemF::Sub(float amount, float wrap)
    {
        if ((m_Total -= amount) < m_Minimum)
        {
            m_Total = wrap;
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void ItemF::SetToMinimum()
    {
        m_Total = m_Minimum;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void ItemF::SetToMaximum()
    {
        m_Total = m_Maximum;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void ItemF::SetMinMax(float min, float max)
    {
        m_Minimum = min;
        m_Maximum = max;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void ItemF::Refill(float amount)
    {
        if (amount == 0)
        {
            m_Total = m_RefillAmount;
        }
        else
        {
            m_Total = amount;
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    bool ItemF::IsFull() const
    {
        return m_Total >= m_Maximum;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    bool ItemF::IsEmpty() const
    {
        return m_Total <= m_Minimum;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    bool ItemF::IsOverflowing() const
    {
        return m_Total > m_Maximum;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    bool ItemF::IsUnderFlowing() const
    {
        return m_Total < m_Minimum;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    float ItemF::GetRoom() const
    {
        return m_Maximum - m_Total;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void ItemF::BoostMax(float boost)
    {
        m_Maximum += boost;
    }
}


