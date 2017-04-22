#pragma once
#include "BaseOptions.h"
#include "SpellLib.h"

class MissFortuneBase
{
public:
	void Menu()
	{
		MainMenu = GPluginSDK->AddMenu("RyTaks_Miss_Fortune");

		ComboMenu = MainMenu->AddMenu("Combo Settings");
		ComboQ = ComboMenu->CheckBox("Use Q", true);
		BounceEnemy = ComboMenu->CheckBox("Use Q Bounce On Champions", true);
		ComboW = ComboMenu->CheckBox("Use W", true);
		ComboE = ComboMenu->CheckBox("Use E", true);
		SemiR = ComboMenu->AddKey("Semi-Auto R", 84);

		HarassMenu = MainMenu->AddMenu("Harass Settings");
		HarassQ = HarassMenu->CheckBox("Use Q", true);
		HarassE = HarassMenu->CheckBox("Use E", true);
		BounceHarass = HarassMenu->CheckBox("Use Q Bounce Harass", true);
		HarassMana = HarassMenu->AddFloat("Min. Mana", 0, 100, 60);

		LaneClearMenu = MainMenu->AddMenu("Farm Settings");
		LaneClearQ = LaneClearMenu->CheckBox("Use Q", true);
		LaneClearE = LaneClearMenu->CheckBox("Use E", true);
		BounceClear = LaneClearMenu->CheckBox("Use Q Bounce to Clear", true);
		BounceCrit = LaneClearMenu->CheckBox("Use Crit Q", true);
		LaneClearMana = LaneClearMenu->AddFloat("Min. Mana", 0, 100, 40);

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
		SpellLib().MissFortune();
	}

	void Combo()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			target = GTargetSelector->FindTarget(ClosestToCursorPriority, PhysicalDamage, Q->Range());
			for (auto target : GEntityList->GetAllHeros(false, true))
			{
				if (target != nullptr && target->IsHero() && !target->IsDead() && target->IsEnemy(GEntityList->Player()))
				{
					if (Q->IsReady() && ComboQ->Enabled() && target->IsValidTarget(GEntityList->Player(), Q->Range()))
					{
						Q->CastOnTarget(target, 5);						
					}
					if (BounceEnemy->Enabled())
					{
						EnemyBounce();
					}
					if (W->IsReady() && ComboW->Enabled() && target->IsValidTarget(GEntityList->Player(), W->Range()))
					{
						W->CastOnPlayer();
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
			Enemy = GTargetSelector->FindTarget(ClosestToCursorPriority, PhysicalDamage, Q->Range());
			for (auto Enemy : GEntityList->GetAllHeros(false, true));

			if (HarassQ->Enabled() && GEntityList->Player()->ManaPercent() >= HarassMana->GetFloat() && !Enemy->IsDead() && target->IsValidTarget(GEntityList->Player(), Q->Range()))
			{
				if (BounceHarass->Enabled() && Q->IsReady())
				{
					Bounce();
				}
				if (Q->IsReady())
				{
					Q->CastOnTarget(Enemy, 5);
				}
			}			
			if (HarassE->Enabled() && E->IsReady() && GEntityList->Player()->ManaPercent() >= HarassMana->GetFloat() && !target->IsDead() && Enemy->IsValidTarget(GEntityList->Player(), E->Range()))
			{
				E->CastOnTarget(Enemy, 5);
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
						if (LaneClearQ->Enabled() && minion->IsValidTarget(GEntityList->Player(), Q->Range()))
						{
							if (BounceClear->Enabled() && Q->IsReady())
							{
								minion1 = GTargetSelector->FindTarget(ClosestPriority, PhysicalDamage, Q->Range());
								minion2 = GTargetSelector->FindTarget(ClosestPriority, PhysicalDamage, Q->Range() + 250);
								for (auto minion1 : GEntityList->GetAllMinions(false, true, true))
								for (auto minion2 : GEntityList->GetAllMinions(false, true, true))
									{
									if ((GEntityList->Player()->GetPosition() - minion1->GetPosition()).Length2D() <= Q->Range() && (minion->GetPosition() - minion2->GetPosition()).Length2D() <= 250)
										{
											Q->LastHitMinion();
										}
									}
							}							
							else if (BounceHarass->Enabled() && Q->IsReady())
							{
								Bounce();
							}
							else if (BounceCrit->Enabled() && Q->IsReady())
							{
								CritBounce();
							}
							else Q->CastOnTarget(minion, 5);
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
		Enemy = GTargetSelector->FindTarget(ClosestToCursorPriority, PhysicalDamage, Q->Range());
		for (auto Enemy : GEntityList->GetAllHeros(false, true))
		{
			if (Enemy != nullptr && Enemy->IsHero() && !Enemy->IsDead())
			{
				if (KSQ->Enabled() && Q->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotQ, Q->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg && Enemy->IsValidTarget(GEntityList->Player(), Q->Range()))
					{
						Q->CastOnTarget(Enemy, 5);
					}
				}
				if (KSE->Enabled() && E->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotE, E->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg && Enemy->IsValidTarget(GEntityList->Player(), E->Range()))
					{
						E->CastOnTarget(Enemy, 5);
					}
				}
				if (KSR->Enabled() && R->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotR, R->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg && Enemy->IsValidTarget(GEntityList->Player(), R->Range()))
					{
						R->CastOnTarget(Enemy, 5);
					}
				}
			}
		}
	}

	void RDamage()
	{
		if (GetAsyncKeyState(SemiR->GetInteger()) && R->IsReady())
		{
			enemy = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, R->Range());
			for (auto enemy : GEntityList->GetAllHeros(false, true))
			{
				if (enemy->IsEnemy(GEntityList->Player()) && (GEntityList->Player()->GetPosition() - enemy->GetPosition()).Length2D() <= R->Range() && !enemy->IsDead() && enemy->IsValidTarget(GEntityList->Player(), R->Range()))
				{
					R->CastOnTarget(enemy, 5);
				}
			}
		}
	}

