#ifndef __ITEMF_H
#define __ITEMF_H

#include <algorithm>

namespace GDX
{
    class ItemF
    {
    public:
        ItemF();
        ItemF(float min, float max);
        explicit ItemF(float max);
        ItemF(float min, float max, float tot);

        ~ItemF() = default;

        void Add(float amount);
        void Add(float amount, float wrap);

        void Sub(float amount);
        void Sub(float amount, float wrap);

        void SetToMinimum();
        void SetToMaximum();
        void SetMinMax(float min, float max);
        void Refill(float amount = 0);
        void BoostMax(float boost);

        [[nodiscard]] bool IsFull() const;
        [[nodiscard]] bool IsEmpty() const;
        [[nodiscard]] bool IsOverflowing() const;
        [[nodiscard]] bool IsUnderFlowing() const;
        [[nodiscard]] float GetRoom() const;

        float m_Minimum;
        float m_Maximum;
        float m_Total;
        float m_RefillAmount;
    };
}

#endif // __ITEMF_H

