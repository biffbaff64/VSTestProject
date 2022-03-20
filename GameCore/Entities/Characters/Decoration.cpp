//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Enums/ActionStates.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Graphics/BaseRenderer.h"
#include "Graphics/Gfx.h"
#include "Core/App.h"

#include "Decoration.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

namespace Game
{
	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	Decoration::Decoration(Enums::GraphicID graphicID)
		:
		GDXSprite(graphicID)
	{
		m_isMoveable = false;
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void Decoration::Initialise(SpriteDescriptor& descriptor)
	{
		Create(descriptor);

		m_bodyCategory = Gfx::CAT_DECORATION;
		m_collidesWith = Gfx::CAT_PLAYER
						| Gfx::CAT_ENEMY
						| Gfx::CAT_WEAPON
						| Gfx::CAT_OBSTACLE
						| Gfx::CAT_ENTITY_BARRIER
						| Gfx::CAT_DOOR;

		if (m_properties->m_isAnimating = (descriptor.m_frames > 1))
		{
			m_animation.SetFrameDuration(descriptor.m_anim_rate);
		}

		m_properties->m_isDrawable = true;
		m_isMoveable = ((m_gid == GraphicID::Barrel)
						|| (m_gid == GraphicID::Crate)
						|| (m_gid == GraphicID::Pot));

		m_direction.StandStill();

		SetActionState(Enums::ActionStates::Standing);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void Decoration::Update()
	{
		if (m_isMoveable)
		{
			if ((m_distance.m_x != 0) || (m_distance.m_y != 0))
			{
				m_sprite.move(sf::Vector2f(m_speed.m_x * m_direction.GetX(), m_speed.m_y * m_direction.GetY()));
				m_distance.m_x -= m_speed.m_x;
				m_distance.m_y -= m_speed.m_y;
			}
		}

		Animate();

		UpdateCommon();
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void Decoration::Draw()
	{
		if (m_properties->m_isDrawable)
		{
			pApp->m_pBaseRenderer->m_renderWindow.draw(m_sprite, pApp->m_pBaseRenderer->m_renderStates);
		}
	}
}
