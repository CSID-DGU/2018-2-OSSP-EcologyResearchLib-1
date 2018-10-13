#pragma once
#include "DataBase.hpp"

class FieldDataBase : public DataBase
{
	struct Whether
	{

	};

	struct Temperature
	{

	};

	struct LocationData
	{
		Position pos;
		Whether wter;
		Temperature temper;
	};

private:
	
public:
	std::vector<LocationData> loc;

};