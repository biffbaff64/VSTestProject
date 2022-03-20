#ifndef __STATS_H
#define __STATS_H

namespace GDX
{
	enum Meters
	{
		_ILLEGAL_GAME_MODE						= 0,
		_SOUND_LOAD_FAIL						= 1,
		_BAD_PLAYER_ACTION						= 2,
		_FONT_LOAD_FAILURE						= 3,
		_BORDERED_FONT_LOAD_FAILURE				= 4,

		_IO_EXCEPTION							= 5,    // System Log Counter 1
		_INDEX_OUT_OF_BOUNDS_EXCEPTION			= 6,    // System Log Counter 2
		_ARRAY_INDEX_OUT_OF_BOUNDS_EXCEPTION	= 7,    // System Log Counter 3
		_SAX_EXCEPTION							= 8,    // System Log Counter 4
		_INTERRUPTED_EXCEPTION					= 9,    // System Log Counter 5
		_NULL_POINTER_EXCEPTION					= 10,   // System Log Counter 6
		_ILLEGAL_STATE_EXCEPTION				= 11,   // System Log Counter 7
		_GDX_RUNTIME_EXCEPTION					= 12,   // System Log Counter 8

		_UNKNOWN_EXCEPTION						= 13,   // System Log Counter 9
		_DUMMY_METER							= 14,   // System Log Counter 10

		//
		// Add any new meters here
		//
		_ENTITY_DATA_EXCEPTION					= 15,   // System Log Counter 11

		_MAX_STATS_METERS						= 16
	};

	class Stats
	{
	public:
		Stats();
		~Stats();

		virtual void Setup();

		template<typename T>
		void AddMeter(Meters meter, T value);
		
		template<typename T>
		void SetMeter(Meters meter, T value);

		void DecMeter(Meters meter);
		void IncMeter(Meters meter);
	};
}

#endif // __STATS_H

