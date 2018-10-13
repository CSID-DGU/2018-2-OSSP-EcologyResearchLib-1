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
	Timer *m_timer; // 타이머

	// 파일 입출력 스트림
	std::ofstream *ofs;
	std::ifstream *ifs;

	DataBase() {}
	virtual ~DataBase(){}
};