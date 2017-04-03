#pragma once
#include "BaseOptions.h"
#include "OnRender.h"
#include "SpellLib.h"
#include "CommonLib.h"

class TwitchBase
{
public:
	void Menu()
	{
		MainMenu = GPluginSDK->AddMenu("RyTak's Twitch");

		ComboMenu = MainMenu->AddMenu("Combo Settings");
		ComboQ = ComboMenu->CheckBox("Use Q", true);
		ComboW = ComboMenu->CheckBox("Use W", true);
		ComboE = ComboMenu->CheckBox("Use E", true);
		ComboR = ComboMenu->CheckBox("Use R", true);

		HarassMenu = MainMenu->AddMenu("Harass Settings");
		HarassW = HarassMenu->CheckBox("Use W", true);
		HarassE = HarassMenu->CheckBox("Use E", true);
		HarassEStacks = HarassMenu->AddFloat("Stacks to Use E", 1, 6, 6);
		HarassMana = HarassMenu->AddFloat("Min. Mana", 0, 100, 60);

		LaneClearMenu = MainMenu->AddMenu("Farm Settings");
		LaneClearW = LaneClearMenu->CheckBox("Use W", true);
		LaneClearWMinions = LaneClearMenu->AddFloat("Minions to Hit with W", 1, 6, 3);
		LaneClearE = LaneClearMenu->CheckBox("Use E", true);
		LaneClearEMinions = LaneClearMenu->AddFloat("Minions to Kill with E", 1, 6, 2);
		LaneClearMana = LaneClearMenu->AddFloat("Min. Mana", 0, 100, 40);

		KSMenu = MainMenu->AddMenu("Killsteal Settings");
		KSE = KSMenu->CheckBox("Killsteal with E", true);

		/*
		DrawMenu = MainMenu->AddMenu("Drawing Settings");
		DrawReady = DrawMenu->CheckBox("Draw Only Ready Spells", true);
		DrawOff = DrawMenu->CheckBox("Disable Drawings", false);
		DrawW = DrawMenu->CheckBox("Draw W", true);
		DrawE = DrawMenu->CheckBox("Draw E", true);
		DrawR = DrawMenu->CheckBox("Draw R", true);
		*/
	}

	void Spells()
	{
		SpellLib().Twitch();
	}

	inline double ExpungeDamage(IUnit* Target)
	{
		float Damage = 0;
		int StackCount = Target->GetBuffCount("TwitchDeadlyVenom");

		if (StackCount == 0) return 0;

		float BonusDamage = ((0.25 * GEntityList->Player()->BonusDamage()) + (0.2 * GEntityList->Player()->TotalMagicDamage())) * StackCount;

		if (GEntityList->Player()->GetSpellLevel(kSlotE) == 1)
		{
			Damage += 20 + (15 * StackCount) + BonusDamage;
		}
			
		if (GEntityList->Player()->GetSpellLevel(kSlotE) == 2)
		{
			Damage += 35 + (20 * StackCount) + BonusDamage;
		}

		if (GEntityList->Player()->GetSpellLevel(kSlotE) == 3)
		{
			Damage += 50 + (25 * StackCount) + BonusDamage;
		}

		if (GEntityList->Player()->GetSpellLevel(kSlotE) == 4)
		{
			Damage += 65 + (30 * StackCount) + BonusDamage;
		}			

		if (GEntityList->Player()->GetSpellLevel(kSlotE) == 5)
		{
			Damage += 80 + (35 * StackCount) + BonusDamage;
		}			

		return GDamage->CalcPhysicalDamage(GEntityList->Player(), Target, Damage);
	}

	void Combo()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			Enemy = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
			for (auto Enemy : GEntityList->GetAllHeros(false, true))
			{
				if (ComboQ->Enabled() && Q->IsReady())
				{
					Q->CastOnPlayer();
				}
				if (ComboW->Enabled() && W->IsReady())
				{
					W->CastOnTarget(Enemy, 5);
				}
				if (ComboE->Enabled() && E->IsReady() && Enemy->HasBuff("TwitchDeadlyVenom"))
				{
					if (Enemy->GetBuffCount("TwitchDeadlyVenom") == 6)
					{
						E->CastOnPlayer();
					}
				}
				if (ComboR->Enabled() && R->IsReady())
				{
					if (EIISR().EnemyIsInSpellRange(R->Range()) == true)
					{
						R->CastOnPlayer();
					}				
				}
			}			
		}
	}

	void Harass()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger())
		{
			Enemy = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, E->Range());
			for (auto Enemy : GEntityList->GetAllHeros(false, true))
			{
				if (HarassW->Enabled() && W->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger())
				{
					W->CastOnTarget(Enemy, 5);
				}
				if (HarassE->Enabled() && E->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && Enemy->HasBuff("TwitchDeadlyVenom"))
				{
					if (HarassEStacks->GetFloat() >= Enemy->GetBuffCount("TwitchDeadlyVenom"))
					{
						E->CastOnPlayer();
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
				minion = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, E->Range());
				for (auto minion : GEntityList->GetAllMinions(false, true, true))
				{
					if (minion->IsEnemy(GEntityList->Player()) && !minion->IsDead() && GEntityList->Player()->IsValidTarget(minion, E->Range()))
					{
						if (LaneClearW->Enabled() && W->IsReady())
						{
							Vec3 pos;
							int hit;
							GPrediction->FindBestCastPosition(W->Range(), W->Radius(), true, true, false, pos, hit);
							if (LaneClearWMinions->GetFloat() >= hit)
							{
								W->CastOnPosition(pos);
							}
						}
						if (LaneClearE->Enabled() && E->IsReady())
						{
							Vec3 pos;
							int hit;
							GPrediction->FindBestCastPosition(E->Range(), E->Radius(), true, true, false, pos, hit);
							if (LaneClearEMinions->GetFloat() >= hit)
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
		Enemy = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, E->Range());
		for (auto Enemy : GEntityList->GetAllHeros(false, true))
		{
			if (KSE->Enabled() && E->IsReady() && Enemy->HasBuff("TwitchDeadlyVenom"))
			{
				if (Enemy->GetHealth() <= (ExpungeDamage(Enemy)))
				{
					E->CastOnPlayer();
				}
			}							
		}
	}
};