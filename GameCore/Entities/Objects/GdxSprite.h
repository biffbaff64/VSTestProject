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
#include "Entities/Components/CollisionCallback.h"
#include "Entities/SpriteDescriptor.h"
#include "Physics/BoxCollision.h"
#include "box2d/b2_body.h"

using namespace Enums;
using namespace GDX;

namespace Game
{
    class GDXSprite
    {
    public:
        GDXSprite();
        explicit GDXSprite( GraphicID gid );
        virtual ~GDXSprite() = default;

        virtual void Initialise( SpriteDescriptor &descriptor );
        virtual void Setup( bool isSpawning );
        virtual void Create( SpriteDescriptor &descriptor );
        virtual void Create( SpriteDescriptor &descriptor, b2BodyType bodyType );
        virtual void InitPosition( Vec3< int > &vec3 );
        virtual SimpleVec3 GetPositionModifier();
        virtual void PreUpdate();
        virtual void Update();
        virtual void PostUpdate();
        virtual void UpdateCommon() const;
        virtual void Tidy();
        virtual void PreDraw();
        virtual void Draw();
        virtual void Animate();
        virtual void SetAnimation( SpriteDescriptor &descriptor );
        virtual void SetPositionFromBody();
        virtual void SetCollisionObject( int x, int y );
        virtual void AddCollisionCallback( const CollisionCallback &callback );
        virtual void UpdateCollisionCheck();
        virtual void UpdateCollisionBox();
        virtual void SetSpriteNumber( int index );
        virtual void SetLink( int link );
        virtual void SetActionState( ActionStates state );

        [[nodiscard]] Vec3< float > GetPosition();
        [[nodiscard]] CollisionObject GetCollisionObject() const;
        [[nodiscard]] float GetTopEdge() const;
        [[nodiscard]] float GetRightEdge() const;
        [[nodiscard]] short GetBodyCategory() const;
        [[nodiscard]] short GetCollidesWith() const;
        [[nodiscard]] int GetSpriteNumber() const;
        [[nodiscard]] int GetLink() const;
        [[nodiscard]] bool IsLinked() const;
        [[nodiscard]] GraphicID GetGID() const;
        [[nodiscard]] GraphicID GetType() const;
        [[nodiscard]] ActionStates GetActionState() const;
        [[nodiscard]] BoundsBox GetBoundingBox() const;
        [[nodiscard]] Vec2< int > GetSize() const;
        [[nodiscard]] sf::Sprite GetSprite();
        [[nodiscard]] bool IsDrawable() const;

        // ------------------------------------------------
        // Data.
        // ------------------------------------------------

        // -------------------------------------------------
        // Identity etc.
        //
        GraphicID    m_gid;                                 // Entity ID
        GraphicID    m_type;                                // Entity Type - _Entity, _OBSTACLE, etc.
        ActionStates m_entityAction;                        // Current action/state
        int          m_spriteNumber;                        // ...
        bool         m_isMainCharacter;
        bool         m_isEnemy;
        int          m_strength;

        // -------------------------------------------------
        // Movement/Transform etc.
        //
        Direction     m_direction;
        Direction     m_lookingAt;
        Vec2< float > m_distance;
        SimpleVec2F   m_speed;
        Vec3< float > m_initXY;                             // Initialisation position
        int           m_zPosition;                          // Z-sort order
        bool          m_isFlippedX;
        bool          m_isFlippedY;
        bool          m_canFlip;
        bool          m_isRotating;
        float         m_rotateSpeed;
        float         m_rotation;
        Vec3< float > m_position;                           // Map position

        // -------------------------------------------------
        // Collision Related
        //
        short                    m_bodyCategory;            // Bit-mask entity collision type
        short                    m_collidesWith;            // Bit-mask of entity types that can be collided with
        float                    m_rightEdge;               // The right edge of this entities collision box
        float                    m_topEdge;                 // The top edge of this entities collision box
        CollisionObject          m_collisionObject;        // ...
        GenericCollisionListener *m_collisionListener;
        BoxCollision             *m_boxCollision;

        // -------------------------------------------------
        // Animation Related
        //
        Animation                  m_animation;
        float                      m_elapsedAnimTime;        // Timer for animation speed
        std::vector< sf::Texture > m_animFrames;
        bool                       m_isAnimating;
        bool                       m_isLoopingAnim;
        int                        m_frameWidth;             // Width in pixels, or width of frame for animations
        int                        m_frameHeight;            // Width in pixels, or width of frame for animations
        sf::Texture                m_animation_texture;
        bool                       m_isDrawable;

    protected:
        sf::Sprite m_sprite;
        int        m_link;
        bool       m_isLinked;
    };
}

#endif // __GDXSPRITE_H
