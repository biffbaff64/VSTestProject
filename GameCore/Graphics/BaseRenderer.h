#ifndef __BASERENDERER_H
#define __BASERENDERER_H

#include "SFML/Graphics.hpp"
#include "OrthoGameCamera.h"

namespace Game
{
    //#define DEMO_SCROLL_ENABLED

    class BaseRenderer
    {
    public:
        BaseRenderer() = default;
        ~BaseRenderer() = default;

        void CreateCameras();
        void Render();
        void CreateGameWindow();

        static void HudRenderer();
        static void WorldRenderer();

        void ResetCameraZoom();
        void EnableAllCameras();
        void DisableAllCameras();

        bool m_canDrawBackground = false;

        sf::Texture      m_backgroundTexture;
        sf::Sprite       m_backgroundSprite;
        sf::RenderWindow m_renderWindow;
        sf::RenderStates m_renderStates;

        OrthoGameCamera m_hudCamera;
        OrthoGameCamera m_spriteCamera;
        OrthoGameCamera m_tiledCamera;

        #ifdef USING_MINIMAP
        OrthoGameCamera m_miniMap;
        #endif

    private:
        void BeginDraw();
        void EndDraw();

        void DrawBackground();
        void DrawTiledMap();
        void DrawSprites();
        void DrawHUD();

        #ifdef USING_MINIMAP
        void DrawMiniMap();
        #endif
    };
}

#endif // __BASERENDERER_H

