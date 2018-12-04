#include "lib_manager.hpp"

using namespace std;

int main()
{
	cout << "HI" << endl;
	FieldDataBase testDB;
	testDB.readDB("testDB.txt");
	//testDB.getLocalName();
	//testDB.getLocalTime();

	return 0;
}