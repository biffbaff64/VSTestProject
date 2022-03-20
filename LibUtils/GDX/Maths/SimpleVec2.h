#ifndef __SIMPLEVEC2_H
#define __SIMPLEVEC2_H

#include "Vec2.h"

namespace GDX
{
    class SimpleVec2 : public Vec2<int>
    {
    public:
        SimpleVec2();
        SimpleVec2(int x, int y);
        SimpleVec2(SimpleVec2 const &vec2);
        ~SimpleVec2() = default;

        void Add(int x, int y);
        void AddX(int x);
        void AddY(int y);

        void Sub(int x, int y);
        void SubX(int x);
        void SubY(int y);

        void Set(int x, int y);
        void Set(SimpleVec2 const &vec2);

        void Mul(int x, int y);
        void Mul(SimpleVec2 const &vec2);

        [[nodiscard]] bool IsEmpty() const;
        void SetEmpty();
    };
}

#endif // __SIMPLEVEC2_H

