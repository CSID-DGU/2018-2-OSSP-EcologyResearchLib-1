/* 

*************************************************************
*															*		
*						MIT License							*	
*															*
*				Copyright (c) 2018 CSID-DGU					*				
*															*
*************************************************************

Coded by : Jong Ha Sin
Last Updated : 18-12-5


[ Preference ]

<Explanation>
- 생물의 경향성 정보를 저장하는 DB
- 각종 알고리즘에 사용된다.


<To do>

[랜덤 워커 알고리즘에 사용되는 이동 선호 요인]

1. 지형
 - 육지/바다, 이동 가능/불가능, 구체적 지형 특성에 따른 세부 확률 조정
 => 지역에 직접 구현, 랜덤워커가 확률 계산 시 해당 지역에서 읽어오기


2. 서식생물
 - 해당 지역에 서식하는 포식자에 따라 이동 확률 감소,
	먹이에 따라 이동 확률 증가

 => 마찬가지로 지역에 직접 구현,
	  지역에서는 계절에 따른 서식생물 분포를 분화할 필요가 있음


3. 시기
 - 계절(혹은 월별)에 따른 규모적 이동 경향성이 파악된다면
	해당 요인을 고려하여 확률 조정
 - 산란기 등 특정 시기에 따른 목표 지역으로의 이동 가능성 고려

 => 랜덤워커 확률 계산 시
	  1) 시기에 따른 이동 경향성 정보 읽어오기
		  (새로운 자료구조 생성 필요,
		   시기별 주요 이동 목표가 되는 지역 및 증가/감소 확률에 대한 데이터)
	  2) 현재 위치와 해당 지역으로의 방향을 계산
	  3) 해당 방향의 확률 증가


4. 시간
 - 낮/밤, 혹은 특정 시간에 따른 이동 경향성이 존재한다면
	해당 요인을 고려하여 확률 조정

=> 마찬가지로 시간에 따른 이동 경향성 데이터 생성 및 읽어오기


(5. 재해)
 - 화산, 태풍 등 자연재해로 인한 이동 경향성 고려
 - 인적 재해
 이는 정확한 예측이 어려우므로 추후에 고려


6. 목적지 (다수의 선호 요인에 포괄적으로 영향)
 - 주요 서식지로의 이동, 대규모 이주 등
	 분명한 목적성을 갖고 이동하는 경향성이 발견될 경우
	 현재 위치로부터 해당 지역으로 향하는 방향에 대해 확률 추가 부여


* 시기, 시간, 목적지 등 패턴화 가능한 정보가 존재할 경우
 - 해당 정보를 데이터베이스에 저장
 - 랜덤워커가 확률계산할 때 데이터베이스에서 불러오기
 - 시간 데이터(시간 및 계절을 구간별로 조건식 이용)
 - 지역 데이터(목적지에 대한 좌표)
 - 확률 증감(랜덤워커에 곧바로 계산해주기 위함)

*/

#pragma once
#include "db_origin.hpp"
#include "db_organism.hpp"
#include "db_environment.hpp"

class Preference
{
private:
	LOCALSTATE movable[3] = {NONE, NONE, NONE}; // prefetr to go somewhere
	std::vector<std::string> preyList;			
										// Prey List which organism can eat and like to eat. 
	
	/*
		알고리즘 내부에서 각 지역 데이터 <=> Organism 내부의 Preference 비교. 
	*/

public:
	// Constructor
	Preference();

	// Destructor
	~Preference();

	// Setter
	void setLocalState(const LOCALSTATE* localState);
	void setPreyList(std::string prey);

	// Getter
	bool checkLocalState(LOCALSTATE localstate);
	bool checkPreyList(const std::string prey);

};

#pragma region Preference_Constructor
Preference::Preference()
{

}

#pragma endregion

#pragma region Preference_Destructor
Preference::~Preference()
{

}

#pragma endregion

#pragma region Preference_Setter
void Preference::setLocalState(const LOCALSTATE* localState)
{
	int ix = 0;
	for (auto& ls : movable)
		ls = localState[ix++];
}

void Preference::setPreyList(std::string prey)
{
	preyList.push_back(prey);
}

#pragma endregion

#pragma region Preference_Getter
bool Preference::checkLocalState(LOCALSTATE localstate)
{
	if (localstate == GROUND && (movable[0] == GROUND)) return true;
	else if (localstate == SEA && (movable[1] == SEA)) return true;
	else if (localstate == AIR && (movable[2] == AIR)) return true;
	else return false;
}

bool Preference::checkPreyList(const std::string prey)
{
	for (auto& item : preyList)
	{
		if (item == prey)
			return true;
	}
	return false;
}

#pragma endregion

