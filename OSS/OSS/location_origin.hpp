/* 

******************************************************
					MIT License
			Copyright (c) 2018 CSID-DGU
******************************************************

Coded by : Jong Ha Sin
Last Updated : 18-12-11

[ Location ] 

<Explanation>
 Client가 접근하는 클래스.
 Field DB를 가지고 있으며 각종 알고리즘의 param으로 사용됩니다.

<To do>
...

*/

#pragma once
#include "db_field.hpp"

class Location 
{
private:
	FieldDataBase* m_FDB;

public:
	// Constructor
	Location();
	Location(std::string& fileName);

	// Destructor
	~Location();

	// Initialiazation
	void initiailize(std::string& fileName);

	// Update
	void updateDB(LocalInfo* localInfo);
	
	// Setter
	void setUpFieldDB(std::string& fileName);

	// Getter
	timer_string_t getTime();
	Organism* getTarget(const std::string& orgName); // return target organism to algorithm
	LocalInfo getLocalInfo(Point p);			// 9개의 방향에 있는 Local data 를 배열로 리턴
	int getWaterTemperature(Point p);

	//Position getTagetPostion();
	
};

#pragma region Location_Constuructor
Location::Location()
{
	m_FDB = new FieldDataBase();
}

Location::Location(std::string& fileName)
{
	m_FDB = new FieldDataBase();
	m_FDB->readDB(fileName);
}
#pragma endregion

#pragma region Location_Destructor
Location::~Location()
{
	delete[] m_FDB;
}
#pragma endregion

#pragma region Location_Initialize
void Location::initiailize(std::string& fileName)
{
	this->setUpFieldDB(fileName);
}
#pragma endregion

#pragma region Location_FieldDB
void Location::setUpFieldDB(std::string& fileName)
{
	m_FDB->readDB(fileName);
}

LocalInfo Location::getLocalInfo(Point p)
{
	return m_FDB->getLocalInfo(p);
}

timer_string_t Location::getTime()
{
	return m_FDB->getLocalTime();
}

#pragma endregion


#pragma region Location_getter
//bool Location::setTarget(std::string& orgName)
//{
//	this->target = m_FDB->retrieveOrganism(orgName);
//
//	if (target != nullptr)
//		return true;
//
//	return false;
//}

Organism* Location::getTarget(const std::string& orgName)
{
	return m_FDB->retrieveOrganism(orgName);
}

int Location::getWaterTemperature(Point p)
{
	return m_FDB->getLocalWaterTemperature(p);
}

#pragma endregion