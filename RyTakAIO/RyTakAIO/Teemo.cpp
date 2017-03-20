#include "BaseOptions.h"
#include "OnRender.h"
#include "SpellLib.h"

class TeemoBase
{
public:
	void Menu()
	{
		MainMenu = GPluginSDK->AddMenu("RyTak's Teemo");

		ComboMenu = MainMenu->AddMenu("Combo Settings");
		ComboQ = ComboMenu->CheckBox("Use Q", true);
		ComboW = ComboMenu->CheckBox("Use W", true);
		ComboR = ComboMenu->CheckBox("Use R", true);
		HitRChampions = ComboMenu->AddInteger("Champions To Hit:", 1, 5, 2);

		HarassMenu = MainMenu->AddMenu("Harass Settings");
		HarassQ = HarassMenu->CheckBox("Use Q", true);
		HarassMana = HarassMenu->AddFloat("Min. Mana", 0, 100, 60);

		LaneClearMenu = MainMenu->AddMenu("Farm Settings");
		LaneClearQ = LaneClearMenu->CheckBox("Use Q", true);
		LaneClearR = LaneClearMenu->CheckBox("Use R", true);
		LaneClearRMinions = LaneClearMenu->AddInteger("Min. R Minions", 1, 6, 2);
		LaneClearMana = LaneClearMenu->AddFloat("Min. Mana", 0, 100, 40);

		KSMenu = MainMenu->AddMenu("Killsteal Settings");
		KSQ = KSMenu->CheckBox("Killsteal with Q", true);
		KSR = KSMenu->CheckBox("Killsteal with R", true);

		DrawMenu = MainMenu->AddMenu("Drawing Settings");
		DrawReady = DrawMenu->CheckBox("Draw Only Ready Spells", true);
		DrawOff = DrawMenu->CheckBox("Disable Drawings", false);
		DrawQ = DrawMenu->CheckBox("Draw Q", true);
		DrawR = DrawMenu->CheckBox("Draw R", true);

	}

	void Spells()
	{
		SpellLib().Teemo();
	}

	void Combo()
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			target = GTargetSelector->FindTarget(ClosestPriority, PhysicalDamage, Q->Range());
			for (auto target : GEntityList->GetAllHeros(false, true))

			if (target != nullptr && target->IsValidTarget())
			{
				if (Q->IsReady() && ComboQ->Enabled())
				{
					Q->CastOnTarget(target, 5);
				}
				if (W->IsReady() && ComboW->Enabled())
				{
					W->CastOnTarget(target, 5);
				}
				if (E->IsReady() && ComboE->Enabled())
				{
					E->CastOnPosition(GGame->CursorPosition());
				}
				if (R->IsReady() && ComboR->Enabled())
				{
					R->CastOnTarget(target, 5);
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
			
			if (HarassQ->Enabled() && GEntityList->Player()->ManaPercent() >= HarassMana->GetInteger() && target->IsValidTarget())
			{
				Q->CastOnTarget(target);
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
					if (minion->IsEnemy(GEntityList->Player()) && !minion->IsDead() && GEntityList->Player()->IsValidTarget())
					{
						if (LaneClearQ->Enabled() && Q->IsReady())
						{
							switch (kSlotQ)
							{
							case 1: Q->LastHitMinion();
							default: Q->CastOnTarget(minion, 2);
							}
						}
						if (LaneClearR->Enabled() && R->IsReady())
						{
							Vec3 pos;
							int hit;
							GPrediction->FindBestCastPosition(R->Range(), R->Radius(), true, true, false, pos, hit);
							if (hit >= LaneClearRMinions->GetInteger())
							{
								R->CastOnTarget(minion);
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
			if (Enemy != nullptr && !Enemy->IsDead())
			{
				if (KSQ->Enabled())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotQ, Q->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg)
					{
						Q->CastOnTarget(Enemy);
					}
				}
				if (KSR->Enabled())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotR, R->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg)
					{
						R->CastOnTarget(Enemy);
					}
				}
			}
		}
	}
};