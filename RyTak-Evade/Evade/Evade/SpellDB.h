#include "SpellData.h"

struct SpellDB
{
	SpellDB();
	SpellData* CreateSpell()
	{
		auto pData = new SpellData;
		return pData->InitializeDefaults();
	}

	std::vector<SpellData*> Spells;
};

extern SpellDB* SpellsDB;