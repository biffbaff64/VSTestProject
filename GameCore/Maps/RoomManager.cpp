#include <string>

#include "GDX/Maths/Vec2.h"
#include "GDX/Maths/Point.h"
#include "TMX/Map.hpp"

#include "RoomManager.h"
#include "Core/App.h"

using namespace GDX;
using namespace Game;

#pragma region room_data_tables
Room roomMap[WORLD_HEIGHT][WORLD_WIDTH] =
{
	// DO NOT CHANGE THIS LINE
	// -----------------------------------------
	{Room(), Room(), Room(), Room(), Room(), Room(), Room(), Room()},
	// -----------------------------------------
	// 0     1                   2                  3                  4                  5                  6                  7
	{Room(), Room(ROOM_S2),      Room(),            Room(),            Room(),            Room(),            Room(PRISON_S),    Room()},  // 1
	{Room(), Room(ROOM1_NS),     Room(SECRET1),     Room(ROOM4_ES),    Room(ROOM_W1),     Room(ROOM_S),      Room(ROOM_SN),     Room()},  // 2
	{Room(), Room(PASSAGE_NES),  Room(ROOM_NESW2),  Room(ROOM_NESW),   Room(ROOM6_ESW),   Room(ROOM11_NESW), Room(ROOM10_NSW),  Room()},  // 3
	{Room(), Room(ROOM2_NES),    Room(ROOM3_NEW),   Room(ROOM9_NESW),  Room(MAZE_NW),     Room(ROOM7_NS),    Room(PASSAGE_NS),  Room()},  // 4
	{Room(), Room(ROOM_N1),      Room(ROOM_E1),     Room(ROOM5_NE),    Room(),            Room(ROOM_NES),    Room(ROOM_NW),     Room()},  // 5
	{Room(), Room(PASSAGE_ES),   Room(ROOM_WS),     Room(),            Room(),            Room(ROOM12_NS),   Room(),            Room()},  // 6
	{Room(), Room(ROOM14_NS),    Room(PASSAGE_NE),  Room(PASSAGE_ESW), Room(ROOM13_ESW),  Room(ROOM_NWS),    Room(PASSAGE_S),   Room()},  // 7
	{Room(), Room(ROOM17_N),     Room(ROOM_N2),     Room(ROOM18_NS),   Room(ROOM2_NS),    Room(ROOM15_NE),   Room(ROOM16_NW),   Room()},  // 8
	{Room(), Room(),                        Room(),            Room(ROOM_N3),     Room(PRISON_N),    Room(),            Room(),            Room()},  // 9
	{Room(),Room(),                        Room(),            Room(),            Room(),            Room(),            Room(),            Room()},  // 10

	// -----------------------------------------
	// DO NOT CHANGE THIS LINE
	// -----------------------------------------
	{Room(), Room(), Room(), Room(), Room(), Room(), Room(), Room()},
	// -----------------------------------------
};

