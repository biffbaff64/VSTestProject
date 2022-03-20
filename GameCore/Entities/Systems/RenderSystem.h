#ifndef SFMLTEST_RENDERSYSTEM_H
#define SFMLTEST_RENDERSYSTEM_H

#include "Entities/Objects/GdxSprite.h"

namespace Game
{
    //#define DRAW_SPRITE_BOXES

    class RenderSystem
    {
    public:
        RenderSystem() = default;
        ~RenderSystem() = default;

        void DrawSprites();

        [[nodiscard]] bool IsInViewWindow(GDXSprite *sprite);

    private:
        #ifdef DRAW_SPRITE_BOXES
        void DrawSpriteBox(GDXSprite *sprite);
        #endif
    };
}

#endif //SFMLTEST_RENDERSYSTEM_H
