#ifndef SFMLTEST_STAROBJECT_H
#define SFMLTEST_STAROBJECT_H

#include "SFML/Graphics.hpp"
#include "GDX/Maths/Vec3.h"

using namespace sf;
using namespace GDX;

namespace Game
{
#define INITIAL_DEPTH           100.0f
#define FINAL_DEPTH             1000.0f
#define MINIMUM_VELOCITY        0.5f
#define MAXIMUM_VELOCITY        5.0f
#define MAXIMUM_STAR_RADIUS     8.0f

    class StarObject
    {
    public:
        StarObject() = default;
        StarObject(const Texture& texture);

        void Update(float speed);
        void Render(float speed);

    private:
        void ResetPosition();
        void MoveStar(float x, float y, float z);

        Vec3<float> m_position;
        Vec3<float> m_velocity;
        Sprite      m_sprite;
    };
}

#endif // SFMLTEST_STAROBJECT_H
