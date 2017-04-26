#pragma once
#include "BaseOptions.h"
#include "SpellLib.h"

class KarthusBase
{
public:
	void Menu()
	{
		MainMenu = GPluginSDK->AddMenu("RyTaks_Karthus");

		ComboMenu = MainMenu->AddMenu("Combo Settings");
		ComboQ = ComboMenu->CheckBox("Use Q", true);
		ComboW = ComboMenu->CheckBox("Use W", true);
		ComboE = ComboMenu->CheckBox("Use E", true);

		HarassMenu = MainMenu->AddMenu("Harass Settings");
		HarassQ = HarassMenu->CheckBox("Use Q", true);
		HarassE = HarassMenu->CheckBox("Use E", true);
		HarassMana = HarassMenu->AddFloat("Min. Mana", 0, 100, 60);

		LaneClearMenu = MainMenu->AddMenu("Farm Settings");
		LaneClearQ = LaneClearMenu->CheckBox("Use Q", true);
		LaneClearE = LaneClearMenu->CheckBox("Use E", true);
		LaneClearEMinions = LaneClearMenu->AddFloat("Hit Minions with E", 1, 6, 3);
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
		SpellLib().Karthus();
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
			for (auto target : GEntityList->GetAllHeros(false, true))
			{
				if (ComboQ->Enabled() && Q->IsReady() && target->IsValidTarget(GEntityList->Player(), Q->Range()))
				{
					Q->CastOnTarget(target, 6);
				}
				if (ComboW->Enabled() && W->IsReady() && target->IsValidTarget(GEntityList->Player(), W->Range()))
				{
					W->CastOnTarget(target, 5);
				}
				if (ComboE->Enabled() && E->IsReady() && target->IsValidTarget(GEntityList->Player(), E->Range()))
				{
					if (EnemyIsInSpellRange(450) == true && !GEntityList->Player()->HasBuff("KarthusDefile"))
					{
						E->CastOnPlayer();
					}
					if (EnemyIsInSpellRange(450) == false && GEntityList->Player()->HasBuff("KarthusDefile"))
					{
						E->CastOnPlayer();
					}
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
				if (HarassQ->Enabled() && Q->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget(GEntityList->Player(), Q->Range()))
				{
					Q->CastOnTarget(target, 5);
				}
				if (HarassE->Enabled() && E->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget(GEntityList->Player(), E->Range()))
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
			if (GEntityList->Player()->ManaPercent() >= LaneClearMana->GetFloat())
			{
				minion = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
				for (auto minion : GEntityList->GetAllMinions(false, true, true))
				{
					if (minion->IsEnemy(GEntityList->Player()) && minion != nullptr && !minion->IsDead() && GEntityList->Player()->IsValidTarget(minion, Q->Range()))
					{
						if (LaneClearQ->Enabled() && Q->IsReady() && minion->IsValidTarget(GEntityList->Player(), Q->Range()))
						{
							Q->LastHitMinion();
						}
						if (LaneClearE->Enabled() && E->IsReady() && minion->IsValidTarget(GEntityList->Player(), E->Range()))
						{
							E->CastOnTarget(minion, 6);
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
					auto dmg = GPluginSDK->GetDamage()->GetSpellDamage(GEntityList->Player(), Enemy, kSlotQ);
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
					auto dmg = GPluginSDK->GetDamage()->GetSpellDamage(GEntityList->Player(), Enemy, kSlotR);
					if (Enemy->GetHealth() <= dmg && Enemy->IsValidTarget(GEntityList->Player(), R->Range()))
					{
						R->CastOnPlayer();
					}
				}
			}
		}
	}
};