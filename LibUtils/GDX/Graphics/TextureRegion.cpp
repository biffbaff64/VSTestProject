#include <math.h>

#include "../Utils/Trace.h"
#include "TextureRegion.h"

namespace GDX
{
	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	TextureRegion::TextureRegion()
		:
		m_texture(),
		m_regionWidth(0),
		m_regionHeight(0),
		m_u(0),
		m_u2(0),
		m_v(0),
		m_v2(0)
	{
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	TextureRegion::TextureRegion(const sf::Texture& texture)
	{
		m_texture		= sf::Texture(texture);
		m_regionWidth	= texture.getSize().x;
		m_regionHeight	= texture.getSize().y;
			
		setRegion(0, 0, texture.getSize().x, texture.getSize().y);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	TextureRegion::TextureRegion(const sf::Texture& texture, int width, int height)
	{
		m_texture		= sf::Texture(texture);
		m_regionWidth	= width;
		m_regionHeight	= height;
			
		setRegion(0, 0, width, height);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	TextureRegion::TextureRegion(const sf::Texture& texture, int x, int y, int width, int height)
	{
		m_texture		= sf::Texture(texture);
		m_regionWidth	= width;
		m_regionHeight	= height;

		setRegion(x, y, width, height);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	TextureRegion::TextureRegion(const TextureRegion& region)
	{
		m_texture		= sf::Texture(region.m_texture);
		m_regionWidth	= region.m_regionWidth;
		m_regionHeight	= region.m_regionHeight;

		setRegion(region);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void TextureRegion::setRegion(sf::Texture texture)
	{
		m_texture = texture;

		setRegion(0, 0, texture.getSize().x, texture.getSize().y);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void TextureRegion::setRegion(int x, int y, int width, int height)
	{
		float invTexWidth	= (1.0f / m_texture.getSize().x);
		float invTexHeight	= (1.0f / m_texture.getSize().y);

		setRegion((x * invTexWidth), (y * invTexHeight), ((x + width) * invTexWidth), ((y + height) * invTexHeight));

		m_regionWidth	= abs(width);
		m_regionHeight	= abs(height);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void TextureRegion::setRegion(float u, float v, float u2, float v2)
	{
		int texWidth	= m_texture.getSize().x;
		int texHeight	= m_texture.getSize().y;

		m_regionWidth	= round(abs(u2 - u) * texWidth);
		m_regionHeight	= round(abs(v2 - v) * texHeight);

		//
		// For a 1x1 region, adjust UVs toward pixel center to avoid filtering
		// artifacts on AMD GPUs when drawing very stretched.

		if ((m_regionWidth == 1) && (m_regionHeight == 1))
		{
			float adjustX = (0.25f / texWidth);
			u += adjustX;
			u2 -= adjustX;

			float adjustY = (0.25f / texHeight);
			v += adjustY;
			v2 -= adjustY;
		}

		m_u = u;
		m_v = v;
		m_u2 = u2;
		m_v2 = v2;
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void TextureRegion::setRegion(const TextureRegion& region)
	{
		m_texture = region.m_texture;

		setRegion(region.m_u, region.m_v, region.m_u2, region.m_v2);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void TextureRegion::setRegion(TextureRegion& region, int x, int y, int width, int height)
	{
		m_texture = region.m_texture;

		setRegion(region.getRegionX() + x, region.getRegionY() + y, width, height);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------
	void TextureRegion::split(int tileWidth, int tileHeight, std::string asset_name)
	{
		m_splitFrames.clear();

		int x = getRegionX();
		int y = getRegionY();

		int startx = x;
		int i = 0;

		const int rows = (m_regionHeight / tileHeight);
		const int cols = (m_regionWidth / tileWidth);

		for (int row = 0; row < rows; row++, y += tileHeight)
		{
			x = startx;

			for (int column = 0; column < cols; column++, x += tileWidth)
			{
				m_temp_texture.loadFromFile(asset_name, sf::IntRect(x, y, tileWidth, tileHeight));
				m_splitFrames.push_back(m_temp_texture);
			}
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	sf::Texture TextureRegion::getTexture()
	{
		return m_texture;
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	int TextureRegion::getRegionWidth()
	{
		return m_regionWidth;
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	int TextureRegion::getRegionHeight()
	{
		return m_regionHeight;
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	bool TextureRegion::isFlippedX()
	{
		return (m_u > m_u2);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	bool TextureRegion::isFlippedY()
	{
		return (m_v > m_v2);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void TextureRegion::setRegionWidth(int width)
	{
		if (isFlippedX())
		{
			setU(m_u2 + width / (float)m_texture.getSize().x);
		}
		else
		{
			setU2(m_u + width / (float)m_texture.getSize().x);
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void TextureRegion::setRegionHeight(int height)
	{
		if (isFlippedY())
		{
			setV(m_v2 + height / (float)m_texture.getSize().y);
		}
		else
		{
			setV2(m_v + height / (float)m_texture.getSize().y);
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	int TextureRegion::getRegionX()
	{
		return round(m_u * m_texture.getSize().x);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void TextureRegion::setRegionX(int x)
	{
		m_u = (x / (float)m_texture.getSize().x);
		m_regionWidth = round(abs(m_u2 - m_u) * m_texture.getSize().x);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	int TextureRegion::getRegionY()
	{
		return round(m_v * m_texture.getSize().y);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void TextureRegion::setRegionY(int y)
	{
		m_v = (y / (float)m_texture.getSize().y);
		m_regionHeight = round(abs(m_v2 - m_v) * m_texture.getSize().y);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void TextureRegion::setU(float u)
	{
		m_u = u;
		m_regionWidth = round(abs(m_u2 - u) * m_texture.getSize().x);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void TextureRegion::setU2(float u2)
	{
		m_u2 = u2;
		m_regionWidth = round(abs(u2 - m_u) * m_texture.getSize().x);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void TextureRegion::setV(float v)
	{
		m_v = v;
		m_regionHeight = round(abs(m_v2 - v) * m_texture.getSize().y);
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	void TextureRegion::setV2(float v2)
	{
		m_v2 = v2;
		m_regionHeight = round(abs(v2 - m_v) * m_texture.getSize().y);
	}
}