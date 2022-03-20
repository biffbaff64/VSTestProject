
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Enums/GraphicID.h"
#include "GDX/Maths/NumberUtils.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Graphics/GameResources.h"
#include "Core/App.h"
#include "Entities/EntityUtils.h"
#include "Entities/EntityStats.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "ManagerUtils.h"
#include "DecorationsManager.h"

namespace Game
{
	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	// (1.0f / 6.0f) == 0.166666667f

	const AnimSpeed decorationsList[] =
	{
		{ Enums::GraphicID::AlcoveTorch,	(0.05f / 6.0f) },
		{ Enums::GraphicID::Anvil,			(1.0f / 6.0f) },	
		{ Enums::GraphicID::Barrel,			(1.0f / 6.0f) },
		{ Enums::GraphicID::Crate,			(1.0f / 6.0f) },
		{ Enums::GraphicID::GlowEyes,		(0.5f / 6.0f) },
		{ Enums::GraphicID::Hammers,		(1.0f / 6.0f) },
		{ Enums::GraphicID::PlantPot,		(1.0f / 6.0f) },
		{ Enums::GraphicID::Pot,			(1.0f / 6.0f) },
		{ Enums::GraphicID::PotStand,		(1.0f / 6.0f) },
		{ Enums::GraphicID::WagonWheel,		(1.0f / 6.0f) },
	};

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	DecorationsManager::DecorationsManager()
	{
		m_maxActiveCount = 0;
		m_activeCount = 0;
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void DecorationsManager::Init()
	{
		Create();
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void DecorationsManager::Create()
	{
		if ((m_activeCount == 0) && (m_maxActiveCount == 0))
		{
			TraceFileFunc();

			ManagerUtils managerUtils;

			for (AnimSpeed item : decorationsList)
			{
				std::vector<SpriteDescriptor> tiles = managerUtils.GetDescriptorList(item.m_graphicID);

				if (tiles.size() > 0)
				{
					for (SpriteDescriptor descriptor : tiles)
					{
						descriptor.m_asset		= CheckAssetName(descriptor);
						descriptor.m_anim_rate	= item.m_speed;

						int index = pApp->m_pEntityManager->m_entityMap.size();

						pApp->m_pEntityManager->m_entityMap.push_back(std::make_shared<Decoration>(descriptor.m_gid));

						pApp->m_pEntityManager->m_entityMap[index]->Initialise(descriptor);

						EntityStats::Log(descriptor.m_gid);

						m_activeCount++;
					}
				}
			}
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	std::string DecorationsManager::CheckAssetName(const SpriteDescriptor& descriptor)
	{
		const char* barrels[] =
		{
			BARREL_1_ASSET,
			BARREL_2_ASSET,
			BARREL_3_ASSET,
			BARREL_4_ASSET
		};

		const char* pots[] =
		{
			POT_1_ASSET,
			POT_2_ASSET,
			POT_3_ASSET,
			POT_4_ASSET,
		};

		constexpr int NUM_BARRELS	= (sizeof(barrels) / sizeof(char*));
		constexpr int NUM_POTS		= (sizeof(pots) / sizeof(char*));

		char asset[256] = { '\0' };
		int index;

		if (descriptor.m_gid == GraphicID::Barrel)
		{
			index = NumberUtils::Random(0, NUM_BARRELS - 1);

			strcpy_s(asset, barrels[index]);
		}
		else if (descriptor.m_gid == GraphicID::Pot)
		{
			index = NumberUtils::Random(0, NUM_POTS - 1);

			strcpy_s(asset, pots[index]);
		}
		else
		{
			strcpy_s(asset, descriptor.m_asset.c_str());
		}

		std::string str(asset);

		return str;
	}
}

