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


[ FieldDataBase ]

<Explanation>

@ 좌표계 - 지도
: 충분히 넓은 지도 좌표계(실제 지형 정보를 담는다)
- 이차원의 지도이므로 이차원 배열로 이루어짐

- 각 좌표가 갖는 데이터
  1) 실제 위도+경도(+고도)
  2) 지형의 특성(육지/바다, 혹은 이동 가능/불가능 여부
	=> e.g. 해양 생물은 육지에서 이동 불가능
    -> 육지/바다 정도의 데이터만 기록하고  이동 가능/불가능 여부는 생물과 결합하여 판단)
  3) 기후
  4) 서식 생명체 배열

@ Timer - 시간 
 : 알고리즘에 활용될 지역 시간 연산을 저장 및 처리한다.


<To do>
void updateGlobalState(); // Update whole Local State
void updateLocalState(int x, int y); // Update each local state
랜덤워크와 딥러닝을 위해 지역 상태가 업데이트 되어야한다.

*/

#pragma once
#include "db_origin.hpp"
#include "db_timer.hpp"
#include "db_environment.hpp"
#include "db_organism.hpp"

#define MAX_FIELD_WIDTH_SIZE 1000
#define MAX_FIELD_HEIGHT_SIZE 1000


struct LocalInfo
{
	LOCALSTATE localState[3] = { NONE, NONE, NONE }; // AIR, SEA, GROUND
	Position pos;	// Real value of Position in earth
	Environment environment;	// Environment information for algorithm
	std::vector<Organism>* organisms; // Organism list for algorithm
};

class FieldDataBase : public DataBase
{
private:
	Environment* localEnvirnment;
	LocalInfo localInfo[MAX_FIELD_WIDTH_SIZE][MAX_FIELD_HEIGHT_SIZE]; // Map array 

public:
	FieldDataBase()
	{
		
	}

	~FieldDataBase()
	{

	}

	void updateGlobalState(); // Update whole Local State
	void updateLocalState(int x, int y); // Update each local state

	void updateOrganismList(int x, int y); // Update Organism list of location

	LOCALSTATE getLocalState(int x, int y);
	std::vector<Organism>* getOrganismList(int x, int y);
};



#pragma region LOCATION_UPDATE
void FieldDataBase::updateGlobalState()
{
	// TO Do
}

void FieldDataBase::updateLocalState(int x, int y)
{
	// TO DO 
}

void FieldDataBase::updateOrganismList(int x, int y)
{
	// to do
}

#pragma endregion


#pragma region LOAD_INFORMATION
LOCALSTATE FieldDataBase::getLocalState(int x, int y)
{
	// to do
}

std::vector<Organism>* FieldDataBase::getOrganismList(int x, int y)
{
	// to do
}
#pragma endregion
