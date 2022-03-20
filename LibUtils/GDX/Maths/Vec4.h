#ifndef __VEC4_H
#define __VEC4_H

namespace GDX
{
    template<typename T>
    class Vec4
    {
    public:
        T m_u;
        T m_v;
        T m_x;
        T m_y;

        Vec4();

        explicit Vec4(T u, T v, T x, T y);

        ~Vec4() = default;
    };

    template<typename T>
    Vec4<T>::Vec4()
    {
        m_u = 0;
        m_v = 0;
        m_x = 0;
        m_y = 0;
    }

    template<typename T>
    Vec4<T>::Vec4(T u, T v, T x, T y)
    {
        m_u = u;
        m_v = v;
        m_x = x;
        m_y = y;
    }

    typedef Vec4<float> Vec4F;
    typedef Vec4<int> Vec4Int;
}

#endif // __VEC4_H

