// Coded by : Byung Suk Oh

#pragma once
#include "domain_eukaryotes.hpp"
#include "tax_kingdom.hpp"

/*
�з� : ��
�и� : ������ (Animalia)
���� : https://namu.wiki/w/%EB%8F%99%EB%AC%BC
*/

enum STATUS
{
	FULL, SLEEPY, FEARED, HIBERNATION, HIDING
};

enum ACTION
{
	SLEEPING, EATING
};

class Animalia : public Eukaryotes
{

};