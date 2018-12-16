/* 

******************************************************
					MIT License
			Copyright (c) 2018 CSID-DGU
******************************************************

Coded by : Jong Ha Sin
 Last Updated : 18-12-16

 [RanddomWalkMovementPathDB]
 - 랜덤 워크 계산 결과를 저장합니다.
 - 클라이언트가 get하는 data set

*/


#pragma once

#include "db_origin.hpp"

class RandomWalkMovementPathDB : public DataBase
{
private:
	std::vector<RWOutput> randomwWalkOutput;

public:
	void pushData(RWOutput randomWalk);
	RWOutput popData();

};