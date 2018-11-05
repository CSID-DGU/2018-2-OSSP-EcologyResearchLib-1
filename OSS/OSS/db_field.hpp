/* MIT License

Copyright (c) 2018 CSID-DGU

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */

/*
Coded by : Jong Ha Sin
Last Updated : 18-11-05



FieldDataBase
....

*/

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