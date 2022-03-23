#ifndef __APPCONFIG_H
#define __APPCONFIG_H

#include <ScreenID.h>
#include "Scenes/SceneBase.h"

namespace Game
{
	class AppConfig
	{
	public:
		AppConfig();
		~AppConfig() = default;

        [[nodiscard]] bool IsUsingBox2DPhysics() const;

		virtual void Pause();
		virtual void UnPause();

		bool m_quit_to_main_menu;       // Game over, back to menu screen
		bool m_force_quit_to_menu;      // Quit to main menu, forced via pause mode for example
		bool m_game_paused;				// TRUE / FALSE Game Paused flag
		bool m_cameras_ready;			// TRUE when all cameras have been created
		bool m_shutdown_active;			// TRUE if game is currently processing EXIT request
		bool m_entities_exist;			// Set true when all entities have been created
		bool m_hud_exists;				// Set true when HUD has finished Setup
		bool m_controllers_fitted;      // TRUE if external controllers are fitted/connected
	};
}

#endif // __APPCONFIG_H

