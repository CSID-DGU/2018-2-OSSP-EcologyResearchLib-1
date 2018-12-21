/* 

******************************************************
					MIT License
			Copyright (c) 2018 CSID-DGU
******************************************************

Coded by : Sa Min Hong
Last Updated : 18-12-20	


[ RandomWalk ]

<Explanation>
- 생물 데이터를 기반으로 생성된 랜덤 워커

- 랜덤 워커가 갖는 데이터
  1) 생물 정보(organism 객체)
  2) 현재 상태(허기, 짝짓기, 잠, 등등 => 생물 정보로부터 받아오거나, 생물 정보에 통합)
  3) 현재 날짜+시간
  4) 현재 좌표(위도+경도)
  5) 9방향 각각의 이동 확률(기본 값 : 각각 0%)

=> 시간과 좌표 데이터가 서로 맞물려 이동 경로 데이터를 표현



[랜덤 워커 - 이동 선호 요인]

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




<To do>

[프로그램 진행]

1. 좌표 맵을 생성
2. 맵에서 각각의 좌표 데이터들을 초기화

3. 랜덤 워커 객체를 갖는 벡터를 생성 (std::vector<RandomWalk> randomWalker;)
4. 랜덤 워커 벡터의 초기 객체 생성 (첫 번째 객체 : randomWalker[0])
5. 좌표 맵을 이용해, 랜덤 워커 첫 번째 객체의 좌표 데이터 초기화 (: 현재 위치 설정)
6. 랜덤 워커 객체의 날짜/시간 데이터 초기화 (: 현재 날짜+시각 설정)

7. 랜덤 워커 객체의 현재 좌표로부터 인접해있는, 총 8개의 좌표 데이터 정보들을 이용해
	랜덤 워커 객체의 8방향 각각의 이동 확률 결정
8. 현재 상태를 고려하여 이동 확률 추가 조정
9. 필요한 요소들이 있다면(e.g. 계절, 시간, 부차적 데이터, 기타 등등) 고려하여
	이동 확률 추가 조정
   ( * 뚜렷한 목적지가 결정될 수 있는 경우(실제 데이터들을 고려, e.g. 규칙적 이동 등) :
		 현재 좌표로부터 해당 목적지를 향하는 방향에 이동 확률을 많이 더해줌 )

10. 랜덤 워커 두 번째 객체 생성
11. 랜덤 워커 초기 객체의 이동 확률 데이터를 고려하여 이동 방향 결정 후,
	  이동 방향에 따라 한 칸 이동한 좌표로 두 번째 객체의 좌표 데이터 초기화
12. 해당 생물의 평균적 이동 속도, 초기 위치에서의 상태, 기타 등등 아주 잘 고려해서
	  두 번째 객체의 날짜/시간 데이터 초기화
13. 두 번째 객체에 대하여 7~9 과정 수행
14. 10~13 반복

15. 목표한 날짜/시각까지 벡터 생성을 완료한 경우, 이를 데이터베이스에 '예측 이동 경로 데이터'로써 저장
16. 따라서, '이동 경로 데이터'는 랜덤 워커 벡터의 형식을 갖는다.
    => 랜덤 워커 벡터의 첫 번째 원소([0]) = 이동 경로의 시작 원소(예측한 데이터가 아닌, 실제 값)
    => 랜덤 워커 벡터의 [1] 원소 ~ [2], [3], ... = 예측 값들

- al_humpback_whale.hpp 에서 쓰일 예정

*/

/*

SEQUENCE

1. 매니저 객체 생성

2. Location DB 로드

3. 알고리즘 객체 생성 (location, predictCount 전달=>생성자)

  [생성자 내부에서 initiate() 실행하여, 초기 객체(인덱스 0) 초기화]

4. 매니저가 알고리즘 객체의 predict() 메소드 실행

5. predict() 내부에서 calcuate() 수행

  [calculate() 메소드가 랜덤워커의 계산 기능 수행]
   => 계산 후, 이동할 방향을 확정

6. 계산이 끝난 후 벡터 내에 결과 저장

7. 계산 결과를 바탕으로 혹등고래의 location 업데이트

8. 반복 횟수가 남았다면 predict() 메소드 실행

  [predict() 호출될 때마다 predictCount--]

9. 반복이 모두 끝난 경우 완성된 이동 경로 데이터(벡터)를
   DB에 저장, 클라이언트에 출력

*/

#pragma once

#include "location_origin.hpp"
#include "db_movementpath.hpp"

class RandomWalk
{
public:
    //생성자 : 로컬 정보, 시간 초기화
	RandomWalk();
    ~RandomWalk() {}

	// Random Walk
	int doRandomWalk(Organism& org, Location& loc);

    // 알고리즘 클래스의 calculate() 내부에서 실행된다.
    // 9방향 각각에 대한 이동 확률 계산 및 설정 메소드
    void setMovingPossibility(const int& pArray);
	void randomGenerate(std::vector<int>& rVec);
};

// 생 성 자
#pragma region RANDOMWALK_CONSTRUCTOR

