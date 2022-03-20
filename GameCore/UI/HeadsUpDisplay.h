#ifndef __HEADSUPDISPLAY_H
#define __HEADSUPDISPLAY_H

#include "SFML/Graphics.hpp"
#include "GDX/Input/Switch.h"
#include "GDX/Maths/Vec2.h"
#include "Enums/GameStates.h"
#include "SharedData/GlobalDefines.h"

#include "MessageManager.h"
#include "ProgressBar.h"
#include "ItemBar.h"

#define HUD_DEMO_UPDATE

using namespace Enums;
using namespace GDX;

namespace Game
{
    class HeadsUpDisplay
    {
    public:
        HeadsUpDisplay();
        ~HeadsUpDisplay() = default;

        void CreateHud();
        void Update();
        void Render();

        void RefillItems();
        void SetHudState(GameStates state);

        [[nodiscard]] GameStates    GetHudState() const;
        [[nodiscard]] ProgressBar   GetHealthBar();
        [[nodiscard]] ProgressBar   GetLivesBar();
        [[nodiscard]] ItemBar       *GetItemBar();

        Switch m_buttonUp;
        Switch m_buttonDown;
        Switch m_buttonLeft;
        Switch m_buttonRight;
        Switch m_buttonPause;
        Switch m_buttonA;
        Switch m_buttonB;
        Switch m_buttonX;
        Switch m_buttonY;

        int m_hudOriginX;
        int m_hudOriginY;

        typedef struct
        {
            Coords coins;
            Coords gems;
            Coords life;
            Coords health;
            Coords villagers;
            Coords compass;

            // Debug display positions
            Coords fps;
            Coords delta;
        }
        DisplayPos;

    private:
        void DrawPanels();
        void DrawItems();
        void DrawCompass();
        void DrawHudMessages();
        void DrawPausePanel();
        void DrawHUDDebug();
        void Write(const char* message, Vec2Int vec2, ...);

        void UpdateBars();
        void UpdateDeveloperItems();
        void UpdateHudPauseMode();

        void LoadContent();
        void LoadFonts();

        ItemBar         *m_itemBar;
        MessageManager  m_messageManager;
        ProgressBar     m_healthBar;
        ProgressBar     m_livesBar;
        GameStates      m_hudState;

        #ifdef HUD_DEMO_UPDATE
        sf::Clock m_stopWatch;
        sf::Clock m_stopWatch2;
        sf::Clock m_stopWatch3;
        #endif

        sf::Font m_hudFont;
        sf::Text m_smallText;
        sf::Text m_midText;
        sf::Text m_bigText;

        sf::Texture     m_ScorePanelTexture;
        sf::Sprite      m_scorePanel;
        sf::Texture     m_compassTexture;
        sf::Sprite      m_compassSprite[4];
    };
}

#endif // __HEADSUPDISPLAY_H

