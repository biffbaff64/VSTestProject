#ifndef __MAINGAME_H
#define __MAINGAME_H

#include <SFML/Graphics.hpp>
#include <GDX/System/FPSCounter.h>

#include "Scenes/SceneManager.h"

namespace Game
{
    class MainGame
    {
    public:
        MainGame();
        virtual ~MainGame() = default;

        void Run();
        void Update(float deltaTime);

    private:
        void GameLoop();
        void ProcessEvents();
        void UpdateCurrentScene(float deltaTime);
        void SetScene(SceneBase *scr);

        const float m_deltaTime = 1.0f / 60.0f;

        sf::Clock m_clock;
    };
}

#endif // __MAINGAME_H

