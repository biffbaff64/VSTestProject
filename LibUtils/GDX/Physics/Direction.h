#ifndef __DIRECTION_H
#define __DIRECTION_H

#include <string>
#include "Movement.h"

namespace GDX
{
    class Direction
    {
    public:
        Direction();
        Direction(int x, int y);
        Direction(Direction const &direction);

        void Set(const Direction &direction);
        void Set(int x, int y);
        void SetX(int x);
        void SetY(int y);
        void StandStill();
        void Toggle();
        void ToggleX();
        void ToggleY();

        [[nodiscard]] bool HasDirection() const;
        [[nodiscard]] int GetX() const;
        [[nodiscard]] int GetY() const;
        [[nodiscard]] int GetFlippedX() const;
        [[nodiscard]] int GetFlippedY() const;

    private:
        int m_x;
        int m_y;
    };
}

#endif // __DIRECTION_H

