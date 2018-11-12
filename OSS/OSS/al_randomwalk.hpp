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
Coded by : 
Last Updated : 18-11-05


[ RandomWalk ]

<Explanation>
- ���� �����͸� ������� ������ ���� ��Ŀ

- ���� ��Ŀ�� ���� ������
  1) ���� ����(organism ��ü)
  2) ���� ����(���, ¦����, ��, ��� => ���� �����κ��� �޾ƿ��ų�, ���� ������ ����)
  3) ���� ��¥+�ð�
  4) ���� ��ǥ(����+�浵)
  5) 9���� ������ �̵� Ȯ��(�⺻ �� : ���� 0%)

=> �ð��� ��ǥ �����Ͱ� ���� �¹��� �̵� ��� �����͸� ǥ��



[���� ��Ŀ - �̵� ��ȣ ����]

1. ����
 - ����/�ٴ�, �̵� ����/�Ұ���, ��ü�� ���� Ư���� ���� ���� Ȯ�� ����

 => ������ ���� ����, ������Ŀ�� Ȯ�� ��� �� �ش� �������� �о����


2. ���Ļ���
 - �ش� ������ �����ϴ� �����ڿ� ���� �̵� Ȯ�� ����,
	���̿� ���� �̵� Ȯ�� ����

 => ���������� ������ ���� ����,
	  ���������� ������ ���� ���Ļ��� ������ ��ȭ�� �ʿ䰡 ����


3. �ñ�
 - ����(Ȥ�� ����)�� ���� �Ը��� �̵� ���⼺�� �ľǵȴٸ�
	�ش� ������ �����Ͽ� Ȯ�� ����
 - ����� �� Ư�� �ñ⿡ ���� ��ǥ ���������� �̵� ���ɼ� ����

 => ������Ŀ Ȯ�� ��� ��
	  1) �ñ⿡ ���� �̵� ���⼺ ���� �о����
		  (���ο� �ڷᱸ�� ���� �ʿ�,
		   �ñ⺰ �ֿ� �̵� ��ǥ�� �Ǵ� ���� �� ����/���� Ȯ���� ���� ������)
	  2) ���� ��ġ�� �ش� ���������� ������ ���
	  3) �ش� ������ Ȯ�� ����


4. �ð�
 - ��/��, Ȥ�� Ư�� �ð��� ���� �̵� ���⼺�� �����Ѵٸ�
	�ش� ������ �����Ͽ� Ȯ�� ����

=> ���������� �ð��� ���� �̵� ���⼺ ������ ���� �� �о����


(5. ����)
 - ȭ��, ��ǳ �� �ڿ����ط� ���� �̵� ���⼺ ���� 
 - ���� ���� 
 �̴� ��Ȯ�� ������ �����Ƿ� ���Ŀ� ����


6. ������ (�ټ��� ��ȣ ���ο� ���������� ����)
 - �ֿ� ���������� �̵�, ��Ը� ���� ��
	 �и��� �������� ���� �̵��ϴ� ���⼺�� �߰ߵ� ���
	 ���� ��ġ�κ��� �ش� �������� ���ϴ� ���⿡ ���� Ȯ�� �߰� �ο�


* �ñ�, �ð�, ������ �� ����ȭ ������ ������ ������ ���
 - �ش� ������ �����ͺ��̽��� ����
 - ������Ŀ�� Ȯ������� �� �����ͺ��̽����� �ҷ�����
 - �ð� ������(�ð� �� ������ �������� ���ǽ� �̿�)
 - ���� ������(�������� ���� ��ǥ)
 - Ȯ�� ����(������Ŀ�� ��ٷ� ������ֱ� ����)




<To do>

[���α׷� ����]

1. ��ǥ ���� ����
2. �ʿ��� ������ ��ǥ �����͵��� �ʱ�ȭ

3. ���� ��Ŀ ��ü�� ���� ���͸� ����
4. ���� ��Ŀ ������ �ʱ� ��ü ����
5. ��ǥ ���� �̿���, ���� ��Ŀ ù ��° ��ü�� ��ǥ ������ �ʱ�ȭ
6. ���� ��Ŀ ��ü�� ��¥/�ð� ������ �ʱ�ȭ
7. ���� ��Ŀ ��ü�� ���� ��ǥ�κ��� �������ִ�, �� 8���� ��ǥ ������ �������� �̿���
	���� ��Ŀ ��ü�� 8���� ������ �̵� Ȯ�� ����
8. ���� ���¸� �����Ͽ� �̵� Ȯ�� �߰� ����
9. �ʿ��� ��ҵ��� �ִٸ�(e.g. ����, �ð�, ������ ������, ��Ÿ ���) �����Ͽ�
	�̵� Ȯ�� �߰� ����
   ( * �ѷ��� �������� ������ �� �ִ� ���(���� �����͵��� ����, e.g. ��Ģ�� �̵� ��) :
		 ���� ��ǥ�κ��� �ش� �������� ���ϴ� ���⿡ �̵� Ȯ���� ���� ������ )

10. ���� ��Ŀ �� ��° ��ü ����
11. ���� ��Ŀ �ʱ� ��ü�� �̵� Ȯ�� �����͸� �����Ͽ� �̵� ���� ���� ��,
	  �̵� ���⿡ ���� �� ĭ �̵��� ��ǥ�� �� ��° ��ü�� ��ǥ ������ �ʱ�ȭ
12. �ش� ������ ����� �̵� �ӵ�, �ʱ� ��ġ������ ����, ��Ÿ ��� ���� �� �����ؼ�
	  �� ��° ��ü�� ��¥/�ð� ������ �ʱ�ȭ
13. �� ��° ��ü�� ���Ͽ� 7~9 ���� ����
14. 10~13 �ݺ�


- al_humpback_whale.hpp ���� ���� ����

*/

#pragma once

#include "db_organism.hpp"
#include "al_algorithm.hpp"

class RandomWalk
{
public:
	RandomWalk();
	~RandomWalk() {};

	void setMovingPossibility(const float& pArray);
	RW_POSSIBILITY getMovingPossibility();

	void randomWalk(const Location& loc); // randomWalk algorithm

private:
	float possibility[DIRECTION_NUMBER] = { 0 };
	// Moving possibility , 9 Direction
};


#pragma region RANDOM_WALK_POSSIBILITY
void RandomWalk::setMovingPossibility(const float& pArray)
{
	// To do
}

float* RandomWalk::getMovingPossibility()
{
	// To do
}
#pragma endregion


#pragma region RANDOMWALK_CONSTRUCTOR
RandomWalk::RandomWalk()
{
	// TO do
}

#pragma endregion


#pragma region RANDOMWALK_ALGORITHM
void RandomWalk::randomWalk(const Location& loc)
{
	// to do
}
#pragma endregion