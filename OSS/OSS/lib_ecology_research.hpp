/*

******************************************************
					MIT License
			Copyright (c) 2018 CSID-DGU
******************************************************

Coded by : Jong Ha Sin
Last Updated : 18-12-11

*/

#pragma once
#include "al_algorithm.hpp"
#include "al_humpback_whale_mp.hpp"
#include "location_origin.hpp"

#pragma region EcologyResearchLib_Declaration
namespace EcologyResearchLib
{
	bool initializeLib();

	namespace LocationLib
	{
		Location* location = nullptr;
		bool assignLocationMemory();
		void setLocationData(std::string& str);
		bool isLocationEmpty();
	}

	namespace AlgorithmLib
	{
		namespace MovementPredictionLib
		{
			MovementPrediction* mpAlgorithm = nullptr;
			bool assignMpAlgorithmMemory();
			void setTargetLocation();
			void setTargetOrganism(std::string& str);
			void run();
		}
	}
}
#pragma endregion

#pragma region EcologyResearchLib_LocationLib
bool EcologyResearchLib::initializeLib()
{
	LocationLib::assignLocationMemory();
	AlgorithmLib::MovementPredictionLib::assignMpAlgorithmMemory();
	return true;
}
#pragma endregion 

using namespace EcologyResearchLib;

#pragma region LocationLib
bool LocationLib::assignLocationMemory()
{
	location = new Location();
	return true;
}

void LocationLib::setLocationData(std::string& str)
{
	location->setUpFieldDB(str);
}

bool LocationLib::isLocationEmpty()
{
	if (location == nullptr)
		return true;

	else
		return false;
}
#pragma endregion

using namespace AlgorithmLib;

#pragma region AlgorithmLib_MovePredictionAlgorithm
bool MovementPredictionLib::assignMpAlgorithmMemory()
{
	// TO DO
	mpAlgorithm = new HumpbackWhaleMP();
	return true;
}

void MovementPredictionLib::setTargetLocation()
{
	if (LocationLib::isLocationEmpty())
	{
		fprintf(stderr, "LOCATION ERROR!!");
		exit(1);
	} 
	
	// set Location to algorithm class
	MovementPredictionLib::mpAlgorithm->setLocation(LocationLib::location);
}

void MovementPredictionLib::setTargetOrganism(std::string& str)
{
	MovementPredictionLib::mpAlgorithm->setTarget(str);
}

void MovementPredictionLib::run()
{

}
#pragma endregion
