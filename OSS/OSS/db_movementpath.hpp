/* 

******************************************************
					MIT License
			Copyright (c) 2018 CSID-DGU
******************************************************

*/


#pragma once

#include "al_randomwalk.hpp"

class RandomWalkMovementPathDB
{
	/*struct PATH
	{
		time_t time;
		Position position;
	};*/


private:
	//std::vector<PATH> randomWalkLog;

public:
	void pushData(RandomWalk randomWalk);
	RandomWalk popData();

};