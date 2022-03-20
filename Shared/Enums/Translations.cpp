#include "Translations.h"

namespace Enums
{
	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	const char* ActionStatesNames[] =
	{
		"InitSpawn",
		"Spawning",
		"Standing",
		"Running",
		"Fighting",
		"Teleporting",
		"Held",
		"Holding",
		"Stunned",
		"Hurt",
		"Dying",
		"Dead",
		"LastRites",
		"Exploding",
		"Killed",
		"Hiding",
		"Talking",
		"Paused",
		"Resetting",
		"Waiting",
		"Riding",
		"Resting",
		"Restarting",
		"SetOpening",
		"SetClosing",
		"Opening",
		"Closing",
		"Open",
		"Closed",
		"MovingIn",
		"MovingOut",
		"MovingUp",
		"MovingDown",
		"ChangingRoom",
		"ChangingLevel",
		"Collidable",
		"Colliding",
		"Active",
		"Inactive",
		"Visible",
		"Invisible",
		"OfferABXYA",
		"OfferABXYB",
		"OfferABXYX",
		"OfferABXYY",
		"PressFloorSwitch",
		"OpenMysteryBox",
		"TalkToVillager",
		"OpenTreasureChest",
		"Rotating",
		"Scaling",
		"ToAndFro",
		"TestAction1",
		"TestAction2",
		"TestAction3",
		"TestAction4",
		"TestAction5",
		"NoAction",
	};

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	const char* GameStatesNames[] =
	{
		"StateMainMenu",
		"StateSettingsScreen",
		"StateDeveloperMenuScreen",
		"StateCreditsScreen",
		"StateLoadingScreen",
		"StateLevelSelectScreen",
		"StateExitScreen",
		"StateHiScoreScreen",
		"StateAchievementsScreen",
		"StateStatsScreen",
		"StatePrivacyPolicyScreen",
		"StateEndgameScreen",
		"StateMainMenuInit",
		"StateMenuUpdate",
		"StateSetup",
		"StateGetReady",
		"StateGame",
		"StatePrepareGameEnd",
		"StateGameFinished",
		"StateGameOver",
		"StateEndGame",
		"StatePaused",
		"StateLevelSetup",
		"StateLevelRetry",
		"StatePrepareLevelFinished",
		"StateLevelFinished",
		"StateMessagePanel",
		"StateDeveloperPanel",
		"StateSettingsPanel",
		"StatePlayAdvert",
		"StateNewHiScore",
		"StatePanelStart", "StatePanelIntro", "StatePanelUpdate", "StatePanelClose",
		"Inactive", "Limbo", "Init", "Update", "Close",
		"StateOpen", "StateOpening", "StateClosing", "StateClosed",
		"StateTriggerFadeIn", "StateTriggerFadeOut", "StateFadeIn", "StateFadeOut",
		"StateFlashing", "StateSteady",
		"StateZoomIn", "StateZoomOut",
		"StatePowerUp", "StatePowerDown",
		"StateDebugHang",
	};

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	const char* GraphicIDNames[] =
	{
		"Player",
		"Player_Weapon",
		"Prisoner",
		"Villager",
		"Coin",
		"SpecialCoin",
		"HiddenCoin",
		"Arrow",
		"SmallBullet",
		"Gem",
		"Sheild",
		"Key",
		"HudKey",
		"Apple",
		"Book",
		"Rune",
		"Potion",
		"Cake",
		"Cherries",
		"Grapes",
		"SilverArmour",
		"GoldArmour",
		"Litter",
		"Pot",
		"Crate",
		"Barrel",
		"GlowEyes",
		"AlcoveTorch",
		"Sacks",
		"PlantPot",
		"WagonWheel",
		"PotStand",
		"Anvil",
		"Hammers",
		"Door",
		"Open_Door",
		"Locked_Door",
		"Laser_Beam",
		"Floor_Button",
		"Lever_Switch",
		"Treasure_Chest",
		"Mystery_Chest",
		"Teleporter",
		"Prize_Balloon",
		"Message_Bubble",
		"Message_Panel",
		"Help_Bubble",
		"Document",
		"Question_Mark",
		"Exclamation_Mark",
		"Talk_Box",
		"Floating_Platform",
		"Selection_Ring",
		"Crosshairs",
		"Escalator",
		"Escalator_Left",
		"Escalator_Right",
		"Escalator_Up",
		"Escalator_Down",
		"Explosion12",
		"Explosion32",
		"Explosion64",
		"Explosion128",
		"Explosion256",
		"Storm_Demon",
		"Bouncer",
		"Mini_Fire_Ball",
		"Spike_Ball",
		"Spike_Block_Horizontal",
		"Spike_Block_Vertical",
		"Double_Spike_Block",
		"Loop_Block_Horizontal",
		"Loop_Block_Vertical",
		"Spikes",
		"Scorpion",
		"Enemy_Bullet",
		"Enemy_Fireball",
		"Soldier",
		"Soldier_Fight",
		"Big_Block_Vertical",
		"Big_Block_Horizontal",
		"Laser",
		"Laser_Beam_Vertical",
		"Laser_Beam_Horizontal",
		"Flame_Thrower",
		"Flame_Thrower_Vertical",
		"Turret",
		"Pickup",
		"Weapon",
		"Interactive",
		"Platform",
		"Monster",
		"Blocks",
		"Ground",
		"Ceiling",
		"Wall",
		"LethalObject",
		"Enemy",
		"Main",
		"Sign",
		"Speech",
		"HudPanel",
		"ExitBox",
		"Obstacle",
		"Decoration",
		"Entity",
		"GDummy",
		"NoID",
	};

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	const char* ScreenIDNames[] =
	{
		"BaseScreen",
		"MainMenu",
		"SettingsScreen",
		"CreditsScreen",
		"LoadingScreen",
		"GameScreen",
		"ExitScreen",
		"HiScoreScreen",
		"AchievementsScreen",
		"StatsScreen",
		"PrivacyPolicyScreen",
		"TestPanel",
		"DeveloperPanel",
		"EndGameScreen",
		"InstructionsScreen",
		"BaseRenderer",
		"TitleRenderer",
		"GameRenderer",
		"NoID",
	};

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	const char* StackNames[] =
	{
		"Score",
		"Lives",
		"Gems",
		"Coins",
		"Keys",
		"Villagers",
	};

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	const char* TaskTypeNames[] =
	{
		"Runes_Master",
		"Potions_Master",
		"Books_Master",
		"Rubbish_Collector",
	};

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	const char* TileIDNames[] =
	{
		"DefaultTile",
		"PlayerTile",
		"PotTile",
		"CrateTile",
		"BarrelTile",
		"SacksTile",
		"LaserTile",
		"DoorTile",
		"VillagerTile",
		"KeyTile",
		"ChestTile",
		"CoinTile",
		"FlameThrowerTile",
		"ShieldTile",
		"SpikeBlockDownTile",
		"SpikeBlockLeftTile",
		"SpikeBallTile",
		"SpikeBlockRightTile",
		"SpikeBlockUpTile",
		"FloorButtonTile",
		"LeverTile",
		"GemTile",
		"AlcoveTorchTile",
		"LoopBlockHorizontalTile",
		"LoopBlockVerticalTile",
		"PrisonerTile",
		"SpecialCoinTile",
		"HiddenCoinTile",
		"MysteryChestTile",
		"FloatingPlatformTile",
		"SoldierTile",
		"StormDemonTile",
		"BouncerTile",
		"ScorpionTile",
		"PlantPotTile",
		"FireBallTile",
		"BigBlockTile",
		"U37Tile",
		"U38Tile",
		"U39Tile",
		"TurretTile",
		"U41Tile",
		"U42Tile",
		"U43Tile",
		"U44Tile",
		"U45Tile",
		"U46Tile",
		"U47Tile",
		"U48Tile",
		"GlowEyesTile",
		"ArrowTile",
		"FlameThrowUpTile",
		"FlameThrowDownTile",
		"FlameThrowLeftTile",
		"FlameThrowRightTile",
		"EscalatorLeftTile",
		"EscalatorRightTile",
		"EscalatorDownTile",
		"EscalatorUpTile",
		"U59Tile",
		"U60Tile",
		"PurpleBookTile",
		"RedBookTile",
		"BrownBookTile",
		"GreyBookTile",
		"YellowBookTile",
		"GreenBookTile",
		"PinkBookTile",
		"BlueBookTile",
		"U69Tile",
		"U70Tile",
		"LightningRuneTile",
		"FireRuneTile",
		"WindRuneTile",
		"SunRuneTile",
		"IceRuneTile",
		"NatureRuneTile",
		"WaterRuneTile",
		"EarthRuneTile",
		"U79Tile",
		"U80Tile",
		"U81Tile",
		"U82Tile",
		"U83Tile",
		"U84Tile",
		"U85Tile",
		"U86Tile",
		"U87Tile",
		"U88Tile",
		"U89Tile",
		"U90Tile",
		"U91Tile",
		"U92Tile",
		"U93Tile",
		"NorthTile",
		"EastTile",
		"SouthTile",
		"WestTile",
		"WayPointTile",
		"BlankTile",
		"NoActionTile",
	};

