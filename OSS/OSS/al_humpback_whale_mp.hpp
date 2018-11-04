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
    virtual void predictByHour(Organism& organism, int hours) override;
    virtual void predictByDay (Organism& organism, int days ) override { predictByHour(organism, days * 24); }
};


// �޼ҵ� ����

// ������ �����͵��� �������� 1�ð� ���� ~ �Է� ���� �ð� ������ �����͸�
// �����Ͽ� �����ͺ��̽��� ����
void HumpbackWhaleMP::predictByHour(Organism& organism, int hours = 1)
{
    // �����ͺ��̽� ���°� ������ �� ����







    // Implements..
}


#endif // _HUMPBACK_WHALE_MOVEMENT_PREDICTION_HPP__