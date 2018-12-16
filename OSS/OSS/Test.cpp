#include "lib_ecology_research.hpp"

using namespace std;

int main()
{
	std::string fileName = "LocationDB.txt";
	std::string target = "HumpbackWhale";

	EcologyResearchLib::initializeLib();
	EcologyResearchLib::LocationLib::setLocationData(fileName);
	EcologyResearchLib::AlgorithmLib::MovementPredictionLib::setTargetLocation();
	EcologyResearchLib::AlgorithmLib::MovementPredictionLib::setTargetOrganism(target);
	EcologyResearchLib::AlgorithmLib::MovementPredictionLib::run();

	
	return 0;
}