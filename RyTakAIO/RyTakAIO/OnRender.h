#pragma once
#include "PluginSDK.h"
#include "BaseOptions.h"
#include "SpellLib.h"

class OnRenderClass
{
public:
	void Render()
	{
		if (DrawOff->Enabled()) return;

		if (DrawReady->Enabled())
		{
			if (DrawQ->Enabled() && Q->IsReady())
			{
				if (Q->Range() >= 0)
				{
					GRender->DrawCircle(GEntityList->Player()->GetPosition(), Q->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				}
			}
			if (DrawW->Enabled() && W->IsReady())
			{
				if (W->Range() >= 0)
				{
					GRender->DrawCircle(GEntityList->Player()->GetPosition(), W->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				}
			}
			if (DrawE->Enabled() && E->IsReady())
			{
				if (E->Range() >= 0)
				{
					GRender->DrawCircle(GEntityList->Player()->GetPosition(), E->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				}
			}
			if (DrawR->Enabled() && R->IsReady())
			{
				if (R->Range() >= 0)

				{
					GRender->DrawCircle(GEntityList->Player()->GetPosition(), R->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				}
			}
		}
		else
		{
			if (DrawQ->Enabled())
			{
				if (Q->Range() >= 0)
				{
					GRender->DrawCircle(GEntityList->Player()->GetPosition(), Q->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				}
			}
			if (DrawW->Enabled())
			{
				if (W->Range() >= 0)
				{
					GRender->DrawCircle(GEntityList->Player()->GetPosition(), W->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				}
			}
			if (DrawE->Enabled())
			{
				if (E->Range() >= 0)
				{
					GRender->DrawCircle(GEntityList->Player()->GetPosition(), E->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				}
			}
			if (DrawR->Enabled())
			{
				if (R->Range() >= 0)
				{
					GRender->DrawCircle(GEntityList->Player()->GetPosition(), R->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				}
			}
		}
	}
};