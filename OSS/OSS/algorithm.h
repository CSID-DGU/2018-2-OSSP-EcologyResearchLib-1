// 생물의 행동을 "예측"하는 알고리즘들
// 그 중에서도 "이동 경로 예측" 구현

// 입력 : 필드, 생물 정보(분류, 상태, 지금까지의 이동 경로), 예측할 기간
// 동작 : 생물 정보를 ref로 입력받아 예측할 기간만큼의 이동 경로를 예측하여
//        생물 정보 중 이동 경로에 추가
// 출력 : 없음

// Organism의 하위 객체들(ex> 고래)을 입력받아서
// 지금까지의 데이터들을 바탕으로 앞으로의 데이터를 예측하여 삽입

// 일정한 시간 간격으로 저장된 데이터들을 바탕으로 
// 역시 일정한 시간 간격 뒤의 데이터를 추가(&로 접근하여 업데이트)

// 예를 들어, 1일 2일 3일의 정보를 갖고 있었으면
// 단순 메소드 호출 시 4일의 정보 하나만 생성

// 1, 2, 3일 정보 가진 상태에서 8일의 정보를 얻고 싶으면
// 4, 5, 6, 7, 8일의 정보 모두 생성하여 객체에 저장

#ifndef _ALGORITHM_H__
#define _ALGORITHM_H__

#include "organism.h"
#include "database.h"


// 생물 이동경로 예측 알고리즘
// 인터페이스를 제공하며,
// 예측 알고리즘은 각 생물마다 구현한다.
class MovementPrediction
{

public:
    // 한 시간 단위로 예측
    virtual void predictByHour(Organism& organism, int hours) = 0;

    // 하루 단위로 예측
    // 24시간으로 변환하여 알고리즘 수행
    // 또는 (생물에 따라) 시간 단위 대신 하루 단위를 기본으로 사용
    virtual void predictByDay (Organism& organism, int days)  = 0;
};


#endif // _ALGORITHM_H__
