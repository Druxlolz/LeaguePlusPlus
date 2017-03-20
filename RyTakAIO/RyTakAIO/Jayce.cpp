#pragma once
#include "PluginSDK.h"
#include "BaseOptions.h"
#include "SpellLib.h"

class JayceBase
{

public:
	void Menu()
	{
		MainMenu = GPluginSDK->AddMenu("RyTak's Jayce");

		ComboMenu = MainMenu->AddMenu("Combo Settings");
		MeleeOptionsC = ComboMenu->AddMenu("Melee Combo");
		ComboQ = MeleeOptionsC->CheckBox("Use Q", true);
		ComboW = MeleeOptionsC->CheckBox("Use W", true);
		ComboE = MeleeOptionsC->CheckBox("Use E", true);
		RangedOptionsC = ComboMenu->AddMenu("Ranged Combo");
		ComboQ2 = RangedOptionsC->CheckBox("Use Q", true);
		ComboW2 = RangedOptionsC->CheckBox("Use W", true);
		ComboE2 = RangedOptionsC->CheckBox("Use E", true);
		ChangeForm = ComboMenu->CheckBox("Auto Form Change", true);
		ComboEQ = ComboMenu->CheckBox("Use E->Q Combo in Gun Form", true);
		SemiEQ = ComboMenu->AddKey("Semi-Auto EQ", 84);

		HarassMenu = MainMenu->AddMenu("Harass Settings");
		MeleeOptionsH = HarassMenu->AddMenu("Melee Harass");
		HarassQ = MeleeOptionsH->CheckBox("Use Q", true);
		HarassW = MeleeOptionsH->CheckBox("Use W", true);
		HarassE = MeleeOptionsH->CheckBox("Use E", true);
		RangedOptionsH = HarassMenu->AddMenu("Ranged Harass");
		HarassQ2 = RangedOptionsH->CheckBox("Use Q", true);
		HarassW2 = RangedOptionsH->CheckBox("Use W", true);
		HarassMana = HarassMenu->AddFloat("Min. Mana", 0, 100, 60);

		LaneClearMenu = MainMenu->AddMenu("Farm Settings");
		MeleeOptionsL = LaneClearMenu->AddMenu("Melee Clear");
		LaneClearQ = MeleeOptionsL->CheckBox("Use Q", true);
		LaneClearW = MeleeOptionsL->CheckBox("Use W", true);
		LaneClearE = MeleeOptionsL->CheckBox("Use E", true);
		RangedOptionsL = LaneClearMenu->AddMenu("Ranged Clear");
		LaneClearQ2 = RangedOptionsL->CheckBox("Use Q", true);
		LaneClearW2 = RangedOptionsL->CheckBox("Use W", true);
		LaneClearE2 = RangedOptionsL->CheckBox("Use E", true);
		LaneClearMana = LaneClearMenu->AddFloat("Min. Mana", 0, 100, 40);

		GapCloseMenu = MainMenu->AddMenu("Gap Close Settings");
		GapCloseE = GapCloseMenu->CheckBox("Use E on Gapcloser", true);

		KSMenu = MainMenu->AddMenu("Killsteal Settings");
		MeleeOptionsK = KSMenu->AddMenu("Melee KS");
		KSQ = MeleeOptionsK->CheckBox("Killsteal with Q", true);
		KSW = MeleeOptionsK->CheckBox("Killsteal with W", true);
		KSE = MeleeOptionsK->CheckBox("Killsteal with E", true);
		RangedOptionsK = KSMenu->AddMenu("Ranged KS");
		KSQ2 = RangedOptionsK->CheckBox("Killsteal with Q", true);
		KSW2 = RangedOptionsK->CheckBox("Killsteal with W", true);
		KSE2 = RangedOptionsK->CheckBox("Killsteal with E", true);

		DrawMenu = MainMenu->AddMenu("Drawing Settings");
		DrawReady = DrawMenu->CheckBox("Draw Only Ready Spells", true);
		DrawOff = DrawMenu->CheckBox("Disable Drawings", false);
		DrawQ = DrawMenu->CheckBox("Draw Q", true);
		DrawW = DrawMenu->CheckBox("Draw W", true);
		DrawE = DrawMenu->CheckBox("Draw E", true);
		DrawQ2 = DrawMenu->CheckBox("Draw Q", true);
		DrawW2 = DrawMenu->CheckBox("Draw W", true);
		DrawE2 = DrawMenu->CheckBox("Draw E", true);
	}
	void Spells()
	{
		SpellLib().Jayce();
	}

