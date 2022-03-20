
#include <SFML/SFML.hpp>

#include "Graphics/GameResources.h"
#include "Graphics/BaseRenderer.h"
#include "Core/App.h"

#include "ItemBar.h"

namespace Game
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    ItemBar::ItemBar()
    {
        m_itemFrameWidth = 0;
        m_itemFrameHeight = 0;
        m_itemPanelIndex = BOOKS_PANEL;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void ItemBar::UpdatePanel()
    {
        if (pApp->m_pHud->m_buttonY.IsPressed())
        {
            m_itemPanelIndex = ((m_itemPanelIndex + 1) % NUM_ITEM_PANELS);
            SetPanelFrame(m_itemPanelIndex);

            for (int i = 0; i < NUM_PANEL_ITEMS; i++)
            {
                SetItemFrame(i);
            }

            pApp->m_pHud->m_buttonY.Release();
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void ItemBar::Reset()
    {
        m_itemPanelIndex = BOOKS_PANEL;

        for (auto& item : m_CollectItems)
        {
            *item = false;
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void ItemBar::DrawPanel()
    {
        m_itemPanelSprite.setPosition(ITEM_PANEL_X, ITEM_PANEL_Y);
        pApp->m_pBaseRenderer->m_renderWindow.draw(m_itemPanelSprite, pApp->m_pBaseRenderer->m_renderStates);

        DrawItems();
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void ItemBar::DrawItems()
    {
        for (int i = 0; i < NUM_PANEL_ITEMS; i++)
        {
            m_itemSprite[i].setPosition
            (
                m_itemPanelSprite.getPosition().x + displayPos[i].x,
                m_itemPanelSprite.getPosition().y + displayPos[i].y
            );
            pApp->m_pBaseRenderer->m_renderWindow.draw(m_itemSprite[i], pApp->m_pBaseRenderer->m_renderStates);
        }
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void ItemBar::SetPanelFrame(int frameNum)
    {
        m_itemPanelSprite.setTextureRect
        (
            sf::IntRect
            (
            0,
            (frameNum * ITEM_PANEL_HEIGHT),
            ITEM_PANEL_WIDTH,
            ITEM_PANEL_HEIGHT
        )
        );
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void ItemBar::SetItemFrame(int index)
    {
        if (m_CollectItems[m_itemPanelIndex][index])
        {
            m_itemSprite[index].setTexture(m_itemTextures[m_itemPanelIndex]);
        }
        else
        {
            m_itemSprite[index].setTexture(m_itemTexturesGrey[m_itemPanelIndex]);
        }

        m_itemSprite[index].setTextureRect
        (
            sf::IntRect((int) (index * m_itemFrameWidth), 0, (int) m_itemFrameWidth, (int) m_itemFrameHeight)
        );
        m_itemSprite[index].setScale(1.5f, 1.5f);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void ItemBar::CreatePanel()
    {
        Reset();

        if (m_itemPanelTexture.loadFromFile(ITEM_PANEL_ASSET))
        {
            m_itemPanelSprite = sf::Sprite(m_itemPanelTexture);
            SetPanelFrame(m_itemPanelIndex);
        }
        else
        {
            // TODO: load error here
        }

        m_itemTextures[BOOKS_PANEL].loadFromFile(ITEM_PANEL_BOOKS);
        m_itemTextures[POTIONS_PANEL].loadFromFile(ITEM_PANEL_POTIONS);
        m_itemTextures[RUNES_PANEL].loadFromFile(ITEM_PANEL_RUNES);

        m_itemTexturesGrey[BOOKS_PANEL].loadFromFile(ITEM_PANEL_BOOKS_GREY);
        m_itemTexturesGrey[POTIONS_PANEL].loadFromFile(ITEM_PANEL_POTIONS_GREY);
        m_itemTexturesGrey[RUNES_PANEL].loadFromFile(ITEM_PANEL_RUNES_GREY);

        m_itemFrameWidth = (m_itemTextures[0].getSize().x / NUM_PANEL_ITEMS);
        m_itemFrameHeight = m_itemTextures[0].getSize().y;

        for (int i = 0; i < NUM_PANEL_ITEMS; i++)
        {
            m_itemSprite[i] = sf::Sprite(m_itemTexturesGrey[m_itemPanelIndex]);
            SetItemFrame(i);
        }
    }
}

