#pragma once
#include "BaseOptions.h"
#include "SpellLib.h"

class ThreshBase
{
public:
	void Menu()
	{
		MainMenu = GPluginSDK->AddMenu("RyTaks_Thresh");

		ComboMenu = MainMenu->AddMenu("Combo Settings");
		ComboQ = ComboMenu->CheckBox("Use Q", true);
		ComboW = ComboMenu->CheckBox("Use W", true);
		ComboE = ComboMenu->CheckBox("Use E", true);
		PullDefault = ComboMenu->CheckBox("Pull E by Default", true);

		HarassMenu = MainMenu->AddMenu("Harass Settings");
		HarassQ = HarassMenu->CheckBox("Use Q", true);
		HarassE = HarassMenu->CheckBox("Use E", true);
		HarassMana = HarassMenu->AddFloat("Min. Mana", 0, 100, 60);

		LaneClearMenu = MainMenu->AddMenu("Farm Settings");
		LaneClearQ = LaneClearMenu->CheckBox("Use Q", true);
		LaneClearE = LaneClearMenu->CheckBox("Use E", true);
		LaneClearMana = LaneClearMenu->AddFloat("Min. Mana", 0, 100, 40);

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
		SpellLib().Thresh();
	}

	bool AllyIsInSpellRange(float range)
	{
		auto allies = GEntityList->GetAllHeros(true, false);
		auto alliesInSpellRange = false;

		for (auto ally : allies)
		{
			auto TargetDistance = (ally->GetPosition() - GEntityList->Player()->GetPosition()).Length2D();
			if (ally != nullptr && ally->GetTeam() == GEntityList->Player()->GetTeam() && ally->IsHero())
			{
				if (TargetDistance < range)
				{
					return true;
				}
				if (TargetDistance > range)
				{
					return false;
				}
			}
		}
		return false;
	}

	bool EnemyIsInSpellRange(float range)
	{
		auto enemies = GEntityList->GetAllHeros(false, true);
		auto enemiesInSpellRange = nullptr;

		for (auto enemy : enemies)
		{
			auto TargetDistance = (enemy->GetPosition() - GEntityList->Player()->GetPosition()).Length2D();
			if (enemy != nullptr && enemy->GetTeam() != GEntityList->Player()->GetTeam() && enemy->IsHero())
			{
				if (TargetDistance < range)
				{
					return true;
				}
				if (TargetDistance > range)
				{
					return false;
				}
			}
		}
		return false;
	}

	void Combo()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
			for (auto ally : GEntityList->GetAllHeros(true, false));
			for (auto target : GEntityList->GetAllHeros(false, true))
			{
				if (target != nullptr && target->IsHero())
				{
					if (ComboQ->Enabled() && Q->IsReady() && target->IsValidTarget(GEntityList->Player(), Q->Range()))
					{
						Q->CastOnTarget(target, 5);
					}
					if (ComboW->Enabled() && W->IsReady() && ally->IsValidTarget(GEntityList->Player(), W->Range()) && ally != nullptr && !ally->IsDead() && AllyIsInSpellRange(W->Range()) == true)
					{
						W->CastOnTarget(ally);
					}
					if (ComboE->Enabled() && E->IsReady() && target->IsValidTarget(GEntityList->Player(), E->Range()))
					{
						if (PullDefault->Enabled())
						{
							EPull();
						}
						else E->CastOnTarget(target, 5);
					}
				}
			}				
		}
	}

	void Harass()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
			for (auto target : GEntityList->GetAllHeros(false, true));
			{
				if (target != nullptr && target->IsHero())
				{
					if (HarassQ->Enabled() && Q->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget(GEntityList->Player(), Q->Range()))
					{
						Q->CastOnTarget(target, 6);
					}
					if (HarassE->Enabled() && E->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget(GEntityList->Player(), E->Range()))
					{
						if (PullDefault->Enabled())
						{
							EPull();
						}
						else E->CastOnTarget(target, 5);
					}
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
					if (minion->IsEnemy(GEntityList->Player()) && !minion->IsDead() && minion != nullptr)
					{
						if (LaneClearQ->Enabled() && Q->IsReady() && target->IsValidTarget(GEntityList->Player(), Q->Range()))
						{
							Q->CastOnTarget(minion);
						}
						if (LaneClearE->Enabled() && E->IsReady() && target->IsValidTarget(GEntityList->Player(), E->Range()))
						{
							E->CastOnTarget(minion);
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
					if (Enemy->GetHealth() <= dmg && Enemy->IsValidTarget(GEntityList->Player(), Q->Range()))
					{
						Q->CastOnTarget(Enemy, kHitChanceHigh);
					}
				}
				if (KSE->Enabled() && E->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotE, E->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg && Enemy->IsValidTarget(GEntityList->Player(), E->Range()))
					{
						E->CastOnTarget(Enemy, kHitChanceHigh);
					}
				}
				if (KSR->Enabled() && R->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotR, R->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg && Enemy->IsValidTarget(GEntityList->Player(), R->Range()) && EnemyIsInSpellRange(R->Range()) == true)
					{
						R->CastOnPlayer();
					}
				}
			}
		}
	}

	void EPull()
	{
		target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, E->Range());
		for (auto target : GEntityList->GetAllHeros(false, true));
		if (ComboE->Enabled() && E->IsReady() && target->IsValidTarget(GEntityList->Player(), E->Range()) && PullDefault->Enabled())
		{
			E->CastFrom(target->GetPosition(), GEntityList->Player()->GetPosition());
		}
	}
};