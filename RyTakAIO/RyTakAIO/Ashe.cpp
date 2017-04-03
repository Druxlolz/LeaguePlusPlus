#pragma once
#include "BaseOptions.h"
#include "OnRender.h"
#include "SpellLib.h"

class AsheBase
{
public:
	void Menu()
	{
		MainMenu = GPluginSDK->AddMenu("RyTak's Ashe");

		ComboMenu = MainMenu->AddMenu("Combo Settings");
		ComboQ = ComboMenu->CheckBox("Use Q", true);
		ComboW = ComboMenu->CheckBox("Use W", true);
		ComboE = ComboMenu->CheckBox("Use E", true);
		SemiR = ComboMenu->AddKey("Semi-Auto R", 84);

		HarassMenu = MainMenu->AddMenu("Harass Settings");
		HarassQ = HarassMenu->CheckBox("Use Q", true);
		HarassW = HarassMenu->CheckBox("Use W", true);
		HarassMana = HarassMenu->AddFloat("Min. Mana", 0, 100, 60);

		LaneClearMenu = MainMenu->AddMenu("Farm Settings");
		LaneClearQ = LaneClearMenu->CheckBox("Use Q", true);
		LaneClearW = LaneClearMenu->CheckBox("Use W", true);
		LaneClearWMinions = LaneClearMenu->AddInteger("Hit x Minions with W", 1, 6, 3);
		LaneClearMana = LaneClearMenu->AddFloat("Min. Mana", 0, 100, 40);

		GapCloseMenu = MainMenu->AddMenu("Gap Closer Settings");
		GapCloseR = GapCloseMenu->CheckBox("Use R on Gap Closer", true);

		KSMenu = MainMenu->AddMenu("Killsteal Settings");
		KSW = KSMenu->CheckBox("Killsteal with W", true);
		KSR = KSMenu->CheckBox("Killsteal with R", false);

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
		SpellLib().Ashe();
	}

	void Combo()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			target = target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
			for (auto target : GEntityList->GetAllHeros(false, true))
			{
				if (target != nullptr && target->IsValidTarget() && target->IsHero())
				{
					if (Q->IsReady() && ComboQ->Enabled())
					{
						Q->CastOnTarget(target, 5);
					}
					if (W->IsReady() && ComboW->Enabled())
					{
						W->CastOnTarget(target, 5);
					}
				}
			}
		}
	}

	void Harass()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed && GEntityList->Player()->ManaPercent() >= HarassMana->GetFloat())
		{
			target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());

			if (HarassQ->Enabled() && Q->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetFloat() && target->IsValidTarget())
			{
				Q->CastOnTarget(target, 3);
			}
			if (HarassW->Enabled() && W->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetFloat() && target->IsValidTarget())
			{
				W->CastOnTarget(target, 3);
			}
		}
	}

	void LaneClear()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			if (GEntityList->Player()->ManaPercent() >= LaneClearMana->GetFloat())
			{
				minion = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, W->Range());
				for (auto minion : GEntityList->GetAllMinions(false, true, true))
				{
					if (minion->IsEnemy(GEntityList->Player()) && !minion->IsDead() && GEntityList->Player()->IsValidTarget(minion, Q->Range()))
					{
						if (LaneClearQ->Enabled() && Q->IsReady())
						{
							Q->CastOnTarget(minion, 5);
						}
						if (LaneClearW->Enabled() && W->IsReady() && LaneClearWMinions->GetInteger())
						{
							W->CastOnTarget(minion, 5);
						}
					}
				}
			}
		}
	}

	void KS()
	{
		Enemy = GTargetSelector->FindTarget(ClosestPriority, PhysicalDamage, Q->Range());
		for (auto Enemy : GEntityList->GetAllHeros(false, true))
		{
			if (Enemy != nullptr && Enemy->IsValidTarget() && Enemy->IsHero())
			{
				if (KSW->Enabled() && W->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotW, W->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg)
					{
						W->CastOnTarget(Enemy, 5);
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

	void GapCloser()
	{
		if (target->IsDashing() && GapCloseR->Enabled())
		{
			R->CastOnTarget(target, 5);
		}
	}

	void RDamage()
	{
		if (GetAsyncKeyState(SemiR->GetInteger()) && R->IsReady())
		{
			enemy = GTargetSelector->FindTarget(QuickestKill, SpellDamage, R->Range());
			for (auto enemy : GEntityList->GetAllHeros(false, true))
			{
				if (enemy->IsValidTarget() && enemy != nullptr && enemy->IsHero())
				{
					R->CastOnTarget(enemy, 5);
				}
			}
		}
	}
};