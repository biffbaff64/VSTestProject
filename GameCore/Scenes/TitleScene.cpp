#include "Graphics/GameResources.h"
#include "Graphics/BaseRenderer.h"
#include "Core/App.h"

#include "TitleScene.h"

namespace Game
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void TitleScene::OnCreate()
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void TitleScene::Initialise()
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void TitleScene::Update(float delta)
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void TitleScene::Draw()
    {
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void TitleScene::OnShow()
    {
        TraceFileFunc();

        LoadContent();

        Initialise();

        pApp->m_pBaseRenderer->m_canDrawBackground = false;
        pApp->m_pBaseRenderer->m_tiledCamera.m_isInUse = false;
        pApp->m_pBaseRenderer->m_spriteCamera.m_isInUse = false;
        pApp->m_pBaseRenderer->m_hudCamera.m_isInUse = true;

        pApp->m_currentScreenID = Enums::ScreenID::TitleScene;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void TitleScene::OnHide()
    {
        TraceFileFunc();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void TitleScene::LoadContent()
    {
        m_backgroundImage.loadFromFile(TITLE_SCENE_BACKGROUND);
        m_overlay1.loadFromFile(TITLE_OVERLAY1);
        m_overlay2.loadFromFile(TITLE_OVERLAY2);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void TitleScene::OnDestroy()
    {
    }
}



