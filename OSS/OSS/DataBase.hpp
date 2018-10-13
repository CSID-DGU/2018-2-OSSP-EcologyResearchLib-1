#pragma once
#include <iostream>
#include <vector>
#include "Timer.hpp"

// Position data struct
typedef struct Position
{
	float fLatitude, fLongitude, fDepth;
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