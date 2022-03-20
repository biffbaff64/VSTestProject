#ifndef __NUMBERUTILS_H
#define __NUMBERUTILS_H

#include <string>

#include <SFML/System.hpp>
#include <SFML/Config.hpp>

namespace GDX
{
    class NumberUtils
    {
    public:

        NumberUtils() = default;
        ~NumberUtils() = default;

        [[nodiscard]] static int GetCount(int amount);

        [[nodiscard]] static void SetSeed(unsigned int Seed);
        [[nodiscard]] static unsigned int GetSeed();
        [[nodiscard]] static float Random(float Begin, float End);
        [[nodiscard]] static int Random(int Begin, int End);

    private:

        static unsigned int RandSeed;
    };
}

#endif // __NUMBERUTILS_H

