/* MIT License

******************************************************
					MIT License
			Copyright (c) 2018 CSID-DGU
******************************************************

/*
 Coded by : Sa Min Hong
 Last Updated : 18-11-05

 [ HumpbackWhaleMP ] 

 <Explanation>
 - 흑동 고래 이동 경로 예측 알고리즘. [ MovementPrediction ] 클래스 상속

 <To do>
 - RandomWalk 클래스 적용할 것.

*/

#include "al_algorithm.hpp"
#include "al_randomwalk.hpp"

// 혹등고래(Humpback Whale) 이동경로 예측(MP) 알고리즘
class HumpbackWhaleMP : public MovementPrediction
{
/*
protected:
    int m_predictCount;   // 예측 루틴 실행 횟수
*/

private:
    // 랜덤워커 배열 = 예측된 이동 경로
	std::vector<RandomWalk> m_randomWalk;
    // 저장용 간소화 배열
    std::vector<RWOutput> m_rwOutput;
    // 예측 루틴 실행 횟수
    int m_predictCount;
    // 현재 랜덤워커 수
    int m_numberOfWalkers;

    // 랜덤워커 객체가 위치할 좌표와, 해당 좌표의 위치 정보
    // 알고리즘 실행 시, Target으로부터 LocalInfo 받아옴(생성자)
    // 예측 수행할 때마다, 업데이트하여 마지막 랜덤워커의 정보를 담게 됨
    LocalInfo m_localInfo;
    // 시간 : localInfo랑 세트
    Timer m_timer;

    // 지정한 예측 루틴 실행 횟수에 도달했는지 검사
    bool isPredictionEnd();


public:

	HumpbackWhaleMP();

    // 생성자 : Target으로부터 LocalInfo, 초기 시간을 받아 멤버에 저장, 실행 횟수 지정
    HumpbackWhaleMP(LocalInfo localInfo, Timer timer, int predictCount)
        : m_localInfo(localInfo), m_timer(timer), m_predictCount(predictCount) {}

    // 예측 수행 = initiate + (predict * count)
    void run();

    // Overridings
    virtual void initiate() override;
    virtual void predict() override;

    // 9방향의 확률 계산 메소드 : 랜덤워커 계산할 2차원 필드 범위를 지정
    void calculate(/*int leftX, int topY, int rightX, int bottomY*/);
    // 랜덤워커 객체 1개 추가
    void addWalker();
    // 특정 선호 요소에 따른 각 방향의 이동확률 계산
    void calculateByPreference();

    // 이동 방향 결정 후, m_localInfo 위치 이동
    void updateLocalInfo();

    // 단위 시간 증가
    void timeElapse();

    // 벡터 내의 마지막 랜덤워커 객체로부터 이동확률을 읽어, 이동 방향 결정
    Direction decideDirection();

    // 랜덤워커 배열 -> 간소화 배열 변환
    void transformRWArray();

    // 간소화 배열 반환
    std::vector<RWOutput> getRWOutput();
};

#pragma region HumpbackWhaleMP_Constructor
HumpbackWhaleMP::HumpbackWhaleMP()
{

}

#pragma endregion

#pragma region Private Fuctions

bool HumpbackWhaleMP::isPredictionEnd()
{
    if(m_numberOfWalkers > m_predictCount)
        return true;
    else
        return false;
}

#pragma endregion

#pragma region Public Functions

void HumpbackWhaleMP::initiate()
{
    // 랜덤워커 배열의 0번 객체 초기화
    m_randomWalk.push_back(RandomWalk(m_localInfo, m_timer));

    // 이제 랜덤워커는 한 명
    m_numberOfWalkers = 1;
}

void HumpbackWhaleMP::predict()
{
    // 한 번 수행될 때마다, 랜덤 워커 객체를 하나 생성하여 벡터에 추가한다.
    // Prototype : 단위는 3일(3일마다 1위도(110km정도)씩 이동)

    // 예측 루틴 반복 :  실행 횟수에 도달한 경우 종료
    while(!isPredictionEnd())
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
    //const RandomWalk& iterator = m_randomWalk[m_numberOfWalkers - 1];

    // 바로 이전 랜덤워커의 확률에 따라 좌표 이동
    // 이동한 좌표에 따라, 해당 지역 정보를 실시간으로 업데이트
    updateLocalInfo();
    // 단위 시간 증가
    timeElapse();

    // 랜덤워커 벡터에 객체 하나 추가, 개체 수 증가
    m_randomWalk.push_back(RandomWalk(m_localInfo, m_timer));
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
}

// 랜덤워커 배열 -> 간소화 배열 변환
void HumpbackWhaleMP::transformRWArray()
{
    for(RandomWalk& walker : m_randomWalk)
    {
        m_rwOutput.push_back(RWOutput(walker.getLocalInfo().pos, walker.getTimer().getTimeString() ));
    }
}

// 간소화 배열 반환
std::vector<RWOutput> HumpbackWhaleMP::getRWOutput()
{
    return m_rwOutput;
}

#pragma endregion
