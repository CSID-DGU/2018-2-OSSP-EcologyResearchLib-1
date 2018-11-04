// Coded by : JONG HA SIN 

#pragma once
#include <iostream>
#include <vector>

// Position data struct
typedef struct Position
{
	float fLatitude, fLongitude, fAltitude;
} Position;

class DataBase
{
public:
	// File I/O stream
	std::ofstream *ofs;
	std::ifstream *ifs;

	DataBase() {}
	virtual ~DataBase(){}
};