	void Bounce()
	{
		minion = GTargetSelector->FindTarget(ClosestPriority, PhysicalDamage, Q->Range());
		Enemy = GTargetSelector->FindTarget(ClosestPriority, PhysicalDamage, Q->Range() + 250);
		for (auto Enemy : GEntityList->GetAllHeros(false, true))
		for (auto minion : GEntityList->GetAllMinions(false, true, true))
		{
			if ((GEntityList->Player()->GetPosition() - minion->GetPosition()).Length2D() <= Q->Range() && 250.f >= (minion->GetPosition() - Enemy->GetPosition()).Length2D() <= (GEntityList->Player()->GetPosition() - Enemy->GetPosition()).Length2D() && Enemy->IsValidTarget(GEntityList->Player(), Q->Range() + 250))
			{
				Q->CastOnTarget(minion, 5);
			}
		}
	}

	void EnemyBounce()
	{
		Enemy1 = GTargetSelector->FindTarget(ClosestPriority, PhysicalDamage, Q->Range());
		Enemy2 = GTargetSelector->FindTarget(ClosestPriority, PhysicalDamage, Q->Range() + 250);
		for (auto Enemy1 : GEntityList->GetAllHeros(false, true))
			for (auto Enemy2 : GEntityList->GetAllHeros(false, true))
			{
				if ((GEntityList->Player()->GetPosition() - Enemy1->GetPosition()).Length2D() <= Q->Range() && 250 >= (Enemy1->GetPosition() - Enemy2->GetPosition()).Length2D() <= (GEntityList->Player()->GetPosition() - Enemy1->GetPosition()).Length2D() && Enemy1->IsValidTarget(GEntityList->Player(), Q->Range()))
				{
					Q->CastOnTarget(minion, 5);
				}
			}
	}

	void CritBounce()
	{
		minion = GTargetSelector->FindTarget(ClosestPriority, PhysicalDamage, Q->Range());
		Enemy = GTargetSelector->FindTarget(ClosestPriority, PhysicalDamage, Q->Range() + 250);
		for (auto Enemy : GEntityList->GetAllHeros(false, true));
		for (auto minion : GEntityList->GetAllMinions(false, true, true));
			{
				if ((GEntityList->Player()->GetPosition() - minion->GetPosition()).Length2D() <= Q->Range() && 250 >= (minion->GetPosition() - Enemy->GetPosition()).Length2D() <= (GEntityList->Player()->GetPosition() - Enemy->GetPosition()).Length2D() && Enemy->IsValidTarget(GEntityList->Player(), Q->Range()) && GPluginSDK->GetDamage()->GetSpellDamage(GEntityList->Player(), Enemy, kSlotQ) > minion->GetHealth())
				{
					Q->LastHitMinion();
				}
			}
	}
};