#pragma once
#include "BaseOptions.h"
#include "SpellLib.h"
#include "IChampion.h"
#include "OnRender.cpp"

class Syndra : public IChampion
{
public:
	void Menu()
	{
		MainMenu = GPluginSDK->AddMenu("RyTaks_Syndra");

		ComboMenu = MainMenu->AddMenu("Combo Settings");
		ComboQ = ComboMenu->CheckBox("Use Q", true);
		ComboW = ComboMenu->CheckBox("Use W", true);
		ComboE = ComboMenu->CheckBox("Use E", true);

		HarassMenu = MainMenu->AddMenu("Harass Settings");
		HarassQ = HarassMenu->CheckBox("Use Q", true);
		HarassW = HarassMenu->CheckBox("Use W", false);
		HarassE = HarassMenu->CheckBox("Use E", false);
		HarassMana = HarassMenu->AddFloat("Min. Mana", 0, 100, 60);

		LaneClearMenu = MainMenu->AddMenu("Farm Settings");
		LaneClearQ = LaneClearMenu->CheckBox("Use Q", true);
		LaneClearW = LaneClearMenu->CheckBox("Use W", true);
		LaneClearE = LaneClearMenu->CheckBox("Use E", true);
		LaneClearMana = LaneClearMenu->AddFloat("Min. Mana", 0, 100, 40);

		KSMenu = MainMenu->AddMenu("Killsteal Settings");
		KSQ = KSMenu->CheckBox("Killsteal with Q", true);
		KSW = KSMenu->CheckBox("Killsteal with W", true);
		KSE = KSMenu->CheckBox("Killsteal with E", true);
		KSR = KSMenu->CheckBox("Killsteal with R", true);

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
		SpellLib().Syndra();
	}

	bool OrbAlive = false;

	void OnCreate(IUnit* synOrb) 
	{
		auto objectName = synOrb->GetObjectName();
		auto Player = GEntityList->Player();

		std::vector<IUnit*> result;
		for (auto synQ : GEntityList->GetAllUnits())
		{
			if (strcmp(objectName, "SyndraQ") == 0 && synOrb->IsVisible() && synOrb->IsValidObject())
			{
				OrbAlive = true;
				result.push_back(synQ);
			}
		}
	}

	void OnDelete(IUnit* synOrb) 
	{
		auto objectName = synOrb->GetObjectName();

		if (strcmp(objectName, "SyndraQ") == 0 && synOrb->IsVisible() && synOrb->IsValidObject())
		{
			OrbAlive = false;
		}
	}

	void Combo()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
			for (auto target : GEntityList->GetAllHeros(false, true))
			{
				if (ComboQ->Enabled() && Q->IsReady() && target->IsValidTarget(GEntityList->Player(), Q->Range()))
				{
					Q->CastOnTarget(target, 5);
				}
				if (ComboW->Enabled() && W->IsReady() && target->IsValidTarget(GEntityList->Player(), W->Range()))
				{
					W->CastOnTarget(target, 5);
				}
				if (ComboE->Enabled() && E->IsReady() && target->IsValidTarget(GEntityList->Player(), E->Range()))
				{
					E->CastOnTarget(target, 5);
				}
			}				
		}
	}

	void Harass()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger())
		{
			target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
			for (auto target : GEntityList->GetAllHeros(false, true))
			{
				if (HarassQ->Enabled() && Q->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget(GEntityList->Player(), Q->Range()))
				{
					Q->CastOnTarget(target, 5);
				}
				if (HarassW->Enabled() && W->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget(GEntityList->Player(), W->Range()))
				{
					W->CastOnTarget(target, 5);
				}
				if (HarassE->Enabled() && E->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget(GEntityList->Player(), E->Range()))
				{
					E->CastOnTarget(target, 5);
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
				minion = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
				for (auto minion : GEntityList->GetAllMinions(false, true, true))
				{
					if (minion->IsEnemy(GEntityList->Player()) && !minion->IsDead())
					{
						if (LaneClearQ->Enabled() && Q->IsReady() && minion->IsValidTarget(GEntityList->Player(), Q->Range()))
						{
							Q->CastOnTarget(minion, 5);
						}
						if (LaneClearW->Enabled() && W->IsReady() && minion->IsValidTarget(GEntityList->Player(), W->Range()))
						{
							E->CastOnTarget(minion, 5);
						}
						if (LaneClearE->Enabled() && E->IsReady() && minion->IsValidTarget(GEntityList->Player(), E->Range()))
						{
							E->CastOnTarget(minion, 5);
						}
					}
				}
			}
		}
	}

	void KS()
	{
		Enemy = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
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
				if (KSW->Enabled() && W->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotW, W->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg && Enemy->IsValidTarget(GEntityList->Player(), W->Range()))
					{
						W->CastOnTarget(Enemy, kHitChanceHigh);
					}
				}
				if (KSE->Enabled() && E->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotE, E->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg && Enemy->IsValidTarget(GEntityList->Player(), E->Range()))
					{
						E->CastOnTarget(Enemy, kHitChanceHigh);
					}
				}
				if (KSR->Enabled() && R->IsReady())
				{
					auto dmg = GPluginSDK->GetDamage()->GetSpellDamage(GEntityList->Player(), Enemy, kSlotR) * GEntityList->Player()->GetSpellBook()->GetAmmo(kSlotR);
					if (Enemy->GetHealth() + (Enemy->HPRegenRate() * 0.5) <= dmg && Enemy->IsValidTarget(GEntityList->Player(), R->Range()))
					{
						R->CastOnTarget(Enemy, 5);
					}
				}
			}
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

	void OnGapCloser(GapCloserSpell const& Args)
	{

	}

	void OnProcessSpell(CastedSpell const& Args)
	{

	}
};