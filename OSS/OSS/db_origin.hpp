/* MIT License

Copyright (c) 2018 CSID-DGU

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */

/*
Coded by : Jong Ha Sin
Last Updated : 18-11-05


[ DataBase ]

<Explanation>

<To do>

*/

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>

#define RW_POSSIBILITY float*
#define DIRECTION_NUMBER 9

typedef std::string timer_string_t;

// Position data struct
typedef struct Position
{
	std::string longitude, latitude, altitude;
} Position;

// The states shows that organisms can move or not to the location
enum LOCALSTATE
{
	GROUND, SEA, AIR, NONE
};

/* 메모 : 해류의 이동 방향 설정 위해, db_origin으로 옮길 예정 */
   // 9방향 이동 경로 : 정지, 북, 북동, 동, ... 서, 북서
enum Direction
{
	STOP,
	NORTH, NORTH_EAST, EAST, SOUTH_EAST,
	SOUTH, SOUTH_WEST, WEST, NOTRH_WEST
};

class DataBase
{
protected:
	// File I/O stream
	std::ofstream ofs;
	std::ifstream ifs;

public:
	DataBase();
	virtual ~DataBase();
	
	// File I/O
	virtual void readDB(std::string& fileName) = 0; // Read DB file from stroage
	void readFileOpen(std::string& fileName);	// Read file open to input stream
	void readFileClose();						// Read file close from input stream
	void getDBLine(std::string& readData);		// Read a line from DB
};


#pragma region DataBase_CONSTURCTOR

DataBase::DataBase()
{

}

#pragma endregion 


#pragma region DataBase_DESTURCTOR

DataBase::~DataBase()
{

}

#pragma endregion 


#pragma region DataBase_FILE_I/O

void DataBase::readFileOpen(std::string& fileName)
{
	ifs.open(fileName);
}

void DataBase::readFileClose()
{
	ifs.close();
}

void DataBase::getDBLine(std::string& readData)
{
	getline(ifs, readData);
	assert(readData.empty() && "READ ERROR!!");
}

#pragma endregion