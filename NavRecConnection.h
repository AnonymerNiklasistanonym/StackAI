#pragma once
#include "Pos2D.h"
#include <memory>
class NavRec;
typedef std::shared_ptr<NavRec> nav_ptr;


struct NavRecConnection {
	float distance=-1; //ALWAYS -1 UNTIL A VALID CONNECTION HAS BEEN FOUND
	nav_ptr from;
	nav_ptr to;
	NavRecConnection(nav_ptr a, nav_ptr b) : from(a), to(b) { checkNeighbor(); }

private:
	void checkNeighbor();
	//RETURNS THE DIRECTION OF A POTENTIAL OVERLAP FROM a POV
	//-1:NONE		0:TOP	1:RIGHT		2:BELOW		3:LEFT
	int OverLaps(const Pos2D& a_start, const Pos2D& a_size, const Pos2D& b_start, const Pos2D& b_size) const;
	bool IsOnLine(const Pos2D& point, const Pos2D& start, const Pos2D& end) const;
	bool InRange(float a, float b_min, float b_max) const;
	float GetEstimatedCost(const nav_ptr& a, const nav_ptr& b) const;
};
