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
 - �浿 �� �̵� ��� ���� �˰���. [ MovementPrediction ] Ŭ���� ���

 <To do>
 - RandomWalk Ŭ���� ������ ��.

*/


#ifndef _HUMPBACK_WHALE_MOVEMENT_PREDICTION_HPP__
#define _HUMPBACK_WHALE_MOVEMENT_PREDICTION_HPP__

#include "al_algorithm.hpp"
#include <vector>

/* 9���� �̵� ��� : ����, ��, �ϵ�, ��, ... ��, �ϼ�
enum Direction
{
    STOP,
    NORTH, NORTH_EAST, EAST, SOUTH_EAST,
    SOUTH, SOUTH_WEST, WEST, NOTRH_WEST
};
*/

// ���߿� �ű���� ����������������������������
// ����ȭ ����� RWOutput (�˰��򿡼� ������Ŀ�� ���� ������ ����� ��������)
typedef struct
{
    std::string     organismName;   // ����ü �̸�
    Position        position;       // ��ǥ
    timer_string_t  time;           // ����ȭ�� �ð� ��Ʈ��
} LocationTimeInfo;

// Ȥ���(Humpback Whale) �̵���� ����(MP) �˰���
class HumpbackWhaleMP : public MovementPrediction
{
/*
protected:
    int m_predictCount;   // ���� ��ƾ ���� Ƚ��
*/

private:
    // ������Ŀ �迭 = ������ �̵� ���
	std::vector<RandomWalk> m_randomWalk;
    // ���� ��ƾ ���� Ƚ��
    int m_predictCount;
    // ���� ������Ŀ ��
    int m_numberOfWalkers;

    // ������Ŀ ��ü�� ��ġ�� ��ǥ��, �ش� ��ǥ�� ��ġ ����
    // �˰��� ���� ��, Target���κ��� LocalInfo �޾ƿ�(������)
    // ���� ������ ������, ������Ʈ�Ͽ� ������ ������Ŀ�� ������ ��� ��
    LocalInfo m_localInfo;
    // �ð� : localInfo�� ��Ʈ
    Timer m_timer;

    // ������ ���� ��ƾ ���� Ƚ���� �����ߴ��� �˻�
    bool isPredictionEnd();


public:
    // ������ : Target���κ��� LocalInfo, �ʱ� �ð��� �޾� ����� ����, ���� Ƚ�� ����
    HumpbackWhaleMP(LocalInfo localInfo, Timer timer, int predictCount)
        : m_localInfo(localInfo), m_timer(timer), m_predictCount(predictCount) {}

    // ���� ���� = initiate + (predict * count)
    void run();

    // Overridings
    virtual void initiate() override;
    virtual void predict() override;

    // 9������ Ȯ�� ��� �޼ҵ� : ������Ŀ ����� 2���� �ʵ� ������ ����
    void calculate(/*int leftX, int topY, int rightX, int bottomY*/);
    // ������Ŀ ��ü 1�� �߰�
    void addWalker();
    // Ư�� ��ȣ ��ҿ� ���� �� ������ �̵�Ȯ�� ���
    void calculateByPreference();

    // �̵� ���� ���� ��, m_localInfo ��ġ �̵�
    void updateLocalInfo();

    // ���� �ð� ����
    void timeElapse();

    // ���� ���� ������ ������Ŀ ��ü�κ��� �̵�Ȯ���� �о�, �̵� ���� ����
    Direction decideDirection();
};

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
    // ������Ŀ �迭�� 0�� ��ü �ʱ�ȭ
    m_randomWalk.push_back(RandomWalk(m_localInfo, m_timer));

    // ���� ������Ŀ�� �� ��
    m_numberOfWalkers = 1;
}

void HumpbackWhaleMP::predict()
{
    // �� �� ����� ������, ���� ��Ŀ ��ü�� �ϳ� �����Ͽ� ���Ϳ� �߰��Ѵ�.
    // Prototype : ������ 3��(3�ϸ��� 1����(110km����)�� �̵�)

    // ���� ��ƾ �ݺ� :  ���� Ƚ���� ������ ��� ����
    while(!isPredictionEnd())
    {
        // ������Ŀ ���� ���� �����ϴ� ������ ��ü�� ���� �̵� Ȯ�� ���
        calculate();

        // ���Ϳ� ���� ��Ŀ ��ü �ϳ� �߰�
        addWalker();
    }
}

void HumpbackWhaleMP::calculate(/*int leftX, int topY, int rightX, int bottomY*/)
{
    // ��� : ���� ���� ��Ŀ ������ ������ ��ü
    // 9���� ������ ���� �̵� Ȯ���� ����Ͽ� ������Ŀ ��ü�� ������Ʈ


    // TODO !!!!!!!


    /* �� ��ȣ ��Ҹ��� ��� ���� */

    // ��ü ����
    calculateByPreference(/* state */);

    // ����
    calculateByPreference(/* temperature */);

    // LAST. �ֺ� ���� �̵� ���ɼ� �Ǵ� (�̵� �Ұ��� : 0 �ʱ�ȭ)
    calculateByPreference(/* ���� */);
}

void HumpbackWhaleMP::addWalker()
{
    // ���ͷ����� : ���� ������ ���� ���ܿ� �ִ� ���� ��Ŀ
    //const RandomWalk& iterator = m_randomWalk[m_numberOfWalkers - 1];

    // �ٷ� ���� ������Ŀ�� Ȯ���� ���� ��ǥ �̵�
    // �̵��� ��ǥ�� ����, �ش� ���� ������ �ǽð����� ������Ʈ
    updateLocalInfo();
    // ���� �ð� ����
    timeElapse();

    // ������Ŀ ���Ϳ� ��ü �ϳ� �߰�, ��ü �� ����
    m_randomWalk.push_back(RandomWalk(m_localInfo, m_timer));
    m_numberOfWalkers++;
}

void HumpbackWhaleMP::updateLocalInfo()
{
    // ������ ������Ŀ�� Ȯ���κ��� ���� ����Ͽ� ���� ����
    Direction nextDirection = decideDirection();

    /* TODO : ������ ���⿡ ���� m_localInfo ��ġ �̵� */

    /* TODO : localInfo ���� �ǽð� ������Ʈ */
}

void HumpbackWhaleMP::timeElapse()
{
    // ���� �ð� ���� : 3��
    m_timer.addDay(3);
}

Direction HumpbackWhaleMP::decideDirection()
{
    // TODO : ���� �߻� �ʿ�
    // 9������ Ȯ���� ���� �������� ��ġ ����

    /* return Direction::DECIDED_DIRECTION ! */
}

#pragma endregion

#endif // _HUMPBACK_WHALE_MOVEMENT_PREDICTION_HPP__