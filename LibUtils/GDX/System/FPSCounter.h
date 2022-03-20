#ifndef __GDX_FPS_COUNTER_H
#define __GDX_FPS_COUNTER_H

#include <SFML/Graphics.hpp>

namespace GDX
{
    class FPSCounter
    {
    public:
        FPSCounter();

        void update();

        [[nodiscard]] float GetFPS();

    private:
        sf::Clock m_delayTimer;
        sf::Clock m_fpsTimer;

        float m_fps;

        int m_frameCount;
    };
}

#endif // __GDX_FPS_COUNTER_H


