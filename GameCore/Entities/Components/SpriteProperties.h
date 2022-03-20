#ifndef SFMLTEST_SPRITEPROPERTIES_H
#define SFMLTEST_SPRITEPROPERTIES_H

namespace Game
{
    class SpriteProperties
    {
    public:
        SpriteProperties();
        ~SpriteProperties() = default;

        SpriteProperties& operator = (const SpriteProperties& properties);

        int m_link;
        int m_strength;

        float m_rotateSpeed;
        float m_rotation;

        bool m_isDrawable;
        bool m_isRotating;
        bool m_isFlippedX;
        bool m_isFlippedY;
        bool m_canFlip;
        bool m_isAnimating;
        bool m_isLinked;
        bool m_isMainCharacter;
        bool m_isEnemy;
    };
}

#endif //SFMLTEST_SPRITEPROPERTIES_H
