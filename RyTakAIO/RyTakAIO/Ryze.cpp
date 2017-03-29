#include "BaseOptions.h"
#include "OnRender.h"
#include "SpellLib.h"
#include <stdlib.h>

class RyzeBase
{
public:
	void Menu()
	{
		MainMenu = GPluginSDK->AddMenu("RyTak's Ryze");

		ComboMenu = MainMenu->AddMenu("Combo Settings");
		UseCombo = ComboMenu->CheckBox("Use Combo", true);
		RyzeCombos = ComboMenu->AddMenu("Ryze Logics");
		ShieldC = RyzeCombos->CheckBox("Use Shield Combo", true);
		StunC = RyzeCombos->CheckBox("Use Stun Combo", true);
		DelayC = RyzeCombos->CheckBox("Use E-E Combo", true);
		DelayQC = RyzeCombos->CheckBox("Use E-E-Q Combo", true);
		DisableAA = ComboMenu->CheckBox("Use AAs", true);

		HarassMenu = MainMenu->AddMenu("Harass Settings");
		HarassQ = HarassMenu->CheckBox("Use Q", true);
		HarassW = HarassMenu->CheckBox("Use W", true);
		HarassE = HarassMenu->CheckBox("Use E", true);
		HarassMana = HarassMenu->AddFloat("Min. Mana", 0, 100, 60);

		LaneClearMenu = MainMenu->AddMenu("Farm Settings");
		LaneClearQ = LaneClearMenu->CheckBox("Use Q", true);
		LaneClearW = LaneClearMenu->CheckBox("Use W", true);
		LaneClearE = LaneClearMenu->CheckBox("Use E", true);
		LaneClearMana = LaneClearMenu->AddFloat("Min. Mana", 0, 100, 40);

		GapCloseMenu = MainMenu->AddMenu("Gap Closer Settings");
		GapCloseW = GapCloseMenu->CheckBox("Snare Gap Closer with W", true);

		KSMenu = MainMenu->AddMenu("Killsteal Settings");
		KSQ = KSMenu->CheckBox("Killsteal with Q", true);
		KSW = KSMenu->CheckBox("Killsteal with W", true);
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
		SpellLib().Ryze();
	}

	void RRange()
	{
		if (GSpellBook->GetLevel(kSlotR) == 0)
			return;
		if (GSpellBook->GetLevel(kSlotR) == 1)
			R->SetOverrideRange(1750);
		if (GSpellBook->GetLevel(kSlotR) == 2)
			R->SetOverrideRange(3000);
	}

