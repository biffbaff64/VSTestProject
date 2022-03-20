//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include <GDX/Graphics/Animation.h>

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "../Hero/MainPlayer.h"
#include "Core/App.h"
#include "Graphics/GameResources.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "PlayerManager.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

namespace Game
{
	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	PlayerManager::PlayerManager() : GenericEntityManager()
	{
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------
	
	void PlayerManager::Init()
	{
		if (m_activeCount == 0)
		{
			SetSpawnPoint();
			Create();
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void PlayerManager::Create()
	{
		if (m_activeCount == 0)
		{
			TraceFileFunc();

			pApp->m_pEntityManager->m_playerIndex = 0;
			pApp->m_pEntityManager->m_playerReady = false;

			pApp->m_pEntityManager->AddEntity(std::make_shared<MainPlayer>());
			pApp->m_pEntityManager->m_entityMap.at(0)->Initialise(m_descriptor);

			pApp->m_pEntityManager->UpdateIndexes();
			pApp->m_pEntityManager->m_playerIndex = m_descriptor.m_index;
			pApp->m_pEntityManager->m_playerReady = true;

			m_activeCount++;
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void PlayerManager::SetSpawnPoint()
	{
		TraceFileFunc();

		m_descriptor = pApp->m_pEntityUtils->GetDescriptor(GraphicID::Player);

		m_descriptor.m_size			= pApp->m_pEntityUtils->GetAssetSize(GraphicID::Player);
		m_descriptor.m_asset		= IDLE_DOWN_ASSET;
		m_descriptor.m_frames		= PLAYER_STAND_FRAMES;
		m_descriptor.m_playmode		= GDX::Animation::PlayMode::Loop;
		m_descriptor.m_position.m_x	= pApp->m_pRoomManager->GetStartPosition().m_x;
		m_descriptor.m_position.m_y	= pApp->m_pRoomManager->GetStartPosition().m_y;
		m_descriptor.m_position.m_z = pApp->m_pEntityUtils->GetInitialZPosition(GraphicID::Player);
	}
}

