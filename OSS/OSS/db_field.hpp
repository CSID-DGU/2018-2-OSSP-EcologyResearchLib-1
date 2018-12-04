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

#define MAX_FIELD_WIDTH_SIZE 40
#define MAX_FIELD_HEIGHT_SIZE 40


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
	LocalInfo localInfo[MAX_FIELD_WIDTH_SIZE][MAX_FIELD_HEIGHT_SIZE]; // Map array 
	Timer * m_timer; // Global Time

public:
	FieldDataBase(); // constructor
	~FieldDataBase(); // destructor

	void updateGlobalState(); // Update whole Local State
	void updateLocalState(int x, int y); // Update each local state

	void updateOrganismList(int x, int y); // Update Organism list of location

	LOCALSTATE getLocalState(int x, int y);
	std::vector<Organism>* getOrganismList(int x, int y);

	// DB Load
	virtual void readDB(std::string fileName); // read DB file
	void loadLocationName(char* name); // Load Location name from DB
	void loadTime(char* time);	// Load Location time from DB
	void loadLocationFeature(); // Load Location feature from DB
};

#pragma region FieldDataBase_CONSTRUCTOR

FieldDataBase::FieldDataBase()
{
	m_timer = new Timer();
}

#pragma endregion

#pragma region FieldDataBase_DESTRUCTOR

FieldDataBase::~FieldDataBase()
{
	delete[] m_timer;
}

#pragma endregion


#pragma region FieldDataBase_UPDATE
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


#pragma region FieldDataBase_INFORMATION
LOCALSTATE FieldDataBase::getLocalState(int x, int y)
{
	// to do
	return LOCALSTATE();
}

std::vector<Organism>* FieldDataBase::getOrganismList(int x, int y)
{
	// to do
	return NULL;
}
#pragma endregion


#pragma region FieldDataBase_FILEIO
void FieldDataBase::readDB(std::string fileName)
{
	using namespace std;
	
	char readData[MAX_STRING]; // data line

	// file open to stream
	ifs.open(fileName);

	// Location name read
	// loadLocationName();
	

	// Location time read
	ifs.getline(readData, MAX_STRING);
	if (readData == "<Location Time>")
	{
		ifs.getline(readData, MAX_STRING);
		loadTime(readData);
		ifs.getline(readData, MAX_STRING); // endLine
	}

	else
	{
		ifs.close();
		return;
	}


	// Location feature data read
	ifs.getline(readData, MAX_STRING);
	if (readData != "<Location Info>")
	{
		ifs.close();
		return;
	}

	while (!ifs.eof())
	{
		

	}

	// file close
	ifs.close();
}

void FieldDataBase::loadLocationName(char* name)
{
	ifs.getline(name, MAX_STRING);
	if (readData == "<Location Name>")
	{
		ifs.getline(readData, MAX_STRING);
		loadLocationName(readData);
		ifs.getline(readData, MAX_STRING); // endLine
	}

	else
	{
		ifs.close();
		return;
	}
}

void FieldDataBase::loadTime(char* time)
{
	m_timer->setTime(time);
}

void FieldDataBase::loadLocationFeature()
{

}

#pragma endregion
