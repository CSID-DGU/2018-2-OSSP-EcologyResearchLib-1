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
Coded by : Jong Ha Sin
Last Updated : 18-11-05


[ FieldDataBase ]

<Explanation>

@ ��ǥ�� - ����
: ����� ���� ���� ��ǥ��(���� ���� ������ ��´�)
- �������� �����̹Ƿ� ������ �迭�� �̷����

- �� ��ǥ�� ���� ������
  1) ���� ����+�浵(+��)
  2) ������ Ư��(����/�ٴ�, Ȥ�� �̵� ����/�Ұ��� ����
	=> e.g. �ؾ� ������ �������� �̵� �Ұ���
    -> ����/�ٴ� ������ �����͸� ����ϰ�  �̵� ����/�Ұ��� ���δ� ������ �����Ͽ� �Ǵ�)
  3) ����
  4) ���� ����ü �迭

@ Timer - �ð� 
 : �˰��� Ȱ��� ���� �ð� ������ ���� �� ó���Ѵ�.


<To do>
void updateGlobalState(); // Update whole Local State
void updateLocalState(int x, int y); // Update each local state
������ũ�� �������� ���� ���� ���°� ������Ʈ �Ǿ���Ѵ�.

*/

#pragma once
#include "db_origin.hpp"
#include "db_timer.hpp"
#include "db_environment.hpp"
#include "db_organism.hpp"

#define MAX_FIELD_WIDTH_SIZE 1000
#define MAX_FIELD_HEIGHT_SIZE 1000


struct LocalInfo
{
	LOCALSTATE localState[3] = { NONE, NONE, NONE }; // AIR, SEA, GROUND
	Position pos;	// Real value of Position in earth
	Environment environment;	// Environment information for algorithm
	std::vector<Organism>* organisms; // Organism list for algorithm
};

class FieldDataBase : public DataBase
{
private:
	Environment* localEnvirnment;
	LocalInfo localInfo[MAX_FIELD_WIDTH_SIZE][MAX_FIELD_HEIGHT_SIZE]; // Map array 

public:
	FieldDataBase()
	{
		
	}

	~FieldDataBase()
	{

	}

	void updateGlobalState(); // Update whole Local State
	void updateLocalState(int x, int y); // Update each local state

	void updateOrganismList(int x, int y); // Update Organism list of location

	LOCALSTATE getLocalState(int x, int y);
	std::vector<Organism>* getOrganismList(int x, int y);
};



#pragma region LOCATION_UPDATE
void FieldDataBase::updateGlobalState()
{
	// TO Do
}

void FieldDataBase::updateLocalState(int x, int y)
{
	// TO DO 
}

void FieldDataBase::updateOrganismList(int x, int y)
{
	// to do
}

#pragma endregion


#pragma region LOAD_INFORMATION
LOCALSTATE FieldDataBase::getLocalState(int x, int y)
{
	// to do
}

std::vector<Organism>* FieldDataBase::getOrganismList(int x, int y)
{
	// to do
}
#pragma endregion
