/* 

******************************************************
					MIT License
			Copyright (c) 2018 CSID-DGU
******************************************************

Coded by : Jong Ha Sin
Last Updated : 18-12-11


[ FieldDataBase ]

<Explanation>

@ 좌표계 - 지도
: 충분히 넓은 지도 좌표계(실제 지형 정보를 담는다)
- 이차원의 지도이므로 이차원 배열로 이루어짐

- 각 좌표가 갖는 데이터
  1) 실제 위도+경도(+고도)
  2) 지형의 특성(육지/바다, 혹은 이동 가능/불가능 여부
	=> e.g. 해양 생물은 육지에서 이동 불가능
    -> 육지/바다 정도의 데이터만 기록하고  이동 가능/불가능 여부는 생물과 결합하여 판단)
  3) 기후
  4) 서식 생명체 배열

@ Timer - 시간 
 : 알고리즘에 활용될 지역 시간 연산을 저장 및 처리한다.


<To do>
void updateGlobalState(); // Update whole Local State
void updateLocalState(int x, int y); // Update each local state
랜덤워크와 딥러닝을 위해 지역 상태가 업데이트 되어야한다.

*/

#pragma once
#include "db_origin.hpp"
#include "db_timer.hpp"
#include "db_organism.hpp"
#include "db_environment.hpp"
#include "tax_species.hpp"

#define MAX_FIELD_WIDTH_SIZE 20
#define MAX_FIELD_HEIGHT_SIZE 20


struct LocalInfo
{
	Position pos;	// Real value of Position in earth
	LOCALSTATE localState[3] = { NONE, NONE, NONE }; // GROUND, AIR, SEA
	Environment environment;		  // Environment information for algorithm
	std::vector<Organism*> localOrganisms; // local Organism list for algorithm
};

class FieldDataBase : public DataBase
{
private:
	std::string localName; // Local name
	LocalInfo localInfo[MAX_FIELD_WIDTH_SIZE][MAX_FIELD_HEIGHT_SIZE]; // Programmed map array 
	std::vector<Organism*> organismList; // all organisms of this area
	Timer * m_timer; // Local Time
	

public:
	FieldDataBase(); // constructor
	~FieldDataBase(); // destructor

	// DB Load
	virtual void readDB(std::string& fileName) override; // read DB file
	void loadLocationName(std::string& readData);		// Load Location name from DB
	void loadTime(std::string& readData);				// Load Location time from DB
	void loadLocationFeature(std::string& readData);	// Load Location feature from DB
	void loadOrganisms(std::string& readData);			// Load location organisms from DB
	void parsingFeatures(const std::string& readData, std::vector<std::string>& parsingVec);
												  // Parsing location features read from DB
	LOCALSTATE convertTopoGraphic(const std::string& feature); // Convert string data 
															   // to (enum) LOCALSTATE
	// void createOrganismList(int x, int y);		  // Create organism list to targeted map 
	bool isLocationName(const std::string& name); // check location name Data or not
	bool isLocationTime(const std::string& time); // check location time data or not
	bool isLocationFeature(const std::string& feature); // check location feature or not
	bool isLocationOrganism(const std::string& feature);
	void createSpecies(const std::string& speciesName, Organism* org);

	// Update
	void updateGlobalState(); // Update whole Local State
	void updateLocalState(int x, int y); // Update each local state
	void updateOrganismList(int x, int y); // Update Organism list of location

	// Retrieve
	Organism* retrieveOrganism(const std::string& name);
	bool isFoundName(const std::string& findName, const std::string& orgName);


	// Setter
	void setLocalName(std::string name); // set local name from DB
	void setLocalTime(std::string time); // set local time from DB
	void setOrganismList(std::string organisms, int x, int y); // set organisms from DB

