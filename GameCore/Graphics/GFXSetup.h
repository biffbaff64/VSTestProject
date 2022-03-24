#ifndef __GFXSETUP_H
#define __GFXSETUP_H

#include "GameResources.h"

namespace Game
{
	class GFXSetup
	{
	public:
		GFXSetup() = default;
		virtual ~GFXSetup() = default;

		static void Init();
	};
}

#endif // __GFXSETUP_H

