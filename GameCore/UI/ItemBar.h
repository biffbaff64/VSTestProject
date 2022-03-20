#ifndef __ITEMBAR_H
#define __ITEMBAR_H

#include "SFML/Graphics.hpp"
#include "GDX/Maths/Vec2.h"
#include "SharedData/GlobalDefines.h"

namespace Game
{
    constexpr int BOOKS_PANEL       = 0;
    constexpr int POTIONS_PANEL     = 1;
    constexpr int RUNES_PANEL       = 2;
    constexpr int NUM_ITEM_PANELS   = 3;
    constexpr int NUM_PANEL_ITEMS   = 8;
    constexpr int ITEM_PANEL_X      = 374;
    constexpr int ITEM_PANEL_Y      = 588;
    constexpr int ITEM_PANEL_WIDTH  = 531;
    constexpr int ITEM_PANEL_HEIGHT = 115;

    class ItemBar
    {
    public:
        ItemBar();
        virtual ~ItemBar() = default;

        void CreatePanel();
        void UpdatePanel();
        void Reset();
        void DrawPanel();
        void SetPanelFrame(int frameNum);

        bool m_CollectItems[NUM_ITEM_PANELS][NUM_PANEL_ITEMS] = { false, };
        int m_itemPanelIndex;

    private:
        void DrawItems();
        void SetItemFrame(int index);

        const CoordsF displayPos[8] =
        {
            {  12, 44 },
            {  78, 44 },
            { 144, 44 },
            { 208, 44 },
            { 275, 44 },
            { 341, 44 },
            { 407, 44 },
            { 473, 44 },
        };

        sf::Texture m_itemPanelTexture;
        sf::Sprite  m_itemPanelSprite;

        // The sprites used to show the individual items
        // in the item bar
        sf::Sprite m_itemSprite[NUM_PANEL_ITEMS];

        // The textures to display when an item is collected
        sf::Texture m_itemTextures[NUM_ITEM_PANELS];

        // the textures to display when an item us not collected
        sf::Texture m_itemTexturesGrey[NUM_ITEM_PANELS];

        unsigned int m_itemFrameWidth;
        unsigned int m_itemFrameHeight;
    };
}

#endif // __ITEMBAR_H

