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
#include <string>

#define MAX_FIELD_WIDTH_SIZE 40
#define MAX_FIELD_HEIGHT_SIZE 40


struct LocalInfo
{
	Position pos;	// Real value of Position in earth
	LOCALSTATE localState[3] = { NONE, NONE, NONE }; // GROUND, AIR, SEA
	Environment environment;	// Environment information for algorithm
	std::vector<Organism>* organisms; // Organism list for algorithm
};

class FieldDataBase : public DataBase
{
private:
	std::string localName; // Local name
	LocalInfo localInfo[MAX_FIELD_WIDTH_SIZE][MAX_FIELD_HEIGHT_SIZE]; // Programmed map array 
	Timer * m_timer; // Local Time

public:
	FieldDataBase(); // constructor
	~FieldDataBase(); // destructor

	void updateGlobalState(); // Update whole Local State
	void updateLocalState(int x, int y); // Update each local state

	void updateOrganismList(int x, int y); // Update Organism list of location

	// Setter
	void setLocalName(std::string name); // set local name from DB
	void setLocalTime(std::string time); // set local time from DB

	// Getter
	LOCALSTATE getLocalState(int x, int y);
	std::vector<Organism>* getOrganismList(int x, int y);
	std::string getLocalName(); // get local name from object
	std::string getLocalTime(); // get local time form object

	// DB Load
	virtual void readDB(const char* fileName); // read DB file
	void loadLocationName(std::string& readData); // Load Location name from DB
	void loadTime(std::string& readData);	// Load Location time from DB
	void loadLocationFeature(std::string& readData); // Load Location feature from DB
	void parsingFeatures(std::vector<std::string>& parsingVec, 
						       const std::string& readData);
								// Parsing location features read from DB
	void getDBLine(std::string& readData);  // Read a line from DB
	bool isLocationName(const std::string& name); // check location name Data or not
	bool isLocationTime(const std::string& time); // check location time data or not
	bool isLocationFeature(const std::string& feature); // check location feature or not
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


#pragma region FieldDataBase_SETTER
void FieldDataBase::setLocalName(std::string name)
{
	localName = name;
}

void FieldDataBase::setLocalTime(std::string time)
{
	m_timer->setTime(time);
}

#pragma endregion

#pragma region FieldDataBase_GETTER
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

std::string FieldDataBase::getLocalName()
{
	return localName;
}

std::string FieldDataBase::getLocalTime()
{
	return m_timer->getTimeString();
}

#pragma endregion


#pragma region FieldDataBase_FILEIO
void FieldDataBase::readDB(const char* fileName)
{
	std::string readData; // data line
	
	// file open to stream
	ifs.open(fileName);

	// Location name read
	loadLocationName(readData);
	
	// Location time read
	loadTime(readData);

	// Location feature data read
	loadLocationFeature(readData);

	// file close
	ifs.close();
}

void FieldDataBase::loadLocationName(std::string& readData)
{
	getDBLine(readData);
	assert(isLocationName(readData) && "Load Location Name Error\n");

	getDBLine(readData);
	setLocalName(readData);
}

void FieldDataBase::loadTime(std::string& readData)
{
	getDBLine(readData);
	assert(isLocationTime(readData) && "Load location time error\n");


	getDBLine(readData);
	setLocalTime(readData);
}

void FieldDataBase::loadLocationFeature(std::string& readData)
{
	std::vector<std::string> parsingVec;
	getDBLine(readData);
	assert(isLocationFeature(readData) && "Load location Feature error\n");

	while (!ifs.eof())
	{
		getDBLine(readData);
		parsingFeatures(parsingVec, readData); // parsing feature data line
		
		// debug
		for (auto& str : parsingVec)
		{
			std::cout << str << std::endl;
		}

		// setup Programmed coordinate
		int x = stoi(parsingVec[0]);
		int y = stoi(parsingVec[1]);
		
		// setup Postion
		localInfo[x][y].pos.altitude = parsingVec[2];
		localInfo[x][y].pos.altitude = parsingVec[3];
		localInfo[x][y].pos.altitude = "0"; // default

		// setup topoGraphic features
		localInfo[x][y].localState[0] = parsingVec[4];

		// setup Enviornment Watertemperature 
		localInfo[x][y].environment.setWaterTemperature(stoi(parsingVec[4]));
		
		// setup Organism List

		parsingVec.clear();
	}

}

void FieldDataBase::getDBLine(std::string& readData)
{
	getline(ifs, readData);
}

void FieldDataBase::parsingFeatures(std::vector<std::string>& parsingVec, const std::string& readData)
{
	std::string parsedStr = "";

	// Parsing
	for (auto& ch : readData)
	{
		if (ch != ' ')
			parsedStr += ch;

		else
		{
			parsingVec.push_back(parsedStr);
			parsedStr.resize(0);
		}
	}
	parsingVec.push_back(parsedStr); // last element pushing
}


bool FieldDataBase::isLocationName(const std::string& name)
{
	return (name == "<Location Name>");
}

bool FieldDataBase::isLocationTime(const std::string& time)
{
	return (time == "<Location Time>");
}

bool FieldDataBase::isLocationFeature(const std::string& feature)
{
	return (feature == "<Location Feature>");
}




#pragma endregion
