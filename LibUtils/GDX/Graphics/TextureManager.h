#ifndef __TEXTURE_MANAGER_H
#define __TEXTURE_MANAGER_H

#include <vector>
#include "SFML/Graphics.hpp"

namespace GDX
{
	class TextureManager
	{
	public:
		TextureManager() = default;
		~TextureManager() = default;

		void AddTexture(const char * imageName);

		[[nodiscard]] const sf::Texture& GetTexture(int index);

		std::vector<sf::Texture> m_textureList;
	};
}

#endif // __TEXTURE_MANAGER_H
