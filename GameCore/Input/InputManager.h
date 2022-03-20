#ifndef __INPUT_MANAGER_H
#define __INPUT_MANAGER_H

#include <SFML/Window.hpp>

namespace Game
{
	class InputManager
	{
	public:
		InputManager() = default;
		~InputManager() = default;

		void OnKeyPressed(sf::Keyboard::Key key);
		void OnKeyReleased(sf::Keyboard::Key key);
	};
}

#endif // __INPUT_MANAGER_H
