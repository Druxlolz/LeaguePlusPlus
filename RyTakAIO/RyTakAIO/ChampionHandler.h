#include "PluginSDK.h"

class ChampionManager
{
public:

	//Base Champion
	virtual ~ChampionManager() = default;
	virtual float Health() = 0;
	virtual float HPRegen() = 0;
	virtual float Mana() = 0;
	virtual float ManaRegen() = 0;
	virtual float AARange() = 0;
	virtual float AttackDamage() = 0;
	virtual float AttackSpeed() = 0;
	virtual float AbilityPower() = 0;
	virtual float Armor() = 0;
	virtual float MagicResist() = 0;
	virtual float MoveSpeed() = 0;
	virtual float BonusManaDamage() = 0;
	
	//Standard Spell Damage
	virtual float QSpellDamage() = 0;
	virtual float WSpellDamage() = 0;
	virtual float ESpellDamage() = 0;
	virtual float RSpellDamage() = 0;

	//Transforming Champion Damage
	virtual float Q2SpellDamage() = 0;
	virtual float W2SpellDamage() = 0;
	virtual float E2SpellDamage() = 0;
	virtual float R2SpellDamage() = 0;

	//Standard Spell Loader
	virtual void LoadSpellQ() = 0;
	virtual void LoadSpellW() = 0;
	virtual void LoadSpellE() = 0;
	virtual void LoadSpellR() = 0;

	//Extended Spell Loader
	virtual void LoadSpellQ2() = 0;
	virtual void LoadSpellW2() = 0;
	virtual void LoadSpellE2() = 0;
	virtual void LoadSpellR2() = 0;

	//Items
	virtual void ActiveItems() = 0;
	virtual void PassiveItems() = 0;

	//Summoner Spells
	virtual void Barrier() = 0;
	virtual void Clarity() = 0;
	virtual void Cleanse() = 0;
	virtual void Exhaust() = 0;
	virtual void Flash() = 0;
	virtual void Ghost() = 0;
	virtual void Heal() = 0;
	virtual void Ignite() = 0;
	virtual void Mark() = 0;
	virtual void Dash() = 0;
	virtual void Smite() = 0;
	virtual void Teleport() = 0;

	//Stat Modifiers
	virtual void MSModifier() = 0;
	virtual void ASModifier() = 0;
};