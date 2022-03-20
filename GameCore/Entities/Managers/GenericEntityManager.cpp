//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include <algorithm>

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include <GDX/Utils/Trace.h>
#include "GenericEntityManager.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

namespace Game
{
	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	GenericEntityManager::GenericEntityManager()
		:
		m_activeCount(0),
		m_isPlaceable(false),
		m_graphicID(GraphicID::NoID),
		m_managerID(GraphicID::NoID)
	{
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	GenericEntityManager::GenericEntityManager(GraphicID graphicID)
		:
		m_activeCount(0),
		m_isPlaceable(false),
		m_graphicID(graphicID),
		m_managerID(graphicID)
	{
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void GenericEntityManager::Init()
	{
		m_activeCount = 0;
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void GenericEntityManager::Update()
	{
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void GenericEntityManager::Create()
	{
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void GenericEntityManager::Free()
	{
		m_activeCount = std::max(0, m_activeCount-1);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void GenericEntityManager::Free(GraphicID graphicID)
	{
		if (m_graphicID == graphicID)
		{
			Free();
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void GenericEntityManager::Reset()
	{
		m_activeCount = 0;
		m_isPlaceable = false;
	}
}
