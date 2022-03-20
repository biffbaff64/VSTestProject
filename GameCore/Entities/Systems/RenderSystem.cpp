//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Enums/GraphicID.h"
#include "SFML/Graphics.hpp"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Graphics/BaseRenderer.h"
#include "Graphics/Gfx.h"
#include "Core/App.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "RenderSystem.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

using namespace Enums;

namespace Game
{
	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------
	
	void RenderSystem::DrawSprites()
	{
		if (pApp->m_pEntityManager->IsEntityUpdateAllowed())
		{
			GDXSprite sprite;

			for (int z = MAXIMUM_Z_DEPTH - 1; z >= 0; z--)
			{
				for (int i = 0; i < pApp->m_pEntityManager->m_entityMap.size(); i++)
				{
					sprite = *pApp->m_pEntityManager->m_entityMap[i];

					if (sprite.m_zPosition == z)
					{
						if (sprite.IsDrawable())
						{
							sprite.Draw();

							#ifdef DRAW_SPRITE_BOXES
							DrawSpriteBox(sprite);
							#endif
						}
					}
				}
			}
		}
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	bool RenderSystem::IsInViewWindow(GDXSprite* sprite)
	{
		return false;
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	#ifdef DRAW_SPRITE_BOXES
	void RenderSystem::DrawSpriteBox(GDXSprite *sprite)
	{
		sf::RectangleShape rectangle;

		rectangle.setSize(sf::Vector2f(sprite.m_frameWidth, sprite.m_frameHeight));
		rectangle.setOutlineColor(sf::Color::Red);
		rectangle.setFillColor(sf::Color::Transparent);
		rectangle.setOutlineThickness(5);
		rectangle.setPosition(sprite.GetPosition().m_x, sprite.GetPosition().m_y);

		BaseRenderer::inst().m_renderWindow.draw(rectangle);
	}
	#endif
}

