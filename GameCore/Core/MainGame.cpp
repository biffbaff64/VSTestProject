// -----------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------

#pragma comment(lib, "flac.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "ogg.lib")
#pragma comment(lib, "openal32.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "vorbis.lib")
#pragma comment(lib, "vorbisenc.lib")
#pragma comment(lib, "vorbisfile.lib")
#pragma comment(lib, "winmm.lib")

// -----------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------

#define NOMINMAX

#include <windows.h>
#include <iostream>

//------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------

#include <SharedData/GlobalDefines.h>

//------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------

#include "Core/App.h"
#include "Graphics/BaseRenderer.h"
#include "Graphics/Gfx.h"
#include "Scenes/SceneBase.h"

//------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------

#include "MainGame.h"

//------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------

int main()
{
    OutputDebugStringA("---------------------------------------------------------------------------\n");
    OutputDebugStringA("---------------------------------------------------------------------------\n");
    OutputDebugStringA("Program Entry...\n");
    OutputDebugStringA("---------------------------------------------------------------------------\n");
    OutputDebugStringA("---------------------------------------------------------------------------\n");

    Game::MainGame* game = new Game::MainGame;

    game->Run();

    return 0;
}

//------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------

namespace Game
{
    //------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------

    MainGame::MainGame()
    {
        pApp = new Game::App;
        pApp->InitialiseObjects();

        pApp->m_currentScreenID   = ScreenID::NoID;
        pApp->m_pCurrentScreen    = nullptr;
    }

    //------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------

    void MainGame::Run()
    {
        TraceFileFunc();

        pApp->SetRunning(true);
        pApp->m_pBaseRenderer->CreateGameWindow();
        pApp->m_pBaseRenderer->CreateCameras();

        GameLoop();
    }

    //------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------

    void MainGame::Update(float deltaTime)
    {
    }

    //------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------

    void MainGame::GameLoop()
    {
        TraceFileFunc();

        SetScene(pApp->m_pGameScene);

        sf::Clock clock;

        float accumulator       = 0;
        float frameTime         = 0;
        float targetFrameTime   = 1.0f / 60.0f;

        float fpsUpdateTimeAccumulator = 0;
        float fpsTime = 1.0f;
        float fps = 0;

        while (pApp->IsRunning())
        {
            frameTime = clock.restart().asSeconds();

            if (frameTime > targetFrameTime)
            {
                frameTime = targetFrameTime;
            }

            ProcessEvents();
             
            accumulator += frameTime;

            while(accumulator >= targetFrameTime)
            {
                accumulator -= targetFrameTime;

                UpdateCurrentScene(targetFrameTime);
            }

            // ---------------------------------------------------------
            // this is only for DISPLAYING the fps, not for calculations
            fpsUpdateTimeAccumulator += frameTime;
            
            if(fpsUpdateTimeAccumulator > fpsTime)
            {
                fpsUpdateTimeAccumulator = 0;
                fps = 1.f / frameTime;
            }
            // ---------------------------------------------------------

            // Render the current scene.
            // Also calls RenderWindow#Display to end the current
            // frame (internally swaps the front and back buffers)
            pApp->m_pBaseRenderer->Render();

            pFramework->Update();
        }

        pApp->m_pBaseRenderer->m_renderWindow.setActive(false);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void MainGame::UpdateCurrentScene(float deltaTime)
    {
        switch (pApp->m_currentScreenID)
        {
            case ScreenID::TitleScene:
                pApp->m_pTitleScene->Update(deltaTime);
                break;

            case ScreenID::GameScene:
                pApp->m_pGameScene->Update(deltaTime);
                break;

            default:
                break;
        }
    }

    //------------------------------------------------------------------------------------------------------
    // check all the window's events that were triggered
    // since the last iteration of the loop
    // -----------------------------------------------------------------------------------------------------

    void MainGame::ProcessEvents()
    {
        sf::Event event;

        while (pApp->m_pBaseRenderer->m_renderWindow.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::KeyPressed:
                {
                    pApp->m_pInputManager->OnKeyPressed(event.key.code);
                }
                break;

                case sf::Event::KeyReleased:
                {
                    pApp->m_pInputManager->OnKeyReleased(event.key.code);
                }
                break;

                case sf::Event::Resized:
                {
                    // TODO:
                }
                break;

                case sf::Event::Closed:
                {
                    pApp->SetRunning(false);
                }
                break;

                default:
                {
                    // No other events processed
                }
                break;
            }
        }
    }

    //------------------------------------------------------------------------------------------------------
    // -----------------------------------------------------------------------------------------------------

    void MainGame::SetScene(SceneBase *scr)
    {
        if (pApp->m_pCurrentScreen != nullptr)
        {
            pApp->m_pCurrentScreen->OnHide();
        }

        pApp->m_pCurrentScreen = scr;
        pApp->m_pCurrentScreen->OnShow();
    }
}


