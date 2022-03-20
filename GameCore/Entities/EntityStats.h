#ifndef __ENTITY_STATS_H
#define __ENTITY_STATS_H

#include "Enums/GraphicID.h"

using namespace Enums;

namespace Game
{
	class EntityStats
	{
	public:
		EntityStats() = default;
		virtual ~EntityStats() = default;

		static void Log(GraphicID graphicID);
	};
}

#endif // __ENTITY_STATS_H

