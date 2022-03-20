#ifndef __PROGRESSBAR_H
#define __PROGRESSBAR_H

#include <string>

#include "SFML/Graphics.hpp"
#include "GDX/Maths/ItemF.h"

namespace Game
{
    class ProgressBar : public GDX::ItemF
    {
    public:
        ProgressBar();
        ProgressBar(float speed, float size, float maxSize, const char* texture);
        virtual ~ProgressBar() = default;

        void Draw(int x, int y);
        void UpdateSlowDecrement();
        void UpdateSlowDecrementWithWrap();
        void SetColor(sf::Color color);
        bool UpdateSlowIncrement();
        bool HasRefillRoom();

        bool m_justEmptied;
        bool m_isAutoRefilling;

        int m_addInterval;
        int m_subInterval;
        int m_height;
        float m_speed;
        float m_scale;

    private:
        void Update();

        sf::Texture m_texture;
        sf::Sprite  m_sprite;
        sf::Clock m_stopWatch;

        float m_previousTotal;
    };
}

#endif // __PROGRESSBAR_H

