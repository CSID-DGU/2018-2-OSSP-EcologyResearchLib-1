// Coded by : Byung Suk Oh

#pragma once

#include "org_orgbase.hpp"
#include "tax_domain.hpp"

/* 
�з� : ��
�и� : ���ٻ����� (Eukaryotes)
���� : https://namu.wiki/w/%EC%A7%84%ED%95%B5%EC%83%9D%EB%AC%BC
*/



class Eukaryotes : public Organism
{
public:
#pragma region EUKARYOTES_STATUS
	enum STATUS
	{
		// Something to add


		LAST = Organism::STATUS::LAST + 1
	};

	enum ACTION
	{
		// Something to add


		LAST = Organism::ACTION::LAST + 1
	};
#pragma endregion


};