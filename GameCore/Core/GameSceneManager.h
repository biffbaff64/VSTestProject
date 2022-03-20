#ifndef __GAMESCENEMANAGER_H
#define __GAMESCENEMANAGER_H

namespace Game
{
    class GameSceneManager
    {
    public:
        GameSceneManager() = default;
        ~GameSceneManager() = default;

        void StateLevelSetup();
        void StateGetReady();
        void StateGame();
        void StateLevelRetry();
        void StateLevelFinished();
        void StateGameOver();
        void StateGameFinished();
        void StateEndGame();
        void StateClosing();
    };
}

#endif // __GAMESCENEMANAGER_H

