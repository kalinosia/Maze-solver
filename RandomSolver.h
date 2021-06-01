#pragma once

#include <vector>

static const int width = 40*2+1;
static const int height = 25 * 2 + 1;
//constexpr auto  height = 25*2+1;

class RandomSolver
{
	
private:

	int x, y;
	int in; //{x,y=0}
	int out; //{x,y=height-1, so only one variable
	int crossroads;

	bool matrix[height][width];

	std::vector<std::pair<int, int>> visited; //to draw where we been
	
public:
	RandomSolver(const bool matrixcome [height][width]);
	~RandomSolver()=default; //??

public:
	bool end();
	void step();
	int pos(char a);
};


