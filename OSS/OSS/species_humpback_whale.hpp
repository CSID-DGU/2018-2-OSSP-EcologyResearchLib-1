// Coded by : Byung Suk Oh 

#pragma once
#include "genus_megaptera.hpp"

/*
Ȥ���
�и� : Megaptera novaeangliae

*/

class HumpBackWhale : public Megaptera
{
public:
#pragma region HUMPBACKWHALE_STATUS
	enum STATUS
	{
		// Something to add
		LAST = Megaptera::STATUS::LAST + 1
	};

	enum ACTION
	{
		// Something to add
		LAST = Megaptera::ACTION::LAST + 1
	};
#pragma endregion
};

