#include "Enums/GameStates.h"
#include "Framework.h"

#include "Graphics/GameResources.h"
#include "Core/App.h"
#include "Gfx.h"

#include "BaseRenderer.h"

using namespace Enums;

namespace Game
{
	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void BaseRenderer::CreateCameras()
	{
		pApp->m_pAppConfig->m_cameras_ready = false;

		m_tiledCamera = OrthoGameCamera
		(
			"Tiled Camera",
			(float) Gfx::inst().m_viewWidth,
			(float) Gfx::inst().m_viewHeight
		);

		m_spriteCamera = OrthoGameCamera
		(
			"Sprite Camera",
			(float) Gfx::inst().m_viewWidth,
			(float) Gfx::inst().m_viewHeight
		);

		m_hudCamera = OrthoGameCamera
		(
			"HUD Camera",
			(float) Gfx::inst().m_hudWidth,
			(float) Gfx::inst().m_hudHeight
		);

		#ifdef USING_MINIMAP
		m_miniMap = OrthoGameCamera
		(
			"Mini Map Camera",
			72.0f,
			72.0f
		);
		m_miniMap.m_View.setViewport(sf::FloatRect(0.0f, 0.0f, 0.1f, 0.1f));
		m_miniMap.m_View.zoom(0.1f);
		#endif

		if (m_backgroundTexture.loadFromFile(FULL_MOON_SCENE_ASSET))
		{
			m_backgroundSprite = sf::Sprite(m_backgroundTexture);
		}
		else
		{
			// TODO: load error here
		}

		pApp->m_pAppConfig->m_cameras_ready = true;
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void BaseRenderer::BeginDraw()
	{
		m_renderWindow.clear(sf::Color::Black);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void BaseRenderer::Render()
	{
		BeginDraw();

		// See BaseRenderer.h
		#ifdef DEMO_SCROLL_ENABLED
		pApp->m_mapUtils.DemoScroll();
		#else
		if ((pApp->m_currentScreenID == Enums::ScreenID::GameScene)
			&& (pApp->m_pEntityManager->m_entityMap.size() > 0))
		{
			pApp->m_pMapUtils->PositionAt
			(
				(int) pApp->m_pEntityManager->m_entityMap[0]->GetPosition().m_x,
				(int) pApp->m_pEntityManager->m_entityMap[0]->GetPosition().m_y
			);
		}
		else
		{
			pApp->m_pMapUtils->PositionAt(0, 0);
		}
		#endif

		DrawBackground();
		DrawTiledMap();
		DrawSprites();
		DrawHUD();

		#ifdef USING_MINIMAP
		DrawMiniMap();
		#endif

		EndDraw();
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void BaseRenderer::EndDraw()
	{
		m_renderWindow.display();
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void BaseRenderer::DrawBackground()
	{
		if (m_canDrawBackground)
		{
			m_backgroundSprite.setPosition(0, 0);
			m_renderWindow.draw(m_backgroundSprite, m_renderStates);
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void BaseRenderer::DrawTiledMap()
	{
		if (m_tiledCamera.m_isInUse)
		{
			m_tiledCamera.SetViewCentre
			(
				(float) pApp->m_pMapData->m_mapPosition.m_x,
				(float) pApp->m_pMapData->m_mapPosition.m_y
			);

			m_renderWindow.setView(m_tiledCamera.m_view);
			pApp->m_pMapData->Render();
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void BaseRenderer::DrawSprites()
	{
		if (m_spriteCamera.m_isInUse)
		{
			m_spriteCamera.SetViewCentre
			(
				(float) pApp->m_pMapData->m_mapPosition.m_x,
				(float) pApp->m_pMapData->m_mapPosition.m_y
			);

			m_renderWindow.setView(m_spriteCamera.m_view);

			WorldRenderer();
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void BaseRenderer::DrawHUD()
	{
		if (m_hudCamera.m_isInUse)
		{
			m_hudCamera.SetViewCentre
			(
				(float) Gfx::inst().m_hudWidth / 2,
				(float) Gfx::inst().m_hudHeight / 2
			);

			m_renderWindow.setView(m_hudCamera.m_view);

			HudRenderer();
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	#ifdef USING_MINIMAP
	void BaseRenderer::DrawMiniMap()
	{
		if (m_miniMap.m_isInUse)
		{
			m_miniMap.SetViewCentre(692, 27);

			m_renderWindow.setView(m_miniMap.m_View);

			app->m_mapData.Render();
		}
	}
	#endif

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	// TODO: Investigate merging WorldRenderer() and HudRenderer()
	void BaseRenderer::HudRenderer()
	{
		if (!pApp->m_pAppConfig->m_shutdown_active)
		{
			switch (Gdx->m_pAppState->Get())
			{
				case GameStates::StateGetReady:
				case GameStates::StatePaused:
				case GameStates::StateLevelFinished:
				case GameStates::StateLevelRetry:
				case GameStates::StateGame:
				case GameStates::StateMessagePanel:
				case GameStates::StateDebugHang:
				case GameStates::StateGameOver:
				case GameStates::StateGameFinished:
				{
					if (pApp->m_pAppConfig->m_hud_exists)
					{
						pApp->m_pHud->Render();
					}
				}
				break;

				case GameStates::StateClosing:
				default:
				{
					// TODO:
				}
				break;
			}
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void BaseRenderer::WorldRenderer()
	{
		if (!pApp->m_pAppConfig->m_shutdown_active)
		{
			switch (Gdx->m_pAppState->Get())
			{
				case GameStates::StateSetup:
				case GameStates::StateGetReady:
				case GameStates::StatePaused:
				case GameStates::StateLevelRetry:
				case GameStates::StateLevelFinished:
				case GameStates::StateGame:
				case GameStates::StateSettingsPanel:
				case GameStates::StateDebugHang:
				{
					pApp->m_pGameScene->Draw();
				}
				break;

				case GameStates::StateMainMenu:
				case GameStates::StateClosing:
				case GameStates::StateGameOver:
				case GameStates::StateEndGame:
				default:
				{
					// TODO:
				}
				break;
			}
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void BaseRenderer::CreateGameWindow()
	{
		sf::ContextSettings settings;

		settings.depthBits			= 24;
		settings.stencilBits		= 8;
		settings.antialiasingLevel	= 4;
		settings.majorVersion		= 3;
		settings.minorVersion		= 0;
		settings.attributeFlags		= sf::ContextSettings::Attribute::Default;

		m_renderWindow.create
		(
			sf::VideoMode
			(
				Gfx::inst().m_DesktopWidth,
				Gfx::inst().m_desktopHeight,
				Gfx::inst().m_pixelsPerMetre
			),
			"SFML Test",
			#if _DEBUG
			sf::Style::Default,
			#else
			sf::Style::Fullscreen,
			#endif
			settings
		);

		m_renderWindow.setVerticalSyncEnabled(false);
		m_renderWindow.setFramerateLimit(60);
		m_renderWindow.setActive(true);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void BaseRenderer::ResetCameraZoom()
	{
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void BaseRenderer::EnableAllCameras()
	{
		m_tiledCamera.m_isInUse = true;
		m_spriteCamera.m_isInUse = true;
		m_hudCamera.m_isInUse = true;

		#ifdef USING_MINIMAP
		m_miniMap.m_isInUse = true;
		#endif
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void BaseRenderer::DisableAllCameras()
	{
		m_tiledCamera.m_isInUse = false;
		m_spriteCamera.m_isInUse = false;
		m_hudCamera.m_isInUse = false;

		#ifdef USING_MINIMAP
		m_miniMap.m_isInUse = false;
		#endif
	}
}
