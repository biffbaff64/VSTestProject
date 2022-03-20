#ifndef __GDX_FRAMEWORK_H
#define __GDX_FRAMEWORK_H

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include <GDX/Graphics/TextureManager.h>
#include <GDX/System/FPSCounter.h>
#include <GDX/Utils/StateManager.h>
#include <GDX/Physics/CollisionUtils.h>

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

typedef struct
{
    GDX::CollisionUtils *m_pCollisionUtils;
    GDX::StateManager   *m_pAppState;
    GDX::TextureManager *m_pTextureManager;
    GDX::FPSCounter     *m_pFPSCounter;
}
GLOBAL_REF_STRUCT;

namespace GDX
{
    class Application
    {
    public:
        Application();
        ~Application();

        void Setup();
        void Update();

        [[nodiscard]] float GetDeltaTime() const;
    };

    extern GLOBAL_REF_STRUCT *Gdx;
    extern Application *pFramework;
}

#endif // __GDX_FRAMEWORK_H

