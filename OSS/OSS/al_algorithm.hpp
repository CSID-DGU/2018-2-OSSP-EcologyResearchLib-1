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

 Coded by : Sa Min Hong
 Last Updated : 18-11-05


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


#ifndef _ALGORITHM_H__
#define _ALGORITHM_H__

#include "location_origin.hpp"
#include "al_randomwalk.hpp"

// 생물 이동경로 예측 알고리즘
// 인터페이스를 제공하며,
// 예측 알고리즘은 각 생물마다 구현한다.
class MovementPrediction
{
protected:  // 하위 클래스에서 자신의 멤버처럼 사용하기 위해
    Location& m_location; // 초기 Location( 배열의 0번 인덱스 )
    int m_predictCount;   // 예측 루틴 실행 횟수

public:

    /* Procedure
     * 
     * 생성자 실행 : initiate()를 통해 초기 Location(좌표, 시간, 상태 등) 생성
     * 
     * predict() : 1회의 예측 루틴 (predictCount만큼 반복)
     * 
     */

    // 생성자 : 초기 Location, 예측 루틴 반복 횟수(기본값 = 1) 초기화
    MovementPrediction(Location& location, int predictCount = 1)
        : m_location(location), m_predictCount(predictCount){}

    // 첫 객체 초기화 (예측 값이 아닌, 실재하는 데이터를 초기 값으로 가져온다.)
    virtual void initiate() = 0;

    // predict 메소드는 Prediction 클래스의 핵심 루틴으로,
    // predictCount 횟수만큼 반복적으로 실행된다.
    virtual void predict() = 0;

    // 예측 루틴 실행 횟수를 설정
    virtual void setPredictCount(const int& predictCount) = 0;
};


#endif // _ALGORITHM_H__
