#ifndef SFMLTEST_STARFIELD_H
#define SFMLTEST_STARFIELD_H

#include <vector>

#include "StarObject.h"

namespace Game
{
#define STAR_SPEED      90.0f
#define MAX_STARS       5//000

    class StarField
    {
    public:
        StarField();
        ~StarField() = default;

        void Setup();
        void Render();

        bool        m_isEnabled;
        sf::Texture m_texture;

    private:
        StarObject m_stars[MAX_STARS];
    };
}

#endif //SFMLTEST_STARFIELD_H
