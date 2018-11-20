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
Coded by : Jong Ha Sin
Last Updated : 18-11-05


[ Location ] 

<Explanation>

<To do>
...

*/

#pragma once
#include "db_field.hpp"
#include "db_environment.hpp"

class Location 
{
	FieldDataBase* m_FDB;
	Organism* target; // searching target for algorithm (now assume one living thing)

public:
	Location(FieldDataBase* fdb) 
	{
		m_FDB = fdb;
	}
	
	~Location()
	{
		delete[] m_FDB;
	}


	void setTarget(Organism* org);
	Organism* getTarget();
};


#pragma region TARGET_ORGANISM
void Location::setTarget(Organism* org)
{
	// TO DO
}

Organism* Location::getTarget()
{
	return nullptr;
	// TO DO
}
#pragma endregion