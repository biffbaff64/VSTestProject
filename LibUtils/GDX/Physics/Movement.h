#ifndef __MOVEMENT_H
#define __MOVEMENT_H

#include "Direction.h"

namespace GDX
{
    #define STILL      0
    #define UP         1
    #define DOWN       2
    #define LEFT       3
    #define RIGHT      4
    #define UP_LEFT    5
    #define UP_RIGHT   6
    #define DOWN_LEFT  7
    #define DOWN_RIGHT 8

    #define HORIZONTAL       1
    #define VERTICAL         2
    #define DIRECTION_IN     1
    #define DIRECTION_OUT    -1
    #define FORWARDS         1
    #define BACKWARDS        -1
    #define DIRECTION_RIGHT  1
    #define DIRECTION_LEFT   -1
    #define DIRECTION_UP     -1
    #define DIRECTION_DOWN   1
    #define DIRECTION_STILL  0
    #define DIRECTION_CUSTOM 2

    class Movement
    {
    public:
        Movement() = default;
        virtual ~Movement() = default;

        [[nodiscard]] const char *GetAliasX(int value) const;
        [[nodiscard]] const char *GetAliasY(int value) const;
    };
}

#endif // __MOVEMENT_H

