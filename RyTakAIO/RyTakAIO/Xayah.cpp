#pragma once
#include "BaseOptions.h"
#include "SpellLib.h"
#include "FeatherManager.h"
#include <string>

class XayahBase
{
public:
	void Menu()
	{
		MainMenu = GPluginSDK->AddMenu("RyTaks_Xayah");

		ComboMenu = MainMenu->AddMenu("Combo Settings");
		ComboQ = ComboMenu->CheckBox("Use Q", true);
		ComboW = ComboMenu->CheckBox("Use W", true);
		ComboE = ComboMenu->CheckBox("Use E", true);
		ComboEFeathers = ComboMenu->AddInteger("Feathers to Hit for E", 1, 20, 3);

		HarassMenu = MainMenu->AddMenu("Harass Settings");
		HarassQ = HarassMenu->CheckBox("Use Q", true);
		HarassW = HarassMenu->CheckBox("Use W", true);
		HarassE = HarassMenu->CheckBox("Use E", true);
		HarassMana = HarassMenu->AddFloat("Min. Mana", 0, 100, 60);

		LaneClearMenu = MainMenu->AddMenu("Farm Settings");
		LaneClearQ = LaneClearMenu->CheckBox("Use Q", true);
		LaneClearQMinions = LaneClearMenu->AddInteger("Hit x Minions with Q", 1, 6, 3);
		LaneClearW = LaneClearMenu->CheckBox("Use W", true);
		LaneClearE = LaneClearMenu->CheckBox("Use E", true);
		LaneClearEMinions = LaneClearMenu->AddInteger("Hit x Minions with E", 1, 6, 3);
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
		SpellLib().Xayah();
	}

	inline double RDamage(IUnit* Target)
	{
		double Damage = 0;

		double BonusDamage = 2 * GEntityList->Player()->BonusDamage();

		if (GEntityList->Player()->GetSpellLevel(kSlotR) == 1)
		{
			Damage += 100 + BonusDamage;
		}

		if (GEntityList->Player()->GetSpellLevel(kSlotR) == 2)
		{
			Damage += 150 + BonusDamage;
		}

		if (GEntityList->Player()->GetSpellLevel(kSlotR) == 3)
		{
			Damage += 200 + BonusDamage;
		}

		return GDamage->CalcPhysicalDamage(GEntityList->Player(), Target, Damage);
	}

	static void OnProcessSpellCast(CastedSpell const& Args)
	{
		FeatherManager::OnProcessSpellCast(Args);
		if (Args.Caster_ == GEntityList->Player())
		{
			if (GGame->TickCount() - FeatherTickCount < 400 && std::string(Args.Name_) == "XayahQ" || std::string(Args.Name_) == "XayahW" || std::string(Args.Name_) == "XayahR")
			{
				E->CastOnPosition(Args.EndPosition_);
			}

			if (GGame->TickCount() - FeatherTickCount < 400 && std::string(Args.Name_) == "XayahE")
			{
				E->CastOnPosition(Args.EndPosition_);
			}
		}
	}
	static void PauseAnimation(IUnit* Source)
	{
		FeatherManager::OnPauseAnimation(Source);
	}
	
	static int GetFeatherCount()
	{
		return FeatherManager::GetFeathers(false).size();
	}

