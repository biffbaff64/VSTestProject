#pragma once

namespace Enums
{
    enum class GraphicID
    {
        // ----------------------------
        Player = 0,
        Player_Weapon,

        // ----------------------------
        Prisoner,
        Villager,

        // ----------------------------
        // Pickup Items
        Coin,
        SpecialCoin,
        HiddenCoin,
        Arrow,
        SmallBullet,
        Gem,
        Sheild,
        Key,
        HudKey,
        Apple,
        Book,
        Rune,
        Potion,
        Cake,
        Cherries,
        Grapes,
        SilverArmour,
        GoldArmour,
        Litter,

        // ----------------------------
        // Decorations
        Pot,
        Crate,
        Barrel,
        GlowEyes,
        AlcoveTorch,
        Sacks,
        PlantPot,
        WagonWheel,
        PotStand,
        Anvil,
        Hammers,

        // ----------------------------
        // Interactive items
        Door,
        Open_Door,
        Locked_Door,
        Laser_Beam,
        Floor_Button,
        Lever_Switch,
        Treasure_Chest,
        Mystery_Chest,
        Teleporter,
        Prize_Balloon,
        Message_Bubble,
        Message_Panel,
        Help_Bubble,
        Document,
        Question_Mark,
        Exclamation_Mark,
        Talk_Box,
        Floating_Platform,
        Selection_Ring,
        Crosshairs,
        Escalator,
        Escalator_Left,
        Escalator_Right,
        Escalator_Up,
        Escalator_Down,

        // ----------------------------
        Explosion12,
        Explosion32,
        Explosion64,
        Explosion128,
        Explosion256,

        // ----------------------------
        // Enemies
        Storm_Demon,
        Bouncer,
        Mini_Fire_Ball,
        Spike_Ball,
        Spike_Block_Horizontal,
        Spike_Block_Vertical,
        Double_Spike_Block,
        Loop_Block_Horizontal,
        Loop_Block_Vertical,
        Spikes,
        Scorpion,
        Enemy_Bullet,
        Enemy_Fireball,
        Soldier,
        Soldier_Fight,
        Big_Block_Vertical,
        Big_Block_Horizontal,

        // ----------------------------
        Laser,
        Laser_Beam_Vertical,
        Laser_Beam_Horizontal,
        Flame_Thrower,
        Flame_Thrower_Vertical,
        Turret,

        // ----------------------------
        // Generic
        Pickup,
        Weapon,
        Interactive,
        Platform,
        Monster,
        Blocks,
        Ground,
        Ceiling,
        Wall,
        LethalObject,
        Enemy,
        Main,
        Sign,
        Speech,
        HudPanel,
        ExitBox,

        // ----------------------------
        // Encapsulating m_type, covering any collision IDs that can be stood on.
        // This will be checked against the collision object TYPE, not the NAME.
        Obstacle,

        // ----------------------------
        // As above but for objects that can't be stood on and are not entities
        Decoration,

        // As above, but for entities
        Entity,

        // ----------------------------

        GDummy,
        NoID
    };
}

