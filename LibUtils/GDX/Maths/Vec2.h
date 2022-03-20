#ifndef __VEC2_H
#define __VEC2_H

namespace GDX
{
    template<typename T>
    class Vec2
    {
    public:
        T m_x;
        T m_y;

        Vec2();
        Vec2(T x, T y);
        ~Vec2() = default;
    };

    template<typename T>
    Vec2<T>::Vec2()
    {
        m_x = 0;
        m_y = 0;
    }

    template<typename T>
    Vec2<T>::Vec2(T x, T y)
    {
        m_x = x;
        m_y = y;
    }

    typedef Vec2<float> Vec2F;
    typedef Vec2<int>   Vec2Int;
}

#endif // __VEC2_H

