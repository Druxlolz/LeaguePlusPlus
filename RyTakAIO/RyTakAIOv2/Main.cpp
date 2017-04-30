#pragma once
#include "PluginSDK.h"
#include "BaseOptions.h"
#include "SpellLib.h"
#include <sstream>

#pragma region Champions
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
#pragma endregion Champions


PluginSetup("RyTak-AIO");

#pragma region Events
PLUGIN_EVENT(void) OnOrbwalkBeforeAttack(IUnit* Target)
{

}

PLUGIN_EVENT(void) OnOrbwalkAttack(IUnit* Source, IUnit* Target)
{

}
#pragma endregion

IChampion* pChampion = nullptr;

#pragma region ChampEvents
PLUGIN_EVENT(void) OnLoad()
{
	pChampion->Menu();
	pChampion->Spells();
}

PLUGIN_EVENT(void) OnGameUpdate()
{	
	pChampion->Combo();
	pChampion->Harass();
	pChampion->LaneClear();
	pChampion->KS();
}

PLUGIN_EVENT(void) Menu()
{
	pChampion->Menu();
}

PLUGIN_EVENT(void) Spells()
{
	pChampion->Spells();
}

PLUGIN_EVENT(void) Combo()
{
	pChampion->Combo();
}

PLUGIN_EVENT(void) Harass()
{
	pChampion->Harass();
}

PLUGIN_EVENT(void) LaneClear()
{
	pChampion->LaneClear();
}

PLUGIN_EVENT(void) KS()
{
	pChampion->KS();
}

PLUGIN_EVENT(void) OnRender()
{
	pChampion->OnRender();
}

PLUGIN_EVENT(void) BeforeAttack(IUnit* Source, IUnit* Target)
{
	pChampion->BeforeAttack(Source, Target);
}

PLUGIN_EVENT(void) AfterAttack(IUnit* Source, IUnit* Target)
{
	pChampion->AfterAttack(Source, Target);
}

PLUGIN_EVENT(void) OnGapCloser(GapCloserSpell const& Args)
{
	pChampion->OnGapCloser(Args);
}

PLUGIN_EVENT(void) OnProcessSpell(CastedSpell const& Args)
{
	pChampion->OnProcessSpell(Args);
}
#pragma endregion ChampEvents


