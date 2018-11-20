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
 - ������ �ൿ�� "����"�ϴ� �˰����� �ֻ��� Ŭ����
 - �Է� : �ʵ�, ���� ����(�з�, ����, ���ݱ����� �̵� ���), ������ �Ⱓ
 - ���� : ���� ������ ref�� �Է¹޾� ������ �Ⱓ��ŭ�� �̵� ��θ� �����Ͽ�
		���� ���� �� �̵� ��ο� �߰�
 - ��� : ����

 <To do>
 - ��� Ŭ�������� "�̵� ��� ����" ����
 - Organism�� ���� ��ü��(ex> ��)�� �Է¹޾Ƽ� 
   ���ݱ����� �����͵��� �������� �������� �����͸� �����Ͽ� ����
 - ������ �ð� �������� ����� �����͵��� ��������
   ���� ������ �ð� ���� ���� �����͸� �߰�(&�� �����Ͽ� ������Ʈ)
   
   ���� ���, 1�� 2�� 3���� ������ ���� �־����� 
   �ܼ� �޼ҵ� ȣ�� �� 4���� ���� �ϳ��� ����
   1, 2, 3�� ���� ���� ���¿��� 8���� ������ ��� ������
   4, 5, 6, 7, 8���� ���� ��� �����Ͽ� ��ü�� ����

*/


#ifndef _ALGORITHM_H__
#define _ALGORITHM_H__

#include "location_origin.hpp"
#include "al_randomwalk.hpp"

// ���� �̵���� ���� �˰���
// �������̽��� �����ϸ�,
// ���� �˰����� �� �������� �����Ѵ�.
class MovementPrediction
{

public:
    // �� �ð� ������ ����
    virtual void predictByHour(Location& loc ,Organism& organism) = 0;

    // �Ϸ� ������ ����
    // 24�ð����� ��ȯ�Ͽ� �˰��� ����
    // �Ǵ� (������ ����) �ð� ���� ��� �Ϸ� ������ �⺻���� ���
    virtual void predictByDay (Location& loc, Organism& organism)  = 0;
};


#endif // _ALGORITHM_H__
