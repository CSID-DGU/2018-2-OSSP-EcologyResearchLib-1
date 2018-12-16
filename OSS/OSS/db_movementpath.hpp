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

#include "db_origin.hpp"

class RandomWalkMovementPathDB : public DataBase
{
private:
	std::vector<RWOutput> randomwWalkOutput;

public:
	void pushData(RWOutput randomWalk);
	RWOutput popData();

};