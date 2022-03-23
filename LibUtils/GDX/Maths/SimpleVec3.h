#ifndef __SIMPLEVEC3_H
#define __SIMPLEVEC3_H

#include "Vec3.h"

namespace GDX
{
    class SimpleVec3 : public Vec3<int>
    {
    public:
        SimpleVec3();
        SimpleVec3(int x, int y, int z);
        SimpleVec3(SimpleVec3 const &vec3);
        virtual ~SimpleVec3() = default;

        void Add(int x, int y, int z);

        inline void AddX(int x)
        {
            m_x += x;
        }

        inline void AddY(int y)
        {
            m_y += y;
        }

        inline void AddZ(int z)
        {
            m_z += z;
        }

        void Sub(int x, int y, int z);

        inline void SubX(int x)
        {
            m_x -= x;
        }

        inline void SubY(int y)
        {
            m_y -= y;
        }
        
        inline void SubZ(int z)
        {
            m_z -= z;
        }

        void Set(int x, int y, int z);
        void Set(SimpleVec3 const &vec3);

        void Mul(int x, int y, int z);
        void Mul(SimpleVec3 const &vec3);

        [[nodiscard]] bool IsEmpty() const;
        void SetEmpty();
    };
}

#endif // __SIMPLEVEC3_H

