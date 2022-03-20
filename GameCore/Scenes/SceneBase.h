#ifndef __SCENEBASE_H
#define __SCENEBASE_H

#include <SFML/Graphics.hpp>

namespace Game
{
    class SceneBase
    {
    public:
        virtual void OnCreate() {}
        virtual void OnDestroy() {}
        virtual void OnShow() {}
        virtual void OnHide() {}

        virtual void ProcessInput() {}
        virtual void Update(float delta) {}
        virtual void Draw() {}
        virtual void LoadContent() {}

        virtual void TriggerFadeIn() {}
        virtual void TriggerFadeOut() {}
    };
}

#endif // SFMLTEST_SCENEBASE_H

