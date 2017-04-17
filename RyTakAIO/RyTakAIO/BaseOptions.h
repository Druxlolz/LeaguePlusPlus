#pragma once
#include "PluginSDK.h"
#include "SpellLib.h"
#include "CommonLib.cpp"

//Main Menu Screens
IMenu* MainMenu;
IMenu* ComboMenu;
IMenu* RyzeCombos;
IMenu* MeleeOptionsC;
IMenu* RangedOptionsC;
IMenu* MeleeOptionsH;
IMenu* RangedOptionsH;
IMenu* MeleeOptionsL;
IMenu* RangedOptionsL;
IMenu* MeleeOptionsK;
IMenu* RangedOptionsK;
IMenu* PickACardMenu;
IMenu* ComboMode;
IMenu* HarassMenu;
IMenu* LaneClearMenu;
IMenu* JungleClearMenu;
IMenu* GapCloseMenu;
IMenu* KSMenu;
IMenu* DrawMenu;

//Combo Menu
IMenuOption* UseCombo;
IMenuOption* ComboQ;
IMenuOption* ComboW;
IMenuOption* ComboWStacks;
IMenuOption* ComboE;
IMenuOption* ComboR;
IMenuOption* SemiR;
IMenuOption* UseBasicCombo;
IMenuOption* UseAdvCombo;
IMenuOption* RSafeRange;
IMenuOption* HitRChampions;
IMenuOption* DisableAA;
IMenuOption* ComboQ2;
IMenuOption* ComboW2;
IMenuOption* ComboE2;
IMenuOption* SemiEQ;

//Harass Menu
IMenuOption* HarassMana;
IMenuOption* HarassQ;
IMenuOption* HarassW;
IMenuOption* HarassE;
IMenuOption* HarassEStacks;
IMenuOption* HarassQ2;
IMenuOption* HarassW2;
IMenuOption* HarassE2;

//Jungle Clear
IMenuOption* JungleClearMana;
IMenuOption* JungleClearQ;
IMenuOption* JungleClearW;
IMenuOption* JungleClearE;
IMenuOption* JungleClearQ2;
IMenuOption* JungleClearW2;
IMenuOption* JungleClearE2;
IMenuOption* JungleClearR;
IMenuOption* JungleClearKey;

//Lane Clear Menu
IMenuOption* LaneClearMana;
IMenuOption* LaneClearQ;
IMenuOption* LaneClearW;
IMenuOption* LaneClearE;
IMenuOption* LaneClearQ2;
IMenuOption* LaneClearW2;
IMenuOption* LaneClearE2;
IMenuOption* LaneClearR;
IMenuOption* LaneClearQMinions;
IMenuOption* LaneClearWMinions;
IMenuOption* LaneClearEMinions;
IMenuOption* LaneClearRMinions;

//KillSteal Menu
IMenuOption* KSQ;
IMenuOption* KSW;
IMenuOption* KSE;
IMenuOption* KSR;
IMenuOption* KSQ2;
IMenuOption* KSW2;
IMenuOption* KSE2;

//Gap Close Menu
IMenuOption* GapCloseQ;
IMenuOption* GapCloseW;
IMenuOption* GapCloseE;
IMenuOption* GapCloseR;
IMenuOption* GapCloseQ2;
IMenuOption* GapCloseW2;
IMenuOption* GapCloseE2;
IMenuOption* PushWithQ;
IMenuOption* PushWithW;
IMenuOption* PushWithE;
IMenuOption* PushWithR;
IMenuOption* PushWithQ2;
IMenuOption* PushWithW2;
IMenuOption* PushWithE2;
IMenuOption* PushDistance;

//Misc. MenuOptions
IMenuOption* QAfterAttack;
IMenuOption* QMinionHarass;
IMenuOption* HarassExQ;
IMenuOption* AutoEKillable;
IMenuOption* AllyUltSave;
IMenuOption* UseQECombo;
IMenuOption* BounceHarass;
IMenuOption* BounceClear;
IMenuOption* BounceEnemy;

//Drawings Menu
IMenuOption* DrawQ;
IMenuOption* DrawW;
IMenuOption* DrawE;
IMenuOption* DrawQ2;
IMenuOption* DrawW2;
IMenuOption* DrawE2;
IMenuOption* DrawR;
IMenuOption* DrawReady;
IMenuOption* DrawOff;

//Spells Data Loader
ISpell2* QCharged;
ISpell2* QHop;

//Summoner Spell Stuff
ISpell* Flash;
ISpell* Ignite;

//TF Stuff
IMenuOption* PickBluesOption;
IMenuOption* PickYellowsOption;
IMenuOption* PickRedsOption;

//Jayce Stuff
IMenuOption* ComboEQ;
IMenuOption* ChangeForm;

//Ryze Stuff
IMenuOption* ShieldC;
IMenuOption* StunC;
IMenuOption* DelayC;
IMenuOption* DelayQC;

//Vector3 Positions Common Calls
Vec3 rPosCast;
Vec3 rPosLast;

//Target Selector Common
IUnit* rTargetLast;
IUnit* Enemy;
IUnit* Enemy1;
IUnit* Enemy2;
IUnit* enemy;
IUnit* minion;
IUnit* minion1;
IUnit* minion2;
IUnit* target;
IUnit* ally;

