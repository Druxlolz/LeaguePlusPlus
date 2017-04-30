#pragma once
#include "BaseOptions.h"
#include "SpellLib.h"
#include "IChampion.h"
#include "OnRender.cpp"

class Lucian : public IChampion
{
public:
	void Menu()
	{
		MainMenu = GPluginSDK->AddMenu("RyTaks_Lucian");

		ComboMenu = MainMenu->AddMenu("Combo Settings");
		ComboQ = ComboMenu->CheckBox("Use Q", true);
		ComboW = ComboMenu->CheckBox("Use W", true);
		ComboE = ComboMenu->CheckBox("Use E", true);

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
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			target = GTargetSelector->FindTarget(ClosestPriority, PhysicalDamage, Q->Range());
			for (auto target : GEntityList->GetAllHeros(false, true))
			{
				if (target != nullptr && target->IsHero())
				{
					if (Q->IsReady() && ComboQ->Enabled() && target->IsValidTarget(GEntityList->Player(), Q->Range()) && HasPassive == false)
					{
						Q->CastOnTarget(target, 5);
					}
					if (W->IsReady() && ComboW->Enabled() && target->IsValidTarget(GEntityList->Player(), W->Range()) && HasPassive == false)
					{
						W->CastOnTarget(target, 5);
					}
					if (E->IsReady() && ComboE->Enabled() && target->IsValidTarget(GEntityList->Player(), E->Range()) && HasPassive == false)
					{
						E->CastOnPosition(GGame->CursorPosition());
					}
				}
			}			
		}
	}

	void Harass()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			target = GTargetSelector->FindTarget(ClosestPriority, PhysicalDamage, Q->Range());
			for (auto target : GEntityList->GetAllHeros(false, true))
			{
				if (HarassQ->Enabled() && Q->IsReady() && target != nullptr && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget(GEntityList->Player(), Q->Range()) && HasPassive == false)
				{
					Q->CastOnTarget(target, 5);
				}
				if (HarassW->Enabled() && W->IsReady() && target != nullptr && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget(GEntityList->Player(), W->Range()) && HasPassive == false)
				{
					W->CastOnTarget(target, 5);
				}
				if (HarassE->Enabled() && E->IsReady() && target != nullptr && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget(GEntityList->Player(), E->Range()) && HasPassive == false)
				{
					E->CastOnPosition(GGame->CursorPosition());
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
				minion = GTargetSelector->FindTarget(ClosestPriority, PhysicalDamage, Q->Range());
				for (auto minion : GEntityList->GetAllMinions(false, true, true))
				{
					if (minion->IsEnemy(GEntityList->Player()) && !minion->IsDead() && minion != nullptr)
					{
						if (LaneClearQ->Enabled() && Q->IsReady() && minion->IsValidTarget(GEntityList->Player(), Q->Range()) && HasPassive == false)
						{
							Vec3 pos;
							int hit;
							GPrediction->FindBestCastPosition(Q->Range(), Q->Radius(), true, true, true, pos, hit);
							{
								if (hit >= LaneClearQMinions->GetInteger())
								{
									Q->CastOnTarget(minion, 5);
								}
							}							
						}
						if (LaneClearW->Enabled() && W->IsReady() && minion->IsValidTarget(GEntityList->Player(), W->Range()) && HasPassive == false)
						{
							Vec3 pos;
							int hit;
							GPrediction->FindBestCastPosition(W->Range(), W->Radius(), true, true, true, pos, hit);
							{
								if (hit >= LaneClearWMinions->GetInteger())
								{
									W->CastOnTarget(minion, 5);
								}
							}
						}
						if (LaneClearE->Enabled() && E->IsReady() && minion->IsValidTarget(GEntityList->Player(), E->Range()) && HasPassive == false)
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
					if (Enemy->IsEnemy(GEntityList->Player()) && Enemy->IsValidTarget(GEntityList->Player(), Q->Range()) && HasPassive == false)
					{
						if (Enemy->GetHealth() < GDamage->GetSpellDamage(GEntityList->Player(), Enemy, kSlotQ))
						{
							Q->CastOnTarget(Enemy, 5);
						}
					}
				}
				if (KSW->Enabled() && W->IsReady())
				{
					if (Enemy->IsEnemy(GEntityList->Player()) && Enemy->IsValidTarget(GEntityList->Player(), W->Range()) && HasPassive == false)
					{
						if (Enemy->GetHealth() < GDamage->GetSpellDamage(GEntityList->Player(), Enemy, kSlotW))
						{
							W->CastOnTarget(Enemy, 5);
						}
					}
				}
				if (KSE->Enabled() && E->IsReady())
				{
					if (Enemy->IsEnemy(GEntityList->Player()) && Enemy->IsValidTarget(GEntityList->Player(), E->Range()) && HasPassive == false)
					{
						if (Enemy->GetHealth() < GDamage->GetSpellDamage(GEntityList->Player(), Enemy, kSlotE))
						{
							E->CastOnPosition(GGame->CursorPosition());
						}
					}
				}
				if (KSR->Enabled() && R->IsReady())
				{
					if (Enemy->IsEnemy(GEntityList->Player()) && Enemy->IsValidTarget(GEntityList->Player(), R->Range()) && HasPassive == false)
					{
						if (Enemy->GetHealth() < GDamage->GetSpellDamage(GEntityList->Player(), Enemy, kSlotR))
						{
							R->CastOnTarget(Enemy, 5);
						}
					}
				}
			}
		}
	}

	void OnGapCloser(GapCloserSpell const& Args)
	{
		if (target->IsDashing() && target != nullptr && GapCloseE->Enabled() && target->IsValidTarget(GEntityList->Player(), E->Range()) && HasPassive == false)
		{
			E->CastOnPosition(GGame->CursorPosition());
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