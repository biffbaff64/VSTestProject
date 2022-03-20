#ifndef __DECORATIONS_MANAGER_H
#define __DECORATIONS_MANAGER_H

#include "../Characters/Decoration.h"
#include "GenericEntityManager.h"

namespace Game
{
	class DecorationsManager : public GenericEntityManager
	{
	public:
		DecorationsManager();
		virtual ~DecorationsManager() = default;

		void Init() override;
		void Create() override;

	private:
		[[nodiscard]] std::string CheckAssetName(const SpriteDescriptor& descriptor);

		int m_maxActiveCount;

		Decoration m_decoration;
	};
}

#endif __DECORATIONS_MANAGER_H
