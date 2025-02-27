#include "ClosedList.h"

bool ClosedList::contains(AStarNode new_node)
{
	return set.find(new_node.GetCantor())!=set.end();
}

void ClosedList::add(AStarNode node)
{
	list.push_back(node);
	set.insert(node.GetCantor());
}

void ClosedList::DebugPrint()
{
	std::cout << "[[Closed List]]" << std::endl;
	for (AStarNode& node : list) {
		if(node.previous)
		std::cout << "Pos: " << node.tile.pos_.x << " / " << node.tile.pos_.y <<" (From: "
			<< node.previous->tile.pos_.x << " / " << node.previous->tile.pos_.y << ")" << " Cost: "<< node.pathcost << std::endl;
		else
			std::cout << "Pos: " << node.tile.pos_.x << " / " << node.tile.pos_.y << " (START)" << std::endl;
	}
	std::cout << "[[[[[[[ ]]]]]]]]" << std::endl;
}
