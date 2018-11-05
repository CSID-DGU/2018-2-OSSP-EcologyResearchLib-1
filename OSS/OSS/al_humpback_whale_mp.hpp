// Coded by : Sa Min Hong 

// 이동 경로 예측 알고리즘
// 혹등 고래

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