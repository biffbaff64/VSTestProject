#ifndef __SWITCH_H
#define __SWITCH_H

namespace GDX
{
    class Switch
    {
    public:
        Switch();
        ~Switch() = default;

        void Press();
        void PressConditional(bool condition);
        void ReleaseConditional(bool condition);
        void Release();
        void TogglePressed();
        void ToggleDisabled();
        void SetDisabled(bool state);

        [[nodiscard]] bool IsPressed() const;
        [[nodiscard]] bool IsDisabled() const;

    protected:
        bool m_IsPressed;
        bool m_IsDisabled;
    };
}

#endif // __SWITCH_H

