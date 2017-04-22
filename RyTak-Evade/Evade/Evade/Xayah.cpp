#include "IChampionManager.h"
#include "SpellDetector.h"

void Xayah::LoadSpecialSpells(SpellData* Data)
{
	if (Init)
		return;

	Init = true;
}

void Xayah::OnDetectorProcessSpell(CastedSpell const& Args, SpellData* Data, bool* ShouldProcess, SpellData** NewData)
{
	if (Data->MenuName.substr(0, 3) != "Xayah")
		return;

	for (auto i : GEntityList->GetAllUnits())
	{
		if (!i->IsValidObject() || i->IsDead() || !i->IsVisible() || i->GetTeam() != Args.Caster_->GetTeam())
			continue;

		if (std::string(i->GetObjectName()) != "Feather")
			continue;

		SpellDetector->AddSpell(Args.Caster_, i->ServerPosition(), Args.EndPosition_, Data);
	}
}
