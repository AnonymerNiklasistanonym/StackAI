#include "NavRec.h"
#include <iostream>
#include "Randomizer.h"

NavRec::NavRec(Pos2D a, Pos2D b) : start(a), size(b), color(random_custom::getRandomColor()) {
	color.a = 150;
}

bool NavRec::contains(Pos2D pos)
{
	if (start.x <= pos.x && start.x + size.x > pos.x)
		if (start.y <= pos.y && start.y + size.y > pos.y)
			return true;
	return false;
}

void NavRec::AddConnection(NavRecConnection& neighbor)
{
	neighbors.push_back(neighbor);
}

void NavRec::RemoveConnection(NavRecConnection& neighbor)
{
	std::cout << "!!ERROR REMOVING CONNECTION NOT IMPLEMENTED YET!!" << neighbor.distance << std::endl;
}

void NavRec::DepthSearchConnections(float connectioncost)
{
	if (current_heuristic > connectioncost ||current_heuristic == -1) {
		current_heuristic = connectioncost;
		for (auto navrec : neighbors) {
			navrec.to->DepthSearchConnections(current_heuristic + navrec.distance);
		}
	}
}
