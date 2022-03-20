#ifndef SFMLTEST_MAPUTILS_H
#define SFMLTEST_MAPUTILS_H

#include <GDX/Maths/SimpleVec2.h>
#include <GDX/Physics/Direction.h>

namespace Game
{
    #define DEMO_SCROLL_XSPEED  4
    #define DEMO_SCROLL_YSPEED  4

    class MapUtils
    {
    public:
        MapUtils();

        void PositionAt(int x, int y);
        void DemoScroll();

    private:
        GDX::Direction m_direction;
    };
}

#endif // SFMLTEST_MAPUTILS_H
