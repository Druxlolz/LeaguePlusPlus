#pragma once
#include "BaseOptions.h"
#include "SpellLib.h"
#include "IChampion.h"
#include "OnRender.cpp"

class Caitlyn : public IChampion
{
public:
	void Menu()
	{
		MainMenu = GPluginSDK->AddMenu("RyTaks_Caitlyn");

		ComboMenu = MainMenu->AddMenu("Combo Settings");
		ComboQ = ComboMenu->CheckBox("Use Q", true);
		ComboW = ComboMenu->CheckBox("Use W", true);
		ComboE = ComboMenu->CheckBox("Use E", true);
		SemiR = ComboMenu->AddKey("Semi-Auto R", 84);

		HarassMenu = MainMenu->AddMenu("Harass Settings");
		HarassQ = HarassMenu->CheckBox("Use Q", true);
		HarassE = HarassMenu->CheckBox("Use E", true);
		HarassMana = HarassMenu->AddFloat("Min. Mana", 0, 100, 60);

		LaneClearMenu = MainMenu->AddMenu("Farm Settings");
		LaneClearQ = LaneClearMenu->CheckBox("Use Q", true);
		LaneClearMana = LaneClearMenu->AddFloat("Min. Mana", 0, 100, 40);

		GapCloseMenu = MainMenu->AddMenu("Gap Closer Settings");
		GapCloseE = GapCloseMenu->CheckBox("Use E on Gap Closer", true);

		KSMenu = MainMenu->AddMenu("Killsteal Settings");
		KSQ = KSMenu->CheckBox("Killsteal with Q", true);
		KSE = KSMenu->CheckBox("Killsteal with E", false);
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
		SpellLib().Caitlyn();
	}

	void RRange()
	{
		if (GSpellBook->GetLevel(kSlotR) == 0)
			return;
		else if (GSpellBook->GetLevel(kSlotR) == 1)
			R->SetOverrideRange(2000);
		else if (GSpellBook->GetLevel(kSlotR) == 2)
			R->SetOverrideRange(2500);
		else if (GSpellBook->GetLevel(kSlotR) == 3)
			R->SetOverrideRange(3000);
	}

	void Combo()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
			for (auto target : GEntityList->GetAllHeros(false, true));
			{
				if (target != nullptr && target->IsHero())
				{
					if (Q->IsReady() && ComboQ->Enabled() && target->IsValidTarget(GEntityList->Player(), Q->Range()))
					{
						Q->CastOnTarget(target, 5);
					}
					if (W->IsReady() && ComboW->Enabled() && target->IsValidTarget(GEntityList->Player(), W->Range()))
					{
						W->CastOnTarget(target, 5);
					}
					if (E->IsReady() && ComboE->Enabled() && target->IsValidTarget(GEntityList->Player(), E->Range()))
					{
						E->CastOnTarget(target, 5);
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
			for (auto target : GEntityList->GetAllHeros(false, true));
			if (HarassQ->Enabled() && Q->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetFloat() && target->IsValidTarget(GEntityList->Player(), Q->Range()))
			{
				Q->CastOnTarget(target, 5);
			}
			if (HarassE->Enabled() && E->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetFloat() && target->IsValidTarget(GEntityList->Player(), E->Range()))
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
				for (auto minion : GEntityList->GetAllMinions(false, true, true));
				{
					if (minion->IsEnemy(GEntityList->Player()) && !minion->IsDead())
					{
						if (LaneClearQ->Enabled() && Q->IsReady() && minion->IsValidTarget(GEntityList->Player(), Q->Range()))
						{
							switch (kSlotQ)
							{
							case 1: Q->LastHitMinion();
							default: Q->CastOnTarget(minion, 5);
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
			if (Enemy != nullptr && Enemy->IsHero())
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
						E->CastOnPosition(GGame->CursorPosition());
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

	void OnGapCloser(GapCloserSpell const& Args) override
	{
		if (target->IsDashing() && GapCloseE->Enabled())
		{
			E->CastOnTarget(target, 5);
		}
	}

	void RDamage()
	{
		if (GetAsyncKeyState(SemiR->GetInteger()) && R->IsReady())
		{
			enemy = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, R->Range());
			for (auto enemy : GEntityList->GetAllHeros(false, true))
			{
				if (enemy->IsEnemy(GEntityList->Player()) && (GEntityList->Player()->GetPosition() - enemy->GetPosition()).Length2D() <= R->Range() && enemy->IsValidTarget())
				{
					R->CastOnTarget(enemy, 5);
				}
			}
		}
	}

	void OnRender() override
	{
		OnRenderClass().Render();
	}

	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}

	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}

	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};