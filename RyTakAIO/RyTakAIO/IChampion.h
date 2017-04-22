#include "PluginSDK.h"
#include "BaseOptions.h"
#include "OnRender.cpp"
#include "Aatrox.cpp"
#include "Ahri.cpp"
#include "Akali.cpp"
#include "Alistar.cpp"
#include "Amumu.cpp"
#include "Anivia.cpp"
#include "Annie.cpp"
#include "Ashe.cpp"
#include "AurelionSol.cpp"
#include "Azir.cpp"
#include "Bard.cpp"
#include "Blitzcrank.cpp"
#include "Brand.cpp"
#include "Braum.cpp"
#include "Caitlyn.cpp"
#include "Camille.cpp"
#include "Cassiopeia.cpp"
#include "ChoGath.cpp"
#include "Corki.cpp"
#include "Darius.cpp"
#include "Diana.cpp"
#include "DrMundo.cpp"
#include "Draven.cpp"
#include "Ekko.cpp"
#include "Elise.cpp"
#include "Evelynn.cpp"
#include "Ezreal.cpp"
#include "Fiddlesticks.cpp"
#include "Fiora.cpp"
#include "Fizz.cpp"
#include "Galio.cpp"
#include "Gangplank.cpp"
#include "Garen.cpp"
#include "Gnar.cpp"
#include "Gragas.cpp"
#include "Graves.cpp"
#include "Hecarim.cpp"
#include "Heimerdinger.cpp"
#include "Illaoi.cpp"
#include "Irelia.cpp"
#include "Ivern.cpp"
#include "Janna.cpp"
#include "JarvanIV.cpp"
#include "Jax.cpp"
#include "Jayce.cpp"
#include "Jhin.cpp"
#include "Jinx.cpp"
#include "Kalista.cpp"
#include "Karma.cpp"
#include "Karthus.cpp"
#include "Kassadin.cpp"
#include "Katarina.cpp"
#include "Kayle.cpp"
#include "Kennen.cpp"
#include "KhaZix.cpp"
#include "Kindred.cpp"
#include "Kled.cpp"
#include "KogMaw.cpp"
#include "LeBlanc.cpp"
#include "LeeSin.cpp"
#include "Leona.cpp"
#include "Lissandra.cpp"
#include "Lucian.cpp"
#include "Lulu.cpp"
#include "Lux.cpp"
#include "Malphite.cpp"
#include "Malzahar.cpp"
#include "Maokai.cpp"
#include "MasterYi.cpp"
#include "MissFortune.cpp"
#include "Mordekaiser.cpp"
#include "Morgana.cpp"
#include "Nami.cpp"
#include "Nasus.cpp"
#include "Nautilus.cpp"
#include "Nidalee.cpp"
#include "Nocturne.cpp"
#include "Nunu.cpp"
#include "Olaf.cpp"
#include "Orianna.cpp"
#include "Pantheon.cpp"
#include "Poppy.cpp"
#include "Quinn.cpp"
#include "Rammus.cpp"
#include "RekSai.cpp"
#include "Renekton.cpp"
#include "Rengar.cpp"
#include "Riven.cpp"
#include "Rumble.cpp"
#include "Ryze.cpp"
#include "Sejuani.cpp"
#include "Shaco.cpp"
#include "Shen.cpp"
#include "Shyvana.cpp"
#include "Singed.cpp"
#include "Sion.cpp"
#include "Sivir.cpp"
#include "Skarner.cpp"
#include "Sona.cpp"
#include "Soraka.cpp"
#include "Swain.cpp"
#include "Syndra.cpp"
#include "TahmKench.cpp"
#include "Taliyah.cpp"
#include "Talon.cpp"
#include "Taric.cpp"
#include "Teemo.cpp"
#include "Thresh.cpp"
#include "Tristana.cpp"
#include "Trundle.cpp"
#include "Tryndamere.cpp"
#include "TwistedFate.cpp"
#include "Twitch.cpp"
#include "Udyr.cpp"
#include "Urgot.cpp"
#include "Varus.cpp"
#include "Vayne.cpp"
#include "Veigar.cpp"
#include "VelKoz.cpp"
#include "Vi.cpp"
#include "Viktor.cpp"
#include "Vladimir.cpp"
#include "Volibear.cpp"
#include "Warwick.cpp"
#include "Wukong.cpp"
#include "Xayah.cpp"
#include "Xerath.cpp"
#include "XinZhao.cpp"
#include "Yasuo.cpp"
#include "Yorick.cpp"
#include "Zac.cpp"
#include "Zed.cpp"
#include "Ziggs.cpp"
#include "Zilean.cpp"
#include "Zyra.cpp"
#include <sstream>

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

