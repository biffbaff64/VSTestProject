#ifndef SFMLTEST_GENERICCOLLISIONLISTENER_H
#define SFMLTEST_GENERICCOLLISIONLISTENER_H

#include "CollisionObject.h"

#include "../Entities/Components/CollisionListener.h"

namespace Game
{
	class GenericCollisionListener : CollisionListener
	{
	public:
		GenericCollisionListener() = default;
		virtual ~GenericCollisionListener() = default;

		void OnPositiveCollision(CollisionObject* cobjHitting) override;
		void OnNegativeCollision() override;
	};
}

#endif //SFMLTEST_GENERICCOLLISIONLISTENER_H
