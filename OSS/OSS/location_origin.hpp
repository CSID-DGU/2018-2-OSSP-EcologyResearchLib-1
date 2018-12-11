/* 

*************************************************************
*															*		
*						MIT License							*	
*															*
*				Copyright (c) 2018 CSID-DGU					*				
*															*
*************************************************************

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
	Organism* target;
	// searching target for algorithm (now assume one living thing)
	/*
		target�� ���Ǵ� �뵵
		1. �˰��� ���ο��� target�� ��ȣ�� DB�� ���
		2. �˰����� ������ target�� ��ġ�� FieldDB�� update�Ǿ����.
	*/

public:
	// Constructor
	Location();
	Location(std::string& fileName);

	// Destructor
	~Location();

	// Initialiazation
	void initiailize(std::string& fileName);

	// DB Setter
	void setUpFieldDB(std::string& fileName);
	bool setTarget(std::string& orgName);
	
	// DB Getter
	timer_string_t getTime();
	Position getTagetPostion();
	Organism* getTarget();
	
	
	void updateDB(LocalInfo* localInfo);
	
	// 9���� ���⿡ �ִ� Local data �� �迭�� ����
	LocalInfo* getLocalInfo();


};

#pragma region Location_Constuructor
Location::Location()
{
	m_FDB = new FieldDataBase();
	target = new Organism();
}

Location::Location(std::string& fileName)
{
	m_FDB = new FieldDataBase();
	m_FDB->readDB(fileName);

	target = new Organism();
}
#pragma endregion

#pragma region Location_Destructor
Location::~Location()
{
	delete[] target;
	delete[] m_FDB;
}
#pragma endregion

#pragma region Location_Initialize
void Location::initiailize(std::string& fileName)
{
	
	this->setUpFieldDB(fileName);
}
#pragma endregion

#pragma region Location_Target
bool Location::setTarget(std::string& orgName)
{
	this->target = m_FDB->retrieveOrganism(orgName);

	if (target != nullptr)
		return true;

	return false;
}

Organism* Location::getTarget()
{
	return target;
}

Position Location::getTagetPostion()
{
	return target->getOrganismPosition();
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