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

분류 : 역
학명 : 진핵생물역 (Eukaryotes)
설명 : https://namu.wiki/w/%EC%A7%84%ED%95%B5%EC%83%9D%EB%AC%BC

*/

#pragma once

#include "org_orgbase.hpp"
#include "tax_domain.hpp"

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