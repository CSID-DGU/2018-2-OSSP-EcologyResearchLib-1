// Coded by : Jong Ha Sin

#pragma once
#include "org_orgbase.hpp"
#include "db_origin.hpp"

#define DIRECTION_NUMBER 8

class OrgDataBase : public DataBase
{
public:
	// Organism status
	enum STATUS { ALIVE, DEAD, HUNGRY, LAST };
	enum ACTION { MOVING, HUNTING, MATING, STOPED, LAST };
	enum SEX { NONE, MALE, FEMALE };

	// Setup Func
	void setAge(int age) { m_Age = age; }
	void setSex(SEX sex) { m_Sex = sex; }
	void setStatus(STATUS status) { m_Status = status; }
	void setAction(ACTION action) { m_Action = action; }
	void setPosition(Position pos) { m_Position = pos; }
	void setPreyList(const std::vector<Organism>& preylist) { /* ±¸»ó Áß */ }
	void addPrey(const Organism& prey) { m_Prey.push_back(prey); }
	

	// Get Func
	int GetAge() const { return m_Age; }
	int GetSex() const { return m_Sex; }
	STATUS GetStatus() const { return m_Status; }
	ACTION GetAction() const { return m_Action; }
	Position GetPosition() const { return m_Position; }
	std::vector<Organism> GetPreyList() const { return m_Prey; }

	// Random Walk 
	void setMovingPossibility(const float& pArray);
	float* getMovingPossibility();

private:
	int m_Age;
	SEX m_Sex;

	STATUS m_Status;
	ACTION m_Action;

	Position m_Position; // Current Position
	std::vector<Organism> m_Prey;  // Prey List which organism can eat.

	float movePosibility[DIRECTION_NUMBER]; // Moving algorithm data
};

#pragma region RANDOM_WALK
void OrgDataBase::setMovingPossibility(const float& pArray)
{
	// To do
}

float* OrgDataBase::getMovingPossibility()
{
	// To do
}
#pragma endregion
