#ifndef __TEXTUREREGION_H
#define __TEXTUREREGION_H

#include <vector>
#include <string>

#include "SFML/Graphics.hpp"

namespace GDX
{
	class TextureRegion
	{
	public:
		TextureRegion();
		TextureRegion(const sf::Texture& texture);
		TextureRegion(const sf::Texture& texture, int width, int height);
		TextureRegion(const sf::Texture& texture, int x, int y, int width, int height);
		TextureRegion(const TextureRegion& region);

		void setRegion(sf::Texture texture);
		void setRegion(int x, int y, int width, int height);
		void setRegion(float u, float v, float u2, float v2);
		void setRegion(const TextureRegion& region);
		void setRegion(TextureRegion& region, int x, int y, int width, int height);
		void setRegionX(int x);
		void setRegionY(int y);
		void setRegionWidth(int width);
		void setRegionHeight(int height);

		void split(int tileWidth, int tileHeight, std::string asset_name);

		[[nodiscard]] sf::Texture getTexture();
		[[nodiscard]] int getRegionWidth();
		[[nodiscard]] int getRegionHeight();
		[[nodiscard]] int getRegionX();
		[[nodiscard]] int getRegionY();
		[[nodiscard]] bool isFlippedX();
		[[nodiscard]] bool isFlippedY();

		std::vector<sf::Texture> m_splitFrames;

	protected:
		sf::Texture m_texture;
		sf::Texture m_temp_texture;

		int		m_regionWidth;
		int		m_regionHeight;
		float	m_u;
		float	m_u2;
		float	m_v;
		float	m_v2;

	private:
		void setU(float u);
		void setU2(float u2);
		void setV(float v);
		void setV2(float v2);
	};
}

#endif // __TEXTUREREGION_H
