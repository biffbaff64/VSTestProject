#ifndef __GAMELEVELMANAGER_H
#define __GAMELEVELMANAGER_H

namespace Game
{
    class GameLevelManager
    {
    public:
        GameLevelManager() :
            m_isFirstTime(true)
        { }

        ~GameLevelManager() = default;

        virtual void PrepareNewGame();
        virtual void PrepareCurrentLevel();
        virtual void SetupForNewLevel();
        virtual void RestartCurrentLevel();
        virtual void CloseCurrentLevel();

        bool m_isFirstTime;
    };
}

#endif // __GAMELEVELMANAGER_H
