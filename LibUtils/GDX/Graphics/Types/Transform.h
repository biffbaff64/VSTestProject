#ifndef __GDX_TRANSFORM_H
#define __GDX_TRANSFORM_H

#include <GDX/Maths/Vector.h>

namespace GDX
{
    class Transform
    {
    public:
        Transform();
        Transform(const Transform &transform);

        Transform &Identity();

        Transform &Scale(const float scaleUniform);
        Transform &Scale(const float scaleX, const float scaleY);

        Transform &Translate(const Vector &v);
        Transform &Translate(const float x, const float y);

        Transform &Rotate(const float radians);

        Transform operator*(const Transform &other) const;

        Vector operator*(const Vector &vector) const;

        static const Transform IDENTITY;

    private:
        Transform(const float row00,
                  const float row01,
                  const float row02,
                  const float row10,
                  const float row11,
                  const float row12);

        union
        {
            float m_values[2][3];

            struct
            {
                float m_row0[2];
                float m_translateX;

                float m_row1[2];
                float m_translateY;
            };
        };
    };
}

#endif // __GDX_TRANSFORM_H

