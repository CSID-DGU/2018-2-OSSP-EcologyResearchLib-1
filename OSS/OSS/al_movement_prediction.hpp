/*

******************************************************
					MIT License					
			Copyright (c) 2018 CSID-DGU					
******************************************************

 Coded by : Sa Min Hong
 Last Updated : 18-12-13


 [ MovementPrediction ] 

 <Explanation>
 - 생물의 행동을 "예측"하는 알고리즘의 최상위 클래스
 - 입력 : 필드, 생물 정보(분류, 상태, 지금까지의 이동 경로), 예측할 기간
 - 동작 : 생물 정보를 ref로 입력받아 예측할 기간만큼의 이동 경로를 예측하여
		생물 정보 중 이동 경로에 추가
 - 출력 : 없음

 <To do>
 - 상속 클래스에서 "이동 경로 예측" 구현
 - Organism의 하위 객체들(ex> 고래)을 입력받아서 
   지금까지의 데이터들을 바탕으로 앞으로의 데이터를 예측하여 삽입
 - 일정한 시간 간격으로 저장된 데이터들을 바탕으로
   역시 일정한 시간 간격 뒤의 데이터를 추가(&로 접근하여 업데이트)
   
   예를 들어, 1일 2일 3일의 정보를 갖고 있었으면 
   단순 메소드 호출 시 4일의 정보 하나만 생성
   1, 2, 3일 정보 가진 상태에서 8일의 정보를 얻고 싶으면
   4, 5, 6, 7, 8일의 정보 모두 생성하여 객체에 저장

*/

#pragma once

#include "location_origin.hpp"
#include "al_randomwalk.hpp"


// 생물 이동경로 예측 알고리즘
// 인터페이스를 제공하며,
// 예측 알고리즘은 각 생물마다 구현한다.


class MovementPrediction
{
protected:
	


public:

    /* Procedure
     * 
     * 생성자 실행 : initiate()를 통해 초기 Location(좌표, 시간, 상태 등) 생성
     * 
     * predict() : 1회의 예측 루틴 (predictCount만큼 반복)
     * 
     */

    // 기본 생성자
	MovementPrediction();

	// Destructor
	virtual ~MovementPrediction();

    // 첫 객체 초기화 (예측 값이 아닌, 실재하는 데이터를 초기 값으로 가져온다.)
	virtual void initiate() = 0;

    // predict 메소드는 Prediction 클래스의 핵심 루틴으로,
    // predictCount 횟수만큼 반복적으로 실행된다.
	virtual void predict() = 0;

	virtual void run() = 0;

	// Setter
	bool setLocation(Location* loc);
	bool setTarget(std::string& orgName);

	// Getter
	std::string getTagetName();

	// Check
	bool isTargetOrganism(Organism* org);
	bool isPredictionEnd();	// 지정한 예측 루틴 실행 횟수에 도달했는지 검사

};


#pragma region MovementPrediction_Constructor
MovementPrediction::MovementPrediction()
{
	m_predictCount = 0;
	m_numberOfWalkers = 0;
}
#pragma endregion

#pragma region MovementPrediction_Destructor
MovementPrediction::~MovementPrediction()
{
	delete[] targetOrganism;
	delete[] location;
}
#pragma endregion

#pragma region MovementPredcitor_Setter
bool MovementPrediction::setLocation(Location* loc)
{
	if (loc != nullptr)
	{
		location = loc;
		return true;
	} return false;
}

bool MovementPrediction::setTarget(std::string& orgName)
{
	//debug
	std::cout << "Find org Name = " << orgName << std::endl;

	if (isTargetOrganism(location->getTarget(orgName)))
	{
		this->targetOrganism = location->getTarget(orgName);
		return true;
	} return false;
}

bool MovementPrediction::isTargetOrganism(Organism* org)
{
	if (org != nullptr)
		return true;
	else
		return false;
}

#pragma endregion


#pragma region MovementPrediction_Getter
std::string MovementPrediction::getTagetName()
{
	assert(targetOrganism != nullptr && "Target is NULLPTR!!");
	return targetOrganism->getOrganismName();
}
#pragma endregion


#pragma region MovementPrediction_Check
bool MovementPrediction::isPredictionEnd()
{
	if (m_numberOfWalkers > m_predictCount)
		return true;
	else
		return false;
}
#pragma endregion


////////////////////////////////////////////////////////////////////////////////

/*
 Coded by : Sa Min Hong
 Last Updated : 18-12-16

 [ HumpbackWhaleMP ]

 <Explanation>
 - 흑동 고래 이동 경로 예측 알고리즘. [ MovementPrediction ] 클래스 상속

 <To do>
 - RandomWalk 클래스 적용할 것.

*/

class HumpbackWhaleMP : public MovementPrediction
{
private:

    // DB pointer
    Organism* m_targetOrganism;	// target Organism to predict
    Location* m_location;			// target Location for algorithm
    
    std::vector<RandomWalk> m_randomWalk;   // 랜덤워커 배열 = 예측된 이동 경로
    std::vector<RWOutput> m_rwOutput;       // 저장용 간소화 배열
    
    int m_predictCount;                     // 예측 루틴 실행 횟수
    int m_numberOfWalkers;                  // 현재 랜덤워커 수
    
    Timer m_timer;                          // 랜덤워커가 갖는 시간
    Point m_point;                          // 랜덤워커의 위치
    
public:

	HumpbackWhaleMP();      // 기본 생성자

	// 생성자 : Target으로부터 초기 시간을 받아 멤버에 저장, 실행 횟수 지정
	HumpbackWhaleMP(Timer timer, int predictCount)
		: m_timer(timer), m_predictCount(predictCount) {}

