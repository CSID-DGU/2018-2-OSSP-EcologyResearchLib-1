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

	// DB Setter
	void setUpFieldDB(std::string& fileName);
	void setTarget(Organism* org);
	
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



#pragma region Location_Target
void Location::setTarget(Organism* org)
{
	// TO DO
}

Organism* Location::getTarget()
{
	return nullptr;
	// TO DO
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