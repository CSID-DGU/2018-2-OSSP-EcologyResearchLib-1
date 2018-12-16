/* 

******************************************************
					MIT License
			Copyright (c) 2018 CSID-DGU
******************************************************


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
	Point p;  // coordinates of organism at location
	Position position;   // Current geographical position
};

class OrgDataBase : public DataBase
{
public:
	// Constructor
	OrgDataBase();

	// Destructor
	~OrgDataBase();

	// File I/O
	virtual void readDB(std::string& fileName) override;
	void loadName(std::string& readData);
	void loadAge(std::string& readData);
	void loadSex(std::string& readData);
	void loadEnergy(std::string& readData);
	void loadStatus(std::string& readData);
	void loadAction(std::string& readData);
	void loadPreferLocalState(std::string& readData);
	void loadPreferPreyList(std::string& readData);

	SEX convertSexData(const std::string& readData);
	STATUS convertStatusData(const std::string& readData);
	ACTION convertActionData(const std::string& readData);
	LOCALSTATE convertLocalStateData(const std::string& readData);

	void parsingStatusData(const std::string& readData, std::vector<STATUS>& statusVec);
	void parsingActionData(const std::string& readData, std::vector<ACTION>& actionVec);
	void parsingLocalStateData(const std::string& readData, Preference* prefer);
	void parsingPreyListData(const std::string& readData, Preference* prefer);

	void completeCheck(const std::string& errMsg);
	

	// Setter
	void setName(const std::string& name);			 // Set Organism's name
	void setAge(const int& age);				     // Set Organism's age
	void setSex(const SEX& sex);					 // Set Organism's sex
	void setEnergy(const int& enerngy);				 // Set Organism's energy
	void setStatus(const std::string& status);		 // Set Organism's status
	void setAction(const std::string& action);		 // Set Organism's action
	void setPreferLocalState(const std::string& readData); 
													// Set Organism's prefer local state					
	void setPreferPreyList(const std::string& readData);
													// Set Organism's prefer prey list
	void setPoint(Point p);							// Set orfanism's point in map
													
	// void setPosition(Position pos) { m_Position = pos; }
	

	// Getter
	std::string getName();
	Position getPosition();
	Point getPoint();

private:
	OrgDBStruct* organismInfo;
};


class Organism
{
protected:
	OrgDataBase* m_ODB;

public:
	
	// Constructor
	Organism();

	// Destructor
	virtual ~Organism();

	// Setter
	void setOrganismInfo(std::string& fileName);

	// Getter
	std::string getOrganismName();
	Position getOrganismPosition();
	Point getPoint();

	// Moving
	// virtual void moving() = 0;
};


#pragma region OrgDataBase_Constructor
OrgDataBase::OrgDataBase()
{
	organismInfo = new OrgDBStruct();
	organismInfo->prefer = new Preference();
}
#pragma endregion

#pragma region OrgDataBase_Destructor
OrgDataBase::~OrgDataBase()
{
	delete[] organismInfo;
}
#pragma endregion

#pragma region OrgDataBase_FILEIO
void OrgDataBase::readDB(std::string& fileName)
{
	//debug
	std::cout << "OrgDataBase::readDB Start" << std::endl;

	std::string readData;
	readFileOpen(fileName);
	loadName(readData);
	loadAge(readData);
	loadSex(readData);
	loadEnergy(readData);
	loadStatus(readData);
	loadAction(readData);
	loadPreferLocalState(readData);
	loadPreferPreyList(readData);

	readFileClose();
}

void OrgDataBase::loadName(std::string& readData)
{
	getDBLine(readData);
	setName(readData);
	completeCheck("LOAD NAME COMPLETE");
}

void OrgDataBase::loadAge(std::string& readData)
{
	getDBLine(readData);
	setAge(stoi(readData));
	completeCheck("LOAD AGE COMPLETE");
}

void OrgDataBase::loadSex(std::string& readData)
{
	getDBLine(readData);
	setSex(convertSexData(readData));
	completeCheck("LOAD SEX COMPLETE");
}

void OrgDataBase::loadEnergy(std::string& readData)
{
	getDBLine(readData);
	setEnergy(stoi(readData));
	completeCheck("LOAD ENERGY COMPLETE");
}

void OrgDataBase::loadStatus(std::string& readData)
{
	getDBLine(readData);
	setStatus(readData);
	completeCheck("LOAD STATUS COMPLETE");
}

void OrgDataBase::loadAction(std::string& readData)
{
	getDBLine(readData);
	setAction(readData);
	completeCheck("LOAD ACTION COMPLETE");
}

void OrgDataBase::loadPreferLocalState(std::string& readData)
{
	getDBLine(readData);
	setPreferLocalState(readData);
	completeCheck("LOAD LOCALSTATE COMPLETE");
}


void OrgDataBase::loadPreferPreyList(std::string& readData)
{
	getDBLine(readData);
	setPreferPreyList(readData);
	completeCheck("LOAD PREYLIST COMPLETE");
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

LOCALSTATE OrgDataBase::convertLocalStateData(const std::string& readData)
{
	if (readData == "GROUND") return GROUND;
	else if (readData == "SEA") return SEA;
	else if (readData == "AIR") return AIR;
	else if (readData == "NONE") return NONE;
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

void OrgDataBase::parsingLocalStateData(const std::string& readData, Preference* prefer)
{
	std::string parsedStr = "";
	LOCALSTATE localState[3];

	std::cout << readData << std::endl;

	int ix = 0;
	for (auto& ch : readData)
	{
	//	std::cout << "ch : " << ch << std::endl;

		if (ch != ' ')
			parsedStr += ch;

		else
		{
			// debug
			std::cout << "parsingLocalStateData::parsedStr = "<<parsedStr << std::endl;

			localState[ix] = convertLocalStateData(parsedStr);
			ix++;
			parsedStr.resize(0);
		}
	} 
	localState[ix] = convertLocalStateData(parsedStr);

	prefer->setLocalState(localState);
}

void OrgDataBase::parsingPreyListData(const std::string& readData, Preference* prefer)
{
	std::string parsedStr = "";

	for (auto& ch : readData)
	{
		if (ch != ' ')
			parsedStr += ch;

		else
		{
			prefer->setPreyList(parsedStr);
			parsedStr.resize(0);
		}
	} 
}

void OrgDataBase::completeCheck(const std::string& errMsg)
{
	std::cout << errMsg << std::endl;
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

void OrgDataBase::setPreferLocalState(const std::string& readData)
{
	parsingLocalStateData(readData, organismInfo->prefer);
}

void OrgDataBase::setPreferPreyList(const std::string& readData)
{
	parsingPreyListData(readData, organismInfo->prefer);
}

#pragma endregion


#pragma OrgDataBase_Getter
std::string OrgDataBase::getName()
{
	return organismInfo->name;
}

Position OrgDataBase::getPosition()
{
	return organismInfo->position;
}

#pragma endregion


///////////////////////////////////////////////////////////////////////////////////

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

void Organism::setOrganismInfo(std::string& fileName)
{
	// debug
	std::cout << "Organism::setOrganismInfo start" << std::endl;

	m_ODB->readDB(fileName);
	
	// debug
	std::cout << "Organism::setOrganismInfo complete" << std::endl;
}
#pragma endregion

#pragma region Organism_Getter
std::string Organism::getOrganismName()
{
	return m_ODB->getName();
}

Position Organism::getOrganismPosition()
{
	return m_ODB->getPosition();
}

Point Organism::getPoint()
{
	return m_ODB->getPoint();
}

#pragma endregion