void LoadChampion()
{
	std::string szChampion = GEntityList->Player()->ChampionName();

	if (szChampion == "Aatrox")
	{
		pChampion = new Aatrox;
		return;
	}

	if (szChampion == "Ahri")
	{
		pChampion = new Ahri;
		return;
	}

	if (szChampion == "Akali")
	{
		pChampion = new Akali;
		return;
	}

	if (szChampion == "Alistar")
	{
		pChampion = new Alistar;
		return;
	}

	if (szChampion == "Amumu")
	{
		pChampion = new Amumu;
		return;
	}

	if (szChampion == "Anivia")
	{
		pChampion = new Anivia;
		return;
	}

	if (szChampion == "Annie")
	{
		pChampion = new Annie;
		return;
	}

	if (szChampion == "Ashe")
	{
		pChampion = new Ashe;
		return;
	}

	if (szChampion == "AurelionSol")
	{
		pChampion = new AurelionSol;
		return;
	}

	if (szChampion == "Azir")
	{
		pChampion = new Azir;
		return;
	}

	if (szChampion == "Bard")
	{
		pChampion = new Bard;
		return;
	}

	if (szChampion == "Blitzcrank")
	{
		pChampion = new Blitzcrank;
		return;
	}

	if (szChampion == "Brand")
	{
		pChampion = new Brand;
		return;
	}

	if (szChampion == "Braum")
	{
		pChampion = new Braum;
		return;
	}

	if (szChampion == "Caitlyn")
	{
		pChampion = new Caitlyn;
		return;
	}

	if (szChampion == "Camille")
	{
		pChampion = new Camille;
		return;
	}

	if (szChampion == "Cassiopeia")
	{
		pChampion = new Cassiopeia;
		return;
	}

	if (szChampion == "ChoGath")
	{
		pChampion = new ChoGath;
		return;
	}

	if (szChampion == "Corki")
	{
		pChampion = new Corki;
		return;
	}

	if (szChampion == "Darius")
	{
		pChampion = new Darius;
		return;
	}

	if (szChampion == "Diana")
	{
		pChampion = new Diana;
		return;
	}

	if (szChampion == "DrMundo")
	{
		pChampion = new DrMundo;
		return;
	}

	if (szChampion == "Draven")
	{
		pChampion = new Draven;
		return;
	}

	if (szChampion == "Ekko")
	{
		pChampion = new Ekko;
		return;
	}

	if (szChampion == "Elise")
	{
		pChampion = new Elise;
		return;
	}

	if (szChampion == "Evelynn")
	{
		pChampion = new Evelynn;
		return;
	}

	if (szChampion == "Ezreal")
	{
		pChampion = new Ezreal;
		return;
	}

	if (szChampion == "Fiddlesticks")
	{
		pChampion = new Fiddlesticks;
		return;
	}

	if (szChampion == "Fiora")
	{
		pChampion = new Fiora;
		return;
	}

	if (szChampion == "Fizz")
	{
		pChampion = new Fizz;
		return;
	}

	if (szChampion == "Galio")
	{
		pChampion = new Galio;
		return;
	}

	if (szChampion == "Gangplank")
	{
		pChampion = new Gangplank;
		return;
	}

	if (szChampion == "Garen")
	{
		pChampion = new Garen;
		return;
	}

	if (szChampion == "Gnar")
	{
		pChampion = new Gnar;
		return;
	}

	if (szChampion == "Gragas")
	{
		pChampion = new Gragas;
		return;
	}

	if (szChampion == "Graves")
	{
		pChampion = new Graves;
		return;
	}

	if (szChampion == "Hecarim")
	{
		pChampion = new Hecarim;
		return;
	}

	if (szChampion == "Heimerdinger")
	{
		pChampion = new Heimerdinger;
		return;
	}

	if (szChampion == "Illaoi")
	{
		pChampion = new Illaoi;
		return;
	}

	if (szChampion == "Irelia")
	{
		pChampion = new Irelia;
		return;
	}

	if (szChampion == "Ivern")
	{
		pChampion = new Ivern;
		return;
	}

	if (szChampion == "Janna")
	{
		pChampion = new Janna;
		return;
	}

	if (szChampion == "JarvanIV")
	{
		pChampion = new JarvanIV;
		return;
	}

	if (szChampion == "Jax")
	{
		pChampion = new Jax;
		return;
	}

	if (szChampion == "Jayce")
	{
		pChampion = new Jayce;
		return;
	}

	if (szChampion == "Jhin")
	{
		pChampion = new Jhin;
		return;
	}

	if (szChampion == "Jinx")
	{
		pChampion = new Jinx;
		return;
	}

	if (szChampion == "Kalista")
	{
		pChampion = new Kalista;
		return;
	}

	if (szChampion == "Karma")
	{
		pChampion = new Karma;
		return;
	}

	if (szChampion == "Karthus")
	{
		pChampion = new Karthus;
		return;
	}

	if (szChampion == "Kassadin")
	{
		pChampion = new Kassadin;
		return;
	}

	if (szChampion == "Katarina")
	{
		pChampion = new Katarina;
		return;
	}

	if (szChampion == "Kayle")
	{
		pChampion = new Kayle;
		return;
	}

	if (szChampion == "Kennen")
	{
		pChampion = new Kennen;
		return;
	}

	if (szChampion == "KhaZix")
	{
		pChampion = new KhaZix;
		return;
	}

	if (szChampion == "Kindred")
	{
		pChampion = new Kindred;
		return;
	}

	if (szChampion == "Kled")
	{
		pChampion = new Kled;
		return;
	}

	if (szChampion == "KogMaw")
	{
		pChampion = new KogMaw;
		return;
	}

	if (szChampion == "LeBlanc")
	{
		pChampion = new LeBlanc;
		return;
	}

	if (szChampion == "LeeSin")
	{
		pChampion = new LeeSin;
		return;
	}

	if (szChampion == "Leona")
	{
		pChampion = new Leona;
		return;
	}

	if (szChampion == "Lissandra")
	{
		pChampion = new Lissandra;
		return;
	}

	if (szChampion == "Lucian")
	{
		pChampion = new Lucian;
		return;
	}

	if (szChampion == "Lulu")
	{
		pChampion = new Lulu;
		return;
	}

	if (szChampion == "Lux")
	{
		pChampion = new Lux;
		return;
	}

	if (szChampion == "Malphite")
	{
		pChampion = new Malphite;
		return;
	}

	if (szChampion == "Malzahar")
	{
		pChampion = new Malzahar;
		return;
	}

	if (szChampion == "Maokai")
	{
		pChampion = new Maokai;
		return;
	}

	if (szChampion == "MasterYi")
	{
		pChampion = new MasterYi;
		return;
	}

	if (szChampion == "MissFortune")
	{
		pChampion = new MissFortune;
		return;
	}

	if (szChampion == "Mordekaiser")
	{
		pChampion = new Mordekaiser;
		return;
	}

	if (szChampion == "Morgana")
	{
		pChampion = new Morgana;
		return;
	}

	if (szChampion == "Nami")
	{
		pChampion = new Nami;
		return;
	}

	if (szChampion == "Nasus")
	{
		pChampion = new Nasus;
		return;
	}

	if (szChampion == "Nautilus")
	{
		pChampion = new Nautilus;
		return;
	}

	if (szChampion == "Nidalee")
	{
		pChampion = new Nidalee;
		return;
	}

	if (szChampion == "Nocturne")
	{
		pChampion = new Nocturne;
		return;
	}

	if (szChampion == "Nunu")
	{
		pChampion = new Nunu;
		return;
	}

	if (szChampion == "Olaf")
	{
		pChampion = new Olaf;
		return;
	}

	if (szChampion == "Orianna")
	{
		pChampion = new Orianna;
		return;
	}

	if (szChampion == "Pantheon")
	{
		pChampion = new Pantheon;
		return;
	}

	if (szChampion == "Poppy")
	{
		pChampion = new Poppy;
		return;
	}

	if (szChampion == "Quinn")
	{
		pChampion = new Quinn;
		return;
	}

	if (szChampion == "Rammus")
	{
		pChampion = new Rammus;
		return;
	}

	if (szChampion == "RekSai")
	{
		pChampion = new RekSai;
		return;
	}

	if (szChampion == "Renekton")
	{
		pChampion = new Renekton;
		return;
	}

	if (szChampion == "Rengar")
	{
		pChampion = new Rengar;
		return;
	}

	if (szChampion == "Riven")
	{
		pChampion = new Riven;
		return;
	}

	if (szChampion == "Rumble")
	{
		pChampion = new Rumble;
		return;
	}

	if (szChampion == "Ryze")
	{
		pChampion = new Ryze;
		return;
	}

	if (szChampion == "Sejuani")
	{
		pChampion = new Sejuani;
		return;
	}

	if (szChampion == "Shaco")
	{
		pChampion = new Shaco;
		return;
	}

	if (szChampion == "Shen")
	{
		pChampion = new Shen;
		return;
	}

	if (szChampion == "Shyvana")
	{
		pChampion = new Shyvana;
		return;
	}

	if (szChampion == "Singed")
	{
		pChampion = new Singed;
		return;
	}

	if (szChampion == "Sion")
	{
		pChampion = new Sion;
		return;
	}

	if (szChampion == "Sivir")
	{
		pChampion = new Sivir;
		return;
	}

	if (szChampion == "Skarner")
	{
		pChampion = new Skarner;
		return;
	}

	if (szChampion == "Sona")
	{
		pChampion = new Sona;
		return;
	}

	if (szChampion == "Soraka")
	{
		pChampion = new Soraka;
		return;
	}

	if (szChampion == "Swain")
	{
		pChampion = new Swain;
		return;
	}

	if (szChampion == "Syndra")
	{
		pChampion = new Syndra;
		return;
	}

	if (szChampion == "TahmKench")
	{
		pChampion = new TahmKench;
		return;
	}

	if (szChampion == "Taliyah")
	{
		pChampion = new Taliyah;
		return;
	}

	if (szChampion == "Talon")
	{
		pChampion = new Talon;
		return;
	}

	if (szChampion == "Taric")
	{
		pChampion = new Taric;
		return;
	}

	if (szChampion == "Teemo")
	{
		pChampion = new Teemo;
		return;
	}

	if (szChampion == "Thresh")
	{
		pChampion = new Thresh;
		return;
	}

	if (szChampion == "Tristana")
	{
		pChampion = new Tristana;
		return;
	}

	if (szChampion == "Trundle")
	{
		pChampion = new Trundle;
		return;
	}

	if (szChampion == "Tryndamere")
	{
		pChampion = new Tryndamere;
		return;
	}

	if (szChampion == "TwistedFate")
	{
		pChampion = new TwistedFate;
		
	}

	if (szChampion == "Twitch")
	{
		pChampion = new Twitch;
		return;
	}

	if (szChampion == "Udyr")
	{
		pChampion = new Udyr;
		return;
	}

	if (szChampion == "Urgot")
	{
		pChampion = new Urgot;
		return;
	}

	if (szChampion == "Varus")
	{
		pChampion = new Varus;
		return;
	}

	if (szChampion == "Vayne")
	{
		pChampion = new Vayne;
		return;
	}

	if (szChampion == "Veigar")
	{
		pChampion = new Veigar;
		return;
	}

	if (szChampion == "Velkoz")
	{
		pChampion = new VelKoz;
		return;
	}

	if (szChampion == "Vi")
	{
		pChampion = new Vi;
		return;
	}

	if (szChampion == "Viktor")
	{
		pChampion = new Viktor;
		return;
	}

	if (szChampion == "Vladimir")
	{
		pChampion = new Vladimir;
		return;
	}

	if (szChampion == "Volibear")
	{
		pChampion = new Volibear;
		return;
	}

	if (szChampion == "Warwick")
	{
		pChampion = new Warwick;
		return;
	}

	if (szChampion == "MonkeyKing")
	{
		pChampion = new Wukong;
		return;
	}
	
	if (szChampion == "Xayah")
	{
		pChampion = new Xayah;
		return;
	}
	
	if (szChampion == "Xerath")
	{
		pChampion = new Xerath;
		return;
	}

	if (szChampion == "XinZhao")
	{
		pChampion = new XinZhao;
		return;
	}

	if (szChampion == "Yasuo")
	{
		pChampion = new Yasuo;
		return;
	}

	if (szChampion == "Yorick")
	{
		pChampion = new Yorick;
		return;
	}

	if (szChampion == "Zac")
	{
		pChampion = new Zac;
		return;
	}

	if (szChampion == "Zed")
	{
		pChampion = new Zed;
		return;
	}

	if (szChampion == "Ziggs")
	{
		pChampion = new Ziggs;
		return;
	}

	if (szChampion == "Zilean")
	{
		pChampion = new Zilean;
		return;
	}

	if (szChampion == "Zyra")
	{
		pChampion = new Zyra;
		
	}
}

