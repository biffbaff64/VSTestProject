#ifndef SFMLTEST_ROOM_H
#define SFMLTEST_ROOM_H

#include <GDX/Maths/SimpleVec2.h>
#include <GDX/Maths/Point.h>

using namespace GDX;

namespace Game
{
#define NORTH       0
#define EAST        1
#define SOUTH       2
#define WEST        3
#define ROOM_START  4
#define UNDEFINED   5

    struct JailKey
    {
        bool m_isCollected;
        bool m_isUsed;
    };

    struct CompassPoint
    {
        Point north;
        Point east;
        Point south;
        Point west;
        Point start;
    };

    class Room
    {
    public:
        Room();
        explicit Room(const char * const roomName);
        ~Room() = default;

        void Set(const Room& room);
        void Debug();

        const char *    m_roomName;
        int             m_roomNumber;
        GDX::Vec2<int>  m_compassPoints[5]; // TODO - use CompassPoint here
        int             m_row;
        int             m_column;
        int             m_mysteryChestsAvailable;
        bool            m_isLocked;
        JailKey         m_jailkey;
    };
}

#endif // SFMLTEST_ROOM_H
