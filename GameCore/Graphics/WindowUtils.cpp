//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Core/App.h"
#include "BaseRenderer.h"
#include "WindowUtils.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

namespace Game
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    sf::FloatRect WindowUtils::GetViewSpace() const
    {
        sf::Vector2f viewCenter = pApp->m_pBaseRenderer->m_renderWindow.getView().getCenter();
        sf::Vector2f viewSize = pApp->m_pBaseRenderer->m_renderWindow.getView().getSize();
        sf::Vector2f viewSizeHalf(viewSize.x / 2, viewSize.y / 2);
        sf::FloatRect viewSpace(viewCenter - viewSizeHalf, viewSize);

        return viewSpace;
    }
}