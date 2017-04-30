#pragma once
#include "PluginSDK.h"
#include "BaseOptions.h"
#include "SpellLib.h"
#include "OnRender.cpp"
#include "IChampion.h"

class TwistedFate : public IChampion
{

public:
	void Menu()
	{
		MainMenu = GPluginSDK->AddMenu("RyTaks_Twisted_Fate");

		ComboMenu = MainMenu->AddMenu("Combo Settings");
		ComboQ = ComboMenu->CheckBox("Use Q", true);
		ComboW = ComboMenu->CheckBox("Use W", true);

		HarassMenu = MainMenu->AddMenu("Harass Settings");
		HarassQ = HarassMenu->CheckBox("Use Q", true);
		HarassW = HarassMenu->CheckBox("Use W", true);
		HarassMana = HarassMenu->AddFloat("Min. Mana", 0, 100, 60);

		LaneClearMenu = MainMenu->AddMenu("Farm Settings");
		LaneClearQ = LaneClearMenu->CheckBox("Use Q", true);
		LaneClearW = LaneClearMenu->CheckBox("Use W", true);
		LaneClearMana = LaneClearMenu->AddFloat("Min. Mana", 0, 100, 40);

		PickACardMenu = MainMenu->AddMenu("Pick A Card Menu");
		PickYellowsOption = PickACardMenu->AddKey("Pick Yellow Card", 87);
		PickBluesOption = PickACardMenu->AddKey("Pick Blue Card", 69);
		PickRedsOption = PickACardMenu->AddKey("Pick Red Card", 84);

		GapCloseMenu = MainMenu->AddMenu("Gap Closer Settings");
		GapCloseW = GapCloseMenu->CheckBox("Gold Card Gap Closer", true);

		KSMenu = MainMenu->AddMenu("Killsteal Settings");
		KSQ = KSMenu->CheckBox("Killsteal with Q", true);

		DrawMenu = MainMenu->AddMenu("Drawing Menu");
		DrawQ = DrawMenu->CheckBox("Draw Q", false);
		DrawOff = DrawMenu->CheckBox("Disable Drawings", true);
	}
	void Spells()
	{
		SpellLib().TwistedFate();
	}

	
	
	void PickACard()
	{
		if (!W->IsReady())
		{
			return;
		}
		else if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotW)) == "PickACard")
		{
			W->CastOnPlayer();
		}
	}

	void GoldCard()
	{
		if (GetAsyncKeyState(PickYellowsOption->GetInteger()) || ComboW->Enabled() || GapCloseW->Enabled())
		{
			if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotW)) == "GoldCardLock")
			{
				W->CastOnPlayer();
			}
		}
	}

	void RedCard()
	{
		if (GetAsyncKeyState(PickRedsOption->GetInteger()) || HarassW->Enabled() || LaneClearW->Enabled())
		{
			if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotW)) == "RedCardLock")
			{
				W->CastOnPlayer();
			}
		}
	}

	void BlueCard()
	{
		if (GetAsyncKeyState(PickBluesOption->GetInteger()) || HarassW->Enabled() || LaneClearW->Enabled())
		{
			if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotW)) == "BlueCardLock")
			{
				W->CastOnPlayer();
			}
		}
	}

	void Combo()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			if (Q->IsReady() && ComboQ->Enabled() && target->IsValidTarget(GEntityList->Player(), Q->Range()))
			{
				Q->CastOnTarget(target, 5);
			}
			if (W->IsReady() && ComboW->Enabled() && target->IsValidTarget(GEntityList->Player(), W->Range()))
			{
				PickACard();
				{
					GoldCard();
				}
			}
		}

	}

	void Harass()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed && GEntityList->Player()->ManaPercent() >= HarassMana->GetFloat())
		{
			if (Q->IsReady() && HarassQ->Enabled() && target->IsValidTarget(GEntityList->Player(), Q->Range()))
			{
				Q->CastOnTarget(target, 5);
			}
			if (W->IsReady() && HarassW->Enabled() && target->IsValidTarget(GEntityList->Player(), W->Range()))
			{
				PickACard();
				{
					RedCard();
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
					if (minion->IsValidTarget() && !minion->IsDead())
					{
						if (LaneClearQ->Enabled() && Q->IsReady() && minion->IsValidTarget(GEntityList->Player(), Q->Range()))
						{
							Q->CastOnTarget(minion, 5);
						}
						if (LaneClearW->Enabled() && W->IsReady() && minion->IsValidTarget(GEntityList->Player(), W->Range()))
						{
							PickACard();
							{
								RedCard();
							}
						}
					}
				}
			}
			else if (GEntityList->Player()->ManaPercent() <= LaneClearMana->GetFloat())
			{
				if (LaneClearW->Enabled() && W->IsReady() && minion->IsValidTarget(GEntityList->Player(), W->Range()))
				{
					PickACard();
					{
						BlueCard();
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
			}
		}
	}

	void GapCloser()
	{
		if (target->IsDashing() && GapCloseW->Enabled() && !target->IsCreep() && !target->IsJungleCreep() && target->IsHero() && target->IsValidTarget(GEntityList->Player(), W->Range()))
		{
			PickACard();
			{
				GoldCard();
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

