#include "Item.h"

namespace GDX
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    Item::Item() : Item(0, 100, 0)
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    Item::Item(int min, int max) : Item(min, max, min)
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    Item::Item(int max) : Item(0, max, 0)
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    Item::Item(int min, int max, int tot)
    {
        m_Minimum      = min;
        m_Maximum      = max;
        m_Total        = tot;
        m_RefillAmount = m_Minimum;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Item::Add(int amount)
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

    void Item::Add(int amount, int wrap)
    {
        if ((m_Total += amount) > wrap)
        {
            m_Total -= wrap;
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Item::Sub(int amount)
    {
        if ((m_Total -= amount) < m_Minimum)
        {
            m_Total = m_Minimum;
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Item::Sub(int amount, int wrap)
    {
        if ((m_Total -= amount) < m_Minimum)
        {
            m_Total = wrap;
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Item::SetToMinimum()
    {
        m_Total = m_Minimum;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Item::SetToMaximum()
    {
        m_Total = m_Maximum;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Item::Refill(int amount = 0)
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

    bool Item::IsFull() const
    {
        return m_Total >= m_Maximum;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    bool Item::IsEmpty() const
    {
        return m_Total <= m_Minimum;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    bool Item::IsOverflowing() const
    {
        return m_Total > m_Maximum;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    bool Item::IsUnderFlowing() const
    {
        return m_Total < m_Minimum;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    int Item::GetRoom() const
    {
        return m_Maximum - m_Total;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Item::BoostMax(int boost)
    {
        m_Maximum += boost;
    }
}


