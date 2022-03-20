#ifndef __VEC3_H
#define __VEC3_H

#include <SFML/Graphics.hpp>

namespace GDX
{
    template<typename T>
    class Vec3
    {
    public:
        T m_x;
        T m_y;
        T m_z;

        Vec3();

        explicit Vec3(T x, T y, T z);

        sf::Vector2f ToVector2f();

        ~Vec3() = default;
    };

    template<typename T>
    sf::Vector2f Vec3<T>::ToVector2f()
    {
        return sf::Vector2f(m_x, m_y);
    }

    template<typename T>
    Vec3<T>::Vec3()
    {
        m_x = 0;
        m_y = 0;
        m_z = 0;
    }

    template<typename T>
    Vec3<T>::Vec3(T x, T y, T z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }

    typedef Vec3<float> Vec3F;
    typedef Vec3<int> Vec3Int;
}

#endif // __VEC3_H

