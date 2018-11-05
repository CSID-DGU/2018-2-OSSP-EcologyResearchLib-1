// Coded by : Byung Suk Oh

#pragma once
#include "phylum_chordata.hpp"
#include "tax_class.hpp"

/*
포유강
학명 : Mammalia

*/

class Mammalia : public Chordata
{
public:
#pragma region MAMMALIA_STATUS
	enum STATUS
	{
		// Something to add
		LAST = Chordata::STATUS::LAST + 1
	};

	enum ACTION
	{
		// Something to add
		LAST = Chordata::ACTION::LAST + 1
	};
#pragma endregion
};
