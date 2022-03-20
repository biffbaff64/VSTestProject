#ifndef __BOX_COLLISION_H
#define __BOX_COLLISION_H

#include <vector>
#include <GDX/Maths/Box.h>
#include "CollisionObject.h"

namespace Game
{
	class CollisionObject;

	class BoxCollision
	{
	public:
		BoxCollision();
		virtual ~BoxCollision() = default;
		
		void ClearContacts();
		bool CheckContact(CollisionObject *boxA);

	private:
		GDX::Box m_topRectangle;
		GDX::Box m_midRectangle;
		GDX::Box m_botRectangle;
	};
}

#endif // __BOX_COLLISION_H
