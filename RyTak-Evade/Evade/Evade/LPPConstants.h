#ifndef LPPConstants_h__
#define LPPConstants_h__

enum eGameObjectClassId
{
	kNeutralMinionCamp = 0,
	kFollowerObject = 1,
	kFollowerObjectWithLerpMovement = 2,
	kAIHeroClient = 3,
	kobj_AI_Marker = 4,
	kobj_AI_Minion = 5,
	kLevelPropAI = 6,
	kobj_AI_Turret = 7,
	kobj_AI_Base = 8,
	kobj_GeneralParticleEmitter = 9,
	kMissileClient = 10,
	kDrawFX = 11,
	kUnrevealedTarget = 12,
	kobj_Barracks = 13,
	kobj_BarracksDampener = 14,
	kobj_Lake = 15,
	kobj_AnimatedBuilding = 16,
	kobj_Building = 17,
	kobj_Levelsizer = 18,
	kobj_NavPoint = 19,
	kobj_SpawnPoint = 20,
	kobj_LampBulb = 21,
	kGrassObject = 22,
	kobj_HQ = 23,
	kobj_InfoPoint = 24,
	kLevelPropGameObject = 25,
	kLevelPropSpawnerPoint = 26,
	kobj_Shop = 27,
	kobj_Turret = 18
};

enum eTeleportType
{
	Teleport_Teleport,
	Teleport_Recall,
	Teleport_Shen,
	Teleport_TwistedFate,
	Teleport_Unknown
};

enum eTeleportStatus
{
	Teleport_Start,
	Teleport_Abort,
	Teleport_Finish
};

enum eDamageItems
{
	kHexgun,
	kDfg,
	kBotrk,
	kBilgewater,
	kHydra,
	kBlackFireTorch,
	kOdingVeils,
	kFrostQueenClaim,
};

enum eSummonerSpell
{
	kSummonerSpellIgnite,
	kSummonerSpellSmite
};

enum eSpellSlot
{
	kSlotQ,
	kSlotW,
	kSlotE,
	kSlotR,
	kSummonerSlot1,
	kSummonerSlot2,
	kItem1,
	kItem2,
	kItem3,
	kItem4,
	kItem5,
	kItem6,
	kSlotTrinket,
	kSlotRecall,
	kSlotUnknown = -1
};

enum eBuffType
{
	BUFF_Internal,
	BUFF_Aura,
	BUFF_CombatEnchancer,
	BUFF_CombatDehancer,
	BUFF_SpellShield,
	BUFF_Stun,
	BUFF_Invisibility,
	BUFF_Silence,
	BUFF_Taunt,
	BUFF_Polymorph,
	BUFF_Slow,
	BUFF_Snare,
	BUFF_Damage,
	BUFF_Heal,
	BUFF_Haste,
	BUFF_SpellImmunity,
	BUFF_PhysicalImmunity,
	BUFF_Invulnerability,
	BUFF_Sleep,
	BUFF_NearSight,
	BUFF_Frenzy,
	BUFF_Fear,
	BUFF_Charm,
	BUFF_Poison,
	BUFF_Suppression,
	BUFF_Blind,
	BUFF_Counter,
	BUFF_Shred,
	BUFF_Flee,
	BUFF_Knockup,
	BUFF_Knockback,
	BUFF_Disarm
};

enum GameObjectCharacterState
{
	State_CanAttack = (1 << 0),
	State_CanCast = (1 << 1),
	State_CanMove = (1 << 2),
	State_Immovable = (1 << 5),
	State_RevealSpecificUnit = (1 << 6),
	State_Taunted = (1 << 7),
	State_Feared = (1 << 8),
	State_Fleeing = (1 << 9),
	State_Supressed = (1 << 10),
	State_Asleep = (1 << 11),
	State_NearSight = (1 << 12),
	State_Ghosted = (1 << 13),
	State_GhostProof = (1 << 14),
	State_Charmed = (1 << 15)
};

