#include "BaseOptions.h"
#include "SpellLib.h"

class CorkiBase
{
public:
	void Menu()
	{
		MainMenu = GPluginSDK->AddMenu("RyTak's Corki");

		ComboMenu = MainMenu->AddMenu("Combo Settings");
		ComboQ = ComboMenu->CheckBox("Use Q", true);
		ComboE = ComboMenu->CheckBox("Use E", true);
		SemiR = ComboMenu->AddKey("Semi-Auto R", 84);

		HarassMenu = MainMenu->AddMenu("Harass Settings");
		HarassQ = HarassMenu->CheckBox("Use Q", true);
		HarassE = HarassMenu->CheckBox("Use E", true);
		HarassMana = HarassMenu->AddFloat("Min. Mana", 0, 100, 60);

		LaneClearMenu = MainMenu->AddMenu("Farm Settings");
		LaneClearQ = LaneClearMenu->CheckBox("Use Q", true);
		LaneClearE = LaneClearMenu->CheckBox("Use E", false);
		LaneClearR = LaneClearMenu->CheckBox("Use R", false);
		LaneClearQMinions = LaneClearMenu->AddInteger("Minions to hit: Q", 1, 6, 3);
		LaneClearRMinions = LaneClearMenu->AddInteger("Minions to hit: R", 1, 6, 3);
		LaneClearMana = LaneClearMenu->AddFloat("Min. Mana", 0, 100, 40);

		GapCloseMenu = MainMenu->AddMenu("Gap Closer Settings");
		GapCloseW = GapCloseMenu->CheckBox("Use W to Anti-Gap Close (Mouse Position)", true);

		KSMenu = MainMenu->AddMenu("Killsteal Settings");
		KSQ = KSMenu->CheckBox("Killsteal with Q", true);
		KSE = KSMenu->CheckBox("Killsteal with E", false);
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
		SpellLib().Corki();
	}

	void Combo()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
			for (auto target : GEntityList->GetAllHeros(false, true))
			{
				if (target != nullptr)
				{
					if (Q->IsReady() && ComboQ->Enabled() && target->IsValidTarget(GEntityList->Player(), Q->Range()))
					{
						Q->CastOnTarget(target, 5);
					}
					if (E->IsReady() && ComboE->Enabled() && target->IsValidTarget(GEntityList->Player(), E->Range()))
					{
						E->CastOnTarget(target, 5);
					}
					if (R->IsReady() && ComboR->Enabled() && target->IsValidTarget(GEntityList->Player(), R->Range()))
					{
						R->CastOnTarget(target, 5);
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
			for (auto target : GEntityList->GetAllHeros(false, true))
			{
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
	}

	void LaneClear()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			minion = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, Q->Range());
			if (GEntityList->Player()->ManaPercent() >= LaneClearMana->GetFloat())
			{
				for (auto minion : GEntityList->GetAllMinions(false, true, true))
				{
					if (minion->IsEnemy(GEntityList->Player()) && !minion->IsDead())
					{
						if (LaneClearQ->Enabled() && Q->IsReady())
						{
							Vec3 pos;
							int hit;
							GPrediction->FindBestCastPosition(Q->Range(), Q->Radius(), true, true, false, pos, hit);
							if (hit >= LaneClearQMinions->GetInteger() && minion->IsValidTarget(GEntityList->Player(), Q->Range()))
							{
								Q->CastOnPosition(pos);
							}
						}
						if (LaneClearE->Enabled() && E->IsReady() && minion->IsValidTarget(GEntityList->Player(), E->Range()))
						{
							E->CastOnTarget(minion);
						}
						if (LaneClearR->Enabled() && R->IsReady() && minion->IsValidTarget(GEntityList->Player(), R->Range()))
						{
							Vec3 pos;
							int hit;
							GPrediction->FindBestCastPosition(R->Range(), R->Radius(), true, true, false, pos, hit);
							if (hit >= LaneClearRMinions->GetInteger())
							{
								R->CastOnPosition(pos);
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
			if (Enemy != nullptr && !Enemy->IsDead() && !Enemy->IsInvulnerable())
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
						E->CastOnTarget(Enemy, 5);
					}
				}
				if (KSR->Enabled() && R->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotR, R->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg && Enemy->IsValidTarget(GEntityList->Player(), Q->Range()))
					{
						R->CastOnTarget(Enemy, kHitChanceHigh);
					}
				}
			}
		}
	}

	void GapCloser()
	{
		if (target->IsDashing() && GapCloseW->Enabled() && target->IsValidTarget(GEntityList->Player(), W->Range()))
		{
			W->CastOnPosition(GGame->CursorPosition());
		}
	}

	void RDamage()
	{
		if (GetAsyncKeyState(SemiR->GetInteger()) && R->IsReady())
		{
			enemy = GTargetSelector->FindTarget(ClosestToCursorPriority, SpellDamage, R->Range());
			for (auto enemy : GEntityList->GetAllHeros(false, true))
			{
				if (enemy->IsEnemy(GEntityList->Player()) && (GEntityList->Player()->GetPosition() - enemy->GetPosition()).Length2D() <= R->Range() && target->IsValidTarget(GEntityList->Player(), R->Range()))
				{
					R->CastOnTarget(enemy, 5);
				}
			}
		}
	}
};