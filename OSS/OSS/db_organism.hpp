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


[ OrgDataBase ]

<Explanation>
- 생명체의 기본 속성을 가진 DB API 클래스
- 최대한 모든 생명체들이 공통적으로 가질 수 있는 특성만을 보유

- 이 DB를 멤버로 가진 Organism 클래스가 있다.
- 더 추가되는 생명체의 속성은

<To do>
...

*/

#pragma once
#include "db_origin.hpp"
#include "db_preference.hpp"

class Organism;

// Organism status
enum STATUS { ALIVE, DEAD, HIBERNATION, STEALTH, SUBMERGENCE, FLOATING, BREEDING };
enum ACTION { MOVING, HUNTING, MATING, STOPED, SLEEPING, 
	          EATING, DIVING, SPOUTING, RESTING };
enum SEX    { MALE, FEMALE, BOTH };

struct OrgDBStruct
{
	std::string name;	// Organism's Name
	int age;			// Organism's Age
	SEX sex;			// Organism's sex
	unsigned energy;    // energy % for survive

	std::vector<STATUS> status;  // Current Status list
	std::vector<ACTION> action;	 // Current action

	Preference* prefer;			 // preference of a organism

	// These datas are Determined by field DB
	int xPoint, yPoint;  // coordinates of organism at location
	Position position;   // Current geographical position
};

class OrgDataBase : public DataBase
{
public:
	// Constructor
	OrgDataBase();

	// Destructor
	~OrgDataBase();

	// Setter
	void setName(const std::string& name);			// Set Organism's name
	void setAge(const int& age);				    // Set Organism's age
	void setSex(const SEX& sex);					// Set Organism's sex
	void setEnergy(const int& enerngy);				// Set Organism's energy
	void setStatus(const std::string& status);		// Set Organism's status
	void setAction(const std::string& action);		// Set Organism's action
	void setPreference();							// Set Organism's Preference

	// void setPosition(Position pos) { m_Position = pos; }
	

	// Getter
	int getAge() const { return m_Age; }
	int getSex() const { return m_Sex; }
	std::vector<STATUS> getStatus() const { return m_Status; }
	ACTION getAction() const { return m_Action; }
	Position getPosition() const { return m_Position; }
	std::vector<Organism> getPreyList() const { return m_Prey; }

	// File I/O
	virtual void readDB(const char* fileName) override;
	void loadName(std::string& readData);
	void loadAge(std::string& readData);
	void loadSex(std::string& readData);
	void loadEnergy(std::string& readData);
	void loadStatus(std::string& readData);
	void loadAction(std::string& readData);
	void loadPreference(std::string& readData);

	SEX convertSexData(const std::string& readData);
	STATUS convertStatusData(const std::string& readData);
	ACTION convertActionData(const std::string& readData);

	void parsingStatusData(const std::string& readData, std::vector<STATUS>& statusVec);
	void parsingActionData(const std::string& readData, std::vector<ACTION>& actionVec);

private:
	OrgDBStruct* organismInfo;
};


class Organism
{
private:
	OrgDataBase* m_ODB;

public:
	// Constructor
	Organism();

	// Destructor
	virtual ~Organism();

	// Setter
	void setOrganismInfo(const char* fileName);

	// Getter


	// Moving
	// virtual void moving() = 0;
};


#pragma region OrgDataBase_Constructor
OrgDataBase::OrgDataBase()
{
	organismInfo = new OrgDBStruct();
}
#pragma endregion

#pragma region OrgDataBase_Destructor
OrgDataBase::~OrgDataBase()
{
	delete[] organismInfo;
}
#pragma endregion

#pragma region OrgDataBase_Setter
void OrgDataBase::setName(const std::string& name)
{
	organismInfo->name = name;
}

void OrgDataBase::setAge(const int& age)
{
	organismInfo->age = age;
}

void OrgDataBase::setSex(const SEX& sex)
{
	organismInfo->sex = sex;
}

void OrgDataBase::setEnergy(const int& enerngy)
{
	organismInfo->energy = enerngy;
}

void OrgDataBase::setStatus(const std::string& status)
{
	parsingStatusData(status, organismInfo->status);
}

void OrgDataBase::setAction(const std::string& action)
{
	parsingActionData(action, organismInfo->action);
}

