#include "IChampionManager.h"
#include "SpellDetector.h"

void Lucian::LoadSpecialSpells(SpellData* Data)
{
	if (Init)
		return;

	Init = true;
}

void Lucian::OnDetectorProcessSpell(CastedSpell const& Args, SpellData* Data, bool* ShouldProcess, SpellData** NewData)
{
	if (Data->MenuName != "LucianQ")
		return;

	if (Args.Target_ != GEntityList->Player())
		return;

	SpellDetector->AddSpell(Args.Caster_, Args.Caster_->ServerPosition().To2D(),
		Args.Target_->GetPosition().To2D() + (Args.Target_->ServerPosition().To2D() - Args.Target_->GetPosition().To2D()).VectorNormalize() * Args.Target_->MovementSpeed() * ((Data->Delay - GGame->Latency()) / 1000.f),
		Data);

	*ShouldProcess = false;
}