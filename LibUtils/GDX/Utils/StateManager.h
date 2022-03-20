#ifndef __STATEMANAGER_H
#define __STATEMANAGER_H

#include "Enums/GameStates.h"

using namespace Enums;

namespace GDX
{
    class StateManager
    {
    public:
        StateManager();
        explicit StateManager(GameStates state);
        virtual ~StateManager() = default;

        virtual GameStates Get();
        virtual void Set(GameStates state);

    private:
        GameStates m_currentState;
    };
}

#endif // __STATEMANAGER_H

