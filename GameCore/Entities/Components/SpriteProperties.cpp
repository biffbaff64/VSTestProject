//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "GDX/Physics/Movement.h"
#include "SharedData/GlobalDefines.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "SpriteProperties.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

namespace Game
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    SpriteProperties::SpriteProperties()
    {
        m_link            = 0;
        m_strength        = MAX_STRENGTH;
        m_rotateSpeed     = 0;
        m_rotation        = 0;
        m_isRotating      = false;
        m_isDrawable      = false;
        m_isFlippedX      = false;
        m_isFlippedY      = false;
        m_canFlip         = false;
        m_isAnimating     = false;
        m_isLinked        = false;
        m_isMainCharacter = false;
        m_isEnemy         = false;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    SpriteProperties& SpriteProperties::operator=(const SpriteProperties& properties)
    {
        m_link              = properties.m_link;
        m_strength          = properties.m_strength;
        m_rotateSpeed       = properties.m_rotateSpeed;
        m_rotation          = properties.m_rotation;
        m_isRotating        = properties.m_isRotating;
        m_isDrawable        = properties.m_isDrawable;
        m_isFlippedX        = properties.m_isFlippedX;
        m_isFlippedY        = properties.m_isFlippedY;
        m_canFlip           = properties.m_canFlip;
        m_isAnimating       = properties.m_isAnimating;
        m_isLinked          = properties.m_isLinked;
        m_isMainCharacter   = properties.m_isMainCharacter;
        m_isEnemy           = properties.m_isEnemy;

        return *this;
    }
}

