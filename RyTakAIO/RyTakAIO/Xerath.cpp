#pragma once
#include "BaseOptions.h"
#include "SpellLib.h"

class XerathBase
{
public:
	void Menu()
	{
		MainMenu = GPluginSDK->AddMenu("RyTaks_Xerath");

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
			if (target != nullptr && target->IsHero() && !target->IsDead())
			{
				if (ComboQ->Enabled() && target->IsValidTarget(GEntityList->Player(), Q->Range()))
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
				}
				if (ComboW->Enabled() && W->IsReady() && target->IsValidTarget(GEntityList->Player(), W->Range()))
				{
					W->CastOnTarget(target, kHitChanceHigh);
				}
				if (ComboE->Enabled() && E->IsReady() && target->IsValidTarget(GEntityList->Player(), E->Range()))
				{
					E->CastOnTarget(target, kHitChanceHigh);
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
			if (HarassQ->Enabled() && Q->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget(GEntityList->Player(), Q->Range()))
			{
				if (Q->IsCharging())
				{
					Q->FindTarget(SpellDamage);
					{
						if (GetEnemiesInRange(Q->Range()) >= 1)
						{
							Q->CastOnTarget(target, kHitChanceHigh);
						}
					}
				}
				else if (Q->IsReady() && GetEnemiesInRange(Q->Range()) >= 1)
				{
					Q->StartCharging();
				}
			}
			if (HarassW->Enabled() && W->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget(GEntityList->Player(), W->Range()))
			{
				W->CastOnTarget(target, kHitChanceHigh);
			}
			if (HarassE->Enabled() && E->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget(GEntityList->Player(), E->Range()))
			{
				E->CastOnTarget(target, kHitChanceHigh);
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
									Vec3 pos;
									int hit;
									GPrediction->FindBestCastPosition(Q->Range(), Q->Radius(), false, true, false, pos, hit);
									if (GetMinionsInRange(Q->Range()) >= LaneClearQMinions->GetInteger() <= hit && !minion->IsInvulnerable())
									{
										Q->CastOnPosition(pos);
									}
								}
							}
							else if (Q->IsReady() && GetMinionsInRange(Q->Range()) >= LaneClearQMinions->GetInteger())
							{
								Q->StartCharging();
							}
						}
						if (LaneClearW->Enabled() && W->IsReady() && LaneClearWMinions->GetInteger() && minion->IsValidTarget(GEntityList->Player(), W->Range()))
						{
							Vec3 pos;
							int hit;
							GPrediction->FindBestCastPosition(W->Range(), W->Radius(), false, true, false, pos, hit);
							if (hit >= LaneClearWMinions->GetInteger())
							{
								W->CastOnPosition(pos);
							}
						}
						if (LaneClearE->Enabled() && E->IsReady() && minion->IsValidTarget(GEntityList->Player(), E->Range()))
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
					auto dmg = GPluginSDK->GetDamage()->GetSpellDamage(GEntityList->Player(), Enemy, kSlotQ);
					if (Enemy->GetHealth() <= dmg && Enemy->IsValidTarget(GEntityList->Player(), Q->Range()))
					{
						if (Q->IsCharging())
						{
							Q->FindTarget(SpellDamage);
							{
								if (GetEnemiesInRange(Q->Range()) >= 1)
								{
									Q->CastOnTarget(target, kHitChanceHigh);
								}
							}
						}
						else if (Q->IsReady())
						{
							Q->StartCharging();
						}
					}
				}
				if (KSW->Enabled() && W->IsReady())
				{
					auto dmg = GPluginSDK->GetDamage()->GetSpellDamage(GEntityList->Player(), Enemy, kSlotW);
					if (Enemy->GetHealth() <= dmg && Enemy->IsValidTarget(GEntityList->Player(), W->Range()))
					{
						W->CastOnTarget(Enemy, kHitChanceHigh);
					}
				}
				if (KSE->Enabled() && E->IsReady())
				{
					auto dmg = GPluginSDK->GetDamage()->GetSpellDamage(GEntityList->Player(), Enemy, kSlotE);
					if (Enemy->GetHealth() <= dmg && Enemy->IsValidTarget(GEntityList->Player(), E->Range()))
					{
						E->CastOnTarget(Enemy, kHitChanceHigh);
					}
				}
				if (KSR->Enabled() && R->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotR, R->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg && Enemy->IsValidTarget(GEntityList->Player(), R->Range()))
					{
						R->CastOnTarget(Enemy, kHitChanceHigh);
					}
				}
			}
		}
	}
	
	bool InitialR()
	{
		if (GetAsyncKeyState(SemiR->GetInteger()) && R->IsReady())
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
	}

	void RDamage()
	{
		if (GetAsyncKeyState(SemiR->GetInteger()) && R->IsReady())
		{
			enemy = GTargetSelector->FindTarget(ClosestToCursorPriority, SpellDamage, R->Range());
			for (auto enemy : GEntityList->GetAllHeros(false, true))
			{
				if (enemy->IsEnemy(GEntityList->Player()) && enemy->IsHero() && (GEntityList->Player()->GetPosition() - enemy->GetPosition()).Length2D() <= R->Range() && enemy->IsValidTarget(GEntityList->Player(), R->Range()))
				{
					if (InitialR() == true)
					{
						R->CastOnTarget(enemy, kHitChanceHigh);
					}
				}
			}
		}
	}

	void GapCloser()
	{
		if (target->IsDashing() && GapCloseE->Enabled() && target->IsHero() && target->IsValidTarget(GEntityList->Player(), E->Range()))
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