#ifndef __ENTITYMANAGER_H
#define __ENTITYMANAGER_H

#include <memory>
#include <vector>

#include <GraphicID.h>

#include "Managers/GenericEntityManager.h"
#include "Managers/DecorationsManager.h"
#include "Managers/PlayerManager.h"
#include "Systems/RenderSystem.h"
#include "Hero/MainPlayer.h"
#include "Entities/Objects/GdxSprite.h"

using namespace Enums;

namespace Game
{
    class EntityManager
    {
    public:
        EntityManager();
        ~EntityManager() = default;

        void Initialise();
        void InitialiseManagerList();
        void InitialiseForLevel();

        void UpdateSprites();
        void TidySprites();
        void DrawSprites();

        size_t AddEntity(std::shared_ptr<GDXSprite>&& sprite);
        int AddManager(GenericEntityManager *manager);
        void RemoveEntity(int index);

        void ReleaseEntity(const GDXSprite& gdxSprite);
        void UpdateIndexes();
        void EstablishLinks();

        [[nodiscard]] static bool IsEntityUpdateAllowed();

        std::vector<std::shared_ptr<GDXSprite>>             m_entityMap;
        std::vector<std::shared_ptr<GenericEntityManager>>  m_managerList;

        bool m_playerReady;
        int  m_playerIndex;

        RenderSystem        m_renderSystem;
        PlayerManager       m_playerManager;
        DecorationsManager  m_decorationsManager;
    };
}

#endif // __ENTITYMANAGER_H

