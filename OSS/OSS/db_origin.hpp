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
#include <vector>
#include <algorithm>

#define RW_POSSIBILITY float*
#define DIRECTION_NUMBER 9


// Position data struct
typedef struct Position
{
	float fLatitude, fLongitude, fAltitude;
} Position;

// The states shows that organisms can move or not to the location
enum LOCALSTATE
{
	AIR_MOVABLE, SEA_MOVABLE, GROUND_MOVABLE, NONE
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
private:
	// File I/O stream
	std::ofstream *ofs;
	std::ifstream *ifs;

public:
	DataBase() {}
	virtual ~DataBase(){}
};