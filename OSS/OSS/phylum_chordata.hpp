// Coded by : Byung Suk Oh

#pragma once
#include "kingdom_animalia.hpp"
#include "phylum_chordata.hpp"

/*
분류 : 문
학명 : 척삭동물문, 척색동물 (Chordata)
설명 : https://ko.wikipedia.org/wiki/%EC%B2%99%EC%82%AD%EB%8F%99%EB%AC%BC
*/

class Chordata : public Animalia
{
public:
#pragma region CHORDATA_STATUS
	enum STATUS
	{
		// Something to add
		LAST = Animalia::STATUS::LAST + 1
	};

	enum ACTION
	{
		// Something to add
		LAST = Animalia::ACTION::LAST + 1
	};
#pragma endregion

};