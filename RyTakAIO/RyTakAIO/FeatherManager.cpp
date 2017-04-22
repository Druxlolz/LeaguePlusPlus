#include "FeatherManager.h"
#include "PluginSDK.h"
#include "Vector3.h"

//CREDITS TO : IJAVA C:

static int NetworkId = -1;
static int tempFeatherTime;
static Vec3 tempFeatherPosition;

int FeatherManager::GetNetworkId()
{
	if (GEntityList->Player()->GetSpellBook()->GetSpellState(kSlotE) == 1)
		return -1;

	return NetworkId;
}

void FeatherManager::OnPauseAnimation(IUnit* source)
{
	for (auto unit : GEntityList->GetAllUnits())
	{
		if (unit != nullptr && source == unit && !source->IsHero())
		{
			NetworkId = unit->GetNetworkId();
		}
	}
}

void FeatherManager::OnProcessSpellCast(CastedSpell const& args)
{
	if (args.Caster_ == GEntityList->Player())
	{
		if (GEntityList->Player() && (std::string(args.Name_) == "XayahQ" || std::string(args.Name_) == "XayahW" || std::string(args.Name_) == "XayahR"))
		{
			tempFeatherTime = GGame->TickCount();
			tempFeatherPosition = args.EndPosition_;
		}

		if (GEntityList->Player() && GetFeather(true) != nullptr && std::string(args.Name_) == "XayahE")
		{
			tempFeatherTime = GGame->TickCount() + 6000;
			tempFeatherPosition = args.EndPosition_;
		}
	}
}

IUnit* FeatherManager::GetFeather(bool FeathersOnly)
{
	if (GetNetworkId() == -1)
		return nullptr;

	auto unit = GEntityList->GetEntityByNetworkId(GetNetworkId());

	if (unit == nullptr)
		return nullptr;

	if (FeathersOnly && std::string(unit->GetObjectName()) == "Feather" || !FeathersOnly && unit->IsValidObject())
	{
		return unit;
	}

	return nullptr;
}

std::vector<Vec3> FeatherManager::GetFeathers(bool toGrab)
{
	std::vector<Vec3> result;

	for (auto Feather : GEntityList->GetAllUnits())
	{
		if (Feather != nullptr && Feather->GetTeam() == GEntityList->Player()->GetTeam() && !Feather->IsDead() && std::string(Feather->GetObjectName()) == "Feather")
		{
			auto valid = false;
			if (Feather->GetNetworkId() != GetNetworkId())
			{
				for (auto b : GEntityList->GetAllUnits())
					if (b->IsValidObject() && (Feather->GetPosition() - b->GetPosition()).Length() < 50
						&& std::string(b->GetObjectName()).find("Feather"))
						valid = true;
			}
			if (valid && (!toGrab || !Feather->IsMoving()))
			{
				result.push_back(Feather->ServerPosition());
			}
		}
	}

	if ((GGame->TickCount() - tempFeatherTime < 400 && GGame->TickCount() - tempFeatherTime > 0) || (GGame->TickCount() - tempFeatherTime < 400))
	{
		result.push_back(tempFeatherPosition);
	}
	return result;
}

void FeatherManager::ProjectOn(Vec2 const& Point, Vec2 const& SegmentStart, Vec2 const& SegmentEnd, ProjectionInfo& Out)
{
	auto cx = Point.x;
	auto cy = Point.y;
	auto ax = SegmentStart.x;
	auto ay = SegmentStart.y;
	auto bx = SegmentEnd.x;
	auto by = SegmentEnd.y;
	auto rL = ((cx - ax) * (bx - ax) + (cy - ay) * (by - ay)) /
		(powf(bx - ax, 2) + powf(by - ay, 2));
	auto pointLine = Vec2(ax + rL * (bx - ax), ay + rL * (by - ay));
	float rS;
	if (rL < 0)
	{
		rS = 0;
	}
	else if (rL > 1)
	{
		rS = 1;
	}
	else
	{
		rS = rL;
	}

	auto isOnSegment = (rS == rL);
	auto pointSegment = isOnSegment ? pointLine : Vec2(ax + rS * (bx - ax), ay + rS * (by - ay));

	Out = ProjectionInfo(isOnSegment, pointSegment, pointLine);
}

float FeatherManager::GetDistance(Vec3 from, Vec3 to)
{
	auto x1 = from.x;
	auto x2 = to.x;
	auto y1 = from.y;
	auto y2 = to.y;
	auto z1 = from.z;
	auto z2 = to.z;
	return static_cast<float>(sqrt(pow((x2 - x1), 2.0) + pow((y2 - y1), 2.0) + pow((z2 - z1), 2.0)));
}

float FeatherManager::GetDistanceV2(Vec2 from, Vec2 to)
{
	auto x1 = from.x;
	auto x2 = to.x;
	auto y1 = from.y;
	auto y2 = to.y;
	return static_cast<float>(sqrt(pow((x2 - x1), 2.0) + pow((y2 - y1), 2.0) + pow(GNavMesh->GetHeightForPoint(to) - GNavMesh->GetHeightForPoint(from), 2.0)));
}

Vec3 FeatherManager::GetFeatherToGrab(int range)
{
	auto FeatherList = GetFeathers(true);
	std::vector<Vec3> result;

	if (FeatherList.size() > 0)
	{
		for (auto Feather : FeatherList)
		{
			if (GetDistance(GEntityList->Player()->ServerPosition(), Feather) <= range)
				result.push_back(Feather);
		}
	}
	return result.size() > 0 ? result[0] : Vec3(0, 0, 0);
}

float FeatherManager::Distance(Vec2 point, Vec2 start, Vec2 End, bool onlyOnSegment)
{
	ProjectionInfo projection_info;
	ProjectOn(point, start, End, projection_info);

	if (projection_info.IsOnSegment || onlyOnSegment == false)
	{
		return projection_info.SegmentPoint.DistanceTo(point);
	}

	return FLT_MAX;
}