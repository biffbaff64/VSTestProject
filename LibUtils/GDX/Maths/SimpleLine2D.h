#ifndef __SIMPLELINE2D_H
#define __SIMPLELINE2D_H

namespace GDX
{
    class SimpleLine2D
    {
    public:
        float m_x1;
        float m_y1;
        float m_x2;
        float m_y2;

        SimpleLine2D(float x1, float y1, float x2, float y2);

        [[nodiscard]] bool Intersects(SimpleLine2D line2D) const;
    };
}

#endif // __SIMPLELINE2D_H