class Aatrox : public IChampion
{
public:
	void OnLoad() override
	{
		AatroxBase().Menu();
		AatroxBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		AatroxBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			AatroxBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			AatroxBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			AatroxBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Ahri : public IChampion
{
public:
	void OnLoad() override
	{
		AhriBase().Menu();
		AhriBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		AhriBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			AhriBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			AhriBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			AhriBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Akali : public IChampion
{
public:
	void OnLoad() override
	{
		AkaliBase().Menu();
		AkaliBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		AkaliBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			AkaliBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			AkaliBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			AkaliBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Alistar : public IChampion
{
public:
	void OnLoad() override
	{
		AlistarBase().Menu();
		AlistarBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		AlistarBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			AlistarBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			AlistarBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			AlistarBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Amumu : public IChampion
{
public:
	void OnLoad() override
	{
		AmumuBase().Menu();
		AmumuBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		AmumuBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			AmumuBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			AmumuBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			AmumuBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Anivia : public IChampion
{
public:
	void OnLoad() override
	{
		AniviaBase().Menu();
		AniviaBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		AniviaBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			AniviaBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			AniviaBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			AniviaBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Annie : public IChampion
{
public:
	void OnLoad() override
	{
		AnnieBase().Menu();
		AnnieBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		AnnieBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			AnnieBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			AnnieBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			AnnieBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Ashe : public IChampion
{
public:
	void OnLoad() override
	{
		AsheBase().Menu();
		AsheBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			AsheBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			AsheBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			AsheBase().LaneClear();
		}
		AsheBase().KS();
		AsheBase().RDamage();
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{
		target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, E->Range());
		for (auto target : GEntityList->GetAllHeros(false, true));
		{
			if (target != nullptr && !target->IsDead() && !target->IsInvulnerable())
			{
				AsheBase().GapCloser();
			}
		}
	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class AurelionSol : public IChampion
{
public:
	void OnLoad() override
	{
		AurelionSolBase().Menu();
		AurelionSolBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		AurelionSolBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			AurelionSolBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			AurelionSolBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			AurelionSolBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Azir : public IChampion
{
public:
	void OnLoad() override
	{
		AzirBase().Menu();
		AzirBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		AzirBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			AzirBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			AzirBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			AzirBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Bard : public IChampion
{
public:
	void OnLoad() override
	{
		BardBase().Menu();
		BardBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		BardBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			BardBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			BardBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			BardBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Blitzcrank : public IChampion
{
public:
	void OnLoad() override
	{
		BlitzcrankBase().Menu();
		BlitzcrankBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		BlitzcrankBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			BlitzcrankBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			BlitzcrankBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			BlitzcrankBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Brand : public IChampion
{
public:
	void OnLoad() override
	{
		BrandBase().Menu();
		BrandBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		BrandBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			BrandBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			BrandBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			BrandBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Braum : public IChampion
{
public:
	void OnLoad() override
	{
		BraumBase().Menu();
		BraumBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		BraumBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			BraumBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			BraumBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			BraumBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Caitlyn : public IChampion
{
public:
	void OnLoad() override
	{
		CaitlynBase().Menu();
		CaitlynBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			CaitlynBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			CaitlynBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			CaitlynBase().LaneClear();
		}
		CaitlynBase().KS();
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{
		target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, E->Range());
		for (auto target : GEntityList->GetAllHeros(false, true));
		{
			if (target != nullptr && !target->IsDead() && !target->IsInvulnerable())
			{
				CaitlynBase().GapCloser();
			}
		}
	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Camille : public IChampion
{
public:
	void OnLoad() override
	{
		CamilleBase().Menu();
		CamilleBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		CamilleBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			CamilleBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			CamilleBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			CamilleBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Cassiopeia : public IChampion
{
public:
	void OnLoad() override
	{
		CassiopeiaBase().Menu();
		CassiopeiaBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		CassiopeiaBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			CassiopeiaBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			CassiopeiaBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			CassiopeiaBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class ChoGath : public IChampion
{
public:
	void OnLoad() override
	{
		ChoGathBase().Menu();
		ChoGathBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		ChoGathBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			ChoGathBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			ChoGathBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			ChoGathBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Corki : public IChampion
{
public:
	void OnLoad() override
	{
		CorkiBase().Menu();
		CorkiBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			CorkiBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			CorkiBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			CorkiBase().LaneClear();
		}
		CorkiBase().KS();
		CorkiBase().RDamage();
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{
		target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, E->Range());
		for (auto target : GEntityList->GetAllHeros(false, true));
		{
			if (target != nullptr && !target->IsDead() && !target->IsInvulnerable())
			{
				CorkiBase().GapCloser();
			}
		}
	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Darius : public IChampion
{
public:
	void OnLoad() override
	{
		DariusBase().Menu();
		DariusBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		DariusBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			DariusBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			DariusBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			DariusBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Diana : public IChampion
{
public:
	void OnLoad() override
	{
		DianaBase().Menu();
		DianaBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		DianaBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			DianaBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			DianaBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			DianaBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class DrMundo : public IChampion
{
public:
	void OnLoad() override
	{
		DrMundoBase().Menu();
		DrMundoBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		DrMundoBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			DrMundoBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			DrMundoBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			DrMundoBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Draven : public IChampion
{
public:
	void OnLoad() override
	{
		DravenBase().Menu();
		DravenBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		DravenBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			DravenBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			DravenBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			DravenBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Ekko : public IChampion
{
public:
	void OnLoad() override
	{
		EkkoBase().Menu();
		EkkoBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		EkkoBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			EkkoBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			EkkoBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			EkkoBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Elise : public IChampion
{
public:
	void OnLoad() override
	{
		EliseBase().Menu();
		EliseBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		EliseBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			EliseBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			EliseBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			EliseBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Evelynn : public IChampion
{
public:
	void OnLoad() override
	{
		EvelynnBase().Menu();
		EvelynnBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		EvelynnBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			EvelynnBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			EvelynnBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			EvelynnBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Ezreal : public IChampion
{
public:
	void OnLoad() override
	{
		EzrealBase().Menu();
		EzrealBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			EzrealBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			EzrealBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			EzrealBase().LaneClear();
		}
		EzrealBase().KS();
		EzrealBase().RDamage();
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{
		target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, E->Range());
		for (auto target : GEntityList->GetAllHeros(false, true));
		{
			if (target != nullptr && !target->IsDead() && !target->IsInvulnerable())
			{
				EzrealBase().GapCloser();
			}
		}
	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Fiddlesticks : public IChampion
{
public:
	void OnLoad() override
	{
		FiddlesticksBase().Menu();
		FiddlesticksBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		FiddlesticksBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			FiddlesticksBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			FiddlesticksBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			FiddlesticksBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Fiora : public IChampion
{
public:
	void OnLoad() override
	{
		FioraBase().Menu();
		FioraBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		FioraBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			FioraBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			FioraBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			FioraBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Fizz : public IChampion
{
public:
	void OnLoad() override
	{
		FizzBase().Menu();
		FizzBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		FizzBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			FizzBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			FizzBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			FizzBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Galio : public IChampion
{
public:
	void OnLoad() override
	{
		GalioBase().Menu();
		GalioBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		GalioBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			GalioBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			GalioBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			GalioBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Gangplank : public IChampion
{
public:
	void OnLoad() override
	{
		GangplankBase().Menu();
		GangplankBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		GangplankBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			GangplankBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			GangplankBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			GangplankBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Garen : public IChampion
{
public:
	void OnLoad() override
	{
		GarenBase().Menu();
		GarenBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		GarenBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			GarenBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			GarenBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			GarenBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Gnar : public IChampion
{
public:
	void OnLoad() override
	{
		GnarBase().Menu();
		GnarBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		GnarBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			GnarBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			GnarBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			GnarBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Gragas : public IChampion
{
public:
	void OnLoad() override
	{
		GragasBase().Menu();
		GragasBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		GragasBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			GragasBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			GragasBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			GragasBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Graves : public IChampion
{
public:
	void OnLoad() override
	{
		GravesBase().Menu();
		GravesBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		GravesBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			GravesBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			GravesBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			GravesBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Hecarim : public IChampion
{
public:
	void OnLoad() override
	{
		HecarimBase().Menu();
		HecarimBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		HecarimBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			HecarimBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			HecarimBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			HecarimBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Heimerdinger : public IChampion
{
public:
	void OnLoad() override
	{
		HeimerdingerBase().Menu();
		HeimerdingerBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		HeimerdingerBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			HeimerdingerBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			HeimerdingerBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			HeimerdingerBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Illaoi : public IChampion
{
public:
	void OnLoad() override
	{
		IllaoiBase().Menu();
		IllaoiBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		IllaoiBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			IllaoiBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			IllaoiBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			IllaoiBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Irelia : public IChampion
{
public:
	void OnLoad() override
	{
		IreliaBase().Menu();
		IreliaBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		IreliaBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			IreliaBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			IreliaBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			IreliaBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Ivern : public IChampion
{
public:
	void OnLoad() override
	{
		IvernBase().Menu();
		IvernBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		IvernBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			IvernBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			IvernBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			IvernBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Janna : public IChampion
{
public:
	void OnLoad() override
	{
		JannaBase().Menu();
		JannaBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		JannaBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			JannaBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			JannaBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			JannaBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class JarvanIV : public IChampion
{
public:
	void OnLoad() override
	{
		JarvanIVBase().Menu();
		JarvanIVBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		JarvanIVBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			JarvanIVBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			JarvanIVBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			JarvanIVBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Jax : public IChampion
{
public:
	void OnLoad() override
	{
		JaxBase().Menu();
		JaxBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		JaxBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			JaxBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			JaxBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			JaxBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Jayce : public IChampion
{
public:
	void OnLoad() override
	{
		JayceBase().Menu();
		JayceBase().Spells();
	}
	void OnRender() override
	{
		JayceBase().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			JayceBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			JayceBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			JayceBase().LaneClear();
		}
		JayceBase().KS();
		JayceBase().AutoFormChange();
		JayceBase().SemiAutoEQ();
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{
		target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, E->Range());
		for (auto target : GEntityList->GetAllHeros(false, true));
		{
			if (target != nullptr && !target->IsDead() && !target->IsInvulnerable())
			{
				JayceBase().GapCloser();
			}
		}
	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Jhin : public IChampion
{
public:
	void OnLoad() override
	{
		JhinBase().Menu();
		JhinBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		JhinBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			JhinBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			JhinBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			JhinBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Jinx : public IChampion
{
public:
	void OnLoad() override
	{
		JinxBase().Menu();
		JinxBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		JinxBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			JinxBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			JinxBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			JinxBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Kalista : public IChampion
{
public:
	void OnLoad() override
	{
		KalistaBase().Menu();
		KalistaBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		KalistaBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			KalistaBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			KalistaBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			KalistaBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Karma : public IChampion
{
public:
	void OnLoad() override
	{
		KarmaBase().Menu();
		KarmaBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		KarmaBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			KarmaBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			KarmaBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			KarmaBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Karthus : public IChampion
{
public:
	void OnLoad() override
	{
		KarthusBase().Menu();
		KarthusBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		KarthusBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			KarthusBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			KarthusBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			KarthusBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Kassadin : public IChampion
{
public:
	void OnLoad() override
	{
		KassadinBase().Menu();
		KassadinBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		KassadinBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			KassadinBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			KassadinBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			KassadinBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Katarina : public IChampion
{
public:
	void OnLoad() override
	{
		KatarinaBase().Menu();
		KatarinaBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		KatarinaBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			KatarinaBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			KatarinaBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			KatarinaBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Kayle : public IChampion
{
public:
	void OnLoad() override
	{
		KayleBase().Menu();
		KayleBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		KayleBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			KayleBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			KayleBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			KayleBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Kennen : public IChampion
{
public:
	void OnLoad() override
	{
		KennenBase().Menu();
		KennenBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		KennenBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			KennenBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			KennenBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			KennenBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class KhaZix : public IChampion
{
public:
	void OnLoad() override
	{
		KhaZixBase().Menu();
		KhaZixBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		KhaZixBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			KhaZixBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			KhaZixBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			KhaZixBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Kindred : public IChampion
{
public:
	void OnLoad() override
	{
		KindredBase().Menu();
		KindredBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		KindredBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			KindredBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			KindredBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			KindredBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Kled : public IChampion
{
public:
	void OnLoad() override
	{
		KledBase().Menu();
		KledBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		KledBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			KledBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			KledBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			KledBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class KogMaw : public IChampion
{
public:
	void OnLoad() override
	{
		KogMawBase().Menu();
		KogMawBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		KogMawBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			KogMawBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			KogMawBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			KogMawBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class LeBlanc : public IChampion
{
public:
	void OnLoad() override
	{
		LeBlancBase().Menu();
		LeBlancBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		LeBlancBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			LeBlancBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			LeBlancBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			LeBlancBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class LeeSin : public IChampion
{
public:
	void OnLoad() override
	{
		LeeSinBase().Menu();
		LeeSinBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		LeeSinBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			LeeSinBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			LeeSinBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			LeeSinBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Leona : public IChampion
{
public:
	void OnLoad() override
	{
		LeonaBase().Menu();
		LeonaBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		LeonaBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			LeonaBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			LeonaBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			LeonaBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Lissandra : public IChampion
{
public:
	void OnLoad() override
	{
		LissandraBase().Menu();
		LissandraBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		LissandraBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			LissandraBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			LissandraBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			LissandraBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Lucian : public IChampion
{
public:
	void OnLoad() override
	{
		LucianBase().Menu();
		LucianBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			LucianBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			LucianBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			LucianBase().LaneClear();
		}
		LucianBase().KS();
		LucianBase().CheckPassive();
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{
		target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, E->Range());
		for (auto target : GEntityList->GetAllHeros(false, true));
		{
			if (target != nullptr && !target->IsDead() && !target->IsInvulnerable())
			{
				LucianBase().GapCloser();
			}
		}
	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Lulu : public IChampion
{
public:
	void OnLoad() override
	{
		LuluBase().Menu();
		LuluBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		LuluBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			LuluBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			LuluBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			LuluBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Lux : public IChampion
{
public:
	void OnLoad() override
	{
		LuxBase().Menu();
		LuxBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		LuxBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			LuxBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			LuxBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			LuxBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Malphite : public IChampion
{
public:
	void OnLoad() override
	{
		MalphiteBase().Menu();
		MalphiteBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		MalphiteBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			MalphiteBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			MalphiteBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			MalphiteBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Malzahar : public IChampion
{
public:
	void OnLoad() override
	{
		MalzaharBase().Menu();
		MalzaharBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		MalzaharBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			MalzaharBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			MalzaharBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			MalzaharBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Maokai : public IChampion
{
public:
	void OnLoad() override
	{
		MaokaiBase().Menu();
		MaokaiBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		MaokaiBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			MaokaiBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			MaokaiBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			MaokaiBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class MasterYi : public IChampion
{
public:
	void OnLoad() override
	{
		MasterYiBase().Menu();
		MasterYiBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		MasterYiBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			MasterYiBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			MasterYiBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			MasterYiBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class MissFortune : public IChampion
{
public:
	void OnLoad() override
	{
		MissFortuneBase().Menu();
		MissFortuneBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			MissFortuneBase().Combo();
			MissFortuneBase().EnemyBounce();
			MissFortuneBase().Bounce();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			MissFortuneBase().Harass();
			MissFortuneBase().EnemyBounce();
			MissFortuneBase().CritBounce();
			MissFortuneBase().Bounce();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			MissFortuneBase().LaneClear();
			MissFortuneBase().EnemyBounce();
			MissFortuneBase().CritBounce();
			MissFortuneBase().Bounce();
		}
		MissFortuneBase().KS();
		MissFortuneBase().RDamage();
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Mordekaiser : public IChampion
{
public:
	void OnLoad() override
	{
		MordekaiserBase().Menu();
		MordekaiserBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		MordekaiserBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			MordekaiserBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			MordekaiserBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			MordekaiserBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Morgana : public IChampion
{
public:
	void OnLoad() override
	{
		MorganaBase().Menu();
		MorganaBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			MorganaBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			MorganaBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			MorganaBase().LaneClear();
		}
		MorganaBase().KS();
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{
		target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, E->Range());
		for (auto target : GEntityList->GetAllHeros(false, true));
		{
			if (target != nullptr && !target->IsDead() && !target->IsInvulnerable())
			{
				MorganaBase().GapCloser();
			}
		}
	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Nami : public IChampion
{
public:
	void OnLoad() override
	{
		NamiBase().Menu();
		NamiBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		NamiBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			NamiBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			NamiBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			NamiBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Nasus : public IChampion
{
public:
	void OnLoad() override
	{
		NasusBase().Menu();
		NasusBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		NasusBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			NasusBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			NasusBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			NasusBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Nautilus : public IChampion
{
public:
	void OnLoad() override
	{
		NautilusBase().Menu();
		NautilusBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		NautilusBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			NautilusBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			NautilusBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			NautilusBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Nidalee : public IChampion
{
public:
	void OnLoad() override
	{
		NidaleeBase().Menu();
		NidaleeBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		NidaleeBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			NidaleeBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			NidaleeBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			NidaleeBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Nocturne : public IChampion
{
public:
	void OnLoad() override
	{
		NocturneBase().Menu();
		NocturneBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		NocturneBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			NocturneBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			NocturneBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			NocturneBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Nunu : public IChampion
{
public:
	void OnLoad() override
	{
		NunuBase().Menu();
		NunuBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		NunuBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			NunuBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			NunuBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			NunuBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Olaf : public IChampion
{
public:
	void OnLoad() override
	{
		OlafBase().Menu();
		OlafBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		OlafBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			OlafBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			OlafBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			OlafBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Orianna : public IChampion
{
public:
	void OnLoad() override
	{
		OriannaBase().Menu();
		OriannaBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		OriannaBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			OriannaBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			OriannaBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			OriannaBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Pantheon : public IChampion
{
public:
	void OnLoad() override
	{
		PantheonBase().Menu();
		PantheonBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		PantheonBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			PantheonBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			PantheonBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			PantheonBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Poppy : public IChampion
{
public:
	void OnLoad() override
	{
		PoppyBase().Menu();
		PoppyBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		PoppyBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			PoppyBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			PoppyBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			PoppyBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Quinn : public IChampion
{
public:
	void OnLoad() override
	{
		QuinnBase().Menu();
		QuinnBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		QuinnBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			QuinnBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			QuinnBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			QuinnBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Rammus : public IChampion
{
public:
	void OnLoad() override
	{
		RammusBase().Menu();
		RammusBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		RammusBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			RammusBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			RammusBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			RammusBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class RekSai : public IChampion
{
public:
	void OnLoad() override
	{
		RekSaiBase().Menu();
		RekSaiBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		RekSaiBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			RekSaiBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			RekSaiBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			RekSaiBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Renekton : public IChampion
{
public:
	void OnLoad() override
	{
		RenektonBase().Menu();
		RenektonBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		RenektonBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			RenektonBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			RenektonBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			RenektonBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Rengar : public IChampion
{
public:
	void OnLoad() override
	{
		RengarBase().Menu();
		RengarBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		RengarBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			RengarBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			RengarBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			RengarBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Riven : public IChampion
{
public:
	void OnLoad() override
	{
		RivenBase().Menu();
		RivenBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		RivenBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			RivenBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			RivenBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			RivenBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Rumble : public IChampion
{
public:
	void OnLoad() override
	{
		RumbleBase().Menu();
		RumbleBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		RumbleBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			RumbleBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			RumbleBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			RumbleBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Ryze : public IChampion
{
public:
	void OnLoad() override
	{
		RyzeBase().Menu();
		RyzeBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			RyzeBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			RyzeBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			RyzeBase().LaneClear();
		}
		RyzeBase().KS();
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{
		target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, E->Range());
		for (auto target : GEntityList->GetAllHeros(false, true));
		{
			if (target != nullptr && !target->IsDead() && !target->IsInvulnerable())
			{
				RyzeBase().GapCloser();
			}
		}
	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Sejuani : public IChampion
{
public:
	void OnLoad() override
	{
		SejuaniBase().Menu();
		SejuaniBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		SejuaniBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			SejuaniBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			SejuaniBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			SejuaniBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Shaco : public IChampion
{
public:
	void OnLoad() override
	{
		ShacoBase().Menu();
		ShacoBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		ShacoBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			ShacoBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			ShacoBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			ShacoBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Shen : public IChampion
{
public:
	void OnLoad() override
	{
		ShenBase().Menu();
		ShenBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		ShenBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			ShenBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			ShenBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			ShenBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Shyvana : public IChampion
{
public:
	void OnLoad() override
	{
		ShyvanaBase().Menu();
		ShyvanaBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		ShyvanaBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			ShyvanaBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			ShyvanaBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			ShyvanaBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Singed : public IChampion
{
public:
	void OnLoad() override
	{
		SingedBase().Menu();
		SingedBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		SingedBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			SingedBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			SingedBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			SingedBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Sion : public IChampion
{
public:
	void OnLoad() override
	{
		SionBase().Menu();
		SionBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		SionBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			SionBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			SionBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			SionBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Sivir : public IChampion
{
public:
	void OnLoad() override
	{
		SivirBase().Menu();
		SivirBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		SivirBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			SivirBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			SivirBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			SivirBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Skarner : public IChampion
{
public:
	void OnLoad() override
	{
		SkarnerBase().Menu();
		SkarnerBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		SkarnerBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			SkarnerBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			SkarnerBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			SkarnerBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Sona : public IChampion
{
public:
	void OnLoad() override
	{
		SonaBase().Menu();
		SonaBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		SonaBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			SonaBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			SonaBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			SonaBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Soraka : public IChampion
{
public:
	void OnLoad() override
	{
		SorakaBase().Menu();
		SorakaBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		SorakaBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			SorakaBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			SorakaBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			SorakaBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Swain : public IChampion
{
public:
	void OnLoad() override
	{
		SwainBase().Menu();
		SwainBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		SwainBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			SwainBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			SwainBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			SwainBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Syndra : public IChampion
{
public:
	void OnLoad() override
	{
		SyndraBase().Menu();
		SyndraBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		SyndraBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			SyndraBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			SyndraBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			SyndraBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class TahmKench : public IChampion
{
public:
	void OnLoad() override
	{
		TahmKenchBase().Menu();
		TahmKenchBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		TahmKenchBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			TahmKenchBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			TahmKenchBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			TahmKenchBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Taliyah : public IChampion
{
public:
	void OnLoad() override
	{
		TaliyahBase().Menu();
		TaliyahBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		TaliyahBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			TaliyahBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			TaliyahBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			TaliyahBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Talon : public IChampion
{
public:
	void OnLoad() override
	{
		TalonBase().Menu();
		TalonBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		TalonBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			TalonBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			TalonBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			TalonBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Taric : public IChampion
{
public:
	void OnLoad() override
	{
		TaricBase().Menu();
		TaricBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		TaricBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			TaricBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			TaricBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			TaricBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Teemo : public IChampion
{
public:
	void OnLoad() override
	{
		TeemoBase().Menu();
		TeemoBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			TeemoBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			TeemoBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			TeemoBase().LaneClear();
		}
		TeemoBase().KS();
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Thresh : public IChampion
{
public:
	void OnLoad() override
	{
		ThreshBase().Menu();
		ThreshBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		ThreshBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			ThreshBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			ThreshBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			ThreshBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Tristana : public IChampion
{
public:
	void OnLoad() override
	{
		TristanaBase().Menu();
		TristanaBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		TristanaBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			TristanaBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			TristanaBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			TristanaBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Trundle : public IChampion
{
public:
	void OnLoad() override
	{
		TrundleBase().Menu();
		TrundleBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		TrundleBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			TrundleBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			TrundleBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			TrundleBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Tryndamere : public IChampion
{
public:
	void OnLoad() override
	{
		TryndamereBase().Menu();
		TryndamereBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		TryndamereBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			TryndamereBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			TryndamereBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			TryndamereBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class TwistedFate : public IChampion
{
public:
	void OnLoad() override
	{
		TwistedFateBase().Menu();
		TwistedFateBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			TwistedFateBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			TwistedFateBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			TwistedFateBase().LaneClear();
		}
		TwistedFateBase().KS();
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{
		target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, E->Range());
		for (auto target : GEntityList->GetAllHeros(false, true));
		{
			if (target != nullptr && !target->IsDead() && !target->IsInvulnerable())
			{
				TwistedFateBase().GapCloser();
			}
		}
	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Twitch : public IChampion
{
public:
	void OnLoad() override
	{
		TwitchBase().Menu();
		TwitchBase().Spells();
	}
	void OnRender() override
	{
		//OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{
		
	}
	void OnGameUpdate() override
	{
		TwitchBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			TwitchBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			TwitchBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			TwitchBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Udyr : public IChampion
{
public:
	void OnLoad() override
	{
		UdyrBase().Menu();
		UdyrBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		UdyrBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			UdyrBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			UdyrBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			UdyrBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Urgot : public IChampion
{
public:
	void OnLoad() override
	{
		UrgotBase().Menu();
		UrgotBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		UrgotBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			UrgotBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			UrgotBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			UrgotBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Varus : public IChampion
{
public:
	void OnLoad() override
	{
		VarusBase().Menu();
		VarusBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			VarusBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			VarusBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			VarusBase().LaneClear();
		}
		VarusBase().KS();
		VarusBase().RDamage();
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{
		target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, E->Range());
		for (auto target : GEntityList->GetAllHeros(false, true));
		{
			if (target != nullptr && !target->IsDead() && !target->IsInvulnerable())
			{
				VarusBase().GapCloser();
			}
		}
	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Vayne : public IChampion
{
public:
	void OnLoad() override
	{
		VayneBase().Menu();
		VayneBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		VayneBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			VayneBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			VayneBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			VayneBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Veigar : public IChampion
{
public:
	void OnLoad() override
	{
		VeigarBase().Menu();
		VeigarBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		VeigarBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			VeigarBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			VeigarBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			VeigarBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class VelKoz : public IChampion
{
public:
	void OnLoad() override
	{
		VelKozBase().Menu();
		VelKozBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		VelKozBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			VelKozBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			VelKozBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			VelKozBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Vi : public IChampion
{
public:
	void OnLoad() override
	{
		ViBase().Menu();
		ViBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		ViBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			ViBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			ViBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			ViBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Viktor : public IChampion
{
public:
	void OnLoad() override
	{
		ViktorBase().Menu();
		ViktorBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		ViktorBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			ViktorBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			ViktorBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			ViktorBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Vladimir : public IChampion
{
public:
	void OnLoad() override
	{
		VladimirBase().Menu();
		VladimirBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		VladimirBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			VladimirBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			VladimirBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			VladimirBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Volibear : public IChampion
{
public:
	void OnLoad() override
	{
		VolibearBase().Menu();
		VolibearBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		VolibearBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			VolibearBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			VolibearBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			VolibearBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Warwick : public IChampion
{
public:
	void OnLoad() override
	{
		WarwickBase().Menu();
		WarwickBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		WarwickBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			WarwickBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			WarwickBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			WarwickBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Wukong : public IChampion
{
public:
	void OnLoad() override
	{
		WukongBase().Menu();
		WukongBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		WukongBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			WukongBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			WukongBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			WukongBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Xayah : public IChampion
{
public:
	void OnLoad() override
	{
		XayahBase().Menu();
		XayahBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{		
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			XayahBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			XayahBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			XayahBase().LaneClear();
		}
		XayahBase().KS();
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{
		
	}
	void OnProcessSpell(CastedSpell const& Args) override
	{
		XayahBase().OnProcessSpellCast(Args);
	}
	bool OnPreCast(int Slot, IUnit* Target, Vec3* StartPosition, Vec3* EndPosition)
	{
		return true;
	}
	void OnPauseAnimation(IUnit* Source) 
	{
		XayahBase().PauseAnimation(Source);
	}
};

class Xerath : public IChampion
{
public:
	void OnLoad() override
	{
		XerathBase().Menu();
		XerathBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			XerathBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			XerathBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			XerathBase().LaneClear();
		}
		XerathBase().KS();
		XerathBase().InitialR();
		XerathBase().RDamage();
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{
		target = GTargetSelector->FindTarget(QuickestKill, PhysicalDamage, E->Range());
		for (auto target : GEntityList->GetAllHeros(false, true));
		{
			if (target != nullptr && !target->IsDead() && !target->IsInvulnerable())
			{
				XerathBase().GapCloser();
			}
		}
	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class XinZhao : public IChampion
{
public:
	void OnLoad() override
	{
		XinZhaoBase().Menu();
		XinZhaoBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		XinZhaoBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			XinZhaoBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			XinZhaoBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			XinZhaoBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Yasuo : public IChampion
{
public:
	void OnLoad() override
	{
		YasuoBase().Menu();
		YasuoBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			YasuoBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			YasuoBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			YasuoBase().LaneClear();
		}
		YasuoBase().KS();
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Yorick : public IChampion
{
public:
	void OnLoad() override
	{
		YorickBase().Menu();
		YorickBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		YorickBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			YorickBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			YorickBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			YorickBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Zac : public IChampion
{
public:
	void OnLoad() override
	{
		ZacBase().Menu();
		ZacBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		ZacBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			ZacBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			ZacBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			ZacBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Zed : public IChampion
{
public:
	void OnLoad() override
	{
		ZedBase().Menu();
		ZedBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		ZedBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			ZedBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			ZedBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			ZedBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Ziggs : public IChampion
{
public:
	void OnLoad() override
	{
		ZiggsBase().Menu();
		ZiggsBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		ZiggsBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			ZiggsBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			ZiggsBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			ZiggsBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Zilean : public IChampion
{
public:
	void OnLoad() override
	{
		ZileanBase().Menu();
		ZileanBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		ZileanBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			ZileanBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			ZileanBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			ZileanBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};

class Zyra : public IChampion
{
public:
	void OnLoad() override
	{
		ZyraBase().Menu();
		ZyraBase().Spells();
	}
	void OnRender() override
	{
		OnRenderClass().Render();
	}
	void BeforeAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void AfterAttack(IUnit* Source, IUnit* Target) override
	{

	}
	void OnGameUpdate() override
	{
		ZyraBase().KS();

		if (GOrbwalking->GetOrbwalkingMode() == kModeCombo)
		{
			ZyraBase().Combo();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeMixed)
		{
			ZyraBase().Harass();
		}
		if (GOrbwalking->GetOrbwalkingMode() == kModeLaneClear)
		{
			ZyraBase().LaneClear();
		}
	}
	void OnGapCloser(GapCloserSpell const& Args) override
	{

	}
	void OnProcessSpell(CastedSpell const& Args) override
	{

	}
};
