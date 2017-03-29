#pragma once
#include "BaseOptions.h"
#include "OnRender.h"
#include "SpellLib.h"

class YasuoBase
{
public:
	void Menu()
	{
		MainMenu = GPluginSDK->AddMenu("RyTak's Yasuo");

		ComboMenu = MainMenu->AddMenu("Combo Settings");
		ComboQ = ComboMenu->CheckBox("Use Q", true);
		ComboE = ComboMenu->CheckBox("Use E", true);
		ComboR = ComboMenu->CheckBox("Use R", true);

		HarassMenu = MainMenu->AddMenu("Harass Settings");
		HarassQ = HarassMenu->CheckBox("Use Q", true);
		HarassE = HarassMenu->CheckBox("Use E", true);

		LaneClearMenu = MainMenu->AddMenu("Farm Settings");
		LaneClearQ = LaneClearMenu->CheckBox("Use Q", true);
		LaneClearE = LaneClearMenu->CheckBox("Use E", true);

		KSMenu = MainMenu->AddMenu("Killsteal Settings");
		KSQ = KSMenu->CheckBox("Killsteal with Q", true);
		KSE = KSMenu->CheckBox("Killsteal with E", true);
		KSR = KSMenu->CheckBox("Killsteal with R", true);

		DrawMenu = MainMenu->AddMenu("Drawing Settings");
		DrawReady = DrawMenu->CheckBox("Draw Only Ready Spells", true);
		DrawOff = DrawMenu->CheckBox("Disable Drawings", false);
		DrawQ = DrawMenu->CheckBox("Draw Q", true);
		DrawW = DrawMenu->CheckBox("Draw W", true);
		DrawE = DrawMenu->CheckBox("Draw E", true);
		DrawR = DrawMenu->CheckBox("Draw R", true);

	}

	void Spells()
	{
		SpellLib().Yasuo();
	}

	void Combo()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
			for (auto target : GEntityList->GetAllHeros(false, true))
			{
				if (ComboQ->Enabled() && Q->IsReady())
				{
					Q->CastOnTarget(target, 5);
				}
				if (ComboE->Enabled() && E->IsReady())
				{
					E->CastOnTarget(target, 5);
				}
				if (ComboR->Enabled() && R->IsReady())
				{
					R->CastOnTarget(target, 5);
				}
			}				
		}
	}

	void Harass()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
			for (auto target : GEntityList->GetAllHeros(false, true))
			{
				if (HarassQ->Enabled() && Q->IsReady())
				{
					Q->CastOnTarget(target, 5);
				}
				if (HarassE->Enabled() && E->IsReady())
				{
					E->CastOnTarget(target, 5);
				}
			}				
		}
	}

	void LaneClear()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			minion = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
			for (auto minion : GEntityList->GetAllMinions(false, true, true))
			{
				if (minion->IsEnemy(GEntityList->Player()) && !minion->IsDead() && GEntityList->Player()->IsValidTarget(minion, Q->Range()))
				{
					if (LaneClearQ->Enabled() && Q->IsReady())
					{
						Q->CastOnTarget(minion, 5);
					}
					if (LaneClearE->Enabled() && E->IsReady())
					{
						E->CastOnTarget(minion, 5);
					}
				}
			}
		}
	}

	void KS()
	{
		Enemy = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
		for (auto Enemy : GEntityList->GetAllHeros(false, true))
		{
			if (Enemy != nullptr && !Enemy->IsDead())
			{
				if (KSQ->Enabled() && Q->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotQ, Q->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg)
					{
						Q->CastOnTarget(Enemy, kHitChanceHigh);
					}
				}
				if (KSE->Enabled() && E->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotE, E->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg)
					{
						E->CastOnTarget(Enemy, kHitChanceHigh);
					}
				}
				if (KSR->Enabled() && R->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotR, R->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg)
					{
						R->CastOnTarget(Enemy, 5);
					}
				}
			}
		}
	}
};