/*

******************************************************
					MIT License
			Copyright (c) 2018 CSID-DGU
******************************************************

Coded by : Jong Ha Sin
Last Updated : 18-12-16

*/

#pragma once
#include "al_movement_prediction.hpp"
#include "location_origin.hpp"

#pragma region EcologyResearchLib_Declaration
namespace EcologyResearchLib
{
	bool initializeLib();

	namespace DBLib
	{
		Location* location = nullptr;
		RandomWalkMovementPathDB* rwDB = nullptr; // User for data return
		
		bool assignLocationMemory();
		bool assignRWDBMemory();
		void setLocationData(std::string& str);
		bool isLocationEmpty();
		void getmovementPathData(const std::string& outFileName);
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

#pragma region EcologyResearchLib_Init
bool EcologyResearchLib::initializeLib()
{
	DBLib::assignLocationMemory();
	DBLib::assignRWDBMemory();
	AlgorithmLib::MovementPredictionLib::assignMpAlgorithmMemory();
	return true;
}
#pragma endregion 

using namespace EcologyResearchLib;

#pragma region DBLib
bool DBLib::assignLocationMemory()
{
	location = new Location();
	return true;
}

bool DBLib::assignRWDBMemory()
{
	rwDB = new RandomWalkMovementPathDB();
	return true;
}

void DBLib::setLocationData(std::string& str)
{
	location->setUpFieldDB(str);
}

bool DBLib::isLocationEmpty()
{
	if (location == nullptr)
		return true;

	else
		return false;
}

void DBLib::getmovementPathData(const std::string& outFileName)
{
	// TO DO
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
	if (DBLib::isLocationEmpty())
	{
		fprintf(stderr, "LOCATION ERROR!!");
		exit(1);
	} 
	
	// set Location to algorithm class
	MovementPredictionLib::mpAlgorithm->setLocation(DBLib::location);
}

void MovementPredictionLib::setTargetOrganism(std::string& str)
{
	if (MovementPredictionLib::mpAlgorithm->setTarget(str))
		std::cout << "Set Target Completed" << std::endl;
	
	else
		std::cout << "Set Target Failed" << std::endl;
}

void MovementPredictionLib::run()
{
	// test
	std::cout << MovementPredictionLib::mpAlgorithm->getTagetName() << std::endl;
	std::cout << "Get Target Completed" << std::endl;

	// run Algorithm
	
}
#pragma endregion
