//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include <SFML/Window/Keyboard.hpp>

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Input.h"

namespace GDX
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void Input::Update()
    {
        m_lastFrameKeys.SetMask(m_thisFrameKeys);

        m_thisFrameKeys.SetBit((int)Key::Left,
                               (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                               || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)));

        m_thisFrameKeys.SetBit((int)Key::Right,
                               (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                               || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)));

        m_thisFrameKeys.SetBit((int)Key::Up,
                               (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                               || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)));

        m_thisFrameKeys.SetBit((int)Key::Down,
                               (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                               || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)));

        m_thisFrameKeys.SetBit((int)Key::Esc, sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    bool Input::IsKeyDown(Key keycode)
    {
        bool lastFrame = m_lastFrameKeys.GetBit((int)keycode);
        bool thisFrame = m_thisFrameKeys.GetBit((int)keycode);

        return thisFrame && !lastFrame;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    bool Input::IsKeyPressed(Key keycode)
    {
        return m_thisFrameKeys.GetBit((int)keycode);
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    bool Input::IsKeyUp(Key keycode)
    {
        bool lastFrame = m_lastFrameKeys.GetBit((int)keycode);
        bool thisFrame = m_thisFrameKeys.GetBit((int)keycode);

        return !thisFrame && lastFrame;
    }
}
