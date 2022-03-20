
#include <cstdlib>
#include <random>
#include <time.h>

#include "NumberUtils.h"

namespace
{
    // Set the random numbers sequence seed with the
    // current system time, so that it is always different
    unsigned int SetRandomSeed()
    {
        unsigned int Seed = static_cast<unsigned int>(time(NULL));

        srand(Seed);
        return Seed;
    }
}

namespace GDX
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    unsigned int NumberUtils::RandSeed = SetRandomSeed();

    //------------------------------------------------------------------------------------------------------
    // Set the seed for the generator. Using a known seed
    // allows you to reproduce the same sequence of random number
    //------------------------------------------------------------------------------------------------------

    void NumberUtils::SetSeed(unsigned int Seed)
    {
        srand(Seed);
        RandSeed = Seed;
    }

    //------------------------------------------------------------------------------------------------------
    // Get the seed used to generate random numbers the generator.
    //------------------------------------------------------------------------------------------------------

    unsigned int NumberUtils::GetSeed()
    {
        return RandSeed;
    }


    //------------------------------------------------------------------------------------------------------
    // Get a random float number in a given range
    // This is not the best algorithm, but it is fast
    // and will be enough in most cases
    // (see Google for best approaches)
    //------------------------------------------------------------------------------------------------------

    float NumberUtils::Random(float Begin, float End)
    {
        return static_cast<float>(rand()) / RAND_MAX * (End - Begin) + Begin;
    }


    //------------------------------------------------------------------------------------------------------
    // Get a random integer number in a given range
    // This is not the best algorithm, but it is fast
    // and will be enough in most cases
    // (see Google for best approaches)
    //------------------------------------------------------------------------------------------------------

    int NumberUtils::Random(int Begin, int End)
    {
        return rand() % (End - Begin + 1) + Begin;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    int NumberUtils::GetCount(int amount)
    {
        int count;

        if (amount > 1000)
        {
            count = 100;
        }
        else if (amount > 100)
        {
            count = 10;
        }
        else if (amount > 50)
        {
            count = 5;
        }
        else
        {
            count = 1;
        }

        return count;
    }
}
