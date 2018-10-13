// 이동 경로 예측 알고리즘
// 혹등 고래

#ifndef _HUMPBACK_WHALE_MOVEMENT_PREDICTION_HPP__
#define _HUMPBACK_WHALE_MOVEMENT_PREDICTION_HPP__

#include "algorithm.h"


// 혹등고래(Humpback Whale) 이동경로 예측(MP) 알고리즘
class HumpbackWhaleMP : public MovementPrediction
{

public:
    virtual void predictByHour(Organism& organism, int hours);
    virtual void predictByDay (Organism& organism, int days ) { predictByHour(organism, days * 24); }
};


// 메소드 구현

// 기존의 데이터들을 바탕으로 1시간 이후 ~ 입력 받은 시간 까지의 데이터를
// 예측하여 데이터베이스에 삽입
void HumpbackWhaleMP::predictByHour(Organism& organism, int hours = 1)
{
    // 데이터베이스 형태가 결정된 후 구현







    // Implements..
}


#endif // _HUMPBACK_WHALE_MOVEMENT_PREDICTION_HPP__