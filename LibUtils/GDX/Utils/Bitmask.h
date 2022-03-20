#ifndef __BITMASK_H
#define __BITMASK_H

#include <cstdint>

namespace GDX
{
    class Bitmask
    {
    public:
        Bitmask();

        void SetMask(Bitmask& other);
        [[nodiscard]] uint32_t GetMask() const;

        [[nodiscard]] bool GetBit(int pos) const;
        void SetBit(int pos, bool on);

        void SetBit(int pos);
        void ClearBit(int pos);

        void Clear();

    private:
        uint32_t m_bits;
    };
}

#endif // __BITMASK_H