	// Getter
	LocalInfo getLocalInfo(Point p);
	std::vector<Organism>* getOrganismList(Point p);
	std::string getLocalName(); // get local name from object
	std::string getLocalTime(); // get local time form object
	int getLocalWaterTemperature(Point p);
	Timer* getTimer();			// get Timer
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



#pragma region FieldDataBase_FILEIO
void FieldDataBase::readDB(std::string& fileName)
{
	std::string readData;

	// file open to stream
	readFileOpen(fileName);
	
	// debug
	std::cout << "readDB File open complete" << std::endl;

	// Location name read
	loadLocationName(readData);

	// debug
	std::cout << "Location Name Read complete" << std::endl;

	// Location time read
	loadTime(readData);

	// debug
	std::cout << "Location Time Read complete" << std::endl;

	// Location organisms read
	loadOrganisms(readData);

	// debug
	std::cout << "Location Organism Read complete" << std::endl;

	// Location feature data read
	loadLocationFeature(readData);

	// file close
	readFileClose();
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

void FieldDataBase::loadOrganisms(std::string& readData)
{
	getDBLine(readData);
	assert(isLocationOrganism(readData) && "Load Organism error\n");

	getDBLine(readData);
	int orgNum = stoi(readData);
	for (int ix = 0; ix < orgNum; ix++)
	{
		getDBLine(readData);
		Organism* org = new Organism();
		std::string orgFile = readData + "DB.txt";
		//createSpecies(readData, org);

		// debug
		std::cout << "FieldDataBase::createSpecies : readData = " << readData << std::endl;
		std::cout << "FieldDataBase::loadOrganisms(std::string& readData) : orgFile = " << orgFile << std::endl;

		org->setOrganismInfo(orgFile);

		// debug
		std::cout << "FieldDataBase::setOrganismInfo Complete" << std::endl;

		organismList.push_back(org);
	}
}

void FieldDataBase::createSpecies(const std::string& speciesName, Organism* org)
{
	if (speciesName == "HumpbackWhale") org = new HumpBackWhale();
	else if (speciesName == "Krill") org = new Organism();
}


void FieldDataBase::loadLocationFeature(std::string& readData)
{
	std::vector<std::string> parsingVec;
	getDBLine(readData);
	assert(isLocationFeature(readData) && "Load location Feature error\n");

	while (!ifs.eof())
	{
		getDBLine(readData);
		parsingFeatures(readData, parsingVec); // parsing feature data line

		// setup Programmed coordinate
		int x = stoi(parsingVec[0]);
		int y = stoi(parsingVec[1]);

		// setup Postion
		localInfo[x][y].pos.altitude = parsingVec[2];
		localInfo[x][y].pos.altitude = parsingVec[3];
		localInfo[x][y].pos.altitude = "0"; // default

		// setup topoGraphic features
		localInfo[x][y].localState[0] = convertTopoGraphic(parsingVec[4]);
		localInfo[x][y].localState[1] = convertTopoGraphic(parsingVec[5]);
		localInfo[x][y].localState[2] = convertTopoGraphic(parsingVec[6]);

		// setup Enviornment Watertemperature 
		localInfo[x][y].environment.setWaterTemperature(stoi(parsingVec[7]));

		// setup Organism List
		for (int ix = 8; ix < parsingVec.size(); ix++)
			setOrganismList(parsingVec[ix], x, y);

		// Clear vector for a next data
		parsingVec.clear();


		//debug
		std::cout << "LOAD SUCCESS" << std::endl;
	}

	//debug
	std::cout << "FIELD DB EOF" << std::endl;
}



void FieldDataBase::parsingFeatures(const std::string& readData, std::vector<std::string>& parsingVec)
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

bool FieldDataBase::isLocationOrganism(const std::string& feature)
{
	return (feature == "<Location Organism>");
}

LOCALSTATE FieldDataBase::convertTopoGraphic(const std::string& feature)
{
	if (feature == "GROUND")	return GROUND;
	else if (feature == "SEA")	return SEA;
	else if (feature == "AIR")	return AIR;
	else						return NONE;
}

//void FieldDataBase::createOrganismList(int x, int y)
//{
//	// Range check 
//	assert(MAX_FIELD_WIDTH_SIZE > x &&
//		MAX_FIELD_HEIGHT_SIZE > y &&
//		x >= 0 &&
//		y >= 0 &&
//		"createOrganismList point ERROR!!");
//
//	localInfo[x][y].organisms = new vector<Organism>;
//}
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

#pragma region FieldDataBase_Retrieve
Organism* FieldDataBase::retrieveOrganism(const std::string& name)
{
	for (auto& orgIter : organismList)
	{
		if (isFoundName(name, orgIter->getOrganismName()))
		{
			return orgIter;
		}
	}
	return nullptr;
}

bool FieldDataBase::isFoundName(const std::string& findName, const std::string& orgName)
{
	// debug
	std::cout << "isFoundName:: (find Name), (orgName) = " << findName << ", " << orgName  << std::endl;


	if (findName == orgName)
		return true;

	else
		return false;
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

void FieldDataBase::setOrganismList(std::string organisms, int x, int y)
{
	for (auto& org : organismList)
	{
		if (org->getOrganismName() == organisms)
		{
			localInfo[x][y].localOrganisms.push_back(org);
			break;
		}
	}
}

#pragma endregion

#pragma region FieldDataBase_GETTER
LocalInfo FieldDataBase::getLocalInfo(Point p)
{
	return localInfo[p.xpos][p.ypos];
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

Timer* FieldDataBase::getTimer()
{

}// get Timer

int FieldDataBase::getLocalWaterTemperature(Point p)
{
	return localInfo[p.xpos][p.ypos].environment.getWaterTemperature();
}
#pragma endregion

