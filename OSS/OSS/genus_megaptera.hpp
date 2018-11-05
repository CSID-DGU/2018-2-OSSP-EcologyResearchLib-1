// Coded by : Byung Suk Oh

#pragma once
#include "family_balaenopteridae.hpp"

/*
혹등고래속
학명 : Megaptera

*/

class Megaptera : public Balaenopteridae
{

public:
#pragma region MEGAPTERA_STATUS
	enum STATUS
	{
		// Something to add
		LAST = Balaenopteridae::STATUS::LAST + 1
	};

	enum ACTION
	{
		// Something to add
		LAST = Balaenopteridae::ACTION::LAST + 1
	};
#pragma endregion
};