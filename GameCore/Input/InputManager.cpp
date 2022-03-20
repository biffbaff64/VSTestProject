//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#pragma warning( push )
#pragma warning( disable : 26812 )

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Core/App.h"
#include "InputManager.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

namespace Game
{
	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void InputManager::OnKeyPressed(sf::Keyboard::Key keycode)
	{
		switch (keycode)
		{
			case sf::Keyboard::A:
				pApp->m_pHud->m_buttonA.Press();
				break;

			case sf::Keyboard::B:
				pApp->m_pHud->m_buttonB.Press();
				break;

			case sf::Keyboard::X:
				pApp->m_pHud->m_buttonX.Press();
				break;

			case sf::Keyboard::Y:
				pApp->m_pHud->m_buttonY.Press();
				break;

				#ifdef _DEBUG
			case sf::Keyboard::Up:
				break;

			case sf::Keyboard::Down:
				break;
				#endif // DEBUG

			default:
				// Unused key pressed
				break;
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void InputManager::OnKeyReleased(sf::Keyboard::Key keycode)
	{
		switch (keycode)
		{
			case sf::Keyboard::A:
				pApp->m_pHud->m_buttonA.Release();
				break;

			case sf::Keyboard::B:
				pApp->m_pHud->m_buttonB.Release();
				break;

			case sf::Keyboard::X:
				pApp->m_pHud->m_buttonX.Release();
				break;

			case sf::Keyboard::Y:
				pApp->m_pHud->m_buttonY.Release();
				break;

				#ifdef _DEBUG
			case sf::Keyboard::Up:
				break;

			case sf::Keyboard::Down:
				break;
				#endif // DEBUG

			default:
				// Unused key pressed
				break;
		}
	}
}

#pragma warning( pop )

