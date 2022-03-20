#ifndef __PLAYER_MANAGER_H
#define __PLAYER_MANAGER_H

#include "../SpriteDescriptor.h"
#include "GenericEntityManager.h"

namespace Game
{
	class PlayerManager : public GenericEntityManager
	{
	public:
		PlayerManager();
		virtual ~PlayerManager() = default;

		void Init() override;
		void Create() override;
		void SetSpawnPoint();

	private:
		SpriteDescriptor m_descriptor;
	};
}

#endif // __PLAYER_MANAGER_H
