#ifndef __ORTHO_GAME_CAMERA_H
#define __ORTHO_GAME_CAMERA_H

#include "SFML/Graphics.hpp"
#include "GDX/Maths/Vec3.h"
#include "GDX/Maths/Vec2.h"

namespace Game
{
    class OrthoGameCamera
    {
    public:
        OrthoGameCamera();
        OrthoGameCamera(const char* name, float width, float height);
        ~OrthoGameCamera() = default;

        void SetViewCentre(float x, float y);
        GDX::Vec2F GetPosition();
        void LerpTo(GDX::Vec2F position, float speed);
        void ResizeViewport(float width, float height, bool centreCamera);

        sf::View        m_view;

        const char* m_name;
        bool            m_isInUse;
        bool            m_LerpingEnabled;
        GDX::Vec3Int    m_lerpVector;
        float           m_defaultZoom;

    private:
        GDX::Vec2F m_position;
    };
}

#endif // __ORTHO_GAME_CAMERA_H

