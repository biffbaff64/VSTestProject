#ifndef __DIRECTIONCOMPONENT_H
#define __DIRECTIONCOMPONENT_H

namespace GDX
{
    class DirectionComponent
    {
    public:
        DirectionComponent(int x, int y, int translated);
        virtual ~DirectionComponent() = default;

        int m_dirX;
        int m_dirY;
        int m_translated;
    };
}

#endif // __DIRECTIONCOMPONENT_H

