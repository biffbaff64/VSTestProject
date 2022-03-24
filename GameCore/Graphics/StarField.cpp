//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#include "Core/App.h"
#include "Graphics/GameResources.h"
#include "StarField.h"

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

namespace Game
{
    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    StarField::StarField()
    {
        m_texture.loadFromFile( SOLID_WHITE_32x32 );
        m_isEnabled = false;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void StarField::Setup()
    {
        for ( auto &m_star: m_stars )
        {
            m_star = StarObject( m_texture );
        }

        m_isEnabled = false;
    }

    //------------------------------------------------------------------------------------------------------
    //------------------------------------------------------------------------------------------------------

    void StarField::Render()
    {
        if ( m_isEnabled )
        {
            for ( StarObject star: m_stars )
            {
                star.Render( STAR_SPEED );
            }
        }
    }
}
