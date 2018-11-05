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
		Environment environment;	// Environment information for algorithm
		std::vector<Organism>* organisms; // Organism list for algorithm
	};

private:
	Timer * m_timer; // Global Time
	LocalInfo localInfo[MAX_FIELD_WIDTH_SIZE][MAX_FIELD_HEIGHT_SIZE]; // Map array 

public:
	FieldDataBase()
	{
		m_timer = new Timer();
	}

	~FieldDataBase()
	{
		delete[] m_timer;
	}

	void updateGlobalState(); // Update whole Local State
	void updateLocalState(int x, int y); // Update each local state
};



#pragma region LOCATION_UPDATE
void FieldDataBase::updateGlobalState()
{
	// TO Do
}

void FieldDataBase::updateLocalState(int x, int y)
{
	// TO DO 
}
#pragma endregion