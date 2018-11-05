// Coded by : Byung Suk Oh

#pragma once
#include "order_cetacea.hpp"

/*
수염고래과
학명 : Balaenopteridae

*/

class Balaenopteridae : public Cetacea
{
public:
#pragma region BALAENOPTERIDAE_STATUS
	enum STATUS
	{
		// Something to add
		LAST = Cetacea::STATUS::LAST + 1
	};

	enum ACTION
	{
		// Something to add
		LAST = Cetacea::ACTION::LAST + 1
	};
#pragma endregion
};