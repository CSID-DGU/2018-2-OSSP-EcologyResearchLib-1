/* MIT License

Copyright (c) 2018 CSID-DGU

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */

/*
Coded by : Byung Suk Oh
Last Updated : 18-11-05

�з� : ��
�и� : ������ (Animalia)
���� : https://namu.wiki/w/%EB%8F%99%EB%AC%BC

*/


#pragma once
#include "domain_eukaryotes.hpp"
#include "tax_kingdom.hpp"

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