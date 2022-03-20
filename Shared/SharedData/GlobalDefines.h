#pragma once

namespace Game
{
	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	struct Coords
	{
		int x;
		int y;
	};

	struct CoordsF
	{
		float x;
		float y;
	};

	struct State
	{
		float x;	// position
		float v;	// velocity
	};

	struct Derivative
	{
		float dx;	// dx/dt = velocity
		float dv;	// dv/dt = acceleration
	};

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

#define MAX_LIVES					5
#define MAX_SCORE					99999999
#define MAX_GEMS					99999999
#define MAX_COINS					99999999
#define MAX_KEYS					100
#define MAX_VILLAGERS				100

#define MAX_PROGRESSBAR_LENGTH		100
#define MAX_STRENGTH				100

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#define SAFE_DELETE(x)				{ if(x){ delete x; x = nullptr; } }
#define SAFE_RELEASE(x)				{ if(x){ x->Release(); x = nullptr; } }
#define SAFE_UNLOAD(x)				{ if(x){ x->Unload(); x = nullptr; } }

//------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------

#define GET_ACTION_NAME				pApp->m_pEnumData->GetActionStateName
#define GET_STATE_NAME				pApp->m_pEnumData->GetGameStateName
#define GET_GID_NAME				pApp->m_pEnumData->GetGraphicIDName
#define GET_TILE_NAME				pApp->m_pEnumData->GetTileIDName
}
// chicken/turkey, bacon, lettuce, sweetcorn, cucumber, cheese, toasted with mayo

