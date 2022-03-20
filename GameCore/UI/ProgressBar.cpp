
//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Framework.h"
#include "SFML/Graphics.hpp"
#include "GDX/Utils/Trace.h"
#include "SharedData/GlobalDefines.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Graphics/BaseRenderer.h"
#include "Core/App.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "ProgressBar.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

namespace Game
{
	constexpr int DEFAULT_BAR_HEIGHT = 26;
	constexpr int DEFAULT_INTERVAL = 100;

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	ProgressBar::ProgressBar()
	{
		TraceFileFunc();

		SetMinMax(0, MAX_PROGRESSBAR_LENGTH);
		SetToMaximum();

		m_addInterval = DEFAULT_INTERVAL;
		m_subInterval = DEFAULT_INTERVAL;
		m_height = DEFAULT_BAR_HEIGHT;
		m_RefillAmount = MAX_PROGRESSBAR_LENGTH;
		m_justEmptied = false;
		m_isAutoRefilling = false;
		m_scale = 1.0f;
		m_speed = 1.0f;
		m_previousTotal = 0;
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	ProgressBar::ProgressBar(float speed, float size, float maxSize, const char* texture)
	{
		TraceFileFunc();

		SetMinMax(0, maxSize);

		m_Total = size;
		m_previousTotal = 0;
		m_height = DEFAULT_BAR_HEIGHT;
		m_RefillAmount = maxSize;
		m_justEmptied = false;
		m_isAutoRefilling = false;
		m_scale = 1.0f;
		m_speed = speed;
		m_addInterval = DEFAULT_INTERVAL;
		m_subInterval = DEFAULT_INTERVAL;

		if (m_texture.loadFromFile(texture))
		{
			trace->Dbg("Successfully loaded %s", texture);
		}
		else
		{
			trace->Dbg("WARNING! Failed to load %s", texture);

			m_texture.create((uint32_t) (m_Total * m_scale), m_height);
		}

		m_sprite = sf::Sprite(m_texture);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void ProgressBar::Update()
	{
		m_sprite.setTexture(m_texture);
		m_sprite.setTextureRect(sf::IntRect(0, 0, (int) (m_Total * m_scale), m_height));

		if (m_Total != m_previousTotal)
		{
			m_previousTotal = m_Total;
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void ProgressBar::Draw(int x, int y)
	{
		if (m_Total > 0)
		{
			Update();

			m_sprite.setPosition((float) x, (float) y);

			pApp->m_pBaseRenderer->m_renderWindow.draw(m_sprite);
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void ProgressBar::UpdateSlowDecrement()
	{
		m_justEmptied = false;

		if (m_Total > 0)
		{
			if (m_stopWatch.getElapsedTime().asMilliseconds() >= m_subInterval)
			{
				Sub(m_speed * pFramework->GetDeltaTime());

				m_justEmptied = (m_Total <= m_Minimum);

				m_stopWatch.restart();
			}
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void ProgressBar::UpdateSlowDecrementWithWrap()
	{
		UpdateSlowDecrement();

		if (m_justEmptied)
		{
			Refill(m_Maximum);

			m_justEmptied = false;
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void ProgressBar::SetColor(sf::Color color)
	{
		if (color != sf::Color::Transparent)
		{
			m_sprite.setColor(color);
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	bool ProgressBar::UpdateSlowIncrement()
	{
		return false;
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	bool ProgressBar::HasRefillRoom()
	{
		return (m_Total < (m_Maximum - m_speed));
	}
}