	// 예측 수행 = initiate + (predict * count)
	
	// Overridings
    virtual void run()  override;
	virtual void initiate() override;
	virtual void predict() override;

	// 9방향의 확률 계산 메소드 : 랜덤워커 계산할 2차원 필드 범위를 지정
	void calculate(/*int leftX, int topY, int rightX, int bottomY*/);
	
	void addWalker();                   // 랜덤워커 객체 1개 추가
	
	void calculateByPreference();       // 특정 선호 요소에 따른 각 방향의 이동확률 계산

	void updateLocalInfo();             // 이동 방향 결정 후, m_localInfo 위치 이동

	void timeElapse();                  // 단위 시간 증가

	Direction decideDirection();        // 벡터 내의 마지막 랜덤워커 객체로부터 이동확률을 읽어, 이동 방향 결정

	void transformRWArray();            // 랜덤워커 배열 -> 간소화 배열 변환

	std::vector<RWOutput> getRWOutput();    // 간소화 배열 반환
};

#pragma region HumpbackWhaleMP_Constructor
HumpbackWhaleMP::HumpbackWhaleMP()
{

}

HumpbackWhaleMP::HumpbackWhaleMP(Timer timer, int predictCount)
{
    // 랜덤워커 첫 객체의 위치 지정
    m_point = m_targetOrganism->getOrgPoint();
}

#pragma endregion


#pragma region Public Functions

void HumpbackWhaleMP::run()
{
    initiate();
    predict();
}

void HumpbackWhaleMP::initiate()
{
	// 랜덤워커 배열의 0번 객체 초기화
	m_randomWalk.push_back(RandomWalk(m_point, m_timer));

	// 이제 랜덤워커는 한 명
	m_numberOfWalkers = 1;
}

void HumpbackWhaleMP::predict()
{
	// 한 번 수행될 때마다, 랜덤 워커 객체를 하나 생성하여 벡터에 추가한다.
	// Prototype : 단위는 3일(3일마다 1위도(110km정도)씩 이동)

	// 예측 루틴 반복 :  실행 횟수에 도달한 경우 종료
	while (!isPredictionEnd())
	{
		// 랜덤워커 벡터 내에 존재하는 마지막 객체에 대해 이동 확률 계산
		calculate();

		// 벡터에 랜덤 워커 객체 하나 추가
		addWalker();
	}
}

void HumpbackWhaleMP::calculate(/*int leftX, int topY, int rightX, int bottomY*/)
{
	// 대상 : 현재 랜덤 워커 벡터의 마지막 객체
	// 9방향 각각에 대한 이동 확률을 계산하여 랜덤워커 객체에 업데이트
    
    float     targetPossibility[DIRECTION_NUMBER] = {0,};
    Point     targetPoint[3][3];
    LocalInfo targetInfo[3][3];

    // 9개의 좌표 중, 중심 좌표 가져오기
    targetPoint[1][1] = m_targetOrganism->getOrgPoint();
    
    // 인접한 9개의 좌표 계산
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
            targetPoint[i][j].xpos = targetPoint[1][1].xpos + (i - 1);
            targetPoint[i][j].ypos = targetPoint[1][1].ypos + (j - 1);
        }

    // 9개의 LocalInfo 가져오기
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            targetInfo[i][j] = m_location->getLocalInfo(targetPoint[i][j]);
        }



	// TODO !!!!!!!


	/* 각 선호 요소마다 계산 진행 */

	// 개체 상태
	calculateByPreference(/* state */);

	// 수온
	calculateByPreference(/* temperature */);

	// LAST. 주변 지형 이동 가능성 판단 (이동 불가능 : 0 초기화)
	calculateByPreference(/* 지형 */);
}

void HumpbackWhaleMP::addWalker()
{
	// 이터레이터 : 백터 내에서 가장 말단에 있는 랜덤 워커
	const RandomWalk& iterator = m_randomWalk[m_numberOfWalkers - 1];

	// 바로 이전 랜덤워커의 확률에 따라 좌표 이동


	// 이동한 좌표에 따라, 해당 지역 정보를 실시간으로 업데이트
	updateLocalInfo();
	// 단위 시간 증가
	timeElapse();

	// 랜덤워커 벡터에 객체 하나 추가, 개체 수 증가
	m_randomWalk.push_back(RandomWalk(m_point, m_timer));
	m_numberOfWalkers++;
}

void HumpbackWhaleMP::updateLocalInfo()
{
	// 마지막 랜덤워커의 확률로부터 랜덤 계산하여 방향 결정
	Direction nextDirection = decideDirection();

	/* TODO : 결정된 방향에 따라 m_localInfo 위치 이동 */

	/* TODO : localInfo 정보 실시간 업데이트 */
}

void HumpbackWhaleMP::timeElapse()
{
	// 단위 시간 증가 : 3일
	m_timer.addDay(3);
}

Direction HumpbackWhaleMP::decideDirection()
{
	// TODO : 난수 발생 필요
	// 9방향의 확률에 대해 랜덤으로 위치 결정

	/* return Direction::DECIDED_DIRECTION ! */
	return Direction();
}

// 랜덤워커 배열 -> 간소화 배열 변환
void HumpbackWhaleMP::transformRWArray()
{
	for (RandomWalk& walker : m_randomWalk)
	{
		m_rwOutput.push_back(RWOutput(walker.getLocalInfo().pos, walker.getTimer().getTimeString()));
	}
}

// 간소화 배열 반환
std::vector<RWOutput> HumpbackWhaleMP::getRWOutput()
{
	return m_rwOutput;
}
#pragma endregion

