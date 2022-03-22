
#include <vector>

#include <Application.h>
#include <GDX/Graphics/TextureRegion.h>
#include <Translations.h>
#include <GlobalDefines.h>

#include "Graphics/BaseRenderer.h"
#include "Graphics/Gfx.h"
#include "Core/App.h"
#include "Physics/BoxCollision.h"
#include "GdxSprite.h"

namespace Game
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    GDXSprite::GDXSprite() : GDXSprite( GraphicID::NoID )
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    GDXSprite::GDXSprite( Enums::GraphicID gid )
    :
    m_gid( gid ),
    m_entityAction( ActionStates::NoAction ),
    m_type( GraphicID::Entity ),
    m_frameWidth( 0 ),
    m_frameHeight( 0 ),
    m_animation(),
    m_spriteNumber( 0 ),
    m_topEdge( 0 ),
    m_rightEdge( 0 ),
    m_zPosition( 0 ),
    m_elapsedAnimTime( 0 ),
    m_bodyCategory( Gfx::CAT_NONE ),
    m_collidesWith( Gfx::CAT_NONE ),
    m_collisionObject( nullptr ),
    m_collisionListener( new GenericCollisionListener )
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GDXSprite::Initialise( SpriteDescriptor &descriptor )
    {
        Create( descriptor );

        //
        // Override in any entity classes and add any
        // other relevant initialisation code here.
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GDXSprite::Setup( bool isSpawning )
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GDXSprite::Create( SpriteDescriptor &descriptor )
    {
        SetAnimation( descriptor );

        m_spriteNumber = descriptor.m_index;
        m_isAnimating  = ( descriptor.m_frames > 1 );
        m_isDrawable   = true;
        m_canFlip      = true;
        m_strength     = MAX_STRENGTH;

        InitPosition( descriptor.m_position );

        SetCollisionObject((int) m_sprite.getPosition().x, (int) m_sprite.getPosition().y );
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GDXSprite::Create( SpriteDescriptor &descriptor, b2BodyType bodyType )
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GDXSprite::InitPosition( GDX::Vec3< int > &vec3 )
    {
        m_sprite.setPosition
        (
        (float) ( vec3.m_x * pApp->m_pMapData->m_tileWidth ),
        (float) ((( vec3.m_y + 1 ) * pApp->m_pMapData->m_tileHeight ) - m_frameHeight )
        );

        m_initXY.m_x = m_sprite.getPosition().x;
        m_initXY.m_y = m_sprite.getPosition().y;

        m_zPosition = vec3.m_z;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    SimpleVec3 GDXSprite::GetPositionModifier()
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GDXSprite::PreUpdate()
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GDXSprite::Update()
    {
        Animate();

        UpdateCommon();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GDXSprite::PostUpdate()
    {
        UpdateCollisionCheck();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GDXSprite::UpdateCommon() const
    {
        if ( m_isRotating )
        {
        }

        if ( m_canFlip )
        {
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GDXSprite::Tidy()
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GDXSprite::PreDraw()
    {
#ifdef USING_BOX2D
        SetPositionFromBody();
#endif
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GDXSprite::Draw()
    {
        if ( m_isDrawable )
        {
            pApp->m_pBaseRenderer->m_renderWindow.draw( m_sprite, pApp->m_pBaseRenderer->m_renderStates );
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GDXSprite::Animate()
    {
        m_sprite.setTexture( m_animation.m_texture );
        m_sprite.setTextureRect( m_animation.GetFrame( m_elapsedAnimTime ));

        m_elapsedAnimTime += pFramework->GetDeltaTime();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GDXSprite::SetAnimation( SpriteDescriptor &descriptor )
    {
        m_animFrames.clear();

        m_frameWidth  = descriptor.m_size.m_x;
        m_frameHeight = descriptor.m_size.m_y;

        if ( m_animation_texture.loadFromFile( descriptor.m_asset ))
        {
            m_animation.m_size.m_x = m_frameWidth;
            m_animation.m_size.m_y = m_frameHeight;

            m_animation.SetTexture( m_animation_texture );
            m_animation.SetPlayMode( descriptor.m_playmode );
            m_animation.SetFrameDuration( descriptor.m_anim_rate );
            m_animation.SetFrameCount( descriptor.m_frames );
        }
        else
        {
            trace->Dbg( "FAILURE! Unable to load %s", descriptor.m_asset.c_str());
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GDXSprite::SetPositionFromBody()
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GDXSprite::SetCollisionObject( int x, int y )
    {
        m_collisionObject = CollisionObject();

        if ( m_gid != GraphicID::NoID )
        {
            pApp->m_pMapData->m_collisionBoxData.push_back( m_collisionObject );
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GDXSprite::AddCollisionCallback( const CollisionCallback &callback )
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GDXSprite::UpdateCollisionCheck()
    {
        UpdateCollisionBox();

        m_collisionObject.CheckInvisibility();
        m_collisionObject.ClearCollision();

        if ( m_collisionObject.m_actionState == ActionStates::Collidable )
        {
            if ( pApp->m_pAABB->CheckContact( &m_collisionObject ))
            {
                m_collisionObject.m_actionState = ActionStates::Colliding;

                m_collisionListener->OnPositiveCollision( &m_collisionObject );

                if ( m_isEnemy && m_collisionObject.m_isInvisibilityAllowed )
                {
                    m_collisionObject.SetInvisibility( 1000 );
                }
            }

            //
            // The collisionObject action might hace changed by the
            // time the flow gets here.
            if ( m_collisionObject.m_actionState != ActionStates::Colliding )
            {
                m_collisionListener->OnNegativeCollision();
            }
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GDXSprite::UpdateCollisionBox()
    {
        m_collisionObject.m_rectangle.m_x      = (int) m_sprite.getPosition().x;
        m_collisionObject.m_rectangle.m_y      = (int) m_sprite.getPosition().y;
        m_collisionObject.m_rectangle.m_width  = (int) m_sprite.getPosition().x + m_frameWidth;
        m_collisionObject.m_rectangle.m_height = (int) m_sprite.getPosition().y + m_frameHeight;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GDXSprite::SetSpriteNumber( int index )
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GDXSprite::SetLink( int link )
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GDXSprite::SetActionState( ActionStates state )
    {
        m_entityAction = state;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    Vec3< float > GDXSprite::GetPosition()
    {
        m_position.m_x = m_sprite.getPosition().x;
        m_position.m_y = m_sprite.getPosition().y;
        m_position.m_z = (float) m_zPosition;

        return m_position;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    CollisionObject GDXSprite::GetCollisionObject() const
    {
        return m_collisionObject;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    float GDXSprite::GetTopEdge() const
    {
        return (float) ( m_position.m_y + (float) m_frameHeight );
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    float GDXSprite::GetRightEdge() const
    {
        return ( m_position.m_x + (float) m_frameWidth );
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    short GDXSprite::GetBodyCategory() const
    {
        return m_bodyCategory;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    short GDXSprite::GetCollidesWith() const
    {
        return m_collidesWith;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    int GDXSprite::GetSpriteNumber() const
    {
        return m_spriteNumber;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    int GDXSprite::GetLink() const
    {
        return m_link;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    bool GDXSprite::IsLinked() const
    {
        return m_isLinked;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    GraphicID GDXSprite::GetGID() const
    {
        return m_gid;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    GraphicID GDXSprite::GetType() const
    {
        return m_type;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    ActionStates GDXSprite::GetActionState() const
    {
        return m_entityAction;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    BoundsBox GDXSprite::GetBoundingBox() const
    {
        Box box
            {
            (int) m_position.m_x,
            (int) m_position.m_y,
            m_frameWidth,
            m_frameHeight
            };

        return { box };
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    Vec2< int > GDXSprite::GetSize() const
    {
        return { m_frameWidth, m_frameHeight };
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    sf::Sprite GDXSprite::GetSprite()
    {
        return m_sprite;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    bool GDXSprite::IsDrawable() const
    {
        return m_isDrawable;
    }
}

