// Coded by : JONG HA SIN 

#pragma once
#include "db_field.hpp"

class Location 
{
	FieldDataBase* m_FDB;
	Organism* target; // searching target for algorithm (now assume one living thing)

public:
	Location(FieldDataBase* fdb) 
	{
		m_FDB = fdb;
	}
	
	~Location()
	{
		delete[] m_FDB;
	}


	void setTarget(Organism* org);
	Organism* getTarget();
};


#pragma region TARGET_ORGANISM
void Location::setTarget(Organism* org)
{
	// TO DO
}

Organism* Location::getTarget()
{
	// TO DO
}
#pragma endregion