#ifndef __APP_H
#define __APP_H

#include <chrono>

#include <Types.h>
#include <Translations.h>

#include <Application.h>

#include "GDX/Graphics/TextureManager.h"
#include "GDX/Physics/CollisionUtils.h"
#include "GDX/Utils/StateManager.h"
#include "GDX/Utils/Trace.h"

#include "Config/AppConfig.h"
#include "Core/GameLevelManager.h"
#include "Entities/EntityManager.h"
#include "Entities/EntityUtils.h"
#include "Entities/Hero/MainPlayer.h"
#include "Graphics/StarField.h"
#include "Graphics/BaseRenderer.h"
#include "Input/InputManager.h"
#include "Maps/MapData.h"
#include "Maps/MapUtils.h"
#include "Maps/RoomManager.h"
#include "Maps/MapCreator.h"
#include "Physics/BoxCollision.h"
#include "Scenes/SceneBase.h"
#include "Scenes/TitleScene.h"
#include "Scenes/GameScene.h"
#include "UI/HeadsUpDisplay.h"

#include "GameProgress.h"

namespace Game
{
    class App : public Application
    {
    public:
        App();
        ~App();

        virtual void InitialiseObjects();
        void SetRunning(bool state);

        [[nodiscard]] int GetPlayerLives() const;
        [[nodiscard]] int GetPlayerIndex() const;
        [[nodiscard]] GDXSprite &GetEntity(int index) const;
        [[nodiscard]] GDXSprite &GetPlayer() const;
        [[nodiscard]] bool IsRunning() const;

        EnumData            *m_pEnumData;
        BaseRenderer        *m_pBaseRenderer;
        GameSceneManager    *m_pGameSceneManager;
        TitleScene          *m_pTitleScene;
        GameScene           *m_pGameScene;
        GameProgress        *m_pGameProgress;
        EntityManager       *m_pEntityManager;
        HeadsUpDisplay      *m_pHud;
        InputManager        *m_pInputManager;
        AppConfig           *m_pAppConfig;
        RoomManager         *m_pRoomManager;
        MapData             *m_pMapData;
        MapUtils            *m_pMapUtils;
        MapCreator          *m_pMapCreator;
        EntityUtils         *m_pEntityUtils;
        BoxCollision        *m_pAABB;

        ScreenID    m_currentScreenID;
        SceneBase   *m_pCurrentScreen;

        #ifdef USING_STARFIELD
        StarField *m_pStarField;
        #endif

        bool m_isGodMode;
        bool m_isDevMode;
        bool m_isDevPanelActive;

    private:
        bool m_isRunning;
    };

    extern App* pApp;
}

#endif // __APP_H

