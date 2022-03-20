#pragma once

namespace Enums
{
    /**
     * A list of all allowable action states for
     * game entities.
     * These are separate to Core States.
     */
    enum class ActionStates
    {
        // ----------------------------
        InitSpawn,
        Spawning,

        // ----------------------------
        Standing,
        Running,
        Fighting,
        Teleporting,
        Held,
        Holding,

        // ----------------------------
        Stunned,
        Hurt,
        Dying,
        Dead,
        LastRites,
        Exploding,
        Killed,

        // ----------------------------
        Hiding,
        Talking,

        // ----------------------------
        Paused,
        Resetting,
        Waiting,
        Riding,
        Resting,
        Restarting,

        // ----------------------------
        SetOpening,
        SetClosing,
        Opening,
        Closing,
        Open,
        Closed,

        // ----------------------------
        MovingIn,
        MovingOut,
        MovingUp,
        MovingDown,

        // ----------------------------
        ChangingRoom,
        ChangingLevel,

        // ----------------------------
        Collidable,
        Colliding,

        // ----------------------------
        Active,
        Inactive,

        // ----------------------------
        Visible,
        Invisible,

        // ----------------------------
        OfferABXYA,
        OfferABXYB,
        OfferABXYX,
        OfferABXYY,

        // ----------------------------
        PressFloorSwitch,
        OpenMysteryBox,
        TalkToVillager,
        OpenTreasureChest,

        // ----------------------------
        Rotating,
        Scaling,
        ToAndFro,

        // ----------------------------
        TestAction1,
        TestAction2,
        TestAction3,
        TestAction4,
        TestAction5,

        // ----------------------------
        NoAction,
    };
}