enum eSpellState
{
	Ready = 0,		// 0 Spell is ready but should also be AND'd by UnableToCast for a full check
	NotReady = (1 << 1), // 2 (Unsure, spell is not ready)
	NotLearned = (1 << 2), // 4 (Spell has not been leveled yet)
	Supressed = (1 << 3), // 8 (You are being supressed)
	Unknown16 = (1 << 4), // 16 (Unsure, used in UnableToCast flags)
	Cooldown = (1 << 5), // 32 (Spell is on CD)
	NoMana = (1 << 6), // 64 (You do not have enough mana to cast the spell)
	Unknown128 = (1 << 7), // 128 (Unsure, used in UnableToCast flags)

						   // if (Spell.Flags == 0 || !(Spell.Flags & UnableToCast)) { Spell.Ready = true; }
						   UnableToCast = (Unknown128 | Cooldown | NotLearned | NotReady)
};

enum eUnitTeam
{
	kNeutral = 44,
	kTeam1 = 100,
	kTeam2 = 200
};

enum eUnitType
{
	FL_INVALID = 0,
	FL_CREEP = 12,
	FL_HERO = 20,
	FL_TURRET = 36,
	FL_MISSILE = 128
};

enum eGameObjectOrder
{
	kHoldPosition = 1,
	kMoveTo = 2,
	kAttackUnit = 3,
	kAutoAttackPet = 4,
	kAutoAttack = 5,
	kMovePet = 6,
	kAttackTo = 7,
	kStop = 10
};

enum eSpellType
{
	kTargetCast,
	kLineCast,
	kCircleCast,
	kConeCast
};

enum eHealthPredictionType
{
	kLastHitPrediction,
	kLaneClearPrediction
};

enum eMeshType
{
	kStaticMesh = 0,
	kGrassMesh = (1 << 0),
	kWallMesh = (1 << 1),
	kBuildingMesh = (1 << 6),
	kPropMesh = (1 << 7),
};

enum eLeagueEvents
{
	kEventOrbwalkBeforeAttack,
	kEventOrbwalkOnAttack,
	kEventOrbwalkAfterAttack,
	kEventOrbwalkTargetChange,
	kEventOrbwalkNonKillableMinion,
	kEventOnGameUpdate,
	kEventOnRender,
	kEventOnSpellCast,
	kEventOnUnitDeath,
	kEventOnCreateObject,
	kEventOnDestroyObject,
	kEventOnDoCast,
	kEventOnInterruptible,
	kEventOnGapCloser,
	kEventOnIssueOrder,
	kEventOnBuffAdd,
	kEventOnBuffRemove,
	kEventOnGameEnd,
	kEventOnLevelUp,
	kEventOnPreCast,
	kEventOrbwalkFindTarget,
	kEventOnDash,
	kEventOnD3DPresent,
	kEventOnD3DPreReset,
	kEventOnD3DPostReset,
	kEventOnRenderBehindHud,
	kEventOnWndProc,
	kEventOnEnterVisible,
	kEventOnExitVisible,
	kEventOnUpdateChargedSpell,
	kEventOnPlayAnimation,
	kEventOnPauseAnimation,
	kEventOnJungleNotification,
	kEventOnNewPath,
	kEventOnTeleport
};

enum eTargetPriority
{
	QuickestKill,				/* Prioritize the quickest kill based on damage type */
	ClosestPriority,			/* Prioritize based on distance */
	ClosestToCursorPriority,	/* Prioritize based on distance from cursor */
	LowestHealthPriority,		/* Prioritize based on lowest health */
	MostStacks,					/* Prioritizes based on most stacks (e.g Vayne W, Twitch passive, etc.) */
	MostAD,						/* Prioritizes based on highest AD */
	MostAP,						/* Prioritizes based on highest AP */
	LeastAttacks,				/* Prioritizes based on least number of physical damage attacks to kill */
	LeastCasts,					/* Prioritizes based on least number of spell cast attacks to kill */
};

enum eDamageType
{
	TrueDamage,
	PhysicalDamage,
	SpellDamage
};

