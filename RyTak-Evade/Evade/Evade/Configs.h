#ifndef Configs_h__
#define Configs_h__

#include "PluginSDK.h"
#include "IChampionManager.h"

#include <unordered_map>

struct EvadeMenuOptions
{
	EvadeMenuOptions()
	{
		if (EvadeMode1->Enabled())
		{
			CrossingTime = 550;
			EvadePointChangeTime = 400;
			EvadingFirstTime = 350;
			EvadingSecondTime = 160;
			EvadingRouteChangeTime = 350;
			ExtraSpellRadius = 9;
			ExtraSpellRange = 20;
			GridSize = 10;
			PathFindingInnerDistance = 50;
			PathFindingOuterDistance = 100;
		}
		if (EvadeMode2->Enabled())
		{
			CrossingTime = 250;
			EvadePointChangeTime = 300;
			EvadingFirstTime = 250;
			EvadingSecondTime = 80;
			EvadingRouteChangeTime = 250;
			ExtraSpellRadius = 9;
			ExtraSpellRange = 20;
			GridSize = 10;
			PathFindingInnerDistance = 35;
			PathFindingOuterDistance = 60;
		}
		if (EvadeMode3->Enabled())
		{
			CrossingTime = 50;
			EvadePointChangeTime = 0;
			EvadingFirstTime = 0;
			EvadingSecondTime = 0;
			EvadingRouteChangeTime = 0;
			ExtraSpellRadius = 9;
			ExtraSpellRange = 20;
			GridSize = 10;
			PathFindingInnerDistance = 35;
			PathFindingOuterDistance = 60;
		}
	}

	void Initialize()
	{
		LoadMenuOptions();
	}

	IMenuOption* GetOptionForSpellName(std::string const Name);
	void LoadMenuOptions();
	void UnloadMenu();
	void LoadSpecialSpellPlugins();
	void LoadSpecialSpell(SpellData* Args);
	void KeyTurnOnOffMaster();

	// Constants
	int CrossingTime;
	int EvadePointChangeTime;
	int EvadingFirstTime;
	int EvadingRouteChangeTime;
	int EvadingSecondTime;
	int ExtraSpellRadius;
	int ExtraSpellRange;
	int GridSize;
	int PathFindingInnerDistance;
	int PathFindingOuterDistance;

	// User Options
	IMenuOption* CheckBlock;
	IMenuOption* CheckCollision;
	IMenuOption* CheckHp;
	IMenuOption* DodgeCircle;
	IMenuOption* DodgeCone;
	IMenuOption* DodgeDangerous;
	IMenuOption* DodgeFoW;
	IMenuOption* DodgeLine;
	IMenuOption* DodgeTrap;
	IMenuOption* DrawSpells;
	IMenuOption* DrawStatus;
	IMenuOption* Enabled;
	IMenuOption* Enabledkey;
	IMenuOption* EvadeMode;
	IMenuOption* EvadeMode1;
	IMenuOption* EvadeMode2;
	IMenuOption* EvadeMode3;
	short keystate;
	bool KeyWasDown = false;

	// Custom Spells

//private:
	std::unordered_map<std::string, IMenuOption*> SpellMenuOptions;
	std::unordered_map<std::string, IChampionManager*> ChampionManagers;
};

extern EvadeMenuOptions* Configs;

#endif // Configs_h__
