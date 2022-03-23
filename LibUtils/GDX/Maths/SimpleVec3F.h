#ifndef __SIMPLEVEC3F_H
#define __SIMPLEVEC3F_H

#include "Vec3.h"

namespace GDX
{
    class SimpleVec3F : public Vec3<float>
    {
    public:
        SimpleVec3F();
        SimpleVec3F(float x, float y, float z);
        SimpleVec3F(SimpleVec3F const &vec3);
        ~SimpleVec3F() = default;

        void Add(float x, float y, float z);
        void AddX(float x);
        void AddY(float y);
        void AddZ(float z);

        void Sub(float x, float y, float z);
        void SubX(float x);
        void SubY(float y);
        void SubZ(float z);

        void Set(float x, float y, float z);
        void Set(SimpleVec3F const &vec3);

        void Mul(float x, float y, float z);
        void Mul(SimpleVec3F const &vec3);

        [[nodiscard]] bool IsEmpty() const;
        void SetEmpty();
    };
}

#endif // __SIMPLEVEC3F_H
