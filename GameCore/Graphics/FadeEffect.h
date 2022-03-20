#ifndef SFMLTEST_FADEEFFECT_H
#define SFMLTEST_FADEEFFECT_H

namespace Game
{
    class FadeEffect
    {
    public:
        FadeEffect()
            :
            m_isActive(false)
        {
        }

        void Update();
        void End();

        void TriggerFadeIn();
        void TriggerFadeOut();

        bool m_isActive;
    };
}

#endif // SFMLTEST_FADEEFFECT_H


