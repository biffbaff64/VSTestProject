
#include "Enums/Translations.h"
#include "Framework.h"
#include "GDX/Physics/CollisionUtils.h"

#include "Core/App.h"
#include "Graphics/Gfx.h"
#include "EntityManager.h"

namespace Game
{
	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	EntityManager::EntityManager()
		:
		m_playerIndex(0),
		m_playerReady(false)
	{
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void EntityManager::Initialise()
	{
		TraceFileFunc();

		m_playerManager			= PlayerManager();
		m_decorationsManager	= DecorationsManager();
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void EntityManager::InitialiseManagerList()
	{
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void EntityManager::InitialiseForLevel()
	{
		TraceFileFunc();

		m_playerManager.Init();
		m_decorationsManager.Init();

		UpdateIndexes();
		EstablishLinks();

		pApp->m_pAppConfig->m_entities_exist = true;
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void EntityManager::UpdateSprites()
	{
		if (IsEntityUpdateAllowed() && !pApp->m_pAppConfig->m_game_paused)
		{
			EnumData enumData;

			//
			// Update all non-player entities.
			for (auto & i : m_entityMap)
			{
				if ((i->m_entityAction != ActionStates::Dead)
					&& (i->m_gid != GraphicID::Player))
				{
					i->Update();
				}
			}

			//
			// Main Player, updated after all other entities.
			// Updated last to allow for possible reacting to
			// other entities actions.
			if (m_playerReady && (m_entityMap[m_playerIndex]->m_entityAction != ActionStates::Dead))
			{
				m_entityMap[m_playerIndex]->Update();
			}

			//
			// Update the various entity managers. These updates will check
			// to see if any entities need re-spawning etc.
			if (!pApp->m_pGameProgress->m_levelCompleted)
			{
				for (auto & i : m_managerList)
				{
					i->Update();
				}
			}
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void EntityManager::DrawSprites()
	{
		m_renderSystem.DrawSprites();
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void EntityManager::TidySprites()
	{
		for (size_t i = 0; i < (int)m_entityMap.size(); i++)
		{
			if (m_entityMap[i]->m_entityAction == ActionStates::Dead)
			{
				if (m_entityMap[i]->m_gid == GraphicID::Player)
				{
				}
				else
				{
					if (m_entityMap[i]->m_gid != GraphicID::NoID)
					{
						m_entityMap[i]->m_collisionObject->Kill();

						pApp->m_pEntityUtils->RemoveEntity(i);

						// TODO:
						// At this point the sprite has been removed from the entity map,
						// but the actual object still exists.
						// Check the best way to fix this.
					}
				}
			}
		}

		Gdx->m_pCollisionUtils->Tidy();
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	size_t EntityManager::AddEntity(std::shared_ptr<GDXSprite>&& sprite)
	{
		size_t index = m_entityMap.size();

		m_entityMap.push_back( std::move(sprite));

		return index;
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	int EntityManager::AddManager(GenericEntityManager *manager)
	{
		return 0;
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void EntityManager::RemoveEntity(int index)
	{
		m_entityMap.erase(m_entityMap.begin() + index);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void EntityManager::ReleaseEntity(const GDXSprite& gdxSprite)
	{
		// TODO:
	}

	//------------------------------------------------------------------------------------------------------
	// Update the indexes into the entity map
	// for the main entities.
	//------------------------------------------------------------------------------------------------------

	void EntityManager::UpdateIndexes()
	{
		m_playerIndex = 0;

		for (size_t i = 0; i < (int)m_entityMap.size(); i++)
		{
			if (m_entityMap[i]->m_gid == Enums::GraphicID::Player)
			{
				m_playerIndex = i;
			}
		}
	}

	//------------------------------------------------------------------------------------------------------
	// Establish links between relevant entities.
	//------------------------------------------------------------------------------------------------------

	void EntityManager::EstablishLinks()
	{
		for (size_t i = 0; i < (int)m_entityMap.size(); i++)
		{
			GDXSprite gdxSprite = *m_entityMap[i];

			if (m_entityMap[i]->m_properties->m_isLinked)
			{
				for (size_t j = 0; j < (int)m_entityMap.size(); j++)
				{
					GDXSprite sprite = *m_entityMap[j];

					if ((sprite.m_spriteNumber != gdxSprite.m_spriteNumber)
						&& (sprite.m_properties->m_link == gdxSprite.m_properties->m_link))
					{
						sprite.m_properties->m_link = gdxSprite.m_spriteNumber;
						gdxSprite.m_properties->m_link = sprite.m_spriteNumber;
					}
				}
			}
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	bool EntityManager::IsEntityUpdateAllowed()
	{
		return (pApp->m_pAppConfig->m_entities_exist && !pApp->m_pAppConfig->m_quit_to_main_menu);
	}
}

