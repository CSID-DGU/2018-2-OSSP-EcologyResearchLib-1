#include "lib_ecology_research.hpp"

using namespace std;

int main()
{
	Location* loc;
	loc = new Location();

	std::string fileName = "testDB.txt";
	loc->setUpFieldDB(fileName);


	EcologyResearchLib::LocationLib::assignLocationMemory();
	EcologyResearchLib::AlgorithmLib::assignMpAlgorithmMemory();

	EcologyResearchLib::LocationLib::location->setUpFieldDB(fileName);
	

	return 0;
}