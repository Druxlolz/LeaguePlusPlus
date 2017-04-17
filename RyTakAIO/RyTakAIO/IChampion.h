#include "IChampion.cpp";
#include "PluginSDK.h";

class IChampion
{
public:
	virtual ~IChampion() = default;
	virtual void OnGameUpdate() = 0;
	virtual void OnRender() = 0;
	virtual void BeforeAttack(IUnit* Source, IUnit* Target) = 0;
	virtual void AfterAttack(IUnit * Source, IUnit * Target) = 0;
	virtual void OnGapCloser(GapCloserSpell const& Args) = 0;
	virtual void OnProcessSpell(CastedSpell const& Args) = 0;
	virtual void OnLoad() = 0;


};