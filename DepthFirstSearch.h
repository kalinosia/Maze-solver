#pragma once

#include <vector>

static const int width = 40 * 2 + 1;
static const int height = 25 * 2 + 1;

class DepthFirstSearch
{
private:
	int x, y;
	int in; //{x,y=0}
	int out; //{x,y=height-1, so only one variable
	bool crossroads[4]; //for later of course most , bool because memory, size_t???[0,0,1,0]
	std::vector<std::pair<int, int>> crossroads_paths; //here we have path from cross roads
	//int last[2];//[y,x] //needed ?
	bool matrix[height][width];
	

public:
	DepthFirstSearch(const bool matrixcome[height][width]);
	~DepthFirstSearch() = default; //??
	std::vector<std::pair<int, int>> visited; //to draw where we been
	int pos(char a); 
	bool end();
	void step();
	
	
};

