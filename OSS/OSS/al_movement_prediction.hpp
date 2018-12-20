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
public:

    /* Procedure
     * 
     * 생성자 실행 : initiate()를 통해 초기 Location(좌표, 시간, 상태 등) 생성
     * 
     * predict() : 1회의 예측 루틴 (predictCount만큼 반복)
     * 
     */

    // 기본 생성자
	MovementPrediction() {};

	// Destructor
	virtual ~MovementPrediction() {};

    // 첫 객체 초기화 (예측 값이 아닌, 실재하는 데이터를 초기 값으로 가져온다.)
	virtual void initiate() = 0;

    // predict 메소드는 Prediction 클래스의 핵심 루틴으로,
    // predictCount 횟수만큼 반복적으로 실행된다.
	virtual void predict() = 0;

	virtual void run() = 0;

	// Setter
	virtual bool setLocation(Location* loc) { return true; };
	virtual bool setTarget(std::string& orgName) { return true; };

	// Getter
	virtual std::string getTagetName() { return nullptr; };

	// Check
	virtual bool isTargetOrganism(Organism* org) { return true; };
	virtual bool isPredictionEnd() { return true; };	// 지정한 예측 루틴 실행 횟수에 도달했는지 검사

};

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
	~HumpbackWhaleMP();

	// 생성자 : Target으로부터 초기 시간을 받아 멤버에 저장, 실행 횟수 지정
	HumpbackWhaleMP(Timer timer, int predictCount)
		: m_timer(timer), m_predictCount(predictCount)
	{}

	// 예측 수행 = initiate + (predict * count)
	
	// Overridings
    virtual void run()  override;
	virtual void initiate() override;
	virtual void predict() override;

	// 9방향의 확률 계산 메소드
	void calculate();
	void addWalker();                   // 랜덤워커 객체 1개 추가
	
	//void calculateByPreference();       // 특정 선호 요소에 따른 각 방향의 이동확률 계산

	//void updateLocalInfo();             // 이동 방향 결정 후, m_localInfo 위치 이동

	void timeElapse();                  // 단위 시간 증가

	Direction decideDirection();        // 벡터 내의 마지막 랜덤워커 객체로부터 이동확률을 읽어, 이동 방향 결정

	void transformRWArray();            // 랜덤워커 배열 -> 간소화 배열 변환

	std::vector<RWOutput> getRWOutput();    // 간소화 배열 반환

	void randomGenerate(std::vector<int>& rVec);

	// setter
	virtual bool setLocation(Location* loc);
	virtual bool setTarget(std::string& orgName);

	// getter
	virtual std::string getTagetName();

	// check
	virtual bool isTargetOrganism(Organism* org);
	virtual bool isPredictionEnd();
};

#pragma region HumpbackWhaleMP_Constructor
HumpbackWhaleMP::HumpbackWhaleMP()
{
	m_predictCount = 0;
	m_numberOfWalkers = 0;
}

//HumpbackWhaleMP::HumpbackWhaleMP(Timer timer, int predictCount)
//{
//	// 랜덤워커 첫 객체의 위치 지정
//	m_point = m_targetOrganism->getOrgPoint();
//}
#pragma endregion

#pragma region HumpbackWhaleMP_Destructor
HumpbackWhaleMP::~HumpbackWhaleMP()
{
	delete[] m_location;
	delete[] m_targetOrganism;
}
#pragma endregion

#pragma region HumpbackWhaleMP_Setter
bool HumpbackWhaleMP::setLocation(Location* loc)
{
	if (loc != nullptr)
	{
		m_location = loc;
		return true;
	} return false;
}

bool HumpbackWhaleMP::setTarget(std::string& orgName)
{
	//debug
	std::cout << "Find org Name = " << orgName << std::endl;

	if (isTargetOrganism(m_location->getTarget(orgName)))
	{
		this->m_targetOrganism = m_location->getTarget(orgName);
		return true;
	} return false;
}


#pragma endregion


#pragma region HumpbackWhaleMP_Getter
std::string HumpbackWhaleMP::getTagetName()
{
	assert(m_targetOrganism != nullptr && "Target is NULLPTR!!");
	return m_targetOrganism->getOrganismName();
}
#pragma endregion


