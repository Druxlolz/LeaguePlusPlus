#pragma once
#include "BaseOptions.h"
#include "OnRender.h"
#include "SpellLib.h"

class XerathBase
{
public:
	void Menu()
	{
		MainMenu = GPluginSDK->AddMenu("RyTak's Xerath");

		ComboMenu = MainMenu->AddMenu("Combo Settings");
		ComboQ = ComboMenu->CheckBox("Use Q", true);
		ComboW = ComboMenu->CheckBox("Use W", true);
		ComboE = ComboMenu->CheckBox("Use E", true);
		SemiR = ComboMenu->AddKey("Semi-Auto R", 84);

		HarassMenu = MainMenu->AddMenu("Harass Settings");
		HarassQ = HarassMenu->CheckBox("Use Q", true);
		HarassW = HarassMenu->CheckBox("Use W", true);
		HarassE = HarassMenu->CheckBox("Use E", true);
		HarassMana = HarassMenu->AddFloat("Min. Mana", 0, 100, 60);

		LaneClearMenu = MainMenu->AddMenu("Farm Settings");
		LaneClearQ = LaneClearMenu->CheckBox("Use Q", true);
		LaneClearW = LaneClearMenu->CheckBox("Use W", true);
		LaneClearE = LaneClearMenu->CheckBox("Use E", true);
		LaneClearQMinions = LaneClearMenu->AddInteger("# Minions to hit: Q", 1, 6, 3);
		LaneClearWMinions = LaneClearMenu->AddInteger("# Minions to hit: W", 1, 6, 3);
		LaneClearMana = LaneClearMenu->AddFloat("Min. Mana", 0, 100, 40);

		GapCloseMenu = MainMenu->AddMenu("Gap Closer Settings");
		GapCloseE = GapCloseMenu->CheckBox("Stun Gap Close Target", true);

		KSMenu = MainMenu->AddMenu("Killsteal Settings");
		KSQ = KSMenu->CheckBox("Killsteal with Q", true);
		KSW = KSMenu->CheckBox("Killsteal with W", true);
		KSE = KSMenu->CheckBox("Killsteal with E", true);
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
		SpellLib().Xerath();
	}

	int GetEnemiesInRange(float range)
	{
		auto enemies = GEntityList->GetAllHeros(false, true);
		auto enemiesInRange = 0;

		for (auto enemy : enemies)
		{
			if (enemy != nullptr && enemy->GetTeam() != GEntityList->Player()->GetTeam() && enemy->IsValidTarget() && enemy->IsHero())
			{
				auto flDistance = (enemy->GetPosition() - GEntityList->Player()->GetPosition()).Length2D();
				if (flDistance < range)
				{
					enemiesInRange++;
				}
			}
		}
		return enemiesInRange;
	}

	int GetMinionsInRange(float range)
	{
		auto minions = GEntityList->GetAllMinions(false, true, true);
		auto minionsInRange = 0;

		for (auto minion : minions)
		{
			if (minion != nullptr && minion->GetTeam() != GEntityList->Player()->GetTeam() && minion->IsValidTarget())
			{
				auto flDistance = (minion->GetPosition() - GEntityList->Player()->GetPosition()).Length2D();
				if (flDistance < range)
				{
					minionsInRange++;
				}
			}
		}
		return minionsInRange;
	}

