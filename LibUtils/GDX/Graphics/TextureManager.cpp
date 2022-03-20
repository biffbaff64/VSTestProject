#include "TextureManager.h"

namespace GDX
{
	void TextureManager::AddTexture(const char * imageName)
	{
		m_textureList.push_back(sf::Texture());
	}

	const sf::Texture& TextureManager::GetTexture(int index)
	{
		return m_textureList[index];
	}
}