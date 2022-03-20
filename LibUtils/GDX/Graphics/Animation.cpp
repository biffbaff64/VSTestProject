//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include <algorithm>

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "SFML/Graphics.hpp"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "GDX/Maths/NumberUtils.h"
#include "GDX/Utils/Trace.h"
#include "Animation.h"

namespace GDX
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    Animation::Animation()
    {
        m_frameDuration     = 0.0f;
        m_frameCount        = 0;
        m_lastFrameNumber   = 0;
        m_lastStateTime     = 0;
        m_playMode          = PlayMode::Normal;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    Animation::Animation(sf::Texture keyFrames)
    {
        m_frameDuration     = 0.0f;
        m_frameCount        = 0;
        m_lastFrameNumber   = 0;
        m_lastStateTime     = 0;
        m_playMode          = PlayMode::Normal;

        SetTexture(keyFrames);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    Animation::Animation(float frameDuration, const sf::Texture keyFrames)
    {
        m_frameDuration     = frameDuration;
        m_frameCount        = 0;
        m_lastFrameNumber   = 0;
        m_lastStateTime     = 0;
        m_playMode          = PlayMode::Normal;

        SetTexture(keyFrames);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    Animation::Animation(float frameDuration, const sf::Texture keyFrames, Animation::PlayMode playmode)
        :
        Animation(frameDuration, keyFrames)
    {
        m_playMode = playmode;

        SetTexture(keyFrames);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    sf::IntRect Animation::GetFrame(float stateTime, bool looping)
    {
        PlayMode oldPlayMode = m_playMode;

        if (looping && ((m_playMode == PlayMode::Normal) || (m_playMode == PlayMode::Reversed)))
        {
            m_playMode = (m_playMode == PlayMode::Normal) ? PlayMode::Loop : PlayMode::LoopReversed;
        }
        else if (!looping && (!(m_playMode == PlayMode::Normal) || (m_playMode == PlayMode::Reversed)))
        {
            m_playMode = (m_playMode == PlayMode::LoopReversed) ? PlayMode::Reversed : PlayMode::Loop;
        }

        sf::IntRect rect = GetFrame(stateTime);

        m_playMode = oldPlayMode;

        return rect;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    // TODO: This needs to work with spritesheets with multiple rows
    sf::IntRect Animation::GetFrame(float stateTime)
    {
        int index = GetFrameIndex(stateTime);

        return sf::IntRect(index * m_size.m_x, 0, m_size.m_x, m_size.m_y);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    int Animation::GetFrameIndex(float stateTime)
    {
        int frameNumber = 0;

        if (m_frameCount > 1)
        {
            frameNumber = (int) (stateTime / m_frameDuration);

            switch (m_playMode)
            {
                case PlayMode::Normal:
                {
                    frameNumber = std::min((int)m_frameCount - 1, frameNumber);
                }
                break;

                case PlayMode::Loop:
                {
                    frameNumber = frameNumber % m_frameCount;
                }
                break;

                case PlayMode::LoopPingpong:
                {
                    frameNumber = frameNumber % ((m_frameCount * 2) - 2);

                    if (frameNumber >= m_frameCount)
                    {
                        frameNumber = m_frameCount - 2 - (frameNumber - m_frameCount);
                    }
                }
                break;

                case PlayMode::LoopRandom:
                {
                    int lastFrameNumber = (int)((m_lastStateTime) / m_frameDuration);

                    if (lastFrameNumber != frameNumber)
                    {
                        frameNumber = NumberUtils::Random(0, m_frameCount - 1);
                    }
                    else
                    {
                        frameNumber = m_lastFrameNumber;
                    }
                }
                break;

                case PlayMode::Reversed:
                {
                    frameNumber = std::max((int) m_frameCount - frameNumber - 1, 0);
                }
                break;

                case PlayMode::LoopReversed:
                {
                    frameNumber = frameNumber % m_frameCount;
                    frameNumber = m_frameCount - frameNumber - 1;
                }
                break;

                default:
                {
                    frameNumber = 0;
                }
                break;
            }
        }

        m_lastFrameNumber = frameNumber;
        m_lastStateTime = stateTime;

        return frameNumber;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    Animation::PlayMode Animation::GetPlayMode()
    {
        return m_playMode;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    bool Animation::IsAnimationFinished(float stateTime) const
    {
        int frameNumber = (int)(stateTime / m_frameDuration);

        return (int) (m_frameCount - 1) < frameNumber;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    float Animation::GetFrameDuration() const
    {
        return m_frameDuration;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Animation::SetPlayMode(Animation::PlayMode playMode)
    {
        m_playMode = playMode;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Animation::SetFrameDuration(float frameDuration)
    {
        m_frameDuration = frameDuration;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Animation::SetFrameCount(int frames)
    {
        m_frameCount = frames;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Animation::SetTexture(const sf::Texture texture)
    {
        m_texture = texture;
    }
}

