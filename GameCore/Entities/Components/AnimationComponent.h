#ifndef SFMLTEST_ANIMATIONCOMPONENT_H
#define SFMLTEST_ANIMATIONCOMPONENT_H

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include <vector>

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include <GDX/Graphics/Animation.h>
#include <GDX/Graphics/TextureRegion.h>

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

namespace Game
{
    class AnimationComponent
    {
    public:
        AnimationComponent() = default;
        virtual ~AnimationComponent() = default;

        GDX::Animation                  m_animation;
        std::vector<GDX::TextureRegion> m_animFrames;
        float                           m_elapsedAnimTime = 0.0f;
    };
}

#endif //SFMLTEST_ANIMATIONCOMPONENT_H
