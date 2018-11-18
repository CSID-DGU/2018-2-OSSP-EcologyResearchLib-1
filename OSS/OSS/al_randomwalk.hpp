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
Coded by : 
Last Updated : 18-11-05


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
    => 랜덤 워커 벡터의 첫 번째 원소([0]) = 이동 경로의 시작 원소(예측한 데이터가 아닌, 실제 값일 수 있음)
    => 랜덤 워커 벡터의 [1] 원소 ~ = 예측 값들

- al_humpback_whale.hpp 에서 쓰일 예정

*/

#pragma once

#define DIRECTION_NUMBER 9

class RandomWalk
{
	// Result of RandomWalk 
	struct RWResult
	{

	};


public:
	RandomWalk();
	~RandomWalk() {};

	void setMovingPossibility(const float& pArray);
	float* getMovingPossibility();

private:
	float possibility[DIRECTION_NUMBER] = { 0 }; 
	// Moving possibility , 9 Direction : 동서남북 + 북동 북서 남동 남서 + 정지
};


#pragma region RANDOM_WALK_POSSIBILITY
void RandomWalk::setMovingPossibility(const float& pArray)
{
	// To do
}

float* RandomWalk::getMovingPossibility()
{
	// To do
}
#pragma endregion


#pragma region RANDOMWALK_CONSTRUCTOR
RandomWalk::RandomWalk()
{
	// TO do
}

#pragma endregion