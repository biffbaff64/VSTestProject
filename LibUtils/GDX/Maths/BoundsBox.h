#ifndef __BOUNDSBOX_H
#define __BOUNDSBOX_H

#include "Box.h"

namespace GDX
{
    class BoundsBox
    {
    public:
        BoundsBox();
        explicit BoundsBox(float left, float top, float right, float bottom);
        BoundsBox(const Box& box);
        virtual ~BoundsBox() = default;

        [[nodiscard]] virtual float GetX() const;
        [[nodiscard]] virtual float GetY() const;
        [[nodiscard]] virtual float GetWidth() const;
        [[nodiscard]] virtual float GetHeight() const;

        float m_left;
        float m_right;
        float m_top;
        float m_bottom;
    };
}

#endif // __BOUNDSBOX_H
