#ifndef __SIMPLEVEC2F_H
#define __SIMPLEVEC2F_H

#include "Vec2.h"

namespace GDX
{
    class SimpleVec2F : public Vec2<float>
    {
    public:
        SimpleVec2F();
        SimpleVec2F(float x, float y);
        SimpleVec2F(SimpleVec2F const &vec2);
        ~SimpleVec2F() = default;

        void Add(float x, float y);
        void AddX(float x);
        void AddY(float y);

        void Sub(float x, float y);
        void SubX(float x);
        void SubY(float y);

        void Set(float x, float y);
        void Set(SimpleVec2F const &vec2);

        void Mul(float x, float y);
        void Mul(SimpleVec2F const &vec2);

        [[nodiscard]] bool IsEmpty() const;
        void SetEmpty();
    };
}

#endif // __SIMPLEVEC2F_H
