#pragma once
#include "PluginSDK.h"
#include "BaseOptions.h"
#include "OnRender.cpp"

class IChampion
{
public:
	virtual ~IChampion() = default;
	//virtual void OnGameUpdate() = 0;
	virtual void Menu() = 0;
	virtual void Spells() = 0;
	virtual void Combo() = 0;
	virtual void Harass() = 0;
	virtual void LaneClear() = 0;
	virtual void KS() = 0;
	virtual void OnRender() = 0;
	virtual void BeforeAttack(IUnit* Source, IUnit* Target) = 0;
	virtual void AfterAttack(IUnit * Source, IUnit * Target) = 0;
	virtual void OnGapCloser(GapCloserSpell const& Args) = 0;
	virtual void OnProcessSpell(CastedSpell const& Args) = 0;
	//virtual void OnLoad() = 0;
};