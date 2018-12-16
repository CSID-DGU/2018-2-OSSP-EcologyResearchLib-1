/* 

******************************************************
					MIT License
			Copyright (c) 2018 CSID-DGU
******************************************************

Coded by : Jong Ha Sin
Last Updated : 18-11-05


[ DataBase ]

<Explanation>

<To do>

*/

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>


#define RW_POSSIBILITY float*
#define DIRECTION_NUMBER 9

typedef std::string timer_string_t;

// Position data struct
typedef struct Position
{
	std::string longitude, latitude, altitude;
} Position;

// The states shows that organisms can move or not to the location
enum LOCALSTATE
{
	GROUND, SEA, AIR, NONE
};

/* �޸� : �ط��� �̵� ���� ���� ����, db_origin���� �ű� ���� */
   // 9���� �̵� ��� : ����, ��, �ϵ�, ��, ... ��, �ϼ�
enum Direction
{
	STOP,
	NORTH, NORTH_EAST, EAST, SOUTH_EAST,
	SOUTH, SOUTH_WEST, WEST, NOTRH_WEST
};


// ����ȭ ����� RWOutput
typedef struct RWOutput
{
	Position        position;       // ��ǥ
	timer_string_t  time;           // ����ȭ�� �ð� ��Ʈ��

	// ������
	RWOutput(Position p, timer_string_t t)
		: position(p), time(t) {}

} RWOutput;


class DataBase
{
protected:
	// File I/O stream
	std::ofstream ofs;
	std::ifstream ifs;

public:
	DataBase();
	virtual ~DataBase();
	
	// File I/O
	virtual void readDB(std::string& fileName)  // Read DB file from stroage
	void readFileOpen(std::string& fileName);	// Read file open to input stream
	void readFileClose();						// Read file close from input stream
	void getDBLine(std::string& readData);		// Read a line from DB
	void writeFileOpen(std::string& fileName);	// Write file open to output stream
	void writeFileClose();						// Write file close from output stream
	
};


#pragma region DataBase_CONSTURCTOR

DataBase::DataBase()
{

}

#pragma endregion 


#pragma region DataBase_DESTURCTOR

DataBase::~DataBase()
{

}

#pragma endregion 


#pragma region DataBase_FILE_I/O

void DataBase::readFileOpen(std::string& fileName)
{
	ifs.open(fileName);
}

void DataBase::readFileClose()
{
	ifs.close();
}

void DataBase::getDBLine(std::string& readData)
{
	getline(ifs, readData);

	// debug
	std::cout << "GetDBLINE :: READ DATA = " << readData << std::endl;

	assert(!readData.empty() && "READ ERROR!!");
}

void DataBase::writeFileOpen(std::string& fileName)
{
	ofs.open(fileName, std::ofstream::out | std::ofstream::app);
}

void DataBase::writeFileClose()
{
	ofs.close();
}
#pragma endregion