CompassPoint doorPositions[] =
{
	{0,0, 0,0, 0,0, 0,0, 0,0},
	// ---------------------------
	// NORTH            EAST                SOUTH             WEST            START
	{  0,   0,  /**/   147,  44,  /**/    74, 104,  /**/     0,   0,  /**/   103,  60},		// [ 1] room_s2
	{ 99,   6,  /**/     0,   0,  /**/    41, 109,  /**/     0,   0,  /**/   105,  41},		// [ 2] room1_ns
	{ 22,   7,  /**/    78,  66,  /**/    31,  93,  /**/     0,   0,  /**/    22,  12},		// [ 3] passage_nes
	{ 76,   6,  /**/    93,  66,  /**/    63, 125,  /**/     0,   0,  /**/    63, 110},		// [ 4] room2_nes
	{ 48,   7,  /**/     0,   0,  /**/     0,   0,  /**/     0,   0,  /**/    48,  18},		// [ 5] room_n
	{  0,   0,  /**/    94,  12,  /**/    72,  98,  /**/     0,   0,  /**/    75,  50},		// [ 6] passage_es
	{ 43,   6,  /**/     0,   0,  /**/    51, 116,  /**/     0,   0,  /**/    51, 107},		// [ 7] room14_ns
	{ 93,   6,  /**/     0,   0,  /**/     0,   0,  /**/     0,   0,  /**/    93,  14},		// [ 8] room17_n
	{  0,   0,  /**/     0,   0,  /**/    16, 118,  /**/     0,   0,  /**/    16, 101},		// [ 9] room_secret1
	{ 37,   5,  /**/    87,  25,  /**/    35,  69,  /**/     0,  25,  /**/    74,  25},		// [10] room_nesw2
	{ 68,   4,  /**/   113,  22,  /**/     0,   0,  /**/     0,  69,  /**/    68,  13},		// [11] room3_new
	{  0,   0,  /**/    91,  62,  /**/     0,   0,  /**/     0,   0,  /**/    81,  62},		// [12] room_e
	{  0,   0,  /**/     0,   0,  /**/    35,  53,  /**/     0,  20,  /**/     9,  21},		// [13] room_ws
	{ 47,   7,  /**/    88,  31,  /**/    65,  68,  /**/     0,   0,  /**/    79,  30},		// [14] passage_ne
	{ 46,   7,  /**/     0,   0,  /**/     0,   0,  /**/     0,   0,  /**/    46,  18},		// [15] room_n2
	{  0,   0,  /**/   159,  22,  /**/    88, 165,  /**/     0,   0,  /**/   144,  22},		// [16] room4_es
	{ 48,   7,  /**/    87,  38,  /**/    37,  71,  /**/     0,  39,  /**/    77,  38},		// [17] room_nesw
	{ 83,   4,  /**/   166,  84,  /**/    83, 167,  /**/     0,  84,  /**/   152,  84},		// [18] room9_nesw
	{ 79,   6,  /**/     0,   0,  /**/     0,   0,  /**/     0,  51,  /**/    11,  51},		// [19] room5_ne
	{  0,   0,  /**/   148,  49,  /**/    93,  73,  /**/     1,  45,  /**/    11,  43},		// [20] passage_esw
	{128,   5,  /**/     0,   0,  /**/   128, 149,  /**/     0,   0,  /**/    51,  94},		// [21] room18_ns
	{ 48,   4,  /**/     0,   0,  /**/     0,   0,  /**/     0,   0,  /**/    74,  36},		// [22] room_n3
	{  0,   0,  /**/     0,   0,  /**/     0,   0,  /**/     0,  53,  /**/    13,  52},		// [23] room_w
	{  0,   0,  /**/   183,  44,  /**/    37, 158,  /**/     0,  94,  /**/   172,  44},		// [24] room6_esw
	{  0,   0,  /**/     0,   0,  /**/     0,   0,  /**/     0,   0,  /**/     0,   0},		// [25] maze1_nw
	{  0,   0,  /**/   158,  69,  /**/    56, 149,  /**/     0, 105,  /**/   124, 108},		// [26] room13_esw
	{114,   7,  /**/     0,   0,  /**/    52, 116,  /**/     0,   0,  /**/   114,  19},		// [27] room2_ns
	{ 41,   6,  /**/     0,   0,  /**/     0,   0,  /**/     0,   0,  /**/    40,  16},		// [28] prison_room_n
	{  0,   0,  /**/     0,   0,  /**/    46,  89,  /**/     0,   0,  /**/    46,  80},		// [29] room_s
	{ 26,   6,  /**/   198,  13,  /**/    76, 120,  /**/     0,  30,  /**/    76, 105},		// [30] room11_nesw
	{204,   4,  /**/     0,   0,  /**/    41, 124,  /**/     0,   0,  /**/    42,  99},		// [31] room7_ns
	{ 46,   5,  /**/    82,  33,  /**/    36,  89,  /**/     0,   0,  /**/    70,  32},		// [32] room_nes
	{ 15,   6,  /**/     0,   0,  /**/    31, 150,  /**/     0,   0,  /**/    31, 141},		// [33] room12_ns
	{ 47,   8,  /**/     0,   0,  /**/    36,  71,  /**/     0,  37,  /**/    47,  13},		// [34] room_nws
	{ 37,   5,  /**/   151,  51,  /**/     0,   0,  /**/     0,   0,  /**/   142,  51},		// [35] room15_ne
	{  0,   0,  /**/     0,   0,  /**/    38,  71,  /**/     0,   0,  /**/    38,  57},		// [36] prison_room_s
	{ 59,   6,  /**/     0,   0,  /**/    20,  89,  /**/     0,   0,  /**/    20,  78},		// [37] room_sn
	{132,   6,  /**/     0,   0,  /**/   129, 124,  /**/     0,  69,  /**/     0,   0},		// [38] room10_nsw
	{ 43,   5,  /**/     0,   0,  /**/    13, 149,  /**/     0,   0,  /**/    41,  13},		// [39] passage_ns
	{ 13,   7,  /**/     0,   0,  /**/     0,   0,  /**/     0,  56,  /**/    14,  14},		// [40] room_nw2
	{  0,   0,  /**/     0,   0,  /**/    32, 149,  /**/     0,   0,  /**/     0,   0},		// [41] passage_s
	{  7,   8,  /**/     0,   0,  /**/     0,   0,  /**/     1,  70,  /**/     7,  17},		// [42] room16_nw
};
#pragma endregion room_data_tables

