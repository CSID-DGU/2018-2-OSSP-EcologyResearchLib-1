// Coded by : Ω≈¡æ«œ

#pragma once
#include "db_origin.hpp"
#include "db_timer.hpp"
#include "db_environment.hpp"
#include "db_organism.hpp"

class FieldDataBase : public DataBase
{
	struct LocalInfo
	{
		Position pos;
		Environment environment;
		std::vector<Organism> organisms;
	};

private:
	Timer * m_timer; // Local Time
	std::vector<LocalInfo> m_localArray; // Location info
	
public:
	FieldDataBase()
	{
		m_timer = new Timer();
	}

	~FieldDataBase()
	{
		delete[] m_timer;
	}
};