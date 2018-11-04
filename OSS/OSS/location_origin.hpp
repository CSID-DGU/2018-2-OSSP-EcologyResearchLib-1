// Coded by : SIN JONG HA

#pragma once
#include "db_field.hpp"

class Location 
{
	FieldDataBase* m_FDB;
public:
	Location(FieldDataBase* fdb) 
	{
		m_FDB = fdb;
	}
	
	~Location()
	{
		delete[] m_FDB;
	}
};