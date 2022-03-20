#pragma once

namespace Enums
{
    enum class TileID
    {
        DefaultTile = 0,

        // Row 1
        PlayerTile = 1,
        PotTile = 2,
        CrateTile = 3,
        BarrelTile = 4,
        SacksTile = 5,
        LaserTile = 6,
        DoorTile = 7,
        VillagerTile = 8,
        KeyTile = 9,
        ChestTile = 10,

        // Row 2
        CoinTile = 11,
        FlameThrowerTile = 12,
        ShieldTile = 13,
        SpikeBlockDownTile = 14,
        SpikeBlockLeftTile = 15,
        SpikeBallTile = 16,
        SpikeBlockRightTile = 17,
        SpikeBlockUpTile = 18,
        FloorButtonTile = 19,
        LeverTile = 20,

        // Row 3
        GemTile = 21,
        AlcoveTorchTile = 22,
        LoopBlockHorizontalTile = 23,
        LoopBlockVerticalTile = 24,
        PrisonerTile = 25,
        SpecialCoinTile = 26,
        HiddenCoinTile = 27,
        MysteryChestTile = 28,
        FloatingPlatformTile = 29,
        SoldierTile = 30,

        // Row 4
        StormDemonTile = 31,
        BouncerTile = 32,
        ScorpionTile = 33,
        PlantPotTile = 34,
        FireBallTile = 35,
        BigBlockTile = 36,
        U37Tile = 37,
        U38Tile = 38,
        U39Tile = 39,
        TurretTile = 40,

        // Row 5
        U41Tile = 41,
        U42Tile = 42,
        U43Tile = 43,
        U44Tile = 44,
        U45Tile = 45,
        U46Tile = 46,
        U47Tile = 47,
        U48Tile = 48,
        GlowEyesTile = 49,
        ArrowTile = 50,

        // Row 6
        FlameThrowUpTile = 51,
        FlameThrowDownTile = 52,
        FlameThrowLeftTile = 53,
        FlameThrowRightTile = 54,
        EscalatorLeftTile = 55,
        EscalatorRightTile = 56,
        EscalatorDownTile = 57,
        EscalatorUpTile = 58,
        U59Tile = 59,
        U60Tile = 60,

        // Row 7
        PurpleBookTile = 61,
        RedBookTile = 62,
        BrownBookTile = 63,
        GreyBookTile = 64,
        YellowBookTile = 65,
        GreenBookTile = 66,
        PinkBookTile = 67,
        BlueBookTile = 68,
        U69Tile = 69,
        U70Tile = 70,

        // Row 8
        LightningRuneTile = 71,
        FireRuneTile = 72,
        WindRuneTile = 73,
        SunRuneTile = 74,
        IceRuneTile = 75,
        NatureRuneTile = 76,
        WaterRuneTile = 77,
        EarthRuneTile = 78,
        U79Tile = 79,
        U80Tile = 80,

        // Row 9
        U81Tile = 81,
        U82Tile = 82,
        U83Tile = 83,
        U84Tile = 84,
        U85Tile = 85,
        U86Tile = 86,
        U87Tile = 87,
        U88Tile = 88,
        U89Tile = 89,
        U90Tile = 90,

        // Row 10
        U91Tile = 91,
        U92Tile = 92,
        U93Tile = 93,
        NorthTile = 94,
        EastTile = 95,
        SouthTile = 96,
        WestTile = 97,
        WayPointTile = 98,
        BlankTile = 99,
        NoActionTile = 100,

        // Tile IDs that are used in path finding
        // These tiles may not necessarily have images
        // defined in the marker_tiles png.
        Ground = 150,
        Hole = 151,
        Water = 152,
        Grass = 153,
        WallEdge = 154,

        // Tile IDs for entities that are never
        // placed into a tilemap, but are created
        // programmatically.
        ExplosionTile = 200,
        LaserHorizontalTile = 201,
        LaserVerticalTile = 202,

        MysteryKey = 210,
        MysteryCoin = 211,
        MysteryMap = 212,
        MysteryAxe = 213,

        Unknown = 255
    };
}

