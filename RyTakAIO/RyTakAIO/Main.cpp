#include "PluginSDK.h"
#include "BaseOptions.h"
#include "OnRender.h"
#include "IChampion.h"
#include "SpellLib.h"
#include <sstream>

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

PLUGIN_EVENT(void) OnGameUpdate()
{
	pChampion->OnGameUpdate();
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

	if (szChampion == "Cho'Gath")
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

	if (szChampion == "Dr.Mundo")
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

	if (szChampion == "Kha'Zix")
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

	if (szChampion == "Kog'Maw")
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

	if (szChampion == "Rek'Sai")
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

	if (szChampion == "Vel'Koz")
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

	if (szChampion == "Wukong")
	{
		pChampion = new Wukong;
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
	pChampion->OnLoad();

	GEventManager->AddEventHandler(kEventOnRender, OnRender);
	GEventManager->AddEventHandler(kEventOnGameUpdate, OnGameUpdate);
	GEventManager->AddEventHandler(kEventOnGapCloser, OnGapCloser);
	GEventManager->AddEventHandler(kEventOnSpellCast, OnProcessSpell);
	GEventManager->AddEventHandler(kEventOrbwalkBeforeAttack, BeforeAttack);
	GEventManager->AddEventHandler(kEventOrbwalkAfterAttack, AfterAttack);
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
}