void OrgDataBase::setPreference()
{
	organismInfo->prefer = new Preference();
}

#pragma endregion

#pragma region OrgDataBase_FILEIO
void OrgDataBase::readDB(const char* fileName)
{
	std::string readData;
	readFileOpen(fileName);

	loadName(readData);
	loadAge(readData);
	loadSex(readData);
	loadEnergy(readData);
	loadStatus(readData);
	loadAction(readData);
	loadPreference(readData);
	
	readFileClose();
}

void OrgDataBase::loadName(std::string& readData)
{
	getDBLine(readData);
	setName(readData);
}

void OrgDataBase::loadAge(std::string& readData)
{
	getDBLine(readData);
	setAge(stoi(readData));
}

void OrgDataBase::loadSex(std::string& readData)
{
	getDBLine(readData);
	setSex(convertSexData(readData));
}

void OrgDataBase::loadEnergy(std::string& readData)
{
	getDBLine(readData);
	setEnergy(stoi(readData));
}

void OrgDataBase::loadStatus(std::string& readData)
{
	getDBLine(readData);
	setStatus(readData);
}

void OrgDataBase::loadAction(std::string& readData)
{
	getDBLine(readData);
	setAction(readData);
}

void OrgDataBase::loadPreference(std::string& readData)
{
	getDBLine(readData);
	setPreference();
}

SEX OrgDataBase::convertSexData(const std::string& readData)
{
	if (readData == "M")			return MALE;
	else if (readData == "F")		return FEMALE;
	else if (readData == "BOTH")	return BOTH;
	else fprintf(stderr, "Converting ERROR!!\n");
}

STATUS OrgDataBase::convertStatusData(const std::string& readData)
{
	if (readData == "ALIVE") return ALIVE;
	else if (readData == "DEAD") return DEAD;
	else if (readData == "HIBERNATION") return HIBERNATION;
	else if (readData == "STEALTH") return STEALTH;
	else if (readData == "SUBMERGENCE") return SUBMERGENCE;
	else if (readData == "HIBERNATION") return HIBERNATION;
	else if (readData == "FLOATING") return FLOATING;
	else if (readData == "BREEDING") return BREEDING;
	else fprintf(stderr, "Converting ERROR!!\n");
}

ACTION OrgDataBase::convertActionData(const std::string& readData)
{
	if (readData == "MOVING") return MOVING;
	else if (readData == "HUNTING") return HUNTING;
	else if (readData == "MATING") return MATING;
	else if (readData == "STOPED") return STOPED;
	else if (readData == "SLEEPING") return SLEEPING;
	else if (readData == "EATING") return EATING;
	else if (readData == "DIVING") return DIVING;
	else if (readData == "SPOUTING") return SPOUTING;
	else if (readData == "RESTING") return RESTING;
	else fprintf(stderr, "Converting ERROR!!\n");
}

void OrgDataBase::parsingStatusData(const std::string& readData, std::vector<STATUS>& statusVec)
{
	std::string parsedStr = "";

	for (auto& ch : readData)
	{
		if (ch != ' ')
			parsedStr += ch;

		else
		{
			statusVec.push_back(convertStatusData(parsedStr));
			parsedStr.resize(0);
		}
	}
	statusVec.push_back(convertStatusData(parsedStr));
}

void OrgDataBase::parsingActionData(const std::string& readData, std::vector<ACTION>& actionVec)
{
	std::string parsedStr = "";

	for (auto& ch : readData)
	{
		if (ch != ' ')
			parsedStr += ch;

		else
		{
			actionVec.push_back(convertActionData(parsedStr));
			parsedStr.resize(0);
		}
	}
	actionVec.push_back(convertActionData(parsedStr));
}

#pragma endregion

///////////////////////////////////////////////////////////////////////////////

#pragma region Organism_CONSTRUCTOR

Organism::Organism()
{
	m_ODB = new OrgDataBase();
}
#pragma endregion 

#pragma region Organism_DESTRUCTOR

Organism::~Organism()
{
	delete[] m_ODB;
}
#pragma endregion 

#pragma region Organism_SETTER

void Organism::setOrganismInfo(const char* fileName)
{
	m_ODB->readDB(fileName);
}
#pragma endregion