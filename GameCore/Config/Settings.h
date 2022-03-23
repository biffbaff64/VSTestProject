#ifndef _SETTINGS_H
#define _SETTINGS_H

namespace Game
{
    class Settings
    {
        const bool BOX2D_PHYSICS = true;

        [[nodiscard]] bool IsEnabled( bool flag ) const;
    };
}

#endif //_SETTINGS_H
