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


// Ȥ���(Humpback Whale) �̵���� ����(MP) �˰���
class HumpbackWhaleMP : public MovementPrediction
{
/*
protected:
    Location& m_location; // �ʱ� Location( �迭�� 0�� �ε��� )
    int m_predictCount;   // ���� ��ƾ ���� Ƚ��
*/

private:
    // ������Ŀ �迭 = ������ �̵� ���
	std::vector<RandomWalk> m_randomWalk; 

public:
    virtual void initiate() override;
    virtual void predict() override;

    // 9������ Ȯ�� ��� �޼ҵ�
    void calculate();
};

void HumpbackWhaleMP::initiate()
{
    m_randomWalk.push_back(RandomWalk());   // ������Ŀ �迭�� 0�� ��ü �ʱ�ȭ

    //To Do
}

void HumpbackWhaleMP::predict()
{
    // �� �� ����� ������, ���� ��Ŀ ��ü�� �ϳ� �����Ͽ� ���Ϳ� �߰��Ѵ�.

    //To Do
}

void HumpbackWhaleMP::calculate()
{
    // 9���� ������ ���� �̵� Ȯ���� ����Ѵ�.
    // predict() ���ο��� ����ȴ�.

    //To Do
}

#endif // _HUMPBACK_WHALE_MOVEMENT_PREDICTION_HPP__