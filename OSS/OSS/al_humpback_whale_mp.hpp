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


// 혹등고래(Humpback Whale) 이동경로 예측(MP) 알고리즘
class HumpbackWhaleMP : public MovementPrediction
{

public:
    virtual void predictByHour(Location& loc, Organism& organism) override;
    virtual void predictByDay (Location& loc, Organism& organism) override {  }
};


// 메소드 구현

// 기존의 데이터들을 바탕으로 1시간 이후 ~ 입력 받은 시간 까지의 데이터를
// 예측하여 데이터베이스에 삽입
void HumpbackWhaleMP::predictByHour(Location& loc, Organism& organism)
{
    // 데이터베이스 형태가 결정된 후 구현







    // Implements..
}


#endif // _HUMPBACK_WHALE_MOVEMENT_PREDICTION_HPP__