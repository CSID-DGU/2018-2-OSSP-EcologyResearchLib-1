// Coded by : Byung Suk Oh

#pragma once
#include "domain_eukaryotes.hpp"
#include "tax_kingdom.hpp"

/*
분류 : 계
학명 : 동물계 (Animalia)
설명 : https://namu.wiki/w/%EB%8F%99%EB%AC%BC
*/

enum ANIMALIA_ACTION
{
	
};

class Animalia : public Eukaryotes
{
public:

#pragma region ANUMALIA_STATUS
	enum STATUS
	{
		// Something to add
		FULL = Eukaryotes::STATUS::LAST + 1,
		SLEEPY, FEARED, HIBERNATION, HIDING, 
		
		LAST
	};

	enum ACTION
	{
		// Something to add
		SLEEPING = Eukaryotes::ACTION::LAST + 1,
		EATING, 
		
		LAST
	};
#pragma endregion

};