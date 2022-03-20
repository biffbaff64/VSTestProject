#ifndef SFMLTEST_TITLESCENE_H
#define SFMLTEST_TITLESCENE_H

#include "SFML/Graphics.hpp"
#include "SceneBase.h"

namespace Game
{
    class TitleScene : public SceneBase
    {
    public:
        TitleScene() = default;
        ~TitleScene() = default;

        void OnCreate() override;
        void OnDestroy() override;
        void Update(float delta) override;
        void OnShow() override;
        void OnHide() override;
        void Draw() override;

    private:
        void LoadContent() override;
        void Initialise();

        sf::Texture m_backgroundImage;
        sf::Texture m_overlay1;
        sf::Texture m_overlay2;
    };
}

#endif // SFMLTEST_TITLESCENE_H

