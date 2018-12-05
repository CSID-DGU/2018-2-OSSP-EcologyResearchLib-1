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


[ OrgDataBase ]

<Explanation>
- 생명체의 기본 속성을 가진 DB API 클래스
- 최대한 모든 생명체들이 공통적으로 가질 수 있는 특성만을 보유

- 이 DB를 멤버로 가진 Organism 클래스가 있다.
- 더 추가되는 생명체의 속성은

<To do>
...

*/

#pragma once
#include "db_origin.hpp"
#include "db_preference.hpp"

class Organism;

// Organism status
enum STATUS { ALIVE, DEAD, HUNGRY, FULL, SLEEPY, FEARED, 
			  HIBERNATION, HIDING, DIVE, FLOATING, BREEDING };
enum ACTION { MOVING, HUNTING, MATING, STOPED, SLEEPING, 
	          EATING, DIVING, SPOUTING, DEFAULT };
enum SEX { MALE, FEMALE, BOTH };

struct OrgDBStruct
{
	std::string name;	// Organism's Name
	int age;			// Organism's Age
	SEX m_Sex;			// Organism's sex
	unsigned energy;    // calories % for survive

	std::vector<STATUS> status;  // Current Status list
	ACTION action;			     // Current action

	Preference prefer;			   // preference of a organism

	// These datas are Determined by field DB
	int xPoint, yPoint;  // coordinates of organism at location
	Position m_Position; // Current geographical position
};

class OrgDataBase : public DataBase
{
public:
	// Setup Func
	void setAge(int age) { m_Age = age; }
	void setSex(SEX sex) { m_Sex = sex; }
	void setStatus(STATUS status) { m_Status.push_back(status); }
	void setAction(ACTION action) { m_Action = action; }
	void setPosition(Position pos) { m_Position = pos; }
	void setPreyList(const std::vector<Organism>& preylist) { /* 구상 중 */ }
	void addPrey(const Organism& prey) { m_Prey.push_back(prey); }
	

	// Get Func
	int getAge() const { return m_Age; }
	int getSex() const { return m_Sex; }
	std::vector<STATUS> getStatus() const { return m_Status; }
	ACTION getAction() const { return m_Action; }
	Position getPosition() const { return m_Position; }
	std::vector<Organism> getPreyList() const { return m_Prey; }

	// File Read
	virtual void readDB(const char* fileName);

private:
	OrgDBStruct organismInfo;
};


class Organism
{
private:
	OrgDataBase* m_ODB;

public:
	// Constructor
	Organism();

	// Destructor
	virtual ~Organism();

	// Setter
	void setOrganismInfo(const char* fileName);

	// Getter


	// Moving
	// virtual void moving() = 0;
};



#pragma region OrgDataBase_FILEIO
void OrgDataBase::readDB(const char* fileName)
{
	std::string readData;

	readFileOpen(fileName);
	// loadName(readData);
	// loadAge(readData);
	// loadSex(readData);
	// 
	
	readFileClose();
}
#pragma region


#pragma region Organism_CONSTRUCTOR

Organism::Organism()
{
	m_ODB = new OrgDataBase();
}
#pragma endregion 

#pragma region Organism_DESTRUCTOR

Organism::~Organism()
{
	delete[] m_ODB;
}
#pragma endregion 

#pragma region Organism_SETTER

void Organism::setOrganismInfo(const char* fileName)
{
	m_ODB->readDB(fileName);
}
#pragma endregion