namespace Game
{
	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	RoomManager::RoomManager()
	{
		m_taskOffered = false;
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void RoomManager::Initialise()
	{
		TraceFileFunc();

		SetRoomNumbers();
		CreateEntryPointsList();

		SimpleVec2 roomPos = FindRoom(ROOM_S2);

		trace->Dbg("roomPos: Row %d, Column %d", roomPos.m_x, roomPos.m_y);

		SetRoom(roomPos);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void RoomManager::SetRoom(const SimpleVec2& coords)
	{
		if (roomMap[coords.m_x][coords.m_y].m_roomName != nullptr)
		{
			m_activeRoom.Set(roomMap[coords.m_x][coords.m_y]);

			m_activeRoom.m_row = coords.m_x;
			m_activeRoom.m_column = coords.m_y;
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void RoomManager::SetRoomNumbers()
	{
		int room_number = 1;

		for (int column = 0; column < WORLD_WIDTH; column++)
		{
			for (auto & row : roomMap)
			{
				if (!row[column].m_isLocked)
				{
					row[column].m_roomNumber = room_number++;
				}
			}
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	SimpleVec2 RoomManager::FindRoom(const char* roomName)
	{
		TraceFileFunc();
		trace->Dbg("Searching for room: %s", roomName);

		SimpleVec2 roomPosition;

		for (int row = 0; row < WORLD_HEIGHT && roomPosition.IsEmpty(); row++)
		{
			for (int column = 0; column < WORLD_WIDTH && roomPosition.IsEmpty(); column++)
			{
				if (roomMap[row][column].m_roomName != nullptr)
				{
					if (roomName == roomMap[row][column].m_roomName)
					{
						roomPosition.m_x = row;
						roomPosition.m_y = column;
					}
				}
			}
		}

		return roomPosition;
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	bool RoomManager::HasExitAt(int pos)
	{
		bool exitFound;

		switch (pos)
		{
			case NORTH:
			case EAST:
			case SOUTH:
			case WEST:
			{
				exitFound = !((m_activeRoom.m_compassPoints[pos].m_x == 0)
					&& (m_activeRoom.m_compassPoints[pos].m_y == 0));
			}
			break;

			case UNDEFINED:
			default:
			{
				exitFound = false;
			}
			break;
		}

		return exitFound;
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	const char* RoomManager::GetCurrentMapNameWithPath()
	{
		return GetMapNameWithPath(roomMap[m_activeRoom.m_row][m_activeRoom.m_column].m_roomName);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	const char* RoomManager::GetMapNameWithPath(const char* mapName)
	{
		sprintf_s(m_tempMapName, "%s%s", "Assets/Maps/", mapName);

		return m_tempMapName;
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	SimpleVec2 RoomManager::GetStartPosition()
	{
		const char* currentMap = roomMap[m_activeRoom.m_row][m_activeRoom.m_column].m_roomName;
		SimpleVec2 positions;

		bool isDone = false;

		for (int row = 0; row < WORLD_HEIGHT && !isDone; row++)
		{
			for (int column = 0; column < WORLD_WIDTH && !isDone; column++)
			{
				if (roomMap[row][column].m_roomName != nullptr)
				{
					if (currentMap == roomMap[row][column].m_roomName)
					{
						positions.Set
						(
							roomMap[row][column].m_compassPoints[ROOM_START].m_x,
							roomMap[row][column].m_compassPoints[ROOM_START].m_y
						);

						isDone = true;
					}
				}
			}
		}

		return positions;
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void RoomManager::CreateEntryPointsList()
	{
		TraceFileFunc();

		for (auto & row : roomMap)
		{
			for (auto & column : row)
			{
				int index = column.m_roomNumber;

				if (index > 0)
				{
					// ----------------------------
					column.m_compassPoints[NORTH].m_x			= doorPositions[index].north.x;
					column.m_compassPoints[NORTH].m_y			= doorPositions[index].north.y;
					// ----------------------------
					column.m_compassPoints[EAST].m_x			= doorPositions[index].east.x;
					column.m_compassPoints[EAST].m_y			= doorPositions[index].east.y;
					// ----------------------------
					column.m_compassPoints[SOUTH].m_x			= doorPositions[index].south.x;
					column.m_compassPoints[SOUTH].m_y			= doorPositions[index].south.y;
					// ----------------------------
					column.m_compassPoints[WEST].m_x			= doorPositions[index].west.x;
					column.m_compassPoints[WEST].m_y			= doorPositions[index].west.y;
					// ----------------------------
					column.m_compassPoints[ROOM_START].m_x	= doorPositions[index].start.x;
					column.m_compassPoints[ROOM_START].m_y	= doorPositions[index].start.y;
				}
			}
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void RoomManager::ExitNorth()
	{
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void RoomManager::ExitSouth()
	{
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void RoomManager::ExitWest()
	{
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void RoomManager::ExitEast()
	{
	}
}