	const char* TileIDNames150[] =
	{
		"Ground",
		"Hole",
		"Water",
		"Grass",
		"WallEdge",
	};

	const char* TileIDNames200[] =
	{
		"ExplosionTile",
		"LaserHorizontalTile",
		"LaserVerticalTile",
		"U203Tile",
		"U204Tile",
		"U205Tile",
		"U206Tile",
		"U207Tile",
		"U208Tile",
		"U209Tile",
		"MysteryKey",
		"MysteryCoin",
		"MysteryMap",
		"MysteryAxe",
	};

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	const char* EnumData::GetActionStateName(int index)
	{
		return ActionStatesNames[index];
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	const char* EnumData::GetGameStateName(int index)
	{
		return GameStatesNames[index];
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	const char* EnumData::GetGraphicIDName(int index)
	{
		return GraphicIDNames[index];
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	const char* EnumData::GetScreenIDName(int index)
	{
		return ScreenIDNames[index];
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	const char* EnumData::GetStackName(int index)
	{
		return StackNames[index];
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	const char* EnumData::GetTaskName(int index)
	{
		return TaskTypeNames[index];
	}

	//------------------------------------------------------------------------------------------------------
	//------------------------------------------------------------------------------------------------------

	const char* EnumData::GetTileIDName(int index)
	{
		if ((index >= 200) && (index <= 213))
		{
			return TileIDNames200[index - 200];
		}
		else if ((index >= 150) && (index <= 154))
		{
			return TileIDNames150[index - 150];
		}
		else if (index <= 100)
		{
			return TileIDNames[index];
		}

		return "unknown";
	}
}

