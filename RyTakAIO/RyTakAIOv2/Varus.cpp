#pragma once
#include "BaseOptions.h"
#include "SpellLib.h"
#include "OnRender.cpp"
#include "IChampion.h"

class Varus : public IChampion
{
public:
	void Menu()
	{
		MainMenu = GPluginSDK->AddMenu("RyTaks_Varus");

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

int GetEnemiesInRange(float range)
{
	auto enemies = GEntityList->GetAllHeros(false, true);
	auto enemiesInRange = 0;

	for (auto enemy : enemies)
	{
		auto TargetDistance = (enemy->GetPosition() - GEntityList->Player()->GetPosition()).Length2D();
		if (enemy != nullptr && enemy->GetTeam() != GEntityList->Player()->GetTeam() && enemy->IsValidTarget() && enemy->IsHero())
		{
			if (TargetDistance < range)
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
		auto TargetDistance = (minion->GetPosition() - GEntityList->Player()->GetPosition()).Length2D();
		if (minion != nullptr && minion->GetTeam() != GEntityList->Player()->GetTeam() && (minion->IsCreep() || minion->IsJungleCreep()))
		{
			if (TargetDistance < range)
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
		if (target != nullptr && target->IsHero())
		{		
			if (ComboQ->Enabled() && Q->IsReady() && target->IsValidTarget(GEntityList->Player(), Q->Range()))
			{
				if (Q->IsCharging())
				{
					Q->FindTarget(PhysicalDamage);
					{
						if (target->IsValidTarget(GEntityList->Player(), Q->Range()) && GetEnemiesInRange(Q->Range()) >= 1 && ComboWStacks->GetInteger() >= target->GetBuffCount("VarusWDebuff"))
						{
							Q->CastOnTarget(target, kHitChanceHigh);
						}
					}
				}
				if (Q->IsReady() && GetEnemiesInRange(Q->Range()) >= 1)
				{
					Q->StartCharging();
				}
			}
			if (ComboE->Enabled() && target->IsValidTarget(GEntityList->Player(), E->Range()) && ComboWStacks->GetInteger() >= target->GetBuffCount("VarusWDebuff"))
			{
				if (E->IsReady())
				{
					E->CastOnTarget(target, 5);
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
			if (HarassQ->Enabled() && Q->IsReady() && target->IsHero() && target->IsValidTarget(GEntityList->Player(), Q->Range()) && target != nullptr)
			{
				if (GetEnemiesInRange(Q->Range()) >= 1)
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
			if (HarassE->Enabled() && E->IsReady() && target->IsHero() && target->IsValidTarget(GEntityList->Player(), E->Range()) && target != nullptr)
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
				if (minion->IsEnemy(GEntityList->Player()) && !minion->IsDead() && minion != nullptr)
				{
					if (LaneClearQ->Enabled() && minion->IsValidTarget(GEntityList->Player(), Q->Range()))
					{
						if (Q->IsCharging())
						{
							Q->FindTarget(PhysicalDamage);
							{
								Vec3 pos;
								int hit;
								GPrediction->FindBestCastPosition(Q->Range(), Q->Radius(), true, true, true, pos, hit);
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
						else return;
					}
					if (LaneClearE->Enabled() && minion->IsValidTarget(GEntityList->Player(), E->Range()))
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
				
				if (KSQ->Enabled() && Q->IsReady() && Enemy->IsValidTarget(GEntityList->Player(), Q->Range()))
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotQ, Q->GetDelay(), true);
					if (GetEnemiesInRange(Q->Range()) >= 1)
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
					if (Enemy->GetHealth() <= dmg && Enemy->IsValidTarget(GEntityList->Player(), E->Range()))
					{
						E->CastOnTarget(target, 5);
					}
				}
				if (KSR->Enabled() && R->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotR, R->GetDelay(), true);					
					if (Enemy->GetHealth() <= dmg && Enemy->IsValidTarget(GEntityList->Player(), R->Range()))
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
				if (enemy->IsEnemy(GEntityList->Player()) && (GEntityList->Player()->GetPosition() - enemy->GetPosition()).Length2D() <= R->Range() && enemy->IsValidTarget(GEntityList->Player(), R->Range()))
				{
					R->CastOnTarget(enemy, 5);
				}
			}
		}
	}

	void OnGapCloser(GapCloserSpell const& Args)
	{
		if (target->IsDashing() && GapCloseR->Enabled() && target->IsHero() && target->IsValidTarget(GEntityList->Player(), R->Range()))
		{
			R->CastOnTarget(target, 5);
		}
	}

	void OnRender()
	{
		OnRenderClass().Render();
	}

	void BeforeAttack(IUnit* Source, IUnit* Target)
	{

	}

	void AfterAttack(IUnit* Source, IUnit* Target)
	{

	}

	void OnProcessSpell(CastedSpell const& Args)
	{

	}
};