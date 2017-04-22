#pragma once
#include "PluginData.h"
#include "Vector3.h"

class FeatherManager
{
public:
	static int GetNetworkId();

	struct ProjectionInfo
	{
		ProjectionInfo() { }

		/// <summary>
		/// The is on segment
		/// </summary>
		bool IsOnSegment;

		/// <summary>
		/// The line point
		/// </summary>
		Vec2 LinePoint;

		/// <summary>
		/// The segment point
		/// </summary>
		Vec2 SegmentPoint;

		/// <summary>
		/// Initializes a new instance of the <see cref="ProjectionInfo"/> struct.
		/// </summary>
		/// <param name="isOnSegment">if set to <c>true</c> [is on segment].</param>
		/// <param name="segmentPoint">The segment point.</param>
		/// <param name="linePoint">The line point.</param>
		ProjectionInfo(bool isOnSegment, Vec2 segmentPoint, Vec2 linePoint)
		{
			IsOnSegment = isOnSegment;
			SegmentPoint = segmentPoint;
			LinePoint = linePoint;
		}
	};

	static void OnProcessSpellCast(CastedSpell const& args);
	static void OnPauseAnimation(IUnit* source);

	static IUnit* GetFeather(bool FeathersOnly);

	static std::vector<Vec3> GetFeathers(bool toGrab);
	static void ProjectOn(Vec2 const& Point, Vec2 const& SegmentStart, Vec2 const& SegmentEnd, ProjectionInfo& Out);
	static float GetDistance(Vec3 from, Vec3 to);
	static float GetDistanceV2(Vec2 from, Vec2 to);

	static Vec3 GetFeatherToGrab(int range);

	static float Distance(Vec2 point, Vec2 start, Vec2 End, bool onlyOnSegment);
};