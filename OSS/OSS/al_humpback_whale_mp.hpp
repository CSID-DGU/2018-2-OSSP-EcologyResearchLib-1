// Coded by : Sa Min Hong 

// �̵� ��� ���� �˰���
// Ȥ�� ��

#ifndef _HUMPBACK_WHALE_MOVEMENT_PREDICTION_HPP__
#define _HUMPBACK_WHALE_MOVEMENT_PREDICTION_HPP__

#include "al_algorithm.hpp"


// Ȥ���(Humpback Whale) �̵���� ����(MP) �˰���
class HumpbackWhaleMP : public MovementPrediction
{

public:
    virtual void predictByHour(Location& loc, Organism& organism) override;
    virtual void predictByDay (Location& loc, Organism& organism) override {  }
};


// �޼ҵ� ����

// ������ �����͵��� �������� 1�ð� ���� ~ �Է� ���� �ð� ������ �����͸�
// �����Ͽ� �����ͺ��̽��� ����
void HumpbackWhaleMP::predictByHour(Location& loc, Organism& organism)
{
    // �����ͺ��̽� ���°� ������ �� ����







    // Implements..
}


#endif // _HUMPBACK_WHALE_MOVEMENT_PREDICTION_HPP__