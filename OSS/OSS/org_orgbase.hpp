// Coded by : Jong Ha Sin

#pragma once

#include "db_organism.hpp"

class Organism
{
private:
	OrgDataBase m_ODB;
	
public:
	
#pragma region ORGANISM_DEFAULT_STATUS
	enum STATUS
	{
		LAST = OrgDataBase::STATUS::LAST + 1
	};

	enum ACTION
	{
		LAST = OrgDataBase::ACTION::LAST + 1
	};
#pragma endregion

	Organism()
	{

	}

	~Organism()
	{

	}

	
};