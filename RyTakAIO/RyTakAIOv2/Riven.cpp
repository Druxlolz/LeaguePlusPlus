#pragma once
#include "BaseOptions.h"
#include "SpellLib.h"

class RivenBase
{
public:
	void Menu()
	{
		MainMenu = GPluginSDK->AddMenu("RyTak's Riven");

		ComboMenu = MainMenu->AddMenu("Combo Settings");
		ComboQ = ComboMenu->CheckBox("Use Q", true);
		ComboW = ComboMenu->CheckBox("Use W", true);
		ComboE = ComboMenu->CheckBox("Use E", true);
		ComboR = ComboMenu->CheckBox("Use R", true);

		HarassMenu = MainMenu->AddMenu("Harass Settings");
		HarassQ = HarassMenu->CheckBox("Use Q", true);
		HarassW = HarassMenu->CheckBox("Use W", true);

		LaneClearMenu = MainMenu->AddMenu("Farm Settings");
		LaneClearQ = LaneClearMenu->CheckBox("Use Q", true);
		LaneClearW = LaneClearMenu->CheckBox("Use W", true);

		KSMenu = MainMenu->AddMenu("Killsteal Settings");
		KSQ = KSMenu->CheckBox("Killsteal with Q", true);
		KSW = KSMenu->CheckBox("Killsteal with W", true);
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
		SpellLib().Riven();
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
					Q->CastOnTarget(target);
				}
				if (ComboW->Enabled() && W->IsReady())
				{
					W->CastOnTarget(target);
				}
				if (ComboE->Enabled() && E->IsReady())
				{
					E->CastOnTarget(target);
				}
				if (ComboR->Enabled() && R->IsReady())
				{
					R->CastOnPlayer();
				}
			}				
		}
	}

	void Harass()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger())
		{
			target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
			for (auto target : GEntityList->GetAllHeros(false, true))
			{
				if (HarassQ->Enabled() && Q->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger())
				{
					Q->CastOnTarget(target);
				}
				if (HarassW->Enabled() && W->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger())
				{
					W->CastOnTarget(target);
				}
			}				
		}
	}

	void LaneClear()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			if (GEntityList->Player()->ManaPercent() >= LaneClearMana->GetFloat())
			{
				minion = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
				for (auto minion : GEntityList->GetAllMinions(false, true, true))
				{
					if (minion->IsEnemy(GEntityList->Player()) && !minion->IsDead() && GEntityList->Player()->IsValidTarget(minion, Q->Range()))
					{
						if (LaneClearQ->Enabled() && Q->IsReady())
						{
							Q->CastOnTarget(minion);
						}
						if (LaneClearW->Enabled() && W->IsReady())
						{
							W->CastOnTarget(minion);
						}
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
				if (KSW->Enabled() && W->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotW, W->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg)
					{
						W->CastOnTarget(Enemy, kHitChanceHigh);
					}
				}
				if (KSR->Enabled() && R2->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotR, R->GetDelay(), true);
					Vec3 pos;
					int hit;
					GPrediction->FindBestCastPosition(R2->Range(), R2->Radius(), true, false, true, pos, hit);
					if (Enemy->GetHealth() <= dmg)
					{
						R2->CastOnPosition(pos);
					}
				}
			}
		}
	}
};