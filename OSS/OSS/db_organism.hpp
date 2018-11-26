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

class Organism;

// Organism status
enum STATUS { ALIVE, DEAD, HUNGRY, FULL, SLEEPY, FEARED, 
			  HIBERNATION, HIDING, DIVE, FLOATING };
enum ACTION { MOVING, HUNTING, MATING, STOPED, SLEEPING, 
	          EATING, DIVING, SPOUTING };
enum SEX { MALE, FEMALE, BOTH };

class OrgDataBase : public DataBase
{
public:
	// Setup Func
	void setAge(int age) { m_Age = age; }
	void setSex(SEX sex) { m_Sex = sex; }
	void setStatus(STATUS status) { m_Status = status; }
	void setAction(ACTION action) { m_Action = action; }
	void setPosition(Position pos) { m_Position = pos; }
	void setPreyList(const std::vector<Organism>& preylist) { /* 구상 중 */ }
	void addPrey(const Organism& prey) { m_Prey.push_back(prey); }
	

	// Get Func
	int getAge() const { return m_Age; }
	int getSex() const { return m_Sex; }
	STATUS getStatus() const { return m_Status; }
	ACTION getAction() const { return m_Action; }
	Position getPosition() const { return m_Position; }
	std::vector<Organism> getPreyList() const { return m_Prey; }


private:
	int m_Age;
	SEX m_Sex;

	STATUS m_Status;
	ACTION m_Action;

	Position m_Position; // Current Position
	std::vector<Organism> m_Prey;  // Prey List which organism can eat.

	int xPoint, yPoint; // coordinates of organism at location

	int energy; // calories % for survive
};


class Organism
{
private:
	OrgDataBase* m_ODB;

public:

	Organism() {}

	Organism(int x, int y)
	{
		m_ODB = new OrgDataBase();
		
	}

	virtual ~Organism()
	{
		delete[] m_ODB;
	}


	// Moving
	virtual void moving() = 0;
};



