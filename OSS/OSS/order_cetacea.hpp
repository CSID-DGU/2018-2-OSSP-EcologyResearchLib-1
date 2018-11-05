// Coded by : Byung Suk Oh

#pragma once

#include "class_mammalia.hpp"

/*
고래목
학명 : Cetacea

*/

class Cetacea : public Mammalia
{
public:
#pragma region CETACEA_STATUS
	enum STATUS
	{
		// Something to add
		DIVE, FLOATING,
		LAST = Mammalia::STATUS::LAST + 1
	};

	enum ACTION
	{
		// Something to add
		DIVING, SPOUTING,
		LAST = Mammalia::ACTION::LAST + 1
	};
#pragma endregion
};