#pragma once
#include "BaseOptions.h"
#include "SpellLib.h"
#include "IChampion.h"
#include "OnRender.cpp"

class Morgana : public IChampion
{
public:
	void Menu()
	{
		MainMenu = GPluginSDK->AddMenu("RyTaks_Morgana");

		ComboMenu = MainMenu->AddMenu("Combo Settings");
		ComboQ = ComboMenu->CheckBox("Use Q", true);
		ComboW = ComboMenu->CheckBox("Use W", true);
		ComboR = ComboMenu->CheckBox("Use R", true);
		HitRChampions = ComboMenu->AddInteger("Champions To Hit:", 1, 5, 2);

		HarassMenu = MainMenu->AddMenu("Harass Settings");
		HarassQ = HarassMenu->CheckBox("Use Q", true);
		HarassW = HarassMenu->CheckBox("Use W", true);
		HarassMana = HarassMenu->AddFloat("Min. Mana", 0, 100, 60);

		LaneClearMenu = MainMenu->AddMenu("Farm Settings");
		LaneClearQ = LaneClearMenu->CheckBox("Use Q", true);
		LaneClearW = LaneClearMenu->CheckBox("Use W", true);
		LaneClearWMinions = LaneClearMenu->AddInteger("Min. R Minions", 1, 6, 2);
		LaneClearMana = LaneClearMenu->AddFloat("Min. Mana", 0, 100, 40);

		GapCloseMenu = MainMenu->AddMenu("Gap Closer Settings");
		GapCloseQ = GapCloseMenu->CheckBox("Snare Gap Closer with Q", true);

		KSMenu = MainMenu->AddMenu("Killsteal Settings");
		KSQ = KSMenu->CheckBox("Killsteal with Q", true);
		KSW = KSMenu->CheckBox("Killsteal with W", true);
		KSR = KSMenu->CheckBox("Killsteal with R", true);

		DrawMenu = MainMenu->AddMenu("Drawing Settings");
		DrawReady = DrawMenu->CheckBox("Draw Only Ready Spells", true);
		DrawOff = DrawMenu->CheckBox("Disable Drawings", true);
		DrawQ = DrawMenu->CheckBox("Draw Q", true);
		DrawW = DrawMenu->CheckBox("Draw W", true);
		DrawE = DrawMenu->CheckBox("Draw E", true);
		DrawR = DrawMenu->CheckBox("Draw R", true);

	}

	void Spells()
	{
		SpellLib().Morgana();
	}

	void Combo()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			target = GTargetSelector->FindTarget(QuickestKill, SpellDamage, Q->Range());
			if (target != nullptr && target->IsValidTarget() && target->IsHero())
			{
				if (Q->IsReady() && ComboQ->Enabled())
				{
					Q->CastOnTarget(target, 4);
				}
				if (W->IsReady() && ComboW->Enabled())
				{
					Vec3 pos;
					int hit;
					GPrediction->FindBestCastPosition(W->Range(), W->Radius(), false, false, true, pos, hit);
					if (hit >= HitRChampions->GetInteger())
					{
						W->CastOnPosition(pos);
					}
				}
				if (R->IsReady() && ComboR->Enabled())
				{
					Vec3 pos;
					int hit;
					GPrediction->FindBestCastPosition(R->Range(), R->Radius(), false, false, true, pos, hit);
					if (hit >= HitRChampions->GetInteger())
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
			target = GTargetSelector->FindTarget(QuickestKill, SpellDamage, Q->Range());
			for (auto target : GEntityList->GetAllHeros(false, true))
			if (HarassQ->Enabled() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget())
			{
				Q->CastOnTarget(target, kHitChanceHigh);
			}
			if (W->IsReady() && HarassW->Enabled() && target->IsValidTarget() && target->IsHero())
			{
				Vec3 pos;
				int hit;
				GPrediction->FindBestCastPosition(W->Range(), W->Radius(), false, false, true, pos, hit);
				if (hit >=  1)
				{
					W->CastOnPosition(pos);
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
							Vec3 pos;
							int hit;
							GPrediction->FindBestCastPosition(W->Range(), W->Radius(), false, true, false, pos, hit);
							if (hit >= LaneClearWMinions->GetInteger())
							{
								W->CastOnPosition(pos);
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
			if (Enemy != nullptr && Enemy->IsValidTarget())
			{
				if (KSQ->Enabled())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotQ, Q->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg)
					{
						Q->CastOnTarget(Enemy);
					}
				}
				if (KSW->Enabled())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotW, W->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg)
					{
						W->CastOnTarget(Enemy);
					}
				}
				if (KSR->Enabled())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotR, R->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg)
					{
						Vec3 pos;
						int hit;
						GPrediction->FindBestCastPosition(R->Range(), R->Radius(), false, false, true, pos, hit);
						if (hit >= 1)
						{
							R->CastOnPlayer();
						}
					}
				}
			}
		}
	}

	void OnGapCloser(GapCloserSpell const& Args)
	{
		if (target->IsDashing() && GapCloseQ->Enabled())
		{
			Q->CastOnTarget(target, 5);
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