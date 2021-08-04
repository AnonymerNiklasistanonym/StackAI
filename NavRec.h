#pragma once
#include "Pos2D.h"
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "NavRecConnection.h"
struct NavRec {
	typedef std::shared_ptr<NavRec> nav_ptr;
	NavRec(Pos2D a, Pos2D b);
	Pos2D start;
	Pos2D size;
	sf::Color color;
	float current_heuristic = -1;
	bool IsValid() { return size.x > 0 && size.y > 0; }
	bool contains(Pos2D pos);
	void AddConnection(NavRecConnection& neighbor);
	void RemoveConnection(NavRecConnection& neighbor);
	void DepthSearchConnections(float connectioncost);
	std::vector<NavRecConnection> neighbors;
private:
};
