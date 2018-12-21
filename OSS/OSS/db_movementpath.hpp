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
	// setter
	void pushData(RWOutput randomWalk);
	
	// getter
	std::vector<RWOutput>* getRWVecPointer();

	// DB I/O
	virtual void writeDB() override;	// Write data to output stream
};


#pragma region RandomWalkMovementPathDB_setter
void RandomWalkMovementPathDB::pushData(RWOutput randomWalk)
{
	randomwWalkOutput.push_back(randomWalk);
}
#pragma endregion

#pragma region RandomWalkMovementPathDB_getter

std::vector<RWOutput>* RandomWalkMovementPathDB::getRWVecPointer()
{
	return &randomwWalkOutput;
}
#pragma endregion

#pragma region RandomWalkMovementPathDB_DB
void RandomWalkMovementPathDB::writeDB()
{
	for (auto& data : randomwWalkOutput)
	{
		ofs << data.point.xpos << " " << data.point.ypos << " " << data.time << std::endl;
	}
}
#pragma endregion