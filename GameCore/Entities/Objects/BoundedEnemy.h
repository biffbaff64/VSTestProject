#ifndef __BOUNDEDENEMY_H
#define __BOUNDEDENEMY_H

#include "GDX/Maths/BoundsBox.h"
#include "Enums/GraphicID.h"

#include "GdxSprite.h"

using namespace Enums;
using namespace GDX;

namespace Game
{
	class BoundedEnemy : public GDXSprite
	{
    public:
        BoundedEnemy(GraphicID graphicID);
        virtual ~BoundedEnemy() = default;

        virtual void Init();
        virtual void CheckMovementBounds();
        virtual void OnMovementBoundsTurn(int edgeSide);
        virtual void SetHorizontalMovementBounds();
        virtual void SetVerticalMovementBounds();

        BoundsBox   m_movementBounds;
        bool        m_isVertical;
        bool        m_justTurnedAroundX;
        bool        m_justTurnedAroundY;
    };
}

#endif // __BOUNDEDENEMY_H