	static void CastELogic(IUnit* target)
	{
		target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, E->Range());
		for (auto target : GEntityList->GetAllHeros(false, true));
		for (auto FeatherV2 : FeatherManager::GetFeathers(true));
		for (auto FeatherV3 : FeatherManager::GetFeathers(true));
		{
			if (GEntityList->Player()->ServerPosition().To2D().DistanceTo(FeatherV2) <= E->Range())
			{
				auto rangeLeft = GEntityList->Player()->ServerPosition().To2D().DistanceTo(FeatherV2);
				auto start_point = FeatherV2; // - (FeatherV2.VectorNormalize() - GEntityList->Player()->ServerPosition().To2D().VectorNormalize()) * 100;
				auto end_point = GEntityList->Player()->ServerPosition().To2D();

				E->SetOverrideDelay(E->GetDelay() * 1000.f + GEntityList->Player()->ServerPosition().To2D().DistanceTo(FeatherV2)
					/ E->Speed() + target->ServerPosition().To2D().DistanceTo(FeatherV2) / E->Speed());
				E->SetRangeCheckFrom(FeatherV3);
				E->SetFrom(FeatherV3);
				AdvPredictionOutput prediction_output;
				E->RunPrediction(target, true, kCollidesWithYasuoWall, &prediction_output);

				if (prediction_output.HitChance >= kHitChanceHigh && GEntityList->Player()->GetSpellBook()->GetAmmo(kSlotE) >= ComboEFeathers->GetInteger() && FeatherManager::Distance(prediction_output.TargetPosition.To2D(), start_point, end_point, true) < E->Radius() + target->BoundingRadius() && target != nullptr)
				{
					E->CastOnPlayer();
					E->SetFrom(Vec3(0, 0, 0));
					return;
				}
			}
		}
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
						Q->CastOnTarget(target, 6);
						GOrbwalking->ResetAA();
					}
					if (W->IsReady() && ComboW->Enabled() && target->IsValidTarget(GEntityList->Player(), W->Range()))
					{
						W->CastOnPlayer();
						GOrbwalking->ResetAA();
					}
					if (E->IsReady() && ComboE->Enabled() && target->IsValidTarget(GEntityList->Player(), E->Range()))
					{
						CastELogic(target);
						GOrbwalking->ResetAA();
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
			for (auto target : GEntityList->GetAllHeros(false, true))
			{
				if (target != nullptr && target->IsHero())
				{
					if (HarassQ->Enabled() && Q->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget(GEntityList->Player(), Q->Range()))
					{
						Q->CastOnTarget(target, 5);
						GOrbwalking->ResetAA();
					}
					if (HarassW->Enabled() && W->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget(GEntityList->Player(), W->Range()))
					{
						W->CastOnPlayer();
						GOrbwalking->ResetAA();
					}
					if (HarassE->Enabled() && E->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget(GEntityList->Player(), E->Range()))
					{
						E->CastOnPlayer();
						GOrbwalking->ResetAA();
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
				minion = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
				for (auto minion : GEntityList->GetAllMinions(false, true, true))
				{
					if (minion->IsEnemy(GEntityList->Player()) && minion != nullptr && !minion->IsDead() && GEntityList->Player()->IsValidTarget(minion, Q->Range()))
					{
						if (LaneClearQ->Enabled() && Q->IsReady() && minion->IsValidTarget(GEntityList->Player(), Q->Range()))
						{
							Vec3 pos;
							int hit;
							GPrediction->FindBestCastPosition(Q->Range(), Q->Radius(), true, true, true, pos, hit);
							if (hit >= LaneClearQMinions->GetInteger())
							{
								Q->CastOnPosition(pos);
								GOrbwalking->ResetAA();
							}							
						}
						if (LaneClearW->Enabled() && W->IsReady() && minion->IsValidTarget(GEntityList->Player(), W->Range()))
						{
							W->CastOnPlayer();
							GOrbwalking->ResetAA();
						}
						if (LaneClearE->Enabled() && E->IsReady() && minion->IsValidTarget(GEntityList->Player(), E->Range()))
						{
							Vec3 pos;
							int hit;
							GPrediction->FindBestCastPosition(E->Range(), E->Radius(), true, true, true, pos, hit);
							if (hit >= LaneClearEMinions->GetInteger())
							{
								E->CastOnPosition(pos);
								GOrbwalking->ResetAA();
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
		for (auto Enemy : GEntityList->GetAllHeros(false, true))
		{
			if (Enemy != nullptr && !Enemy->IsDead() && Enemy->IsHero())
			{
				if (KSQ->Enabled() && Q->IsReady())
				{
					auto dmg = GPluginSDK->GetDamage()->GetSpellDamage(GEntityList->Player(), Enemy, kSlotQ);
					if (Enemy->GetHealth() <= dmg && Enemy->IsValidTarget(GEntityList->Player(), 1100.f))
					{
						Q->CastOnTarget(Enemy, kHitChanceHigh);
						GOrbwalking->ResetAA();
					}
				}
				if (KSW->Enabled() && W->IsReady())
				{
					auto dmg = GPluginSDK->GetDamage()->GetSpellDamage(GEntityList->Player(), Enemy, kSlotW);
					if (Enemy->GetHealth() <= dmg && Enemy->IsValidTarget(GEntityList->Player(), W->Range()))
					{
						W->CastOnPlayer();
						GOrbwalking->ResetAA();
					}
				}
				if (KSE->Enabled() && E->IsReady())
				{
					auto dmg = GPluginSDK->GetDamage()->GetSpellDamage(GEntityList->Player(), Enemy, kSlotE) * GetFeatherCount();
					if (Enemy->GetHealth() <= dmg && Enemy->IsValidTarget(GEntityList->Player(), E->Range()))
					{
						CastELogic(Enemy);
						GOrbwalking->ResetAA();
					}
				}
				if (KSR->Enabled() && R->IsReady())
				{
					if (Enemy->GetHealth() <= RDamage(Enemy) && Enemy->IsValidTarget(GEntityList->Player(), 1100.f))
					{
						R->CastOnTarget(Enemy, 5);
						GOrbwalking->ResetAA();
					}
				}
			}
		}
	}
};