#pragma once
#include "BaseOptions.h"
#include "OnRender.h"
#include "SpellLib.h"
#include "CommonLib.h"

class VarusBase
{
public:
	void Menu()
	{
		MainMenu = GPluginSDK->AddMenu("RyTak's Varus");

		ComboMenu = MainMenu->AddMenu("Combo Settings");
		ComboQ = ComboMenu->CheckBox("Use Q", true);
		ComboWStacks = ComboMenu->AddInteger("Stacks of W to use Q/E", 1, 3, 3);
		ComboE = ComboMenu->CheckBox("Use E", true);
		SemiR = ComboMenu->AddKey("Semi-Auto R", 84);
		HitRChampions = ComboMenu->AddInteger("Champs to Hit", 1, 5, 2);

		HarassMenu = MainMenu->AddMenu("Harass Settings");
		HarassQ = HarassMenu->CheckBox("Use Q", true);
		HarassE = HarassMenu->CheckBox("Use E", true);
		HarassMana = HarassMenu->AddFloat("Min. Mana", 0, 100, 60);

		LaneClearMenu = MainMenu->AddMenu("Farm Settings");
		LaneClearQ = LaneClearMenu->CheckBox("Use Q", true);
		LaneClearE = LaneClearMenu->CheckBox("Use E", true);
		LaneClearQMinions = LaneClearMenu->AddInteger("Minions to Hit with Q", 1, 6, 2);
		LaneClearEMinions = LaneClearMenu->AddInteger("Minions to Hit with E", 1, 6, 2);
		LaneClearMana = LaneClearMenu->AddFloat("Min. Mana", 0, 100, 40);

		GapCloseMenu = MainMenu->AddMenu("Gap Closer Settings");
		GapCloseR = GapCloseMenu->CheckBox("Use R to Stun Gap Closer", true);

		KSMenu = MainMenu->AddMenu("Killsteal Settings");
		KSQ = KSMenu->CheckBox("Killsteal with Q", true);
		KSE = KSMenu->CheckBox("Killsteal with E", true);
		KSR = KSMenu->CheckBox("Killsteal with R", true);

		DrawMenu = MainMenu->AddMenu("Drawing Settings");
		DrawReady = DrawMenu->CheckBox("Draw Only Ready Spells", true);
		DrawOff = DrawMenu->CheckBox("Disable Drawings", true);
		DrawQ = DrawMenu->CheckBox("Draw Q", true);
		DrawE = DrawMenu->CheckBox("Draw E", true);
		DrawR = DrawMenu->CheckBox("Draw R", true);

	}

void Spells()
{
	SpellLib().Varus();
}

void Combo()
{
	if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
	{
		target = GTargetSelector->FindTarget(QuickestKill, SpellDamage, Q->Range());
		for (auto target : GEntityList->GetAllHeros(false, true));
		if (target != nullptr && target->IsValidTarget() && target->IsHero() && target->IsValidTarget())
		{
			if (ComboWStacks->GetInteger() >= target->GetBuffCount("varuswdebuff"))
			{
				if (Q->IsReady())
				{
					if (Q->IsCharging())
					{
						Q->FindTarget(PhysicalDamage);
						{
							if (target->IsValidTarget(target, Q->Range()) && GEIR().GetEnemiesInRange(Q->Range()) >= 1)
							{
								Q->CastOnTarget(target, kHitChanceHigh);
							}
						}
					}
					if (Q->IsReady() && GEIR().GetEnemiesInRange(Q->Range()) >= 1)
					{
						Q->StartCharging();
					}
				}
				if (ComboE->Enabled())
				{
					if (E->IsReady())
					{
						E->CastOnTarget(target, 5);
					}
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
			for (auto target : GEntityList->GetAllHeros(false, true));
			if (HarassQ->Enabled() && Q->IsReady() && target->IsHero() && target->IsValidTarget())
			{
				if (GEIR().GetEnemiesInRange(Q->Range()) >= 1)
				{
					if (Q->IsCharging())
					{
						Q->FindTarget(PhysicalDamage);
						{
							Q->CastOnTarget(target, kHitChanceHigh);
							return;
						}
					}
					else
					{
						Q->StartCharging();
					}
				}
			}
			if (HarassE->Enabled() && E->IsReady() && target->IsHero() && target->IsValidTarget())
			{
				E->CastOnTarget(target, 5);
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
				if (minion->IsEnemy(GEntityList->Player()) && !minion->IsDead() && GEntityList->Player()->IsValidTarget(minion, Q->Range()))
				{
					if (LaneClearQ->Enabled())
					{
						if (Q->IsCharging())
						{
							Q->FindTarget(PhysicalDamage);
							{
								Vec3 pos;
								int hit;
								GPrediction->FindBestCastPosition(Q->Range(), Q->Radius(), true, true, true, pos, hit);
								if (GMIR().GetMinionsInRange(Q->Range()) >= LaneClearQMinions->GetInteger() <= hit && !minion->IsInvulnerable())
								{
									Q->CastOnPosition(pos);
								}
							}
						}
						else if (Q->IsReady() && GMIR().GetMinionsInRange(Q->Range()) >= LaneClearQMinions->GetInteger())
						{
							Q->StartCharging();
						}
						else return;
					}
					if (LaneClearE->Enabled())
					{
						if (E->IsReady())
						{
							E->LastHitMinion();
						}
						else if (E->IsReady() && LaneClearE->Enabled())
						{
							Vec3 pos;
							int hit;
							GPrediction->FindBestCastPosition(E->Range(), E->Radius(), true, true, false, pos, hit);
							if (hit >= LaneClearEMinions->GetInteger())
							{
								E->CastOnPosition(pos);
							}
						}
						else return;
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
			if (Enemy != nullptr && !Enemy->IsDead())
			{
				auto target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
				
				if (KSQ->Enabled() && Q->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotQ, Q->GetDelay(), true);
					if (GEIR().GetEnemiesInRange(Q->Range()) >= 1)
					{
						Q->StartCharging();
					}

					if (Q->IsCharging())
					{
						if (Enemy->GetHealth() <= dmg)
						{
							Q->CastOnTarget(target, 5);
						}
					}
					return;
				}
				if (KSE->Enabled() && E->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotE, E->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg)
					{
						E->CastOnTarget(target, 5);
					}
				}
				if (KSR->Enabled() && R->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotR, R->GetDelay(), true);					
					if (Enemy->GetHealth() <= dmg)
					{
						R->CastOnTarget(target, 5);
					}
				}
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
				if (enemy->IsEnemy(GEntityList->Player()) && (GEntityList->Player()->GetPosition() - enemy->GetPosition()).Length2D() <= R->Range() && enemy->IsValidTarget())
				{
					R->CastOnTarget(enemy, 5);
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
};