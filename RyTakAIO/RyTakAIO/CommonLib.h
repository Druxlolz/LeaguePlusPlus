#pragma once
#include "PluginData.h"
#include "SpellLib.h"
#include "BaseOptions.h"

class GEIR	
{
public:
	int GetEnemiesInRange(float range)
	{
		auto enemies = GEntityList->GetAllHeros(false, true);
		auto enemiesInRange = 0;

		for (auto enemy : enemies)
		{
			auto TargetDistance = (enemy->GetPosition() - GEntityList->Player()->GetPosition()).Length2D();
			if (enemy != nullptr && enemy->GetTeam() != GEntityList->Player()->GetTeam() && enemy->IsValidTarget() && enemy->IsHero())
			{
				if (TargetDistance < range)
				{
					enemiesInRange++;
				}
			}
		}
		return enemiesInRange;
	}
};

class GAIR
{
public:
	int GetAlliesInRange(float range)
	{
		auto allies = GEntityList->GetAllHeros(true, false);
		auto alliesInRange = 0;

		for (auto ally : allies)
		{
			auto TargetDistance = (ally->GetPosition() - GEntityList->Player()->GetPosition()).Length2D();
			if (ally != nullptr && ally->GetTeam() != GEntityList->Player()->GetTeam() && ally->IsValidTarget() && ally->IsHero())
			{
				if (TargetDistance < range)
				{
					alliesInRange++;
				}
			}
		}
		return alliesInRange;
	}
};

class GMIR
{
public:
	int GetMinionsInRange(float range)
	{
		auto minions = GEntityList->GetAllMinions(false, true, true);
		auto minionsInRange = 0;

		for (auto minion : minions)
		{
			auto TargetDistance = (minion->GetPosition() - GEntityList->Player()->GetPosition()).Length2D();
			if (minion != nullptr && minion->GetTeam() != GEntityList->Player()->GetTeam() && (minion->IsCreep() || minion->IsJungleCreep()))
			{
				if (TargetDistance < range)
				{
					minionsInRange++;
				}
			}
		}
		return minionsInRange;
	}
};

class EIISR
{
public:
	bool EnemyIsInSpellRange(float range)
	{
		auto enemies = GEntityList->GetAllHeros(false, true);
		auto enemiesInSpellRange = false;

		for (auto enemy : enemies)
		{
			auto TargetDistance = (enemy->GetPosition() - GEntityList->Player()->GetPosition()).Length2D();
			if (enemy != nullptr && enemy->GetTeam() != GEntityList->Player()->GetTeam() && enemy->IsValidTarget() && enemy->IsHero())
			{
				if (TargetDistance < range)
				{
					enemiesInSpellRange = true;
				}
			}
		}
		return true;
	}
};

class AIISR
{
public:
	bool AllyIsInSpellRange(float range)
	{
		auto allies = GEntityList->GetAllHeros(true, false);
		auto alliesInSpellRange = false;

		for (auto ally : allies)
		{
			auto TargetDistance = (ally->GetPosition() - GEntityList->Player()->GetPosition()).Length2D();
			if (ally != nullptr && ally->GetTeam() == GEntityList->Player()->GetTeam() && ally->IsValidTarget() && ally->IsHero())
			{
				if (TargetDistance < range)
				{
					alliesInSpellRange = true;
				}
			}
		}
		return true;
	}
};