enum eInterruptibleDanger
{
	kLowDanger,
	kMediumDanger,
	kHighDanger
};

enum eObjectTeam
{
	kTeamUnknown = 0,
	kTeamOrder = 100,
	kTeamChaos = 200,
	kTeamNeutral = 300,
};

enum eFontWeight
{
	kFontWeightThin,
	kFontWeightNormal,
	kFontWeightBold,
	kFontWeightHeavy
};

enum eFontLocation
{
	kFontLocationNormal,
	kFontLocationCenterVertical,
	kFontLocationCenterHorizontal,
	kFontLocationCenter
};

enum eCollisionFlags
{
	kCollidesWithNothing = 0,
	kCollidesWithMinions = (1 << 1),	// Spell collides with enemy minions
	kCollidesWithHeroes = (1 << 2),		// Spell collides with enemy champions
	kCollidesWithYasuoWall = (1 << 3),	// Spell collides with Yasuo wall
	kCollidesWithWalls = (1 << 4),		// Spell collides with walls
	kCollidesWithAllies = (1 << 5)		// Spell collides with ally champions
};

enum eOrbwalkingMode
{
	kModeLastHit,
	kModeMixed,
	kModeLaneClear,
	kModeCombo,
	kModeFreeze,
	kModeCustom,
	kModeNone
};

enum ePingCategory
{
	kPingNormal = 0,
	kPingDanger = 2,
	kPingEnemyMissing = 3,
	kPingOnMyWay = 4,
	kPingFallback = 5,
	kPingAssistMe = 6
};

enum eGameType
{
	kGameNormal,
	kGameDominion,
	kGameTutorial,
	kGameARAM,
	kGameFirstBlood,
	kGameAscension,
};

enum eMapType
{
	kMapCrystalScar = 8,
	kMapTwistedTreeline = 10,
	kMapSummonersRift = 11,
	kMapHowlingAbyss = 12,
};

enum eTaunt
{
	kDance,
	kTaunt,
	kLaugh,
	kJoke,
	kToggle,
};

