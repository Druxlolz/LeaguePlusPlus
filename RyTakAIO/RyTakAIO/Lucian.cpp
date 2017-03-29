#pragma once
#include "BaseOptions.h"
#include "OnRender.h"
#include "SpellLib.h"

class LucianBase
{
public:
	void Menu()
	{
		MainMenu = GPluginSDK->AddMenu("RyTak's Lucian");

		ComboMenu = MainMenu->AddMenu("Combo Settings");
		ComboQ = ComboMenu->CheckBox("Use Q", true);
		ComboW = ComboMenu->CheckBox("Use W", true);
		ComboE = ComboMenu->CheckBox("Use E", true);
		UseLucianPassive = ComboMenu->CheckBox("Spell Weave with Passive", true);

		HarassMenu = MainMenu->AddMenu("Harass Settings");
		HarassQ = HarassMenu->CheckBox("Use Q", true);
		HarassW = HarassMenu->CheckBox("Use W", false);
		HarassMana = HarassMenu->AddFloat("Min. Mana", 0, 100, 60);

		LaneClearMenu = MainMenu->AddMenu("Farm Settings");
		LaneClearQ = LaneClearMenu->CheckBox("Use Q", true);
		LaneClearW = LaneClearMenu->CheckBox("Use W", false);
		LaneClearE = LaneClearMenu->CheckBox("Use E", false);
		LaneClearQMinions = LaneClearMenu->AddInteger("Min. Q Minions", 1, 6, 2);
		LaneClearWMinions = LaneClearMenu->AddInteger("Min. W Minions", 1, 6, 2);
		LaneClearMana = LaneClearMenu->AddFloat("Min. Mana", 0, 100, 40);

		GapCloseMenu = MainMenu->AddMenu("Gap Closer Settings");
		GapCloseE = GapCloseMenu->CheckBox("Use E to Anti-Gap Close (Mouse Position)", true);

		KSMenu = MainMenu->AddMenu("Killsteal Settings");
		KSQ = KSMenu->CheckBox("Killsteal with Q", true);
		KSW = KSMenu->CheckBox("Killsteal with W", false);
		KSE = KSMenu->CheckBox("Gap-close to Killsteal with E", false);
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
		SpellLib().Lucian();
	}

	bool HasPassive = nullptr;

	//Passive code by Alqohol
	void CheckPassive()
	{
		if (GEntityList->Player()->HasBuff("LucianPassiveBuff"))
		{
			HasPassive = true;
		}
		else
		{
			HasPassive = false;
		}
	}

	void Combo()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo && HasPassive == false)
		{
			target = GTargetSelector->FindTarget(ClosestPriority, PhysicalDamage, Q->Range());
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
					if (E->IsReady() && ComboE->Enabled())
					{
						E->CastOnPosition(GGame->CursorPosition());
					}
				}
			}			
		}
	}

	void Harass()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger())
		{
			target = GTargetSelector->FindTarget(ClosestPriority, PhysicalDamage, Q->Range());
			for (auto target : GEntityList->GetAllHeros(false, true))
			{
				if (HarassQ->Enabled() && Q->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget())
				{
					Q->CastOnTarget(target);
				}
				if (HarassW->Enabled() && W->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget())
				{
					W->CastOnTarget(target);
				}
				if (HarassE->Enabled() && E->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget())
				{
					E->CastOnPosition(GGame->CursorPosition());
				}
			}			
		}
	}

	void LaneClear()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear && HasPassive == false)
		{
			if (GEntityList->Player()->ManaPercent() >= LaneClearMana->GetFloat())
			{
				minion = GTargetSelector->FindTarget(ClosestPriority, PhysicalDamage, Q->Range());
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
						if (LaneClearE->Enabled() && E->IsReady())
						{
							E->CastOnPosition(GGame->CursorPosition());
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
					if (Enemy->IsEnemy(GEntityList->Player()) && GEntityList->Player()->IsValidTarget(Enemy, Q->Range()))
					{
						if (Enemy->GetHealth() < GDamage->GetSpellDamage(GEntityList->Player(), Enemy, kSlotQ))
						{
							Q->CastOnTarget(Enemy);
						}
					}
				}
				if (KSW->Enabled() && W->IsReady())
				{
					if (Enemy->IsEnemy(GEntityList->Player()) && GEntityList->Player()->IsValidTarget(Enemy, W->Range()))
					{
						if (Enemy->GetHealth() < GDamage->GetSpellDamage(GEntityList->Player(), Enemy, kSlotW))
						{
							W->CastOnTarget(Enemy);
						}
					}
				}
				if (KSE->Enabled() && E->IsReady())
				{
					if (Enemy->IsEnemy(GEntityList->Player()) && GEntityList->Player()->IsValidTarget(Enemy, E->Range()))
					{
						if (Enemy->GetHealth() < GDamage->GetSpellDamage(GEntityList->Player(), Enemy, kSlotE))
						{
							E->CastOnPosition(GGame->CursorPosition());
						}
					}
				}
				if (KSR->Enabled() && R->IsReady())
				{
					if (Enemy->IsEnemy(GEntityList->Player()) && GEntityList->Player()->IsValidTarget(Enemy, R->Range()))
					{
						if (Enemy->GetHealth() < GDamage->GetSpellDamage(GEntityList->Player(), Enemy, kSlotR))
						{
							R->CastOnTarget(Enemy);
						}
					}
				}
			}
		}
	}

	void GapCloser()
	{
		if (target->IsDashing() && GapCloseE->Enabled())
		{
			E->CastOnPosition(GGame->CursorPosition());
		}
	}
};