	void Combo()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			target = GTargetSelector->FindTarget(QuickestKill, SpellDamage, Q->Range());
			for (auto target : GEntityList->GetAllHeros(false, true));
			if (target != nullptr && target->IsValidTarget() && target->IsHero() && !target->IsDead())
			{
				if (ComboQ->Enabled())
				{
					if (Q->IsCharging())
					{
						Q->FindTarget(SpellDamage);
						{
							if (GetEnemiesInRange(Q->Range()) >= 1)
							{
								Q->CastOnTarget(target, kHitChanceCollision);
							}
						}
					}
					else if (Q->IsReady())
					{
						Q->StartCharging();
					}
					else return;
				}
				if (ComboW->Enabled() && W->IsReady())
				{
					W->CastOnTarget(target, 5);
				}
				if (ComboE->Enabled() && E->IsReady())
				{
					E->CastOnTarget(target, 4);
				}
			}
		}
	}

	void Harass()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger())
		{
			target = GTargetSelector->FindTarget(QuickestKill, SpellDamage, Q->Range());
			for (auto target : GEntityList->GetAllHeros(false, true));
			if (HarassQ->Enabled() && Q->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger())
			{
				if (Q->IsCharging())
				{
					Q->FindTarget(SpellDamage);
					{
						if (GetEnemiesInRange(Q->Range()) >= 1)
						{
							Q->CastOnTarget(target, kHitChanceCollision);
						}
					}
				}
				else if (Q->IsReady() && GetEnemiesInRange(Q->Range()) >= 1)
				{
					Q->StartCharging();
				}
				else return;
			}
			if (HarassW->Enabled() && W->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger())
			{
				W->CastOnTarget(target);
			}
			if (HarassE->Enabled() && E->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger())
			{
				E->CastOnTarget(target);
			}
		}
	}

	void LaneClear()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			if (GEntityList->Player()->ManaPercent() >= LaneClearMana->GetFloat())
			{
				for (auto minion : GEntityList->GetAllMinions(false, true, true))
				{
					if (minion != nullptr && !minion->IsDead() && minion->IsValidTarget(minion, Q->Range()))
					{
						if (LaneClearQ->Enabled())
						{
							if (Q->IsCharging())
							{
								Q->FindTarget(SpellDamage);
								{
									if (GetMinionsInRange(Q->Range()) >= LaneClearQMinions->GetInteger() && !minion->IsInvulnerable())
									{
										Q->LastHitMinion();
									}
								}
							}
							else if (Q->IsReady() && GetMinionsInRange(Q->Range()) >= LaneClearQMinions->GetInteger())
							{
								Q->StartCharging();
							}
							else return;
						}
						if (LaneClearW->Enabled() && W->IsReady() && LaneClearWMinions->GetInteger())
						{
							Vec3 pos;
							int hit;
							GPrediction->FindBestCastPosition(W->Range(), W->Radius(), false, true, false, pos, hit);
							if (hit >= LaneClearWMinions->GetInteger())
							{
								W->CastOnPosition(pos);
							}
						}
						if (LaneClearE->Enabled() && E->IsReady())
						{
							E->FindTarget(SpellDamage);
							{
								E->LastHitMinion();
							}
						}
					}
				}
			}
		}
	}

	void KS()
	{
		Enemy = GTargetSelector->FindTarget(ClosestPriority, SpellDamage, Q->Range());
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
						{
							Q->CastOnTarget(Enemy);
						}
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
				if (KSE->Enabled() && E->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotE, E->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg)
					{
						E->CastOnTarget(Enemy, 5);
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
	
	bool InitialR()
	{
		if (GEntityList->Player()->HasBuff("XerathLocusOfPower2") || GEntityList->Player()->HasBuff("XerathLocusPulse"))
		{
			return  true;
		}
		else
		{
			return false;
		}
	}

	void RDamage()
	{
		if (GetAsyncKeyState(SemiR->GetInteger()) && R->IsReady())
		{
			enemy = GTargetSelector->FindTarget(ClosestToCursorPriority, SpellDamage, R->Range());
			for (auto enemy : GEntityList->GetAllHeros(false, true))
			{
				if (enemy->IsEnemy(GEntityList->Player()) && (GEntityList->Player()->GetPosition() - enemy->GetPosition()).Length2D() <= R->Range() && enemy->IsValidTarget())
				{
					if (InitialR() == true)
					{
						R->CastOnTarget(enemy, 5);
					}
				}
			}
		}
	}

	void GapCloser()
	{
		if (target->IsDashing() && GapCloseE->Enabled())
		{
			E->CastOnTarget(target, 5);
		}
	}

	void RRange()
	{
		if (GSpellBook->GetLevel(kSlotR) == 0)
			return;
		else if (GSpellBook->GetLevel(kSlotR) == 1)
			R->SetOverrideRange(3520);
		else if (GSpellBook->GetLevel(kSlotR) == 2)
			R->SetOverrideRange(4840);
		else if (GSpellBook->GetLevel(kSlotR) == 3)
			R->SetOverrideRange(6160);
	}
};