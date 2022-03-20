#ifndef SFMLTEST_WINDOWUTILS_H
#define SFMLTEST_WINDOWUTILS_H

#include "SFML/Graphics.hpp"

namespace Game
{
    class WindowUtils
    {
    public:
        WindowUtils() = default;
        ~WindowUtils() = default;

        [[nodiscard]] sf::FloatRect GetViewSpace() const;
    };
}

#endif //SFMLTEST_WINDOWUTILS_H