#pragma region HumpbackWhaleMP_Check
bool HumpbackWhaleMP::isPredictionEnd()
{
	if (m_numberOfWalkers > m_predictCount)
		return true;
	else
		return false;
}

bool HumpbackWhaleMP::isTargetOrganism(Organism* org)
{
	if (org != nullptr)
		return true;
	else
		return false;
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

void HumpbackWhaleMP::calculate()
{
	// 대상 : 현재 랜덤 워커 벡터의 마지막 객체
	// 9방향 각각에 대한 이동 확률을 계산하여 랜덤워커 객체에 업데이트
     
    int     targetPossibility[3][3] = { 0, }; // 9개 위치의 확률
    Point     targetPoint[3][3];    // 9개 위치의 좌표 값
    LocalInfo targetInfo[3][3];     // 9개 위치의 Local 정보
    STATUS    targetStatus = m_targetOrganism->getOrgStatus();  // 타겟 생물체의 상태

    // 확률 가중치
    int warmTemperatureWeight;
    int coldTemperatureWeight;
    int preyWeight;

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

    /* 영향 요소들을 이용해 가중치 계산*/

    if(targetStatus == BREEDING)
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

    // 중앙 위치의 온도 값
    int centerTemerature = m_location->getWaterTemperature(targetPoint[4][4]);

    // 먹이
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (const auto& orgMember : targetInfo[i][j].localOrganisms)
            {
                // 1. 해당 위치에 크릴 새우가 있을 경우
                if(orgMember->getOrganismName() == "Krill")
                    targetPossibility[i][j] += preyWeight;   // 가중치 가산

                // 2. 온도
                if(targetStatus == BREEDING)
                {
                    // 주변의 온도가 중앙보다 높은 경우
                    if (m_location->getWaterTemperature(targetPoint[i][j]) > centerTemerature)
                    {
                        targetPossibility[i][j] += warmTemperatureWeight;   // 가중치 가산
                    }
                }
                else    // NONBREEDING
                {
                    // 주변의 온도가 중앙보다 낮은 경우
                    if (m_location->getWaterTemperature(targetPoint[i][j]) < centerTemerature)
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
            if(targetInfo[i][j].localState[2] != SEA)
                targetPossibility[i][j] = 0;
        }

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

	// 이동 좌표 결정
	randomGenerate(randVec);
	
	
}

void HumpbackWhaleMP::addWalker()
{
	// 이터레이터 : 백터 내에서 가장 말단에 있는 랜덤 워커
	const RandomWalk& iterator = m_randomWalk[m_numberOfWalkers - 1];


    /* 2018.12.16 ~ TODO ***********************************
     *
     * 1. 난수 발생시켜서 이동할 방향 결정
     * 2. 결정된 방향으로 이동 (moveWalker(방향) 메소드 구현 및 호출)
     * 3. 이동된 방향으로 새로운 랜덤워커 객체 생성(벡터 말단에 push_back)
     * 4. ~반복하여 랜덤워커 벡터가 생성됨
     * 5. 생성된 벡터를 간소화 배열로 변환(구현되어있음, 수정 필요) => 간소화 배열 반환
     *
     * ******************************************************
     */


    // 말단 랜덤워커의 9개의 이동 확률을 읽고, 랜덤으로 방향 결정


	// 결정된 방향으로 이동
    // moveWalker(direction);

	// 단위 시간 증가
	timeElapse();

    // 이동한 좌표에 따라, 해당 지역 정보를 실시간으로 업데이트
	// 랜덤워커 벡터에 객체 하나 추가, 개체 수 증가
	m_randomWalk.push_back(RandomWalk(m_point, m_timer));
	m_numberOfWalkers++;
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
		// m_rwOutput.push_back(RWOutput(walker.getLocalInfo().pos, walker.getTimer().getTimeString()));
	}
}

// 간소화 배열 반환
std::vector<RWOutput> HumpbackWhaleMP::getRWOutput()
{
	return m_rwOutput;
}

void HumpbackWhaleMP::randomGenerate(std::vector<int>& rVec)
{
	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(rVec.begin(), rVec.end(), g);
}
#pragma endregion

