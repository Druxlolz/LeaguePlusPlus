#pragma once
#include "PluginSDK.h"
#include "BaseOptions.h"

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
				GRender->DrawCircle(GEntityList->Player()->GetPosition(), Q->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				{
					if (Q->Range() == FLT_MAX)
					{
						return;
					}
				}
			}
			if (DrawW->Enabled() && W->IsReady())
			{
				GRender->DrawCircle(GEntityList->Player()->GetPosition(), W->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				{
					if (W->Range() == FLT_MAX)
					{
						return;
					}
				}
			}
			if (DrawE->Enabled() && E->IsReady())
			{
				GRender->DrawCircle(GEntityList->Player()->GetPosition(), E->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				{
					if (E->Range() == FLT_MAX)
					{
						return;
					}
				}
			}
			if (DrawR->Enabled() && R->IsReady())
			{
				GRender->DrawCircle(GEntityList->Player()->GetPosition(), R->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				{
					if (R->Range() == FLT_MAX)
					{
						return;
					}
				}
			}
		}
		else
		{
			if (DrawQ->Enabled())
			{
				GRender->DrawCircle(GEntityList->Player()->GetPosition(), Q->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				{
					if (Q->Range() == FLT_MAX)
					{
						return;
					}
				}
			}
			if (DrawW->Enabled())
			{
				GRender->DrawCircle(GEntityList->Player()->GetPosition(), W->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				{
					if (W->Range() == FLT_MAX)
					{
						return;
					}
				}
			}
			if (DrawE->Enabled())
			{
				GRender->DrawCircle(GEntityList->Player()->GetPosition(), E->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				{
					if (E->Range() == FLT_MAX)
					{
						return;
					}
				}
			}
			if (DrawR->Enabled())
			{
				GRender->DrawCircle(GEntityList->Player()->GetPosition(), R->Range(), Vec4(255, 255, 0, 255), 5.0f, false, false);
				{
					if (R->Range() == FLT_MAX)
					{
						return;
					}
				}
			}
		}
	}
};