RandomWalk::RandomWalk()
{
    //std::fill_n(possibility, 9, 0); // 9방향 확률 모두 0으로 초기화
}

#pragma endregion

// 이동 확률 계산 및 설정
#pragma region RANDOM_WALK_caculate

void RandomWalk::setMovingPossibility(const int& pArray)
{
	
}

int RandomWalk::doRandomWalk(Organism& org, Location& loc)
{
	// 대상 : 현재 랜덤 워커 벡터의 마지막 객체
	// 9방향 각각에 대한 이동 확률을 계산하여 랜덤워커 객체에 업데이트

	int     targetPossibility[3][3] = { 0, }; // 9개 위치의 확률
	Point     targetPoint[3][3];    // 9개 위치의 좌표 값
	LocalInfo targetInfo[3][3];     // 9개 위치의 Local 정보
	STATUS    targetStatus = org.getOrgStatus();  // 타겟 생물체의 상태

	// 확률 가중치
	int warmTemperatureWeight;
	int coldTemperatureWeight;
	int preyWeight;

	// 9개의 좌표 중, 중심 좌표 가져오기
	targetPoint[1][1] = org.getOrgPoint();

	// debug
	std::cout << org.getOrganismName() << std::endl;
	std::cout << "TargetPoint Load : " << targetPoint[1][1].xpos << " " << targetPoint[1][1].ypos << std::endl;


	// 인접한 9개의 좌표 계산
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			targetPoint[i][j].xpos = targetPoint[1][1].xpos + (i - 1);
			targetPoint[i][j].ypos = targetPoint[1][1].ypos + (j - 1);

			// debug
			// std::cout << targetPoint[i][j].xpos << " , " << targetPoint[i][j].ypos << std::endl;
		}

	// 9개의 LocalInfo 가져오기
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			targetInfo[i][j] = loc.getLocalInfo(targetPoint[i][j]);
		}

	//debug
	std::cout << "Get each LocalInfo Complete" << std::endl;

	/* 영향 요소들을 이용해 가중치 계산*/

	if (targetStatus == BREEDING)
	{
		warmTemperatureWeight = 7;
		coldTemperatureWeight = 2;
		preyWeight = 3;
	}
	else
	{
		warmTemperatureWeight = 1;
		coldTemperatureWeight = 3;
		preyWeight = 6;
	}

	//debug
	std::cout << "Weight assign Complete" << std::endl;


	// 중앙 위치의 온도 값
	int centerTemperature = loc.getWaterTemperature(targetPoint[1][1]);
	std::cout << "centerTemperature : " << centerTemperature << std::endl;

	//debug
	std::cout << "CenterTemperature Complete" << std::endl;

	// 먹이
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			for (auto& orgMember : targetInfo[i][j].localOrganisms)
			{
				// 1. 해당 위치에 크릴 새우가 있을 경우
				if (orgMember->getOrganismName() == "Krill")
					targetPossibility[i][j] += preyWeight;   // 가중치 가산

				// 2. 온도
				if (targetStatus == BREEDING)
				{
					// 주변의 온도가 중앙보다 높은 경우
					if (loc.getWaterTemperature(targetPoint[i][j]) > centerTemperature)
					{
						targetPossibility[i][j] += warmTemperatureWeight;   // 가중치 가산
					}
				}
				else    // NONBREEDING
				{
					// 주변의 온도가 중앙보다 낮은 경우
					if (loc.getWaterTemperature(targetPoint[i][j]) < centerTemperature)
					{
						targetPossibility[i][j] += coldTemperatureWeight;   // 가중치 가산
					}
				}


			}

	// LAST. 주변 지형 이동 가능성 판단 (이동 불가능 : 0 초기화)
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			// 해당 인접 위치가 바다가 아닌 경우 : 이동 확률을 0으로 초기화
			if (targetInfo[i][j].localState[1] != SEA)
				targetPossibility[i][j] = 0;
		}
	
	//debug
	/*for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			std::cout << targetPossibility[i][j] << std::endl;*/


	//debug
	std::cout << "Topology complete" << std::endl;

	// 확률 계산
	std::vector<int> randVec;
	int arrNum = 0;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			int randNum = targetPossibility[i][j];

			while (randNum--)
				randVec.push_back(arrNum);

			arrNum++;
		}

	//debug
	std::cout << "Possibility setup complete" << std::endl;

	/*for (auto& num : randVec)
		std::cout << num << " ";
	std::cout << std::endl;*/

	// 이동 좌표 결정
	randomGenerate(randVec);

	//debug
	std::cout << "Random Generatre Complete" << std::endl;

	// debug
	for (auto& num : randVec)
		std::cout << num << " ";
	std::cout << std::endl;

	return randVec.back();
}

void RandomWalk::randomGenerate(std::vector<int>& rVec)
{
	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(rVec.begin(), rVec.end(), g);

	// debug
	for (auto& num : rVec)
		std::cout << num << " ";
	std::cout << std::endl;
}
#pragma endregion