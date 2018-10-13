#pragma once
#include <iostream>
#include <vector>
#include "db_timer.hpp"

// Position data struct
typedef struct Position
{
	float fLatitude, fLongitude, fAltitude;
} Position;

class DataBase
{
public:
	Timer *m_timer; // Ÿ�̸�

	// ���� ����� ��Ʈ��
	std::ofstream *ofs;
	std::ifstream *ifs;

	DataBase() {}
	virtual ~DataBase(){}
};