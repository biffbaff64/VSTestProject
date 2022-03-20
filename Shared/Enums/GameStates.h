#pragma once

namespace Enums
{
    enum class GameStates
    {
        StateMainMenu,
        StateSettingsScreen,
        StateDeveloperMenuScreen,
        StateCreditsScreen,
        StateLoadingScreen,
        StateLevelSelectScreen,
        StateExitScreen,
        StateHiScoreScreen,
        StateAchievementsScreen,
        StateStatsScreen,
        StatePrivacyPolicyScreen,
        StateEndgameScreen,

        StateMainMenuInit,
        StateMenuUpdate,
        StateSetup,
        StateGetReady,
        StateGame,
        StatePrepareGameEnd,
        StateGameFinished,
        StateGameOver,
        StateEndGame,
        StatePaused,
        StateLevelSetup,
        StateLevelRetry,
        StatePrepareLevelFinished,
        StateLevelFinished,
        StateMessagePanel,
        StateDeveloperPanel,
        StateSettingsPanel,
        StatePlayAdvert,
        StateNewHiScore,

        StatePanelStart, StatePanelIntro, StatePanelUpdate, StatePanelClose,

        Inactive, Limbo, Init, Update, Close,

        StateOpen, StateOpening, StateClosing, StateClosed,

        StateTriggerFadeIn, StateTriggerFadeOut, StateFadeIn, StateFadeOut,

        StateFlashing, StateSteady,

        StateZoomIn, StateZoomOut,

        StatePowerUp, StatePowerDown,

        StateDebugHang,
    };
}