	void Combo()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{				
			target = GTargetSelector->FindTarget(ClosestPriority, SpellDamage, Q->Range());
			for (auto target : GEntityList->GetAllHeros(false, true))

			GOrbwalking->SetAttacksAllowed(DisableAA->Enabled());
			if (target != nullptr && target->IsValidTarget())
			{
				if (UseCombo->Enabled())
				{
					switch (kSlotUnknown)
					{
					default:
					{
						if (ShieldC->Enabled())
						{
							ShieldCombo();
						}
					}
					case 1:
					{
						if (StunC->Enabled())
						{
							StunCombo();
						}
					}
					case 2:
					{
						if (DelayC->Enabled())
						{
							DelayE();
						}
					}
					case 3:
					{
						if (DelayQC->Enabled())
						{
							DelayEQ();
						}
					}
					}
				}
			}
		}
	}

	void Harass()
	{
		Enemy = GTargetSelector->FindTarget(ClosestPriority, SpellDamage, Q->Range());
		for (auto Enemy : GEntityList->GetAllHeros(false, true))
			if (GOrbwalking->GetOrbwalkingMode() == kModeMixed && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger())
			{
				GOrbwalking->SetAttacksAllowed(DisableAA->Enabled());
				if (HarassQ->Enabled() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget())
				{
					Q->CastOnTarget(Enemy, 5);
				}
				if (HarassW->Enabled() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget())
				{
					W->CastOnTarget(Enemy, 5);
				}
				if (HarassE->Enabled() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget())
				{
					E->CastOnTarget(Enemy, 5);
				}
			}
	}

	void LaneClear()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			GOrbwalking->SetAttacksAllowed(DisableAA->Enabled());
			if (GEntityList->Player()->ManaPercent() >= LaneClearMana->GetFloat())
			{
				for (auto minion : GEntityList->GetAllMinions(false, true, true))
				{
					if (minion->IsEnemy(GEntityList->Player()) && !minion->IsDead() && GEntityList->Player()->IsValidTarget(minion, Q->Range()))
					{
						if (LaneClearQ->Enabled() && Q->IsReady())
						{
							switch (kSlotQ)
							{
							case 1: Q->LastHitMinion();
							default: Q->CastOnTarget(minion, 5);
							}
						}
						if (LaneClearW->Enabled() && W->IsReady())
						{
							switch (kSlotW)
							{
							case 1: W->LastHitMinion();
							default: W->CastOnTarget(minion, 5);
							}
						}
						if (LaneClearE->Enabled() && E->IsReady())
						{
							switch (kSlotE)
							{
							case 1: E->LastHitMinion();
							case 2: E->CastOnTargetAoE(minion);
							default: DelayE();
							}
						}
					}
				}
			}
		}
	}

	void LastHit()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeLastHit)
		{
			GOrbwalking->SetAttacksAllowed(true);
		}
	}

	void KS()
	{
		for (auto Enemy : GEntityList->GetAllHeros(false, true))
		{
			if (Enemy != nullptr  && Enemy->IsValidTarget())
			{
				if (KSQ->Enabled())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotQ, Q->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg)
					{
						Q->CastOnTarget(Enemy, 5);
					}
				}
				if (KSW->Enabled())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotW, W->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg)
					{
						W->CastOnTarget(Enemy, 5);
					}
				}
				if (KSE->Enabled())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotE, E->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg)
					{
						E->CastOnTarget(Enemy, 5);
					}
				}
			}
		}
	}

	void StunCombo()
	{
		enemy = GTargetSelector->FindTarget(ClosestPriority, SpellDamage, Q->Range());
		for (auto enemy : GEntityList->GetAllHeros(false, true))
		if (E->IsReady())
		{
			E->CastOnTarget(enemy, 5);
			{
				if (W->IsReady())
				{
					W->CastOnTarget(enemy, 5);
				}				
			}
		}
	}

	void ShieldCombo()
	{
		enemy = GTargetSelector->FindTarget(ClosestPriority, SpellDamage, Q->Range());
		for (auto enemy : GEntityList->GetAllHeros(false, true));
		{
			if (W->IsReady())
			{
				W->CastOnTarget(enemy, 5);
				{
					if (E->IsReady())
					{
						E->CastOnTarget(enemy, 5);
						{
							if (Q->IsReady())
							{
								Q->CastOnTarget(enemy, 5);
							}
						}
					}					
				}
			}
		}
	}

	void DelayE()
	{
		enemy = GTargetSelector->FindTarget(ClosestPriority, SpellDamage, E->Range());
		for (auto enemy : GEntityList->GetAllHeros(false, true))
		if (E->IsReady())
		{
			E->CastOnTarget(enemy, 5);
			{
				Sleep(kSlotE);
				{
					if (E->IsReady())
					{
						E->CastOnTarget(enemy, 5);
					}
				}
			}
		}
	}

	void DelayEQ()
	{
		enemy = GTargetSelector->FindTarget(ClosestPriority, SpellDamage, Q->Range());
		for (auto enemy : GEntityList->GetAllHeros(false, true))
		if (DelayQC->Enabled())
		{
			if (E->IsReady())
			{
				E->CastOnTarget(enemy, 5);
				{
					Sleep(kSlotE);
					{
						if (E->IsReady())
						{
							E->CastOnTarget(enemy, 5);
							{
								if (Q->IsReady())
								{
									Q->CastOnTarget(enemy, 5);
								}
							}
						}
					}
				}
			}
		}
	}

	void GapCloser()
	{
		if (Enemy->IsDashing() && GapCloseW->Enabled())
		{
			W->CastOnTarget(Enemy, 5);
		}
	}
};