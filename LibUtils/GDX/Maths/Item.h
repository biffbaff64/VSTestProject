#ifndef __ITEM_H
#define __ITEM_H

#include <algorithm>

namespace GDX
{
    class Item
    {
    public:
        Item();
        Item(int min, int max);
        explicit Item(int max);
        Item(int min, int max, int tot);

        ~Item() = default;

        void Add(int amount);
        void Add(int amount, int wrap);

        void Sub(int amount);
        void Sub(int amount, int wrap);

        void SetToMinimum();
        void SetToMaximum();
        void Refill(int amount);
        void BoostMax(int boost);

        [[nodiscard]] bool IsFull() const;
        [[nodiscard]] bool IsEmpty() const;
        [[nodiscard]] bool IsOverflowing() const;
        [[nodiscard]] bool IsUnderFlowing() const;
        [[nodiscard]] int GetRoom() const;

        int m_Minimum;
        int m_Maximum;
        int m_Total;
        int m_RefillAmount;
    };
}

#endif // __ITEM_H

