#pragma once

#include "ActionStates.h"
#include "GameStates.h"
#include "GraphicID.h"
#include "ScreenID.h"
#include "Stack.h"
#include "TaskType.h"
#include "TileID.h"

namespace Enums
{
	class EnumData
	{
	public:
		EnumData() = default;
		virtual ~EnumData() = default;

		[[nodiscard]] const char* GetActionStateName(int index);
		[[nodiscard]] const char* GetGameStateName(int index);
		[[nodiscard]] const char* GetGraphicIDName(int index);
		[[nodiscard]] const char* GetScreenIDName(int index);
		[[nodiscard]] const char* GetStackName(int index);
		[[nodiscard]] const char* GetTaskName(int index);
		[[nodiscard]] const char* GetTileIDName(int index);
	};
}

