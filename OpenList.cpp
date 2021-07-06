#pragma once
#include "OpenList.h"

void OpenList::addOrUpdate(AStarNode new_node)
{
	for (AStarNode& node : list) {
		if (node.tile.m_pos == new_node.tile.m_pos) {
			if (node.pathCost > new_node.pathCost) {
				node.pathCost = new_node.pathCost;
				return;
			}
			return;
		}
	}
	list.push_back(new_node);
}

AStarNode OpenList::popLowestCost()
{
	//print();
	auto low_point = std::max_element(list.begin(),list.end());
	AStarNode lowest = *low_point;
	//std::cout << "Lowest was: " << lowest.estCost << std::endl;
	list.erase(low_point);
	//print();
	return lowest;

	//auto  lowest = *low_point;
	//list.erase(list.begin() + low_point);
	//print();
	//return lowest;

	//std::sort(list.begin(), list.end(), std::greater<AStarNode>());
	//AStarNode lowest = list.at(0);
	//list.erase(list.begin());
	//return lowest;
}

void OpenList::print()
{
	std::cout << "==Open List==" << std::endl;
	for (AStarNode& node : list) {
		if (node.previous)
		std::cout << node.tile.m_pos.x << " / " << node.tile.m_pos.y << " (From: "
			<< node.previous->tile.m_pos.x << " / " << node.previous->tile.m_pos.y << ")" << std::endl
			<<"Tile: " << node.pathCost <<" Heuristic: "<< node.estCost- node.pathCost << " Total: " << node.estCost << std::endl;
		else {
			std::cout << node.tile.m_pos.x << " / " << node.tile.m_pos.y << " (START)" << std::endl
				<< "Tile: " << node.pathCost << " Heuristic: " << node.estCost - node.pathCost << " Total: " << node.estCost << std::endl;
		}
	}
	std::cout << "===============" << std::endl;
}
