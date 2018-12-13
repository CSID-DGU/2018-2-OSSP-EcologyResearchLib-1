/*

******************************************************
					MIT License					
			Copyright (c) 2018 CSID-DGU					
******************************************************

 Coded by : Sa Min Hong
 Last Updated : 18-12-11


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

#include "location_origin.hpp"


// 생물 이동경로 예측 알고리즘
// 인터페이스를 제공하며,
// 예측 알고리즘은 각 생물마다 구현한다.


class MovementPrediction
{
protected:
    //int m_predictCount;   // 예측 루틴 실행 횟수
	Organism* targetOrganism;	// target Organism to predict
	Location* location;	// target Location for algorithm

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
	virtual void initiate() {};

    // predict 메소드는 Prediction 클래스의 핵심 루틴으로,
    // predictCount 횟수만큼 반복적으로 실행된다.
	virtual void predict() {};

	// Setter
	bool setLocation(Location* loc);
	bool setTarget(std::string& orgName);

	// Getter
	std::string getTagetName();

	// Check
	bool isTargetOrganism(Organism* org);

};


#pragma region MovementPrediction_Constructor
MovementPrediction::MovementPrediction()
{

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



