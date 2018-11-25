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

 [ HumpbackWhaleMP ] 

 <Explanation>
 - 흑동 고래 이동 경로 예측 알고리즘. [ MovementPrediction ] 클래스 상속

 <To do>
 - RandomWalk 클래스 적용할 것.

*/


#ifndef _HUMPBACK_WHALE_MOVEMENT_PREDICTION_HPP__
#define _HUMPBACK_WHALE_MOVEMENT_PREDICTION_HPP__

#include "al_algorithm.hpp"
#include <vector>


// 혹등고래(Humpback Whale) 이동경로 예측(MP) 알고리즘
class HumpbackWhaleMP : public MovementPrediction
{
/*
protected:
    Location& m_location; // 초기 Location( 배열의 0번 인덱스 )
    int m_predictCount;   // 예측 루틴 실행 횟수
*/

private:
    // 랜덤워커 배열 = 예측된 이동 경로
	std::vector<RandomWalk> m_randomWalk; 

public:
    virtual void initiate() override;
    virtual void predict() override;

    // 9방향의 확률 계산 메소드
    void calculate();
};

void HumpbackWhaleMP::initiate()
{
    m_randomWalk.push_back(RandomWalk());   // 랜덤워커 배열의 0번 객체 초기화

    //To Do
}

void HumpbackWhaleMP::predict()
{
    // 한 번 수행될 때마다, 랜덤 워커 객체를 하나 생성하여 벡터에 추가한다.

    //To Do
}

void HumpbackWhaleMP::calculate()
{
    // 9방향 각각에 대한 이동 확률을 계산한다.
    // predict() 내부에서 실행된다.

    //To Do
}

#endif // _HUMPBACK_WHALE_MOVEMENT_PREDICTION_HPP__