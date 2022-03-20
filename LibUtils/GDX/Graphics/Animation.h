#ifndef __ANIMATION_H
#define __ANIMATION_H

#include <vector>

#include "SFML/Graphics.hpp"
#include "GDX/Maths/Vec2.h"

namespace GDX
{
    class Animation
    {
    public:
        enum class PlayMode
        {
            Normal,
            Reversed,
            Loop,
            LoopReversed,
            LoopPingpong,
            LoopRandom,
        };

        Animation();
        Animation(sf::Texture texture);
        Animation(float frameDuration, const sf::Texture texture);
        Animation(float frameDuration, const sf::Texture texture, PlayMode playMode);

        [[nodiscard]] int GetFrameIndex(float stateTime);
        [[nodiscard]] sf::IntRect GetFrame(float stateTime, bool looping);
        [[nodiscard]] sf::IntRect GetFrame(float stateTime);
        [[nodiscard]] bool IsAnimationFinished(float stateTime) const;
        [[nodiscard]] float GetFrameDuration() const;
        [[nodiscard]] PlayMode GetPlayMode();

        void SetPlayMode(PlayMode playMode);
        void SetFrameDuration(float frameDuration);
        void SetFrameCount(int frames);
        void SetTexture(const sf::Texture texture);

        Vec2<int>   m_size;
        sf::Texture m_texture;

    private:
        float m_frameDuration;
        float m_lastStateTime;
        int   m_frameCount;
        int   m_lastFrameNumber;

        PlayMode m_playMode = PlayMode::Normal;
    };
}

#endif //SFMLTEST_ANIMATION_H

