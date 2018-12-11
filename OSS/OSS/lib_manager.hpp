/* 

*************************************************************
*															*		
*						MIT License							*	
*															*
*				Copyright (c) 2018 CSID-DGU					*				
*															*
*************************************************************

Coded by : Jong Ha Sin
Last Updated : 18-11-05

*/


#pragma once

#include "location_origin.hpp"
#include "al_algorithm.hpp"


class Manager
{
private:
	Location* location;
	MovementPrediction* mpAlgorithm;

public:
	
	void setMpAlgorithm(MovementPrediction* mpAlgo);
	void setLocation();
	
	void executeAlgorithm();

};


#pragma region ALGORITHM
void Manager::setMpAlgorithm(MovementPrediction* mpAlgo)
{
	mpAlgorithm = mpAlgo;
}


void Manager::setLocation()
{
	// location DB setup
	// location->setUpFieldDB();
}

void Manager::executeAlgorithm()
{
	//mpAlgorithm->predict(location);
}
#pragma endregion