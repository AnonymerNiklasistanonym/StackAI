#pragma once
#include "Path.h"
#include <memory>
#include <queue>
#include <set>
#include "AStarNode.h"
#include "Pos2D.h"
#include "NavRec.h"
class World;
typedef std::shared_ptr<AStarNode> anode_ptr;
typedef std::shared_ptr<NavRec> nav_ptr;
class Pathfinder {
public:
	std::shared_ptr<Path> GetPath(World& world, Pos2D start, Pos2D target);
	std::vector<nav_ptr> navrecs;
	bool IsReachable(World& world, Pos2D start, Pos2D target);
	sf::RenderWindow* window_;
	Spritesheet* font_;
	void UpdateNavRec(World& world, Pos2D location);
	bool IsInNavRec(Pos2D location);
	nav_ptr FindNavRecFromPos(World& world, Pos2D location);
	static float SemiEuclidDistance(Pos2D& start, Pos2D& target);

private:
	nav_ptr GetNavRecAtPos(Pos2D target);
	void ClearNavRecHeuristic();
	float Heuristic(Pos2D start, Pos2D target);
	std::shared_ptr<Path> ReversePathFromTarget(AStarNode target);
	float ManhattanDistance(Pos2D& start, Pos2D& target);
	float DiagonalMod(Pos2D& a, Pos2D& b);
};
