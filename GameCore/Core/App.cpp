//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "App.h"

namespace Game
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    App* pApp;

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    App::App()
    {
        m_pEnumData             = new EnumData;
        m_pBaseRenderer         = new BaseRenderer;
        m_pGameSceneManager     = new GameSceneManager;
        m_pTitleScene           = new TitleScene;
        m_pGameScene            = new GameScene;
        m_pGameProgress         = new GameProgress;
        m_pEntityManager        = new EntityManager;
        m_pHud                  = new HeadsUpDisplay;
        m_pInputManager         = new InputManager;
        m_pAppConfig            = new AppConfig;
        m_pRoomManager          = new RoomManager;
        m_pMapData              = new MapData;
        m_pMapUtils             = new MapUtils;
        m_pMapCreator           = new MapCreator;
        m_pEntityUtils          = new EntityUtils;
        m_pAABB                 = new BoxCollision;

        m_currentScreenID   = ScreenID::NoID;
        m_pCurrentScreen    = nullptr;

        m_isRunning         = false;
        m_isDevMode         = false;
        m_isDevPanelActive  = false;
        m_isGodMode         = false;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void App::InitialiseObjects()
    {
        trace->Init(LOG_CONSOLE);

        #ifdef USING_STARFIELD
        m_pStarField = new StarField;
        m_pStarField->Setup();
        #endif

        // ----------------------------
        // Developer Flags
        m_isDevPanelActive = false;
        m_isDevMode = false;
        m_isGodMode = false;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    GDXSprite& App::GetPlayer() const
    {
        return *m_pEntityManager->m_entityMap.at(m_pEntityManager->m_playerIndex);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    int App::GetPlayerLives() const
    {
        return m_pGameProgress->m_Lives.m_Total;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    int App::GetPlayerIndex() const
    {
        return m_pEntityManager->m_playerIndex;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    GDXSprite& App::GetEntity(int index) const
    {
        return *m_pEntityManager->m_entityMap.at(index);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void App::SetRunning(bool state)
    {
        m_isRunning = state;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    bool App::IsRunning() const
    {
        return m_isRunning;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    App::~App()
    {
        delete m_pEnumData;
        delete m_pBaseRenderer;
        delete m_pGameSceneManager;
        delete m_pTitleScene;
        delete m_pGameScene;
        delete m_pGameProgress;
        delete m_pEntityManager;
        delete m_pHud;
        delete m_pInputManager;
        delete m_pAppConfig;
        delete m_pRoomManager;
        delete m_pMapData;
        delete m_pMapUtils;
        delete m_pMapCreator;
        delete m_pEntityUtils;
        delete m_pAABB;

        #ifdef USING_STARFIELD
        delete m_pStarField;
        #endif

        delete Gdx->m_pAppState;
        delete Gdx->m_pTextureManager;
    }
}

