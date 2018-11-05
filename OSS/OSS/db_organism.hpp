// Coded by : Jong Ha Sin

#pragma once
#include "org_orgbase.hpp"
#include "db_origin.hpp"

class OrgDataBase : public DataBase
{
public:
	// Organism status
	enum STATUS { ALIVE, DEAD, HUNGRY, LAST };
	enum ACTION { MOVING, HUNTING, MATING, STOPED, LAST };
	enum SEX { NONE, MALE, FEMALE };

	// Setup Func
	void SetAge(int age) { m_Age = age; }
	void SetSex(SEX sex) { m_Sex = sex; }
	void SetStatus(STATUS status) { m_Status = status; }
	void SetAction(ACTION action) { m_Action = action; }
	void SetPosition(Position pos) { m_Position = pos; }
	void SetPreyList(const std::vector<Organism>& preylist) { /* ±¸»ó Áß */ }
	void AddPrey(const Organism& prey) { m_Prey.push_back(prey); }

	// Get Func
	int GetAge() const { return m_Age; }
	int GetSex() const { return m_Sex; }
	STATUS GetStatus() const { return m_Status; }
	ACTION GetAction() const { return m_Action; }
	Position GetPosition() const { return m_Position; }
	std::vector<Organism> GetPreyList() const { return m_Prey; }

protected:
	int m_Age;
	SEX m_Sex;

	STATUS m_Status;
	ACTION m_Action;

	Position m_Position; // Current Position
	std::vector<Organism> m_Prey;  // Prey List which organism can eat.
};