#ifndef __COLLISIONOBJECT_H
#define __COLLISIONOBJECT_H

#include <SFML/Graphics.hpp>

#include <ActionStates.h>
#include <GraphicID.h>

#include <GDX/Maths/Box.h>

namespace Game 
{
    class CollisionObject
    {
    public:
        CollisionObject();
        virtual ~CollisionObject();

        void CheckInvisibility();
        void SetInvisibility(int timeInMilliseconds);
        void ClearCollision();
        void Kill();

        void*               m_contactEntity;
        void*               m_parentEntity;
        GDX::Box            m_rectangle;
        Enums::ActionStates m_actionState;
        Enums::GraphicID    m_gid;
        Enums::GraphicID    m_type;

        short int   m_contactMask;
        int         m_index;

        sf::Clock   m_invisibilityTimer;
        bool        m_isInvisibilityAllowed;
        int         m_invisibilityDelay;
    };
}

#endif // __COLLISIONOBJECT_H

