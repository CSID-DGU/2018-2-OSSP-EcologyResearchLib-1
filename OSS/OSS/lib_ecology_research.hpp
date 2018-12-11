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

*/

#pragma once
#include "al_algorithm.hpp"
#include "location_origin.hpp"

#pragma region EcologyResearchLib_Declaration
namespace EcologyResearchLib
{
	namespace LocationLib
	{
		Location* location;
		bool assignLocationMemory();
	}

	namespace AlgorithmLib
	{
		MovementPrediction* mpAlgorithm;
		bool assignMpAlgorithmMemory();
	}
}
#pragma endregion


#pragma region EcologyResearchLib_LocationLib
bool EcologyResearchLib::LocationLib::assignLocationMemory()
{
	location = new Location();
}
#pragma endregion

#pragma region EcologyResearchLib_AlgorithmLib
bool EcologyResearchLib::AlgorithmLib::assignMpAlgorithmMemory()
{
	//mpAlgorithm = new mpAlgorithm();
}
#pragma endregion
