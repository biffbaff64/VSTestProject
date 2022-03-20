//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Application.h"
#include "GameStates.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Graphics/BaseRenderer.h"
#include "App.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "GameSceneManager.h"

namespace Game
{
    //------------------------------------------------------------------------------------------------------
    /// Initialise the current level.
    // If the level is restarting, that will also be handled here
    //------------------------------------------------------------------------------------------------------
    void GameSceneManager::StateLevelSetup()
    {
        TraceFileFunc();

        pApp->m_pGameScene->m_gameLevelManager->PrepareCurrentLevel();

        pApp->m_pBaseRenderer->EnableAllCameras();
        pApp->m_pBaseRenderer->m_canDrawBackground = true;

        if (pApp->m_pGameScene->m_isFirstTime)
        {
            // TODO: Start game tune
            // TODO: Add 'Get Ready' message
        }

        Gdx->m_pAppState->Set(GameStates::StateGetReady);
        pApp->m_pGameProgress->m_gameSetupDone                = true;
        pApp->m_pGameScene->m_gameLevelManager->m_isFirstTime = false;
    }

    //------------------------------------------------------------------------------------------------------
    // Display and Update the 'Get Ready' message
    //------------------------------------------------------------------------------------------------------
    void GameSceneManager::StateGetReady()
    {
        TraceFileFunc();

        pApp->m_pHud->Update();

        // TODO: Check for 'Get Ready' message finishing
        // TODO: See Java 'Runner' for details

        Gdx->m_pAppState->Set(GameStates::StateGame);
        pApp->m_pHud->SetHudState(GameStates::StatePanelUpdate);

        pApp->m_pGameScene->m_isFirstTime = false;

        GDXSprite ptr = *pApp->m_pEntityManager->m_entityMap.at(0);

        if (ptr.m_entityAction == ActionStates::Restarting)
        {
            // TODO: Re-Setup the player after a death/restart
        }

        #ifdef USING_STARFIELD
        app->m_pStarField->m_isEnabled = true;
        #endif
    }

    //------------------------------------------------------------------------------------------------------
    // Update the game for states:-
    // STATE_DEVELOPER_PANEL
    // STATE_SETTINGS_PANEL
    // STATE_PAUSED
    // STATE_GAME
    //------------------------------------------------------------------------------------------------------
    void GameSceneManager::StateGame()
    {
        pApp->m_pHud->Update();

        if (Gdx->m_pAppState->Get() == GameStates::StateDeveloperPanel)
        {
            if (!pApp->m_isDevPanelActive)
            {
                Gdx->m_pAppState->Set(GameStates::StateGame);
                pApp->m_pHud->SetHudState(GameStates::StatePanelUpdate);
            }
        }
        else
        {
            pApp->m_pEntityManager->UpdateSprites();
            pApp->m_pEntityManager->TidySprites();

            //
            // Check for game ending
            if (!pApp->m_pGameScene->m_endgameManager->Update())
            {
                //
                // Tasks to perform if the game has NOT ended
                if (Gdx->m_pAppState->Get() == GameStates::StatePaused)
                {
                    if (!pApp->m_pAppConfig->m_game_paused)
                    {
                        Gdx->m_pAppState->Set(GameStates::StateGame);
                    }
                }
            }
        }
    }

    //------------------------------------------------------------------------------------------------------
    // Handles the preparation for retrying the current
    // level, after Player loses a life.
    //------------------------------------------------------------------------------------------------------
    void GameSceneManager::StateLevelRetry()
    {
    }

    //------------------------------------------------------------------------------------------------------
    // Handles finishing the current level and
    // moving on to the next one.
    //
    // NOTE: "Level finished" for this game is actually "room exit".
    //------------------------------------------------------------------------------------------------------
    void GameSceneManager::StateLevelFinished()
    {
    }

    //------------------------------------------------------------------------------------------------------
    // Game Over, due to losing all lives.
    // (Waits for the 'Game Over' message to disappear.)
    //------------------------------------------------------------------------------------------------------
    void GameSceneManager::StateGameOver()
    {
    }

    //------------------------------------------------------------------------------------------------------
    // Game Over, due to all levels being completed.
    //------------------------------------------------------------------------------------------------------
    void GameSceneManager::StateGameFinished()
    {
    }

    //------------------------------------------------------------------------------------------------------
    // Game Ended, hand control back to MainMenuScreen.
    //------------------------------------------------------------------------------------------------------
    void GameSceneManager::StateEndGame()
    {
        // TODO: Stop game tune

        pApp->m_pGameProgress->CloseLastGame();
        pApp->m_pGameScene->OnDestroy();

        // TODO: Set screen to TitleScene
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------
    void GameSceneManager::StateClosing()
    {
    }
}

