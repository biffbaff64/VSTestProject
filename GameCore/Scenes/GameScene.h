#ifndef __GAMESCENE_H
#define __GAMESCENE_H

#include "Core/GameSceneManager.h"
#include "Core/GameLevelManager.h"
#include "Core/EndgameManager.h"
#include "SceneBase.h"

namespace Game
{
    class GameScene : public SceneBase
    {
    public:
        GameScene() :
            m_isFirstTime(true),
            m_gameLevelManager(new GameLevelManager),
            m_endgameManager(new EndgameManager)
        {
        }

        ~GameScene()
        {
            delete m_gameLevelManager;
            delete m_endgameManager;
        }

        void OnCreate() override;
        void OnDestroy() override;
        void Update(float delta) override;
        void OnShow() override;
        void OnHide() override;
        void Draw() override;

        void ResetGameScene();

    private:
        void LoadContent() override;
        void Initialise();

        bool                m_isFirstTime;
        GameLevelManager    *m_gameLevelManager;
        EndgameManager      *m_endgameManager;

        friend class GameSceneManager;
    };
}

#endif // __GAMESCENE_H
