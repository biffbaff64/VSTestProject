
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Enums/Translations.h"
#include "Framework.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Core/App.h"
#include "Graphics/BaseRenderer.h"
#include "Graphics/Gfx.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "MainPlayer.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

namespace Game
{
	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	MainPlayer::MainPlayer() : GDXSprite(GraphicID::Player)
	{
		m_canOfferButton		= false;
		m_canOpenMessagePanel	= false;
		m_isPossessed			= false;
		m_isOnPlatform			= false;
		m_isOnFloorButton		= false;
		m_isHurting				= false;
		m_isGrabbing			= false;
		m_isCasting				= false;
		m_isShooting			= false;
		m_isMovingX				= false;
		m_isMovingY				= false;
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void MainPlayer::Initialise(SpriteDescriptor& descriptor)
	{
		TraceFileFunc();

		Create(descriptor);

		m_bodyCategory = Gfx::CAT_PLAYER;
		m_collidesWith = Gfx::CAT_ENEMY | Gfx::CAT_ENEMY_WEAPON;

		Setup(false);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void MainPlayer::Setup(bool isSpawning)
	{
		TraceFileFunc();

		m_direction.Set(DIRECTION_STILL, DIRECTION_STILL);
		m_lookingAt.Set(m_direction);

		m_properties->m_strength	= MAX_STRENGTH;
		m_properties->m_isRotating	= false;
		m_properties->m_isFlippedX  = false;
		m_properties->m_isFlippedY  = false;
		m_properties->m_canFlip     = false;
		m_properties->m_isDrawable  = true;

		m_isPossessed		= false;
		m_isOnPlatform		= false;
		m_isOnFloorButton	= false;
		m_isHurting			= false;
		m_isGrabbing		= false;
		m_isCasting			= false;
		m_isShooting		= false;
		m_isMovingX			= false;
		m_isMovingY			= false;

		m_canOfferButton		= false;
		m_canOpenMessagePanel	= true;

		m_sprite.setRotation(0);
		m_sprite.setPosition(m_initXY.ToVector2f());
		m_collisionObject->ClearCollision();

		SetActionState(ActionStates::Spawning);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void MainPlayer::Update()
	{
		switch (m_entityAction)
		{
			case ActionStates::Dying:
			case ActionStates::Exploding:
			case ActionStates::Resetting:
			case ActionStates::Restarting:
			case ActionStates::Waiting:
			case ActionStates::Dead:
			case ActionStates::Paused:
			case ActionStates::Killed:
			case ActionStates::ChangingRoom:
			{
				// Added to prevent error messages (see default)
			}
			break;

			case ActionStates::Spawning:
			case ActionStates::Fighting:
			{
				if (m_animation.IsAnimationFinished(m_elapsedAnimTime))
				{
					SetActionState(ActionStates::Standing);
				}
			}
			break;

			case ActionStates::Standing: 
			{
				if (m_direction.HasDirection())
				{
					m_lookingAt.Set(m_direction);
				}

				// TODO: m_buttons->CheckButtons();
			}
			break;

			case ActionStates::Hurt:
			{
				// TODO:

				m_isHurting = false;

				SetActionState(ActionStates::Standing);
			}
			break;

			case ActionStates::Riding:
			case ActionStates::Running:
			{
				m_lookingAt.Set(m_direction);

				// TODO: m_buttons->CheckButtons();

				// TODO: MovePlayer();
			}
			break;

			default:
			{
				trace->Err
					(
						"WARNING: Unknown Action state for MainPlayer: %d",
						pApp->m_pEnumData->GetActionStateName((int) m_entityAction)
					);
			}
			break;
		}

		Animate();

		UpdateCommon();
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void MainPlayer::Draw()
	{
		if (m_properties->m_isDrawable)
		{
			pApp->m_pBaseRenderer->m_renderWindow.draw(m_sprite, pApp->m_pBaseRenderer->m_renderStates);
		}

		// TODO: draw overlayed items here
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void MainPlayer::SetActionState(ActionStates state)
	{
		m_entityAction = state;
	}
	
	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void MainPlayer::UpdateCollisionBox()
	{
		m_collisionObject->m_rectangle.m_x		= m_sprite.getPosition().x + (m_frameWidth / 3);
		m_collisionObject->m_rectangle.m_y		= m_sprite.getPosition().y + (m_frameHeight / 5);
		m_collisionObject->m_rectangle.m_width	= m_frameWidth / 3;
		m_collisionObject->m_rectangle.m_height	= m_frameHeight / 2;

		m_view_box.m_x      = (int) (m_sprite.getPosition().x - (VIEWBOX_WIDTH / 2));
		m_view_box.m_y      = (int) (m_sprite.getPosition().y - (VIEWBOX_HEIGHT / 2));
		m_view_box.m_width  = (int) VIEWBOX_WIDTH;
		m_view_box.m_height = (int) VIEWBOX_HEIGHT;
	}
}



