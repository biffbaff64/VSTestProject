#ifndef __GENERIC_ENTITYMANAGER_H
#define __GENERIC_ENTITYMANAGER_H

#include "Enums/GraphicID.h"

using namespace Enums;

namespace Game
{
	class GenericEntityManager
	{
	public:
		GenericEntityManager();
		GenericEntityManager(GraphicID graphicID);

		virtual void Init();
		virtual void Update();
		virtual void Create();
		virtual void Free();
		virtual void Free(GraphicID graphicID);
		virtual void Reset();

		int			m_activeCount;
		bool		m_isPlaceable;
		GraphicID	m_graphicID;
		GraphicID	m_managerID;
	};
}

#endif // __GENERIC_ENTITYMANAGER_H
