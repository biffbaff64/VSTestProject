#ifndef __GFX_H
#define __GFX_H

#include <SFML/Graphics.hpp>

#include "GDX/Maths/Vec2.h"

namespace Game
{
    #define PPM                     64.0f
    #define PPM_RATIO               (1.0f / PPM)
    #define MAXIMUM_Z_DEPTH         20
    #define DEFAULT_ZOOM            1.0f
    #define DEFAULT_SCALE           1.0f
    #define DESIRED_FPS             60.0f
    #define MIN_FPS                 30.0f
    #define STEP_TIME               (1.0f / 60.0f)
    #define VELOCITY_ITERATIONS     8
    #define POSITION_ITERATIONS     3
    #define FALL_GRAVITY            9.8f
    #define TERMINAL_VELOCITY       (PPM / FALL_GRAVITY)

    class Gfx
    {
    public:
        Gfx();
        ~Gfx() = default;

        static Gfx &inst()
        {
            static Gfx *instance = new Gfx();
            return *instance;
        }

        [[nodiscard]] int VisibleMapWidth() const;
        [[nodiscard]] int VisibleMapHeight() const;

        //
        // Entity Collision filter masks
        static const short CAT_NONE             = 0x0000;   // - 00 (0     )
        static const short CAT_PLAYER           = 0x0001;   // - 01 (1     )
        static const short CAT_MOBILE_ENEMY     = 0x0002;   // - 02 (2     )
        static const short CAT_FIXED_ENEMY      = 0x0004;   // - 03 (4     )
        static const short CAT_PLAYER_WEAPON    = 0x0008;   // - 04 (8     )
        static const short CAT_ENEMY_WEAPON     = 0x0010;   // - 05 (16    )
        static const short CAT_DECORATION       = 0x0020;   // - 06 (32    )
        static const short CAT_OBSTACLE         = 0x0020;   // - 07 (64    )
        static const short CAT_ENTITY_BARRIER   = 0x0020;   // - 08 (128   )
        static const short CAT_DOOR             = 0x0020;   // - 09 (256   )
        static const short CAT_UNDEFINED_10     = 0x0020;   // - 10 (512   )
        static const short CAT_UNDEFINED_11     = 0x0020;   // - 11 (1024  )
        static const short CAT_UNDEFINED_12     = 0x0020;   // - 12 (2048  )
        static const short CAT_UNDEFINED_13     = 0x0020;   // - 13 (4096  )
        static const short CAT_UNDEFINED_14     = 0x0020;   // - 14 (8192  )
        static const short CAT_UNDEFINED_15     = 0x0020;   // - 15 (16384 )

        //
        // Combined masks
        static const short CAT_ENEMY  = (short) (CAT_MOBILE_ENEMY | CAT_FIXED_ENEMY);
        static const short CAT_WEAPON = (short) (CAT_PLAYER_WEAPON | CAT_ENEMY_WEAPON);

        sf::Time m_timePerFrame;

        //
        // General physics and graphics values
        int         m_pixelsPerMetre;
        GDX::Vec2F  m_worldGravity;
        int         m_hudWidth;
        int         m_hudHeight;
        int         m_viewWidth;
        int         m_viewHeight;
        int         m_DesktopWidth;
        int         m_desktopHeight;
        float       m_lerpSpeed;
    };
}

#endif // __GFX_H

