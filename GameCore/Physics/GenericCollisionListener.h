#ifndef SFMLTEST_GENERICCOLLISIONLISTENER_H
#define SFMLTEST_GENERICCOLLISIONLISTENER_H

#include "CollisionObject.h"

#include "../Entities/Components/CollisionCallback.h"

namespace Game
{
	class GenericCollisionListener : CollisionCallback
	{
	public:
		GenericCollisionListener() = default;
		virtual ~GenericCollisionListener() = default;

		void OnPositiveCollision(CollisionObject* cobjHitting) override;
		void OnNegativeCollision() override;
	};
}

#endif //SFMLTEST_GENERICCOLLISIONLISTENER_H
