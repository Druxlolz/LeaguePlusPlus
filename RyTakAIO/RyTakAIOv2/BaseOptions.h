#ifndef BASEOPTIONS_H__
#define BASEOPTIONS_H__

#pragma once

#include "PluginSDK.h"
#include "SpellLib.h"

//Main Menu Screens
static IMenu* MainMenu;
static IMenu* ComboMenu;
static IMenu* RyzeCombos;
static IMenu* MeleeOptionsC;
static IMenu* RangedOptionsC;
static IMenu* MeleeOptionsH;
static IMenu* RangedOptionsH;
static IMenu* MeleeOptionsL;
static IMenu* RangedOptionsL;
static IMenu* MeleeOptionsK;
static IMenu* RangedOptionsK;
static IMenu* PickACardMenu;
static IMenu* ComboMode;
static IMenu* HarassMenu;
static IMenu* LaneClearMenu;
static IMenu* JungleClearMenu;
static IMenu* GapCloseMenu;
static IMenu* KSMenu;
static IMenu* DrawMenu;

//Combo Menu
static IMenuOption* UseCombo;
static IMenuOption* ComboQ;
static IMenuOption* ComboW;
static IMenuOption* ComboWStacks;
static IMenuOption* ComboE;
static IMenuOption* ComboEFeathers;
static IMenuOption* ComboR;
static IMenuOption* SemiR;
static IMenuOption* UseBasicCombo;
static IMenuOption* UseAdvCombo;
static IMenuOption* RSafeRange;
static IMenuOption* HitRChampions;
static IMenuOption* DisableAA;
static IMenuOption* ComboQ2;
static IMenuOption* ComboW2;
static IMenuOption* ComboE2;
static IMenuOption* SemiEQ;
static IMenuOption* PullDefault;

//Harass Menu
static IMenuOption* HarassMana;
static IMenuOption* HarassQ;
static IMenuOption* HarassW;
static IMenuOption* HarassE;
static IMenuOption* HarassEStacks;
static IMenuOption* HarassQ2;
static IMenuOption* HarassW2;
static IMenuOption* HarassE2;

//Jungle Clear
static IMenuOption* JungleClearMana;
static IMenuOption* JungleClearQ;
static IMenuOption* JungleClearW;
static IMenuOption* JungleClearE;
static IMenuOption* JungleClearQ2;
static IMenuOption* JungleClearW2;
static IMenuOption* JungleClearE2;
static IMenuOption* JungleClearR;
static IMenuOption* JungleClearKey;

//Lane Clear Menu
static IMenuOption* LaneClearMana;
static IMenuOption* LaneClearQ;
static IMenuOption* LaneClearW;
static IMenuOption* LaneClearE;
static IMenuOption* LaneClearQ2;
static IMenuOption* LaneClearW2;
static IMenuOption* LaneClearE2;
static IMenuOption* LaneClearR;
static IMenuOption* LaneClearQMinions;
static IMenuOption* LaneClearWMinions;
static IMenuOption* LaneClearEMinions;
static IMenuOption* LaneClearRMinions;

//KillSteal Menu
static IMenuOption* KSQ;
static IMenuOption* KSW;
static IMenuOption* KSE;
static IMenuOption* KSR;
static IMenuOption* KSQ2;
static IMenuOption* KSW2;
static IMenuOption* KSE2;

//Gap Close Menu
static IMenuOption* GapCloseQ;
static IMenuOption* GapCloseW;
static IMenuOption* GapCloseE;
static IMenuOption* GapCloseR;
static IMenuOption* GapCloseQ2;
static IMenuOption* GapCloseW2;
static IMenuOption* GapCloseE2;
static IMenuOption* PushWithQ;
static IMenuOption* PushWithW;
static IMenuOption* PushWithE;
static IMenuOption* PushWithR;
static IMenuOption* PushWithQ2;
static IMenuOption* PushWithW2;
static IMenuOption* PushWithE2;
static IMenuOption* PushDistance;

//Misc. MenuOptions
static IMenuOption* QAfterAttack;
static IMenuOption* QMinionHarass;
static IMenuOption* HarassExQ;
static IMenuOption* AutoEKillable;
static IMenuOption* AllyUltSave;
static IMenuOption* UseQECombo;
static IMenuOption* BounceHarass;
static IMenuOption* BounceClear;
static IMenuOption* BounceEnemy;
static IMenuOption* BounceCrit;

//Drawings Menu
static IMenuOption* DrawQ;
static IMenuOption* DrawW;
static IMenuOption* DrawE;
static IMenuOption* DrawQ2;
static IMenuOption* DrawW2;
static IMenuOption* DrawE2;
static IMenuOption* DrawR;
static IMenuOption* DrawReady;
static IMenuOption* DrawOff;

//Spells Data Loader
static ISpell2* QCharged;
static ISpell2* QHop;

//Summoner Spell Stuff
static ISpell* Flash;
static ISpell* Ignite;

//TF Stuff
static IMenuOption* PickBluesOption;
static IMenuOption* PickYellowsOption;
static IMenuOption* PickRedsOption;

//Jayce Stuff
static IMenuOption* ComboEQ;
static IMenuOption* ChangeForm;

//Ryze Stuff
static IMenuOption* ShieldC;
static IMenuOption* StunC;
static IMenuOption* DelayC;
static IMenuOption* DelayQC;

//Vector3 Positions Common Calls
static Vec3 rPosCast;
static Vec3 rPosLast;
static Vec2 FeatherV2;
static Vec3 FeatherV3;

//Target Selector Common
static IUnit* rTargetLast;
static IUnit* Enemy;
static IUnit* Enemy1;
static IUnit* Enemy2;
static IUnit* enemy;
static IUnit* minion;
static IUnit* minion1;
static IUnit* minion2;
static IUnit* target;
static IUnit* ally;

//Tick Stuff
static int FeatherTickCount;

#endif // !BASEOPTIONS_H__