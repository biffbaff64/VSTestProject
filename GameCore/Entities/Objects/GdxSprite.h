#ifndef __GDXSPRITE_H
#define __GDXSPRITE_H

#include <SFML/Graphics.hpp>
#include <ActionStates.h>
#include <GraphicID.h>

#include "GDX/Maths/Vec3.h"
#include "GDX/Maths/Vec2.h"
#include "GDX/Maths/BoundsBox.h"
#include "GDX/Maths/SimpleVec2F.h"
#include "GDX/Maths/SimpleVec3.h"
#include "GDX/Physics/Direction.h"

#include "Physics/CollisionObject.h"
#include "Physics/GenericCollisionListener.h"
#include "Entities/Components/AnimationComponent.h"
#include "Entities/Components/CollisionListener.h"
#include "Entities/Components/SpriteProperties.h"
#include "Entities/SpriteDescriptor.h"

using namespace Enums;
using namespace GDX;

namespace Game
{
	class GDXSprite
	{
	public:
		GDXSprite();
		explicit GDXSprite(GraphicID gid);
		virtual ~GDXSprite() = default;

		//
		// Functions to be overridden in any child classes.
		virtual void Initialise(SpriteDescriptor& descriptor);
		virtual void Update();
		virtual void Animate();

		//
		// Optional Functions to be overridden.
		virtual void Setup(bool isSpawning) {}
		virtual void PreDraw();
		virtual void Draw();
		virtual void SetAnimation(SpriteDescriptor& descriptor);
		virtual void UpdateCollisionBox();
		virtual void SetActionState(ActionStates state);

		//
		// Generally not overridden (but can be if required).
		void Create(SpriteDescriptor& descriptor);
		void UpdateCommon() const;
		void InitPosition(Vec3<int>& vec3);
		void SetCollisionObject(int x, int y);
		void UpdateCollisionCheck();
		void Tidy();

		[[nodiscard]] float GetTopEdge() const;
		[[nodiscard]] float GetRightEdge() const;
		[[nodiscard]] BoundsBox GetBoundingBox() const;
		[[nodiscard]] Vec2<int> GetSize() const;
		[[nodiscard]] Vec3<float> GetPosition();
		[[nodiscard]] sf::Sprite GetSprite();
		[[nodiscard]] bool IsDrawable();
        [[nodiscard]] ActionStates GetActionState() const;

		// ------------------------------------------------
		// Data.
		int		m_spriteNumber;						// ...
		int		m_zPosition;						// Z-sort order

		int     m_frameWidth;						// Width in pixels, or width of frame for animations
		int     m_frameHeight;						// Width in pixels, or width of frame for animations
		float   m_rightEdge;						// The right edge of this entities collision box
		float   m_topEdge;							// The top edge of this entities collision box
		short   m_bodyCategory;						// Bit-mask entity collision type
		short	m_collidesWith;						// Bit-mask of entity types that can be collided with
		float	m_elapsedAnimTime;					// Timer for animation speed

		CollisionObject*	m_collisionObject;		// ...
		SpriteProperties*	m_properties;			// ...

		GraphicID		m_gid;						// Entity ID
		GraphicID		m_type;						// Entity Type - _Entity, _OBSTACLE, etc.
		ActionStates	m_entityAction;				// Current action/state
		Vec3<float>		m_position;					// Map position
		Vec3<float>		m_initXY;					// Initialisation position
		Direction		m_direction;
		Direction		m_lookingAt;
		Vec2<float>		m_distance;
		SimpleVec2F		m_speed;
		Animation		m_animation;

		sf::Texture m_animation_texture;
		std::vector<sf::Texture> m_animFrames;

	protected:
		sf::Sprite                  m_sprite;
		GenericCollisionListener*	m_collisionListener;
	};
}

#endif // __GDXSPRITE_H
