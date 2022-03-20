//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Application.h"
#include "GameStates.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Core/App.h"
#include "AppConfig.h"

namespace Game
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    AppConfig::AppConfig()
        :
        m_quit_to_main_menu(false),
        m_force_quit_to_menu(false),
        m_game_paused(false),
        m_cameras_ready(false),
        m_shutdown_active(false),
        m_entities_exist(false),
        m_hud_exists(false),
        m_controllers_fitted(false)
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void AppConfig::Pause()
    {
        m_game_paused = true;

        Gdx->m_pAppState->Set(GameStates::StatePaused);
        pApp->m_pHud->SetHudState(GameStates::StatePaused);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void AppConfig::UnPause()
    {
        m_game_paused = false;

        Gdx->m_pAppState->Set(GameStates::StateGame);
        pApp->m_pHud->SetHudState(GameStates::StatePanelUpdate);
    }
}

