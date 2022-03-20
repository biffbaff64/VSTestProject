//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "App.h"
#include "GameLevelManager.h"

namespace Game
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GameLevelManager::PrepareNewGame()
    {
        TraceFileFunc();

        if (m_isFirstTime)
        {
            // Make sure all progress counters are initialised
            pApp->m_pGameProgress->ResetProgress();

            // TODO: Initialise the room that the game will start in
            pApp->m_pRoomManager->Initialise();

            // TODO: Create collision and entity controllers

            // TODO: app->m_entityUtils.CreateData();
            // TODO: BoxCollision::CreateData();
            pApp->m_pEntityManager->Initialise();
            pApp->m_pMapData->UpdateMap();
            pApp->m_pHud->CreateHud();
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GameLevelManager::PrepareCurrentLevel()
    {
        TraceFileFunc();

        if (pApp->m_pGameProgress->m_isRestarting)
        {
            RestartCurrentLevel();
        }
        else if (m_isFirstTime || pApp->m_pGameProgress->m_levelCompleted)
        {
            SetupForNewLevel();

            pApp->m_pGameProgress->ResetProgress();
        }

        pApp->m_pAppConfig->m_game_paused      = false;
        pApp->m_pAppConfig->m_quit_to_main_menu  = false;
        pApp->m_pAppConfig->m_force_quit_to_menu = false;

        pApp->m_pGameProgress->m_isRestarting   = false;
        pApp->m_pGameProgress->m_levelCompleted = false;
        pApp->m_pGameProgress->m_playerLifeOver = false;

        if (m_isFirstTime)
        {
            pApp->m_pHud->RefillItems();
            pApp->m_pHud->Update();
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GameLevelManager::SetupForNewLevel()
    {
        TraceFileFunc();

        pApp->m_pMapData->LoadMap();
        pApp->m_pMapCreator->CreateMapData();

        pApp->m_pEntityManager->InitialiseForLevel();

        //
        // Create entity paths if any relevant data
        // exists in the tilemap data.
        // TODO: app->m_pathUtils.setup();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GameLevelManager::RestartCurrentLevel()
    {
        TraceFileFunc();

//        app->m_entityManager.ResetAllPositions();

        pApp->GetPlayer().Setup(true);

        if (pApp->m_pGameProgress->m_levelCompleted)
        {
            pApp->m_pEntityManager->UpdateIndexes();
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GameLevelManager::CloseCurrentLevel()
    {
    }
}

