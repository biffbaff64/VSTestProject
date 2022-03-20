#ifndef SFMLTEST_ENTITYMANAGERCOMPONENT_H
#define SFMLTEST_ENTITYMANAGERCOMPONENT_H

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Enums/GraphicID.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

namespace Game
{
    class EntityManagerComponent
    {
    public:
        virtual void Init() = 0;
        virtual void Update() = 0;
        virtual void Create() = 0;
        virtual void Free() = 0;
        virtual void Free(Enums::GraphicID gid) = 0;
        virtual void Reset() = 0;
        virtual void SetActiveCount() = 0;
        virtual void SetPlaceable(bool placeable) = 0;

        [[nodiscard]] virtual int GetActiveCount() = 0;
        [[nodiscard]] virtual Enums::GraphicID GetGID() = 0;
    };
}

#endif //SFMLTEST_ENTITYMANAGERCOMPONENT_H
