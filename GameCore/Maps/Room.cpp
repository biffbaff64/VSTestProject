
#include "../Core/App.h"
#include "Room.h"

namespace Game
{
    Room::Room() : Room("")
    {
    }

    Room::Room(const char * roomName)
    {
        m_roomName                = roomName;
        m_roomNumber              = 0;
        m_mysteryChestsAvailable  = 0;
        m_row                     = 0;
        m_column                  = 0;
        m_isLocked                = false;

        m_jailkey.m_isCollected = false;
        m_jailkey.m_isUsed      = false;

        // No need to initialise m_compassPoints as this will be
        // done later on in RoomManager().
    }

    void Room::Set(const Room &room)
    {
        m_roomName                = room.m_roomName;
        m_roomNumber              = room.m_roomNumber;
        m_mysteryChestsAvailable  = room.m_mysteryChestsAvailable;
        m_row                     = room.m_row;
        m_column                  = room.m_column;
        m_isLocked                = room.m_isLocked;
        m_jailkey                 = room.m_jailkey;

        m_compassPoints[NORTH]        = room.m_compassPoints[NORTH];
        m_compassPoints[EAST]         = room.m_compassPoints[EAST];
        m_compassPoints[SOUTH]        = room.m_compassPoints[SOUTH];
        m_compassPoints[WEST]         = room.m_compassPoints[WEST];
        m_compassPoints[ROOM_START]   = room.m_compassPoints[ROOM_START];
    }

    void Room::Debug()
    {
        TraceFileFunc();

        trace->Dbg("Room Name: %s", m_roomName);
        trace->Dbg("Room Num : %d", m_roomNumber);
        trace->Dbg("NORTH: %3d, %3d", m_compassPoints[NORTH].m_x, m_compassPoints[NORTH].m_y);
        trace->Dbg("EAST : %3d, %3d", m_compassPoints[EAST].m_x, m_compassPoints[EAST].m_y);
        trace->Dbg("SOUTH: %3d, %3d", m_compassPoints[SOUTH].m_x, m_compassPoints[SOUTH].m_y);
        trace->Dbg("WEST : %3d, %3d", m_compassPoints[WEST].m_x, m_compassPoints[WEST].m_y);
        trace->Dbg("START: %3d, %3d", m_compassPoints[ROOM_START].m_x, m_compassPoints[ROOM_START].m_y);
        trace->Divider();
    }
}