	void AutoFormChange()
	{
		if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotR)) == "JayceStanceGtH" || std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotR)) == "JayceStanceHtG")
		{
			if (!Q->IsReady() && !W->IsReady() && !E->IsReady() && R->IsReady() && ChangeForm->Enabled())
			{
				JayceHtG();
			}
			if (!Q2->IsReady() && !W2->IsReady() && !E2->IsReady() && R2->IsReady() && ChangeForm->Enabled())
			{
				JayceGtH();
			}
		}
	}

	//Hammer Dunk
	void JayceSkies()
	{
		if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotQ)) == "JayceToTheSkies")
		{
			Q->CastOnTarget(target, 5);
		}
	}

	//Hammer Field
	void JayceField()
	{
		if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotW)) == "JayceStaticField")
		{
			W->CastOnPlayer();
		}
	}

	//Hammer Knockback
	void JayceThunder()
	{
		if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotE)) == "JayceThunderingBlow")
		{
			E->CastOnTarget(target, 5);
		}
	}

	//Gun Missile
	void JayceShock()
	{
		if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotQ)) == "JayceShockBlast")
		{
			Q2->CastOnTarget(target, 5);
		}
	}

	//Gun 3 Shot
	void JayceHyper()
	{
		if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotW)) == "JayceHyperCharge")
		{
			W2->CastOnTarget(target, 5);
		}
	}

	//Accel. Gate
	void JayceGate()
	{
		if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotE)) == "JayceAccelerationGate")
		{
			Vec3 pos;
			int hit;
			GPrediction->FindBestCastPosition(Q2->Range(), E2->Radius(), false, false, true, pos, hit);
			{
				E2->CastOnPosition(pos);
			}
		}
	}

	//Gun to Hammer
	void JayceGtH()
	{
		if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotR)) == "JayceStanceGtH")
		{
			R2->CastOnPlayer();
		}
	}

	//Hammer to Gun
	void JayceHtG()
	{
		if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotR)) == "JayceStanceHtG")
		{
			R->CastOnPlayer();
		}
	}

	//EQ Combo for Gun Mode
	void EQCombo()
	{
		target = GTargetSelector->FindTarget(ClosestPriority, PhysicalDamage, Q->Range());
		for (auto target : GEntityList->GetAllHeros(false, true))
		if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotE)) == "JayceAccelerationGate" && std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotQ)) == "JayceShockBlast" && ComboEQ->Enabled())
		{
			if ((GEntityList->Player()->GetPosition() - target->GetPosition()).Length2D() <= Q2->Range())
			{
				Vec3 posE;
				Vec3 posQ;
				int hit;
				GPrediction->FindBestCastPosition(Q2->Range(), Q2->Radius(), false, true, true, posQ, hit);
				GPrediction->FindBestCastPosition(E2->Range(), E2->Radius(), false, false, true, posE, hit);
				{
					E2->CastOnPosition(posQ);
					{
						if (Q2->IsReady())
						{
							Q2->CastOnTarget(target, 4);
						}
					}
				}
			}
			if ((GEntityList->Player()->GetPosition() - target->GetPosition()).Length2D() >= Q2->Range())
			{
				return;
			}
		}
	}

	void MissileCheck()
	{
		if (GMissileData->GetName(Q2) == "JayceShockBlastMis")
		{
			Q2->SetOverrideRange(1050);
			Q2->SetOverrideSpeed(1450);
		}	
		if (GMissileData->GetName(Q2) == "JayceShockBlastCharged")
		{
			Q2->SetOverrideRange(1470);
			Q2->SetOverrideSpeed(1890);
		}
	}

	void Combo()
	{
		target = GTargetSelector->FindTarget(ClosestPriority, PhysicalDamage, Q->Range());
		for (auto target : GEntityList->GetAllHeros(false, true))
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotR)) == "JayceStanceHtG")
			{
				if (Q->IsReady() && ComboQ->Enabled())
				{
					Q->CastOnTarget(target, 5);
				}
				if (W->IsReady() && ComboW->Enabled() && target->IsValidTarget(GEntityList->Player(), W->Range()))
				{
					JayceField();
				}
				if (E->IsReady() && ComboE->Enabled())
				{
					E->CastOnTarget(target, 5);
				}
			}
			if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotR)) == "JayceStanceGtH")
			{
				if (W2->IsReady() && ComboW2->Enabled())
				{
					JayceHyper();
				}
				if (ComboEQ->Enabled())
				{
					EQCombo();
				}
			}
		}
	}

	void Harass()
	{
		target = GTargetSelector->FindTarget(ClosestPriority, PhysicalDamage, Q->Range());
		for (auto target : GEntityList->GetAllHeros(false, true))
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed && GEntityList->Player()->ManaPercent() >= HarassMana->GetFloat())
		{
			if (target != nullptr && target->IsValidTarget() && !target->IsDead())
			{
				if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotR)) == "JayceStanceHtG")
				{
					if (Q->IsReady() && HarassQ->Enabled())
					{
						Q->CastOnTarget(target, 5);
					}
					if (W->IsReady() && HarassW->Enabled() && target->IsValidTarget(GEntityList->Player(), W->Range()))
					{
						JayceField();
					}
					if (E->IsReady() && HarassE->Enabled())
					{
						E->CastOnTarget(target, 5);
					}
				}
				if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotR)) == "JayceStanceGtH")
				{
					if (Q2->IsReady() && HarassQ2->Enabled())
					{
						JayceShock();
					}
					if (W2->IsReady() && HarassW2->Enabled())
					{
						JayceHyper();
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
				minion = GTargetSelector->FindTarget(ClosestPriority, PhysicalDamage, Q->Range());
				for (auto minion : GEntityList->GetAllMinions(false, true, true))
				{
					if (minion != nullptr && !minion->IsDead())
					{
						if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotR)) == "JayceStanceHtG")
						{
							if (LaneClearQ->Enabled() && Q->IsReady() && minion->IsValidTarget(GEntityList->Player(), Q->Range()))
							{
								Q->CastOnTarget(minion, 4);
							}
							if (LaneClearW->Enabled() && W->IsReady() && minion->IsValidTarget(GEntityList->Player(), W->Range()))
							{
								JayceField();
							}
							if (LaneClearE->Enabled() && E->IsReady() && minion->IsValidTarget(GEntityList->Player(), E->Range()))
							{
								E->CastOnTarget(minion, 4);
							}
						}
						if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotR)) == "JayceStanceGtH")
						{
							if (LaneClearQ2->Enabled() && Q2->IsReady())
							{
								JayceShock();
							}
							if (LaneClearW2->Enabled() && W2->IsReady())
							{
								JayceHyper();
							}
						}
					}
				}
			}
		}
	}

	void KS()
	{
		Enemy = GTargetSelector->FindTarget(ClosestPriority, PhysicalDamage, Q->Range());
		for (auto Enemy : GEntityList->GetAllHeros(false, true))
		{
			if (Enemy != nullptr && Enemy->IsValidTarget())
			{
				if (KSQ->Enabled() && Q->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotQ, Q->GetDelay(), false);
					if (Enemy->GetHealth() <= dmg)
					{
						JayceSkies();
					}
				}
				if (KSW->Enabled() && W->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotW, W->GetDelay(), false);
					if (Enemy->GetHealth() <= dmg)
					{
						JayceField();
					}
				}
				if (KSE->Enabled() && E->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotE, E->GetDelay(), false);
					if (Enemy->GetHealth() <= dmg)
					{
						JayceThunder();
					}
				}
				if (KSQ2->Enabled() && Q2->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotQ, Q2->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg)
					{
						JayceShock();
					}
				}
				if (KSW2->Enabled() && W2->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotW, W2->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg)
					{
						JayceHyper();
					}
				}
				if (KSQ2->Enabled() && KSE2->Enabled() && Q2->IsReady() && E2->IsReady())
				{
					auto dmg = GHealthPrediction->GetKSDamage(Enemy, kSlotQ, Q2->GetDelay(), true);
					if (Enemy->GetHealth() <= dmg)
					{
						EQCombo();
					}
				}
			}
		}
	}

	void GapCloser()
	{
		if (target->IsDashing() && GapCloseE->Enabled())
		{
			if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotR)) == "JayceStanceGtH" && R2->IsReady())
			{
				JayceGtH();
			}
			if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotR)) == "JayceStanceHtG")
			{
				JayceThunder();
			}
			else return;
		}
	}

	void SemiAutoEQ()
	{
		if (GetAsyncKeyState(SemiEQ->GetInteger()) && E2->IsReady() && Q2->IsReady())
		{
			enemy = GTargetSelector->FindTarget(ClosestPriority, PhysicalDamage, Q2->Range());
			for (auto enemy : GEntityList->GetAllHeros(false, true))
			{
				if (enemy->IsEnemy(GEntityList->Player()) && (GEntityList->Player()->GetPosition() - enemy->GetPosition()).Length2D() <= Q2->Range() && enemy->IsHero())
				{
					EQCombo();
				}
				if ((GEntityList->Player()->GetPosition() - enemy->GetPosition()).Length2D() >= Q2->Range())
				{
					return;
				}
			}
		}
	}

	void Render()
	{
		if (DrawOff->Enabled()) return;

		if (DrawReady->Enabled())
		{
			if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotR)) == "JayceStanceHtG")
			{
				if (DrawQ->Enabled() && Q->IsReady())
				{
					GRender->DrawCircle(GEntityList->Player()->GetPosition(), Q->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				}
				if (DrawW->Enabled() && W->IsReady())
				{
					GRender->DrawCircle(GEntityList->Player()->GetPosition(), W->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				}
				if (DrawE->Enabled() && E->IsReady())
				{
					GRender->DrawCircle(GEntityList->Player()->GetPosition(), E->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				}
			}
			if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotR)) == "JayceStanceGtH")
			{
				if (DrawQ2->Enabled() && Q2->IsReady())
				{
					GRender->DrawCircle(GEntityList->Player()->GetPosition(), Q2->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				}
				if (DrawW2->Enabled() && W2->IsReady())
				{
					GRender->DrawCircle(GEntityList->Player()->GetPosition(), W2->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				}
				if (DrawE2->Enabled() && E2->IsReady())
				{
					GRender->DrawCircle(GEntityList->Player()->GetPosition(), E2->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				}
			}
		}
		else
		{
			if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotR)) == "JayceStanceHtG")
			{
				if (DrawQ->Enabled())
				{
					GRender->DrawCircle(GEntityList->Player()->GetPosition(), Q->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				}
				if (DrawW->Enabled())
				{
					GRender->DrawCircle(GEntityList->Player()->GetPosition(), W->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				}
				if (DrawE->Enabled())
				{
					GRender->DrawCircle(GEntityList->Player()->GetPosition(), E->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				}
			}
			if (std::string(GEntityList->Player()->GetSpellBook()->GetName(kSlotR)) == "JayceStanceGtH")
			{
				if (DrawQ2->Enabled())
				{
					GRender->DrawCircle(GEntityList->Player()->GetPosition(), Q2->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				}
				if (DrawW2->Enabled())
				{
					GRender->DrawCircle(GEntityList->Player()->GetPosition(), W2->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				}
				if (DrawE2->Enabled())
				{
					GRender->DrawCircle(GEntityList->Player()->GetPosition(), E2->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				}
			}
		}
	}
};

