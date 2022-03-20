#ifndef __MAINPLAYER_H
#define __MAINPLAYER_H

#include "Enums/ActionStates.h"
#include "GDX/Maths/Box.h"

#include "Entities/Objects/GdxSprite.h"
#include "ButtonInputHandler.h"
#include "CollisionHandler.h"

using namespace Enums;

namespace Game
{
    #define VIEWBOX_WIDTH   (Gfx::inst().m_viewWidth + (Gfx::inst().m_viewWidth / 2))
    #define VIEWBOX_HEIGHT  (Gfx::inst().m_viewHeight + (Gfx::inst().m_viewHeight / 2))
    #define PLAYER_X_SPEED  6
    #define PLAYER_Y_SPEED  6

    class MainPlayer : public GDXSprite
    {
    public:
        MainPlayer();
        ~MainPlayer() = default;

        void Initialise(SpriteDescriptor& descriptor) override;
        void Setup(bool isSpawning) override;
        void Update() override;
        void Draw() override;
        void UpdateCollisionBox() override;
        void SetActionState(ActionStates state) override;

        GDX::Box m_view_box;

        friend ButtonInputHandler;
        friend CollisionHandler;

    protected:
        bool m_isOnPlatform;
        bool m_isOnFloorButton;
        bool m_isPossessed;
        bool m_isHurting;
        bool m_isGrabbing;
        bool m_isCasting;
        bool m_isShooting;
        bool m_isMovingX;
        bool m_isMovingY;

        bool m_canOfferButton;
        bool m_canOpenMessagePanel;

    private:
        sf::Texture m_ABXYTexture;
        sf::Sprite m_ABXYSprite;
    };
}

#endif // __MAINPLAYER_H

