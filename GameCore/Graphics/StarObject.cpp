//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include <iostream>

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "GDX/Maths/NumberUtils.h"
#include "Framework.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Gfx.h"
#include "BaseRenderer.h"
#include "Core/App.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "StarObject.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

namespace Game
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    StarObject::StarObject(const sf::Texture& texture)
    {
        m_sprite = sf::Sprite(texture);

        ResetPosition();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void StarObject::Update(float speed)
    {
        if ((m_position.m_z < 0)
            || (m_position.m_z > FINAL_DEPTH)
            || (m_position.m_y < (float) -Gfx::inst().m_viewHeight) || (m_position.m_y > (float) Gfx::inst().m_viewHeight)
            || (m_position.m_x < (float) -Gfx::inst().m_viewWidth) || (m_position.m_x > (float) Gfx::inst().m_viewWidth))
        {
            ResetPosition();
        }

        MoveStar
            (
                (m_velocity.m_x * speed) * pFramework->GetDeltaTime(),
                (m_velocity.m_y * speed) * pFramework->GetDeltaTime(),
                (m_velocity.m_z * speed) * pFramework->GetDeltaTime()
            );
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void StarObject::Render(float speed)
    {
        Update(speed);

        float x = (m_position.m_x / m_position.m_z) * ((float) pApp->m_pMapData->m_tileWidth * 0.5f);
        float y = (m_position.m_y / m_position.m_z) * ((float) pApp->m_pMapData->m_tileHeight * 0.5f);

        float radius = ((MAXIMUM_STAR_RADIUS - ((m_position.m_z * MAXIMUM_STAR_RADIUS) * 0.001f)) * m_velocity.m_z) * 0.2f;

        m_sprite.setPosition(x, y);
        m_sprite.setTextureRect(sf::IntRect(0, 0, (int) radius, (int) radius));

        if (pApp->m_isDevMode)
        {
            trace->Divider();
            trace->Dbg("m_position: %f, %f, %f", m_position.m_x, m_position.m_y, m_position.m_z);
            trace->Dbg("Here: X: %f, Y: ", x, y);
        }

        pApp->m_pBaseRenderer->m_renderWindow.draw(m_sprite, pApp->m_pBaseRenderer->m_renderStates);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void StarObject::ResetPosition()
    {
        m_position.m_x = GDX::NumberUtils::Random(-Gfx::inst().m_viewWidth, Gfx::inst().m_viewWidth);
        m_position.m_y = GDX::NumberUtils::Random(-Gfx::inst().m_viewHeight, Gfx::inst().m_viewHeight);
        m_position.m_z = GDX::NumberUtils::Random(INITIAL_DEPTH, FINAL_DEPTH);
        m_velocity.m_z = GDX::NumberUtils::Random(MINIMUM_VELOCITY, MAXIMUM_VELOCITY);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void StarObject::MoveStar(float x, float y, float z)
    {
        m_position.m_x -= x;
        m_position.m_y -= y;
        m_position.m_z -= z;
    }
}


