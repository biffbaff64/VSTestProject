#include "CollisionObject.h"

using namespace Enums;

namespace Game
{
	CollisionObject::CollisionObject()
	    :
		m_contactEntity(),
		m_parentEntity(),
	    m_actionState(Enums::ActionStates::NoAction),
	    m_gid(GraphicID::NoID),
	    m_type(GraphicID::NoID),
	    m_invisibilityDelay(0),
	    m_isInvisibilityAllowed(false),
	    m_contactMask(0),
	    m_index(0)
	{
	}

	CollisionObject::~CollisionObject()
	{
		delete m_contactEntity;
		delete m_parentEntity;
	}

	void CollisionObject::CheckInvisibility()
	{
        if ((m_actionState != ActionStates::Collidable) && m_isInvisibilityAllowed)
        {
			if (m_invisibilityTimer.getElapsedTime().asMilliseconds() >= m_invisibilityDelay)
            {
				m_actionState = ActionStates::Collidable;
            }
        }
	}

	void CollisionObject::SetInvisibility(int timeInMilliseconds)
	{
		m_actionState = Enums::ActionStates::Invisible;
		m_invisibilityDelay = timeInMilliseconds;
	}

	void CollisionObject::ClearCollision()
	{
		if (m_actionState != ActionStates::Dead)
		{
			m_actionState = ActionStates::Collidable;

			m_contactEntity	= nullptr;
			m_contactMask	= 0;
		}
	}
	
	void CollisionObject::Kill()
	{
		m_actionState = ActionStates::Dead;
	}
}




