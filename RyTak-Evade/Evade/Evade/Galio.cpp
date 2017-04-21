#include "IChampionManager.h"
#include "SpellDetector.h"
#include "Evade.h"

void Galio::LoadSpecialSpells(SpellData* Data)
{
	if (Init)
		return;

	Init = true;
}

void Galio::OnDetectorProcessSpell(CastedSpell const& Args, SpellData* Data, bool* ShouldProcess, SpellData** NewData)
{
	if (Data->MenuName != "GalioQCircle")
		return;

	SpellData* pData = Evade::OnProcessSpells["GalioQArc"];

	if (pData != nullptr)
		SpellDetector->AddSpell(Args.Caster_, Args.Caster_->ServerPosition(), Args.EndPosition_, pData);
}

void Galio::OnDetectorCreateSpell(IUnit* Sender, IUnit* Missile, SpellData* Data, SpellData** NewData, bool* ShouldProcess)
{
	if (Data->MenuName != "GalioW")
		return;

	IUnit* pHero = nullptr;

	for (auto i : GEntityList->GetAllHeros(false, true))
	{
		if (i->IsValidObject() && std::string(i->ChampionName()) == Data->ChampName)
		{
			pHero = i;
			break;
		}
	}

	if (Data->MenuName != "GalioE")
		return;

	for (auto i : GEntityList->GetAllHeros(false, true))
	{
		if (i->IsValidObject() && std::string(i->ChampionName()) == Data->ChampName)
		{
			pHero = i;
			break;
		}
	}

	if (Data->MenuName != "GalioE2")
		return;

	for (auto i : GEntityList->GetAllHeros(false, true))
	{
		if (i->IsValidObject() && std::string(i->ChampionName()) == Data->ChampName)
		{
			pHero = i;
			break;
		}
	}

	if (pHero != nullptr)
		SpellDetector->AddSpell(pHero, GMissileData->GetStartPosition(Missile), GMissileData->GetEndPosition(Missile), Data, Missile);

	*ShouldProcess = false;
}