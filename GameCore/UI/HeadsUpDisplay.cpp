//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include <iostream>
#include <stdarg.h>

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Engine.h"
#include "SharedData/GlobalDefines.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Graphics/GameResources.h"
#include "Maps/Room.h"
#include "Core/App.h"
#include "Graphics/BaseRenderer.h"

#include "HeadsUpDisplay.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

namespace Game
{
    // Table of x,y coordinates for items that are
    // drawn onto the HUD.
    const HeadsUpDisplay::DisplayPos hudDisplayPos =
    {
        {1000,  22},    // Coins total
        {1000,  64},    // Gems total
        {  75,  28},    // Life bar
        {  75,  70},    // Health bar
        { 820,  38},    // Villagers
        {1172,  25},    // Compass

        // Debug display positions
        {  40, 120},    // FPS
        {  40, 150},    // Delta Time
    };

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    HeadsUpDisplay::HeadsUpDisplay()
        :
        m_itemBar(),
        m_messageManager(),
        m_hudState(GameStates::StatePanelStart),
        m_hudOriginX(0),
        m_hudOriginY(0)
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void HeadsUpDisplay::CreateHud()
    {
        TraceFileFunc();

        pApp->m_pAppConfig->m_hud_exists = false;

        m_messageManager = MessageManager();

        LoadContent();
        LoadFonts();

        SetHudState(GameStates::StatePanelStart);

        pApp->m_pAppConfig->m_hud_exists = true;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void HeadsUpDisplay::Update()
    {
        switch (m_hudState)
        {
            case GameStates::StatePanelStart:
            {
                SetHudState(GameStates::StatePanelUpdate);
            }
            break;

            case GameStates::StatePanelUpdate:
            {
                if (m_buttonPause.IsPressed())
                {
                    pApp->m_pAppConfig->Pause();

                    m_buttonPause.Release();

                    m_hudState = GameStates::StatePaused;
                }
                else
                {
                    UpdateBars();
                    UpdateDeveloperItems();

                    m_itemBar->UpdatePanel();

                    // TODO: Update HUD Message handler
                    if (m_messageManager.m_isEnabled)
                    {
                    }
                }
            }
            break;

            case GameStates::StatePaused:
            {
                UpdateHudPauseMode();
            }
            break;

            default:
            {
                trace->FileFunc
                (
                    "ERROR: Illegal Hud State: %s",
                    pApp->m_pEnumData->GetActionStateName((int) m_hudState)
                );
            }
            break;
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void HeadsUpDisplay::UpdateBars()
    {
        m_healthBar.m_Total = pApp->GetEntity(pApp->GetPlayerIndex()).m_properties->m_strength;
        m_livesBar.m_Total = pApp->GetPlayerLives() * (MAX_PROGRESSBAR_LENGTH / MAX_LIVES);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void HeadsUpDisplay::UpdateDeveloperItems()
    {
        #ifdef HUD_DEMO_UPDATE
        if (m_stopWatch.getElapsedTime().asMilliseconds() >= 100)
        {
            pApp->m_pGameProgress->m_CoinCount.Add(10);
            pApp->m_pGameProgress->m_GemCount.Add(1);

            m_stopWatch.restart();
        }

        if (m_stopWatch2.getElapsedTime().asMilliseconds() >= 400)
        {
            pApp->m_pGameProgress->m_Lives.Sub(1, MAX_LIVES);

            m_stopWatch2.restart();
        }

        if (m_stopWatch3.getElapsedTime().asMilliseconds() >= 80)
        {
            if (--pApp->GetEntity(pApp->GetPlayerIndex()).m_properties->m_strength < 0)
            {
                pApp->GetEntity(pApp->GetPlayerIndex()).m_properties->m_strength = MAX_STRENGTH;
            }

            pApp->m_pGameProgress->m_Villagers.Add(1, MAX_VILLAGERS);

            m_stopWatch3.restart();
        }
        #endif
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void HeadsUpDisplay::UpdateHudPauseMode()
    {
        // TODO:
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void HeadsUpDisplay::Render()
    {
        if (pApp->m_pAppConfig->m_hud_exists)
        {
            DrawPanels();
            DrawItems();
            DrawCompass();
            DrawHudMessages();

            if (m_hudState == GameStates::StatePaused)
            {
                DrawPausePanel();
            }

            #if _DEBUG
            DrawHUDDebug();
            #endif
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void HeadsUpDisplay::SetHudState(GameStates state)
    {
        m_hudState = state;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    GameStates HeadsUpDisplay::GetHudState() const
    {
        return m_hudState;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    ProgressBar HeadsUpDisplay::GetHealthBar()
    {
        return m_healthBar;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    ProgressBar HeadsUpDisplay::GetLivesBar()
    {
        return m_livesBar;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    ItemBar* HeadsUpDisplay::GetItemBar()
    {
        return m_itemBar;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void HeadsUpDisplay::DrawPanels()
    {
        m_scorePanel.setPosition(0, 0);

        pApp->m_pBaseRenderer->m_renderWindow.draw(m_scorePanel, pApp->m_pBaseRenderer->m_renderStates);

        // Draw the panel(s) of collectable items
        m_itemBar->DrawPanel();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void HeadsUpDisplay::DrawItems()
    {
        m_healthBar.Draw(hudDisplayPos.health.x, hudDisplayPos.health.y);
        m_livesBar.Draw(hudDisplayPos.life.x, hudDisplayPos.life.y);

        m_midText.setFillColor(sf::Color::White);

        char coins[10];
        char gems[10];
        char villagers[10];

        sprintf_s(coins, "%08d", pApp->m_pGameProgress->m_CoinCount.m_Total);
        sprintf_s(gems, "%08d", pApp->m_pGameProgress->m_GemCount.m_Total);
        sprintf_s(villagers, "%03d", pApp->m_pGameProgress->m_Villagers.m_Total);

        m_midText.setString(coins);
        m_midText.setPosition(hudDisplayPos.coins.x, hudDisplayPos.coins.y);
        pApp->m_pBaseRenderer->m_renderWindow.draw(m_midText, pApp->m_pBaseRenderer->m_renderStates);

        m_midText.setString(gems);
        m_midText.setPosition(hudDisplayPos.gems.x, hudDisplayPos.gems.y);
        pApp->m_pBaseRenderer->m_renderWindow.draw(m_midText, pApp->m_pBaseRenderer->m_renderStates);

        m_bigText.setString(villagers);
        m_bigText.setPosition(hudDisplayPos.villagers.x, hudDisplayPos.villagers.y);
        pApp->m_pBaseRenderer->m_renderWindow.draw(m_bigText, pApp->m_pBaseRenderer->m_renderStates);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void HeadsUpDisplay::DrawCompass()
    {
        if (pApp->m_pRoomManager->HasExitAt(NORTH))
        {
            m_compassSprite[NORTH].setPosition(hudDisplayPos.compass.x, hudDisplayPos.compass.y);
            pApp->m_pBaseRenderer->m_renderWindow.draw(m_compassSprite[NORTH], pApp->m_pBaseRenderer->m_renderStates);
        }

        if (pApp->m_pRoomManager->HasExitAt(EAST))
        {
            m_compassSprite[EAST].setPosition(hudDisplayPos.compass.x, hudDisplayPos.compass.y);
            pApp->m_pBaseRenderer->m_renderWindow.draw(m_compassSprite[EAST], pApp->m_pBaseRenderer->m_renderStates);
        }

        if (pApp->m_pRoomManager->HasExitAt(SOUTH))
        {
            m_compassSprite[SOUTH].setPosition(hudDisplayPos.compass.x, hudDisplayPos.compass.y);
            pApp->m_pBaseRenderer->m_renderWindow.draw(m_compassSprite[SOUTH], pApp->m_pBaseRenderer->m_renderStates);
        }

        if (pApp->m_pRoomManager->HasExitAt(WEST))
        {
            m_compassSprite[WEST].setPosition(hudDisplayPos.compass.x, hudDisplayPos.compass.y);
            pApp->m_pBaseRenderer->m_renderWindow.draw(m_compassSprite[WEST], pApp->m_pBaseRenderer->m_renderStates);
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void HeadsUpDisplay::DrawHudMessages()
    {
        // TODO:
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void HeadsUpDisplay::DrawPausePanel()
    {
        // TODO:
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void HeadsUpDisplay::DrawHUDDebug()
    {
//        Write("FPS: %f", Vec2Int(hudDisplayPos.fps.x, hudDisplayPos.fps.y), GDX::pEngine->GetFPS());
//        Write("DELTA TIME: %f", Vec2Int(hudDisplayPos.delta.x, hudDisplayPos.delta.y), GDX::pEngine->GetDeltaTime());
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void HeadsUpDisplay::Write(const char* message, Vec2Int vec2, ...)
    {
        char output_string[256];
        va_list argList;

        va_start(argList, vec2);
        vsprintf_s(output_string, message, argList);
        va_end(argList);

        m_midText.setFillColor(sf::Color::White);
        m_midText.setString(output_string);
        m_midText.setPosition(vec2.m_x, vec2.m_y);

        pApp->m_pBaseRenderer->m_renderWindow.draw(m_midText, pApp->m_pBaseRenderer->m_renderStates);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void HeadsUpDisplay::RefillItems()
    {
        m_healthBar.SetToMaximum();
        m_livesBar.SetToMaximum();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void HeadsUpDisplay::LoadContent()
    {
        TraceFileFunc();

        m_ScorePanelTexture.loadFromFile(HUD_PANEL_ASSET);
        m_scorePanel = sf::Sprite(m_ScorePanelTexture);

        m_compassTexture.loadFromFile(COMPASS_ASSET);

        m_compassSprite[NORTH] = sf::Sprite(m_compassTexture);
        m_compassSprite[NORTH].setTextureRect(sf::IntRect(76, 0, 76, 76));

        m_compassSprite[EAST] = sf::Sprite(m_compassTexture);
        m_compassSprite[EAST].setTextureRect(sf::IntRect(152, 0, 76, 76));

        m_compassSprite[SOUTH] = sf::Sprite(m_compassTexture);
        m_compassSprite[SOUTH].setTextureRect(sf::IntRect(228, 0, 76, 76));

        m_compassSprite[WEST] = sf::Sprite(m_compassTexture);
        m_compassSprite[WEST].setTextureRect(sf::IntRect(304, 0, 76, 76));

        //
        // The player strength for the current life
        m_healthBar = ProgressBar(1, 0, MAX_PROGRESSBAR_LENGTH, GREEN_PROGRESS_BAR_ASSET);
        m_healthBar.m_height = 19.0f;
        m_healthBar.m_scale = 3.0f;

        // TODO: DESIGN DECISION
        // - Should the player have lives, are they still a thing? Should it, instead,
        // just keep resetting back to the last registered checkpoint?

        //
        // The number of lives the player has
        m_livesBar = ProgressBar(1, 0, MAX_PROGRESSBAR_LENGTH, RED_PROGRESS_BAR_ASSET);
        m_livesBar.m_height = 19.0f;
        m_livesBar.m_scale = 3.0f;

        m_itemBar = new ItemBar();
        m_itemBar->m_itemPanelIndex = BOOKS_PANEL;
        m_itemBar->CreatePanel();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void HeadsUpDisplay::LoadFonts()
    {
        TraceFileFunc();

        m_hudFont.loadFromFile("Assets/Fonts/Acme-Regular.ttf");

        m_bigText.setFont(m_hudFont);
        m_bigText.setCharacterSize(40);
        m_bigText.setStyle(sf::Text::Regular);

        m_midText.setFont(m_hudFont);
        m_midText.setCharacterSize(22);
        m_midText.setStyle(sf::Text::Regular);

        m_smallText.setFont(m_hudFont);
        m_smallText.setCharacterSize(15);
        m_smallText.setStyle(sf::Text::Regular);

    }
}
