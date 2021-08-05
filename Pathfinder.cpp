#include "Pos2D.h"
#include <memory>
#include "World.h"
#include "Path.h"
#include "Pathfinder.h"
#include <queue>
#include "AStarNode.h"
#include <cmath>
#include "OpenList.h"
#include "ASCII.h"
#include "ClosedList.h"
#include <SFML/Graphics.hpp>
#include "NavRecConnection.h"
#include "NavRec.h"

typedef std::shared_ptr<NavRec> nav_ptr;
float sqr2 = 1.41421356237f;
std::shared_ptr<Path> Pathfinder::GetPath(World& world, Pos2D start, Pos2D target)
{
	ClearNavRecHeuristic();
	nav_ptr target_nav_rec = GetNavRecAtPos(target);
	if (!target_nav_rec)
		return nullptr;
	target_nav_rec->DepthSearchConnections(0);
	if (!IsReachable(world, start, target)) {
		return nullptr;
	}
	OpenList openlist;
	ClosedList closedlist;
	anode_ptr start_node(new AStarNode(world.GetTile(start)));
	openlist.AddOrUpdate(*start_node);
	while (!openlist.empty()) {
		AStarNode current_node = openlist.PopLowestCost();
		if (current_node.tile.pos_ == target) {
			return ReversePathFromTarget(current_node);
		}
		auto adjacents = world.GetAdjacents(current_node.tile.pos_);
		anode_ptr cur(new AStarNode(current_node));
		for (Tile& t : adjacents) {
			float pathcost = current_node.pathcost + t.GetTileCost() * DiagonalMod(current_node.tile.pos_, t.pos_);
			AStarNode next = AStarNode(pathcost + Heuristic(t.pos_, target), pathcost, cur, t);
			if(!closedlist.contains(next))
				openlist.AddOrUpdate(next);
		}
		closedlist.add(current_node);
	}
	return nullptr;
}

bool Pathfinder::IsReachable(World& world, Pos2D start, Pos2D target) {
	if (GetNavRecAtPos(start)->current_heuristic == -1)
		return false;
	return world.GetTile(target).walkable_;
}

nav_ptr Pathfinder::GetNavRecAtPos(Pos2D position)
{
	for (auto navrec : navrecs) {
		if (navrec->contains(position)) {
			return navrec;
		}
	}
	return nullptr;
}

void Pathfinder::ClearNavRecHeuristic()
{
	for (auto navrec : navrecs) {
		navrec->current_heuristic = -1;
	}
}

float Pathfinder::Heuristic(Pos2D start, Pos2D target) {
	float euclid_heu = SemiEuclidDistance(start,target);
	float nav_heu = GetNavRecAtPos(start)->current_heuristic;
	return (euclid_heu + nav_heu) * 0.5f;
}

std::shared_ptr<Path> Pathfinder::ReversePathFromTarget(AStarNode target)
{
	std::shared_ptr<Path> path(new Path(target.tile.pos_));
	while (target.previous) {
		Pos2D pos = target.previous->tile.pos_;
		path->AddNode(pos);
		target = *target.previous;
	}
	path->ReversePath();
	return path;
}

float Pathfinder::ManhattanDistance(Pos2D& start, Pos2D& target)
{
	float cost = (float)std::abs(start.x - target.x) + (float)std::abs(start.y - target.y);
	return cost;
}

float Pathfinder::SemiEuclidDistance(Pos2D& start, Pos2D& target)
{
	float cost = 0;
	int dif_x = std::abs(start.x - target.x);
	int dif_y = std::abs(start.y - target.y);
	int dif_d = std::abs(dif_x - dif_y);
	cost += dif_d;
	cost += std::min(dif_x, dif_y) * sqr2;
	return cost;
}

float Pathfinder::DiagonalMod(Pos2D& a, Pos2D& b)
{
	if (ManhattanDistance(a, b) == 1)
		return 1;
	else
		return sqr2;
}

void Pathfinder::UpdateNavRec(World& world, Pos2D location) {
	navrecs.clear();
	int width = world.kTilesWidth - location.x;
	int height = world.kTilesHeight - location.y;
		for (int y = location.y; y < height; y++) {
			for (int x = location.x; x < width; x++) {
				if (world.GetTile(x, y).walkable_) {
					if (!IsInNavRec(Pos2D(x, y))) {
						auto navrec = FindNavRecFromPos(world, Pos2D(x,y));
						if (navrec->IsValid()) {
							navrecs.push_back(navrec);
						}
						else
							std::cout << "Invalid";
					}
				}
			}
		}
	for (auto& navrec : navrecs) {
		for (auto& navrec_comp : navrecs) {
			if (navrec != navrec_comp) {
				NavRecConnection connect = NavRecConnection(navrec, navrec_comp);
				if (connect.distance > 0) {
					navrec->AddConnection(connect);
				}
			}
		}
	}
}



bool Pathfinder::IsInNavRec(Pos2D location) {
	for (auto navrec : navrecs) {
		if (navrec->contains(location)) {
			return true;
		}
	}
	return false;
}

nav_ptr Pathfinder::FindNavRecFromPos(World& world, Pos2D location) {
	int width = world.kTilesWidth;
	int height = world.kTilesHeight;
	for (int x = location.x; x < width; x++) {
		if (!world.GetTile(x, location.y).walkable_ || IsInNavRec(Pos2D(x,location.y))) {
			width = x;
			break;
		}
	}
	for (int y = location.y; y < height; y++) {
		for (int x = location.x; x < width; x++) {
			if (!world.GetTile(x, y).walkable_ || IsInNavRec(Pos2D(x, y))) {
				height = y;
				break;
			}
		}
	}
	height -= location.y;
	width -= location.x;
	Pos2D size(width, height);
	nav_ptr nav(new NavRec(location, size));
	return nav;
}
