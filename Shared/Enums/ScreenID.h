#pragma once

namespace Enums
{
    enum class ScreenID
    {
        TitleScene = 0,
        GameScene = 1,

        BaseScreen,
        SettingsScreen,
        CreditsScreen,
        LoadingScreen,
        ExitScreen,
        HiScoreScreen,
        AchievementsScreen,
        StatsScreen,
        PrivacyPolicyScreen,
        TestPanel,
        DeveloperPanel,
        EndGameScreen,
        InstructionsScreen,

        BaseRenderer,
        TitleRenderer,
        GameRenderer,

        NoID
    };
}