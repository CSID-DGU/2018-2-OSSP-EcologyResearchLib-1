// Coded by : Jong Ha Sin

#pragma once
#include "db_origin.hpp"
#include "db_timer.hpp"
#include "db_environment.hpp"
#include "db_organism.hpp"

#define MAX_FIELD_WIDTH_SIZE 100
#define MAX_FIELD_HEIGHT_SIZE 100

class FieldDataBase : public DataBase
{
	enum LOCALSTATE
	{
		AIR_MOVABLE, SEA_MOVABLE, GROUND_MOVABLE, NONE
	};

	struct LocalInfo
	{
		LOCALSTATE localState[3] = { NONE, NONE, NONE }; // AIR, SEA, GROUND
		Position pos;	// Real value of Position in earth
		Environment* environment;	// Environment information for algorithm
		std::vector<Organism>* organisms; // Organism list for algorithm
	};

private:
	Timer * m_timer; // Local Time
	LocalInfo localInfo[MAX_FIELD_WIDTH_SIZE][MAX_FIELD_HEIGHT_SIZE];
	
public:
	FieldDataBase()
	{
		m_timer = new Timer();
	}

	~FieldDataBase()
	{
		delete[] m_timer;
	}

	void changeLocalState(int x, int y); // Update Local State
};

void FieldDataBase::changeLocalState(int x, int y)
{

}