enum eInventoryItems
{
	kBootsOfSpeed = 1001,
	kFaerieCharm = 1004,
	kRejuvenationBead = 1006,
	kGiantsBelt = 1011,
	kCloakOfAgility = 1018,
	kBlastingWand = 1026,
	kSapphireCrystal = 1027,
	kRubyCrystal = 1028,
	kClothArmor = 1029,
	kChainVest = 1031,
	kNullMagicMantle = 1033,
	kLongSword = 1036,
	kPickaxe = 1037,
	kBFSword = 1038,
	kHuntersTalisman = 1039,
	kHuntersMachete = 1041,
	kDagger = 1042,
	kRecurveBow = 1043,
	kBrawlersGloves = 1051,
	kAmplifyingTome = 1052,
	kVampiricScepter = 1053,
	kDoransSheild = 1054,
	kDoransBlade = 1055, 
	kDoransRing = 1056,
	kNegatronCloak = 1057,
	kNeedlesslyLargeRod = 1058,
	kDarkSeal = 1082,
	kCull = 1083,
	kStalkersBladeWarrior = 1400,
	kStalkersBladeCinderhulk = 1401,
	kStalkersBladeRunicEchoes = 1402,
	kTrackersKnifeWarrior = 1408,
	kTrackersKnifeCinderhulk = 1409,
	kTrackersKnifeRunicEchoes = 1410,
	kSkirmishersSabreWarrior = 1412,
	kSkirmishersSabreCinderhulk = 1413,
	kSkirmishersSabreRunicEchoes = 1414,
	kStalkersBladeBloodrazor = 1416,
	kTrackersKnifeBloodrazor = 1418,
	kSkirmishersSabreBloodrazor = 1419,
	kHealthPotion = 2003,
	kTotalBiscuitOfRejuvination = 2009,
	kTotalBiscuitOfRejuvinationSR = 2010,
	kKricheisShard = 2015,
	kRefillablePotion = 2031,
	kHuntersPotion = 2032,
	kCorruptingPotion = 2033,
	kVisionWard = 2043,
	kRubySightstone = 2045,
	kOraclesExtract = 2047,
	kSightstone = 2049,
	kExplorersWard = 2050,
	kGuardiansHorn = 2051,
	kPoroSnax = 2052,
	kRaptorCloak = 2053,
	kDietPoroSnax = 2054,
	kControlWard = 2055,
	kElixirOfIron = 2138,
	kElixirOfSorcery = 2139,
	kElixirOfWrath = 2140,
	kEyeOfTheWatchers = 2301,
	kEyeOfTheOasis = 2302,
	kEyeOfTheEquinox = 2303,
	kAbyssalScepter = 3001,
	kArchangelsStaff = 3003,
	kManamune = 3004,
	kBerserkersGreaves = 3006,
	kArchangelsStaffQuickCharge = 3007,
	kManamuneQuickCharge = 3008,
	kBootsOfSwiftness = 3009,
	kCatalystOfAeons = 3010,
	kSorcerersShoes = 3020,
	kFrozenMallet = 3022,
	kGlacialShroud = 3024,
	kIcebornGauntlet = 3025,
	kGuardianAngel = 3026,
	kRodOfAges = 3027,
	kChaliceOfHarmony = 3028,
	kRodOfAgesQuickCharge = 3029,
	kHextechGLP800 = 3030,
	kInfinityEdge = 3031,
	kMortalReminder = 3033,
	kGiantSlayer = 3034,
	kLastWhisper = 3035,
	kLordDominiksRegards = 3036,
	kSeraphsEmbrace = 3040,
	kMejaisSoulstealer = 3041,
	kMuramana = 3042,
	kMuramanaQuickCharge = 3043,
	kPhage = 3044,
	kPhantomDancer = 3046,
	kNinjaTabi = 3047,
	kSeraphsEmbraceQuickCharge = 3048,
	kZekesHarbinger = 3050,
	kJaurimsFist = 3052,
	kSteraksGage = 3053,
	kOhmwrecker = 3056,
	kSheen = 3057,
	kBannerOfCommand = 3060,
	kSpiritVisage = 3065,
	kKindlegem = 3067,
	kSunfireCape = 3068,
	kTalismanOfAscension = 3069,
	kTearOfTheGoddess = 3070,
	kTheBlackCleaver = 3071,
	kTheBloodthirster = 3072,
	kTearOfTheGoddessQuickCharge = 3073,
	kRavenousHydra = 3074,
	kThornmail = 3075,
	kTiamat = 3077,
	kTrinityForce = 3078,
	kWardensMail = 3082,
	kWarmogsArmor = 3083,
	kOverlordsBloodmail = 3084,
	kRunaansHurricane = 3085,
	kZeal = 3086,
	kStatikkShiv = 3087,
	kRabadonsDeathcap = 3089,
	kWoogletsWitchcap = 3090,
	kWitsEnd = 3091,
	kFrostQueensClaim = 3092,
	kRapidFirecannon = 3094,
	kNomadsMedallion = 3096,
	kTargonsBrace = 3097,
	kFrostfang = 3098,
	kLichBane = 3100,
	kStinger = 3101,
	kBansheesVeil = 3102,
	kLordVanDammsPillager = 3104,
	kAegisOfTheLegion = 3105,
	kRedemption = 3107,
	kFiendishCodex = 3108,
	kKnightsVow = 3109,
	kFrozenHeart = 3110,
	kMercurysTreads = 3111,
	kGuardiansOrb = 3112,
	kAetherWisp = 3113,
	kForbiddenIdol = 3114,
	kNashorsTooth = 3115,
	kRylaisCrystalScepter = 3116,
	kBootsOfMobility = 3117,
	kWickedHatchet = 3122,
	kExecutionersCalling = 3123,
	kGuinsoosRageblade = 3124,
	kCaulfieldsWarhammer = 3133,
	kSerratedDirk = 3134,
	kVoidStaff = 3135,
	kHauntingGuise = 3136,
	kDervishBlade = 3137,
	kMercurialScimitar = 3139,
	kQuicksilverSash = 3140,
	kYomuusGhostblade = 3142,
	kRanduinsOmen = 3143,
	kBilgewaterCutlass = 3144,
	kHextechRevolver = 3145,
	kHextechGunblade = 3146,
	kDuskbladeOfDraktharr = 3147,
	kLiandrysTorment = 3151,
	kHextechProtobelt01 = 3152,
	kBladeOfTheRuinedKing = 3153,
	kHexdrinker = 3155,
	kMawOfMalmortius = 3156,
	kZhonyasHourglass = 3157,
	kIonianBootsOfLucidity = 3158,
	kMorellonomicon = 3165,
	kMoonflairSpellblade = 3170,
	kAthenesUnholyGrail = 3174,
	kHeadOfKhazixBonetooth = 3175,
	kSanguineBlade = 3181,
	kGuardiansHammer = 3184,
	kTheLightbringer = 3185,
	kArcaneSweeper = 3187,
	kLocketOfTheIronSolari = 3190,
	kSeekersArmguard = 3191,
	kTheHexCoreMk1 = 3196,
	kTheHexCoreMk2 = 3197,
	kPerfectHexCore = 3198,
	kPrototypeHexCore = 3200,
	kSpectresCowl = 3211,
	kMikaelsCrucible = 3222,
	kPoachersDirk = 3252,
	kLudensEcho = 3285,
	kAncientCoin = 3301,
	kRelicShield = 3302,
	kSpellthiefsEdge = 3303,
	kWardingTotem = 3340,
	kSweepingLens = 3341,
	kSoulAnchor = 3345, 
	kArcaneSweeperHunter = 3348,
	kGreaterStealthTotem = 3361,
	kGreaterVisionTotem = 3362,
	kFarsightAlteration = 3363,
	kOracleAlteration = 3364,
	kFaceOfTheMountain = 3401,
	kHeadOfKhazixSweeping = 3410,
	kHeadOfKhazixScrying = 3416,
	kHeadOfKhazixMementos = 3422 || 3455,
	kGoldenTranscendence = 3460,
	kGoldenTranscendenceDisabled = 3461,
	kSeerStone = 3462,
	kArdentCenser = 3504,
	kEssenceReaver = 3508,
	kZzRotPortal = 3512,
	kTheBlackSpear = 3599,
	kSiegeTeleport = 3630,
	kSiegeBallista = 3631,
	kSiegeUnknown = 3632,
	kSiegeTeleport2 = 3633,
	kTowerBeamOfRuination = 3634,
	kPortPad = 3635,
	kTowerStormBulwark = 3636,
	kNexusSiegeWeaponSlot = 3637,
	kFlashZone = 3640,
	kVanguardBanner = 3641,
	kSiegeRefund = 3642,
	kEntropyField = 3643,
	kSeerStoneTrinket = 3645,
	kShieldTotem = 3647,
	kSiegeTeleportInactive = 3648,
	kSiegeSightWarder = 3649,
	kBootEnchantmentWarrior = 3671,
	kBootEnchantmentCinderhulk = 3672,
	kBootEnchantmentRunicEchoes = 3673,
	kFrostedSnax = 3680,
	kSuperSpicySnax = 3681,
	kEspressoSnax = 3682,
	kRainbowSnaxPartyPack = 3683,
	kStalkersBlade = 3706,
	kTrackersKnife = 3711,
	kSkirmishersSabre = 3715,
	kDeadMansPlate = 3742,
	kTitanicHydra = 3748,
	kBamisCinder = 3751,
	kRighteousGlory = 3800,
	kCrystallineBracer = 3801,
	kLostChapter = 3802,
	kDeathsDance = 3812,
	kEdgeOfNight = 3814,
	kFireAtWill = 3901,
	kDeathsDaughter = 3902,
	kRaiseMorale = 3903,
};

#endif // LPPConstants_h__