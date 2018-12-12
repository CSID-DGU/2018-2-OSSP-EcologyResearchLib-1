/* 

******************************************************
					MIT License
			Copyright (c) 2018 CSID-DGU
******************************************************

Coded by : Jong Ha Sin
Last Updated : 18-12-11

[ Location ] 

<Explanation>
 Client�� �����ϴ� Ŭ����.
 Field DB�� ������ ������ ���� �˰����� param���� ���˴ϴ�.

<To do>
...

*/

#pragma once
#include "db_field.hpp"
#include "db_environment.hpp"

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
	LocalInfo* getLocalInfo();			// 9���� ���⿡ �ִ� Local data �� �迭�� ����

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

LocalInfo* Location::getLocalInfo()
{
	// retrieve

	// TO DO
	/*
		9���� LocalInfo�� ����ϰ��� �ϴ� �˰��� �Ѱ��ִ� �Լ�
	*/
	
	return NULL;
}

timer_string_t Location::getTime()
{
	return m_FDB->getLocalTime();
}

#pragma endregion


#pragma region Location_Setter
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

#pragma endregion