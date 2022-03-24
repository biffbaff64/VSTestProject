#ifndef SFMLTEST_ROOMMANAGER_H
#define SFMLTEST_ROOMMANAGER_H

#include <vector>

#include <GDX/Maths/SimpleVec2.h>

#include "Room.h"
#include "Room_Defines.h"

using namespace GDX;

namespace Game
{
    constexpr auto WORLD_WIDTH             = 8;
    constexpr auto WORLD_HEIGHT            = 12;
    constexpr auto DEFAULT_START_ROW       = 1;
    constexpr auto DEFAULT_START_COLUMN    = 1;

    class RoomManager
    {
    public:
        RoomManager();
        virtual ~RoomManager() = default;

        void Initialise();
        void ExitNorth();
        void ExitSouth();
        void ExitWest();
        void ExitEast();

        [[nodiscard]] const char* GetCurrentMapNameWithPath();
        [[nodiscard]] const char* GetMapNameWithPath(const char * mapName);
        [[nodiscard]] bool HasExitAt(int pos);
        [[nodiscard]] SimpleVec2 GetStartPosition();

        bool    m_taskOffered;
        Room    m_activeRoom;

    private:
        [[nodiscard]] SimpleVec2 FindRoom(const char * roomName);

        void SetRoom(const SimpleVec2& coords);
        void SetRoomNumbers();
        void CreateEntryPointsList();

        char m_tempMapName[256] = { '\0' };
    };
}

#endif // SFMLTEST_ROOMMANAGER_H
