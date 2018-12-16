/* 

******************************************************
					MIT License
			Copyright (c) 2018 CSID-DGU
******************************************************

Coded by : Jong Ha Sin
 Last Updated : 18-12-16

 [RanddomWalkMovementPathDB]
 - ���� ��ũ ��� ����� �����մϴ�.
 - Ŭ���̾�Ʈ�� get�ϴ� data set

*/


#pragma once

#include "al_randomwalk.hpp"

class RandomWalkMovementPathDB
{
private:
	std::vector<RWOutput> randomwWalkOutput;

public:
	void pushData(RWOutput randomWalk);
	RWOutput popData();

};