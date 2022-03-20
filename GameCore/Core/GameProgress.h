#ifndef __GAMEPROGRESS_H
#define __GAMEPROGRESS_H

#include "GDX/Maths/Item.h"
#include "Enums/Stack.h"
#include "SharedData/GlobalDefines.h"
#include "UI/ItemBar.h"

namespace Game
{
    class GameProgress
    {
    public:
        GameProgress();
        ~GameProgress() = default;

        void ResetProgress();
        void Update();
        void AddTo(Stack stack, int amount);
        void ToMinimum();
        void CloseLastGame();

        bool m_isRestarting = false;
        bool m_levelCompleted = false;
        bool m_gameCompleted = false;
        bool m_gameSetupDone = false;
        bool m_playerLifeOver = false;
        int  m_playerLevel = 1;

        float m_gameDifficulty = 0.0f;

        GDX::Item m_Score;
        GDX::Item m_Lives;
        GDX::Item m_GemCount;
        GDX::Item m_CoinCount;
        GDX::Item m_KeyCount;
        GDX::Item m_Villagers;

    private:
        static void UpdateStack(GDX::Item* item, int* stack);

        int m_ScoreStack = 0;
        int m_LivesStack = 0;
        int m_GemsStack = 0;
        int m_CoinsStack = 0;
        int m_KeysStack = 0;
        int m_VillagersStack = 0;
    };
}

#endif // __GAMEPROGRESS_H
