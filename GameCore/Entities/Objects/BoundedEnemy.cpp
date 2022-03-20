//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include <GDX/Physics/Direction.h>

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "../../Core/App.h"
#include "BoundedEnemy.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

namespace Game
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    BoundedEnemy::BoundedEnemy(GraphicID graphicID)
		:
		m_justTurnedAroundX(false),
		m_justTurnedAroundY(false),
		m_isVertical(false)
	{
	}

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void BoundedEnemy::Init()
	{
		m_justTurnedAroundX = false;
		m_justTurnedAroundY = false;
	}

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void BoundedEnemy::CheckMovementBounds()
	{
        if (m_direction.GetX() != DIRECTION_STILL)
        {
            m_justTurnedAroundX = false;

            if (m_direction.GetX() == DIRECTION_LEFT)
            {
                if ((m_sprite.getPosition().x < pApp->m_pMapData->m_mapBox.m_left)
                    || (m_sprite.getPosition().x <= m_movementBounds.m_left))
                {
                    m_justTurnedAroundX = true;
                }
            }
            else if (m_direction.GetX() == DIRECTION_RIGHT)
            {
                if ((m_sprite.getPosition().x > pApp->m_pMapData->m_mapBox.m_right)
                    || (m_sprite.getPosition().x >= m_movementBounds.m_right))
                {
                    m_justTurnedAroundX = true;
                }
            }

            if (m_justTurnedAroundX)
            {
                OnMovementBoundsTurn(m_direction.GetX());

                m_direction.ToggleX();
            }
        }

        if (m_direction.GetY() != DIRECTION_STILL)
        {
            m_justTurnedAroundY = false;

            if (m_direction.GetY() == DIRECTION_UP)
            {
                if ((m_sprite.getPosition().y < pApp->m_pMapData->m_mapBox.m_top)
                    || (m_sprite.getPosition().y >= m_movementBounds.m_top))
                {
                    m_justTurnedAroundY = true;
                }
            }
            else if (m_direction.GetY() == DIRECTION_DOWN)
            {
                if ((m_sprite.getPosition().y >= pApp->m_pMapData->m_mapBox.m_bottom)
                    || (m_sprite.getPosition().y <= m_movementBounds.m_bottom))
                {
                    m_justTurnedAroundY = true;
                }
            }

            if (m_justTurnedAroundY)
            {
                OnMovementBoundsTurn(m_direction.GetY());

                m_direction.ToggleY();
            }
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void BoundedEnemy::OnMovementBoundsTurn(int edgeSide)
	{
	}

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void BoundedEnemy::SetHorizontalMovementBounds()
	{
        if (m_direction.GetX() == DIRECTION_LEFT)
        {
            m_movementBounds = BoundsBox
            (
                // left
                (m_sprite.getPosition().x - m_distance.m_x),
                // top
                m_sprite.getPosition().y,
                // right
                m_sprite.getPosition().x,
                // bottom
                (m_sprite.getPosition().y + m_frameHeight)
            );
        }
        else if (m_direction.GetX() == DIRECTION_RIGHT)
        {
            m_movementBounds = BoundsBox
            (
                // left
                m_sprite.getPosition().x,
                // top
                m_sprite.getPosition().y,
                // right
                (m_sprite.getPosition().x + m_distance.m_x),
                // bottom
                (m_sprite.getPosition().y + m_frameHeight)
            );
        }

        m_isVertical = (m_direction.GetX() == DIRECTION_STILL);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void BoundedEnemy::SetVerticalMovementBounds()
	{
        if (m_direction.GetY() == DIRECTION_UP)
        {
            m_movementBounds = BoundsBox
            (
                // left
                m_sprite.getPosition().x,
                // top
                (m_sprite.getPosition().y - m_distance.m_y),
                // right
                (m_sprite.getPosition().x + m_frameWidth),
                // bottom
                m_sprite.getPosition().y
            );
        }
        else if (m_direction.GetY() == DIRECTION_DOWN)
        {
            m_movementBounds = BoundsBox
            (
                // left
                m_sprite.getPosition().x,
                // top
                m_sprite.getPosition().y,
                // right
                (m_sprite.getPosition().x + m_frameWidth),
                // bottom
                (m_sprite.getPosition().y + m_distance.m_y)
            );
        }

        m_isVertical = (m_direction.GetY() != DIRECTION_STILL);
    }
}

