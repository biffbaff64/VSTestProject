#ifndef __COLLISIONLISTENER_H
#define __COLLISIONLISTENER_H

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Physics/CollisionObject.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

namespace Game
{
    class CollisionObject;

    class CollisionListener
    {
    public:
        CollisionListener() = default;
        virtual ~CollisionListener() = default;

        virtual void OnPositiveCollision(CollisionObject* cobjHitting) = 0;
        virtual void OnNegativeCollision() = 0;
    };
}

#endif // __COLLISIONLISTENER_H
