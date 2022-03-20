//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Framework.h"
#include "Core/App.h"
#include "Graphics/BaseRenderer.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "GameScene.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

using namespace Enums;

namespace Game
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GameScene::OnCreate()
    {
        TraceFileFunc();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GameScene::Initialise()
    {
        trace->Divider();
        TraceFileFunc();

        if (m_isFirstTime)
        {
            trace->Divider();
            trace->Divider();
            trace->Dbg("NEW GAME");
            trace->Dbg("DEVMODE: %d", pApp->m_isDevMode);
            trace->Dbg("GODMODE: %d", pApp->m_isGodMode);
            trace->Divider();

            m_gameLevelManager->PrepareNewGame();

            Gdx->m_pAppState->Set(GameStates::StateLevelSetup);
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GameScene::Update(float delta)
    {
        pApp->m_pMapData->UpdateMap();
        pApp->m_pGameProgress->Update();

        switch (Gdx->m_pAppState->Get())
        {
            case GameStates::StateMainMenu:
                break;

            case GameStates::StateLevelSetup:
            {
                pApp->m_pGameSceneManager->StateLevelSetup();
            }
            break;

            case GameStates::StateGetReady:
            {
                pApp->m_pGameSceneManager->StateGetReady();
            }
            break;

            case GameStates::StateDeveloperPanel:
            case GameStates::StatePaused:
            case GameStates::StateGame:
            {
                pApp->m_pGameSceneManager->StateGame();
            }
            break;

            case GameStates::StateLevelRetry:
            {
                pApp->m_pGameSceneManager->StateLevelRetry();
            }
            break;

            case GameStates::StateLevelFinished:
            {
                pApp->m_pGameSceneManager->StateLevelFinished();
            }
            break;

            case GameStates::StateGameOver:
            {
                pApp->m_pGameSceneManager->StateGameOver();
            }
            break;

            case GameStates::StateGameFinished:
            {
                pApp->m_pGameSceneManager->StateGameFinished();
            }
            break;

            case GameStates::StateEndGame:
            {
                pApp->m_pGameSceneManager->StateEndGame();
            }
            break;

            case GameStates::StateClosing:
            {
                pApp->m_pGameSceneManager->StateClosing();
            }
            break;

            default:
                break;
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GameScene::Draw()
    {
        #ifdef USING_STARFIELD
        if (app->m_pStarField->m_isEnabled)
        {
            app->m_pStarField->Render();
        }
        #endif

        pApp->m_pEntityManager->DrawSprites();

        // TODO: DebugRenderer::DrawBoxes();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GameScene::OnShow()
    {
        TraceFileFunc();

        LoadContent();

        pApp->m_currentScreenID = ScreenID::GameScene;

        pApp->m_pBaseRenderer->DisableAllCameras();

        Initialise();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GameScene::OnHide()
    {
        TraceFileFunc();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GameScene::ResetGameScene()
    {
        m_isFirstTime = true;

        pApp->m_pAppConfig->m_game_paused = false;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GameScene::LoadContent()
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void GameScene::OnDestroy()
    {
    }
}


