#pragma once
#include "BaseOptions.h"
#include "SpellLib.h"
#include "IChampion.h"
#include "OnRender.cpp"

class Kalista : public IChampion
{
public:
	void Menu()
	{
		MainMenu = GPluginSDK->AddMenu("RyTaks_Kalista");

		ComboMenu = MainMenu->AddMenu("Combo Settings");
		ComboQ = ComboMenu->CheckBox("Use Q", true);
		ComboE = ComboMenu->CheckBox("Use E", true);
		AllyUltSave = ComboMenu->CheckBox("Use Ult To Save Oathswarn Partner", true);
		AllySaveHP = ComboMenu->AddFloat("Use Ult When % HP", 1, 100, 15);

		HarassMenu = MainMenu->AddMenu("Harass Settings");
		HarassQ = HarassMenu->CheckBox("Use Q", true);
		HarassE = HarassMenu->CheckBox("Use E", true);
		HarassMana = HarassMenu->AddFloat("Min. Mana", 0, 100, 60);

		LaneClearMenu = MainMenu->AddMenu("Farm Settings");
		LaneClearQ = LaneClearMenu->CheckBox("Use Q", true);
		LaneClearE = LaneClearMenu->CheckBox("Use E", true);
		LaneClearMana = LaneClearMenu->AddFloat("Min. Mana", 0, 100, 40);

		KSMenu = MainMenu->AddMenu("Killsteal Settings");
		KSQ = KSMenu->CheckBox("Killsteal with Q", true);
		KSE = KSMenu->CheckBox("Killsteal with E", true);

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
		SpellLib().Kalista();
	}

	inline double RendDamage(IUnit* Target)
	{
		double Damage = 0;
		int count = Target->GetBuffCount("kalistaexpungemarker");

		if (count < 0)
		{
			return static_cast<double>(0.f);
		}

		double d1[] = { 20, 30, 40, 50, 60 };
		double d2[] = { 10, 14, 19, 25, 32 };
		double d3[] = { 0.2, 0.225, 0.25, 0.275, 0.3 };

		Damage += (d1[GEntityList->Player()->GetSpellLevel(kSlotE)] + 0.6 * (GEntityList->Player()->PhysicalDamage() + GEntityList->Player()->BonusDamage())) + ((count - 1) * (d2[GEntityList->Player()->GetSpellLevel(kSlotE)] + d3[GEntityList->Player()->GetSpellLevel(kSlotE)] * (GEntityList->Player()->PhysicalDamage() + GEntityList->Player()->BonusDamage())));
		return GDamage->CalcPhysicalDamage(GEntityList->Player(), Target, Damage);
	}

	void Combo()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			ally = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, R->Range());
			for (auto ally : GEntityList->GetAllHeros(true, false));
			target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, E->Range());
			target = GTargetSelector->FindTarget(ClosestPriority, PhysicalDamage, Q->Range());
			for (auto target : GEntityList->GetAllHeros(false, true));
			{
				if (target != nullptr && target->IsHero())
				{
					if (ComboQ->Enabled() && Q->IsReady() && target->IsValidTarget(GEntityList->Player(), Q->Range()))
					{
						Q->CastOnTarget(target, 5);
					}
					if (ComboE->Enabled() && E->IsReady() && target->IsValidTarget(GEntityList->Player(), E->Range()))
					{
						if (RendDamage(target) > target->GetHealth() && target->HasBuff("kalistaexpongemarker"))
						{
							E->CastOnUnit(target);
						}
						if (RendDamage(target) < target->GetHealth() || !target->HasBuff("kalistaexpongemarker"))
						{
							return;
						}
					}
					if (AllyUltSave->Enabled() && ally != nullptr)
					{
						if (ally->HasBuff("kalistacoopstrikeally"))
						{
							if (AllySaveHP->GetFloat() == ((ally->GetHealth() / ally->GetMaxHealth()) / 100.f) && ally->IsValidTarget(GEntityList->Player(), 1400.f))
							{
								R->CastOnUnit(ally);
							}
						}
						if (!ally->HasBuff("kalistacoopstrikeally") || !ally->IsValidTarget(GEntityList->Player(), 1400.f))
						{
							return;
						}
					}
				}				
			}				
		}
	}

	void Harass()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
			for (auto target : GEntityList->GetAllHeros(false, true));
			if (target != nullptr && target->IsHero())
			{
				if (HarassQ->Enabled() && Q->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget(GEntityList->Player(), Q->Range()))
				{
					Q->CastOnTarget(target, 5);
				}
				if (HarassE->Enabled() && E->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget(GEntityList->Player(), E->Range()))
				{
					E->CastOnTarget(target);
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
					if (!minion->IsDead() && minion != nullptr)
					{
						if (LaneClearQ->Enabled() && Q->IsReady() && minion->IsValidTarget(GEntityList->Player(), Q->Range()))
						{
							Q->CastOnTarget(minion, 5);
						}
						if (LaneClearE->Enabled() && E->IsReady() && minion->IsValidTarget(GEntityList->Player(), E->Range()))
						{
							if (RendDamage(minion) > minion->GetHealth() && minion->HasBuff("kalistaexpongemarker"))
							{
								E->CastOnUnit(minion);
							}
							if (RendDamage(minion) < minion->GetHealth() || !minion->HasBuff("kalistaexpongemarker"))
							{
								return;
							}
						}
					}
				}
			}
		}
	}

	void KS()
	{
		Enemy = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
		Enemy = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, E->Range());
		for (auto Enemy : GEntityList->GetAllHeros(false, true))
		{
			if (Enemy != nullptr && !Enemy->IsDead())
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
					auto dmg = RendDamage(Enemy);
					if (Enemy->GetHealth() <= dmg && Enemy->IsValidTarget(GEntityList->Player(), E->Range()))
					{
						E->CastOnTarget(Enemy, kHitChanceHigh);
					}
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

	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}

	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};