PLUGIN_API void OnLoad(IPluginSDK* PluginSDK)
{
	PluginSDKSetup(PluginSDK);
	LoadChampion();
	pChampion->Menu();
	pChampion->Spells();

	GEventManager->AddEventHandler(kEventOnRender, OnRender);
	GEventManager->AddEventHandler(kEventOnGameUpdate, OnGameUpdate);
	GEventManager->AddEventHandler(kEventOnGapCloser, OnGapCloser);
	GEventManager->AddEventHandler(kEventOnSpellCast, OnProcessSpell);
	GEventManager->AddEventHandler(kEventOrbwalkBeforeAttack, BeforeAttack);
	GEventManager->AddEventHandler(kEventOrbwalkAfterAttack, AfterAttack);
	GEventManager->AddEventHandler(kEventCombo, Combo);
	GEventManager->AddEventHandler(kEventHarass, Harass);
	GEventManager->AddEventHandler(kEventLaneClear, LaneClear);
	GEventManager->AddEventHandler(kEventKS, KS);
}

PLUGIN_API void OnUnload()
{
	MainMenu->Remove();

	GEventManager->RemoveEventHandler(kEventOnRender, OnRender);
	GEventManager->RemoveEventHandler(kEventOnGameUpdate, OnGameUpdate);
	GEventManager->RemoveEventHandler(kEventOnGapCloser, OnGapCloser);
	GEventManager->RemoveEventHandler(kEventOnSpellCast, OnProcessSpell);
	GEventManager->RemoveEventHandler(kEventOrbwalkBeforeAttack, BeforeAttack);
	GEventManager->RemoveEventHandler(kEventOrbwalkAfterAttack, AfterAttack);
	GEventManager->RemoveEventHandler(kEventCombo, Combo);
	GEventManager->RemoveEventHandler(kEventHarass, Harass);
	GEventManager->RemoveEventHandler(kEventLaneClear, LaneClear);
	GEventManager->RemoveEventHandler(kEventKS, KS);
}