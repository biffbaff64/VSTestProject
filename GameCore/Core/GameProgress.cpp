//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include <Application.h>
#include <GDX/Maths/NumberUtils.h>
#include <Enums/GameStates.h>

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "App.h"
#include "GameProgress.h"

// TODO:
// I'm no longer sure about this class. It seems that a lot of the data is
// specific to the main player only and I'm not sure if it is in the
// right place.
// Give it some thought.

namespace Game
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    GameProgress::GameProgress()
    {
        ResetProgress();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GameProgress::ResetProgress()
    {
        m_isRestarting      = false;
        m_levelCompleted    = false;
        m_gameCompleted     = false;
        m_gameSetupDone     = false;
        m_playerLifeOver    = false;

        m_playerLevel = 1;
        m_gameDifficulty = 1.0f;

        m_Score     = GDX::Item(0, MAX_SCORE, 0);
        m_Lives     = GDX::Item(0, MAX_LIVES, MAX_LIVES);
        m_GemCount  = GDX::Item(0, MAX_GEMS, 0);
        m_CoinCount = GDX::Item(0, MAX_COINS, 0);
        m_KeyCount  = GDX::Item(0, MAX_KEYS, 0);
        m_Villagers = GDX::Item(0, MAX_VILLAGERS, 0);

        m_Score.m_RefillAmount = 0;
        m_Lives.m_RefillAmount = MAX_LIVES;

        m_Score.SetToMaximum();
        m_Lives.SetToMaximum();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GameProgress::Update()
    {
        switch (Gdx->m_pAppState->Get())
        {
            case GameStates::StatePaused:
            case GameStates::StateGame:
            case GameStates::StateMessagePanel:
            {
                UpdateStack(&m_Score, &m_ScoreStack);
                UpdateStack(&m_Lives, &m_LivesStack);
                UpdateStack(&m_GemCount, &m_GemsStack);
                UpdateStack(&m_CoinCount, &m_CoinsStack);
                UpdateStack(&m_KeyCount, &m_KeysStack);
                UpdateStack(&m_Villagers, &m_VillagersStack);
            }
            break;

            default:
                break;
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GameProgress::UpdateStack(GDX::Item* item, int* stack)
    {
        int amount;

        if (*stack > 0)
        {
            amount = GDX::NumberUtils::GetCount(*stack);

            item->Add(amount);
            *stack -= amount;
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GameProgress::AddTo(Stack stack, int amount)
    {
        switch (stack)
        {
            case Stack::Score:
                m_Score.Add(amount);
                break;

            case Stack::Lives:
                m_Lives.Add(amount);
                break;

            case Stack::Gems:
                m_GemCount.Add(amount);
                break;

            case Stack::Coins:
                m_CoinCount.Add(amount);
                break;

            case Stack::Keys:
                m_KeyCount.Add(amount);
                break;

            case Stack::Villagers:
                m_Villagers.Add(amount);
                break;

            default:
                break;
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GameProgress::ToMinimum()
    {
        m_Score.SetToMinimum();
        m_Lives.SetToMinimum();
        m_GemCount.SetToMinimum();
        m_CoinCount.SetToMinimum();
        m_KeyCount.SetToMinimum();
        m_Villagers.SetToMinimum();

        pApp->m_pHud->GetItemBar()->Reset();

        m_playerLifeOver = false;
        m_playerLevel = 1;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GameProgress::CloseLastGame()
    {
    }
}

