/* 

*************************************************************
*															*		
*						MIT License							*	
*															*
*				Copyright (c) 2018 CSID-DGU					*				
*															*
*************************************************************

Coded by : Jong Ha Sin
Last Updated : 18-12-5


[ Preference ]

<Explanation>
- ������ ���⼺ ������ �����ϴ� DB
- ���� �˰��� ���ȴ�.


<To do>

[���� ��Ŀ �˰��� ���Ǵ� �̵� ��ȣ ����]

1. ����
 - ����/�ٴ�, �̵� ����/�Ұ���, ��ü�� ���� Ư���� ���� ���� Ȯ�� ����
 => ������ ���� ����, ������Ŀ�� Ȯ�� ��� �� �ش� �������� �о����


2. ���Ļ���
 - �ش� ������ �����ϴ� �����ڿ� ���� �̵� Ȯ�� ����,
	���̿� ���� �̵� Ȯ�� ����

 => ���������� ������ ���� ����,
	  ���������� ������ ���� ���Ļ��� ������ ��ȭ�� �ʿ䰡 ����


3. �ñ�
 - ����(Ȥ�� ����)�� ���� �Ը��� �̵� ���⼺�� �ľǵȴٸ�
	�ش� ������ ����Ͽ� Ȯ�� ����
 - ����� �� Ư�� �ñ⿡ ���� ��ǥ ���������� �̵� ���ɼ� ���

 => ������Ŀ Ȯ�� ��� ��
	  1) �ñ⿡ ���� �̵� ���⼺ ���� �о����
		  (���ο� �ڷᱸ�� ���� �ʿ�,
		   �ñ⺰ �ֿ� �̵� ��ǥ�� �Ǵ� ���� �� ����/���� Ȯ���� ���� ������)
	  2) ���� ��ġ�� �ش� ���������� ������ ���
	  3) �ش� ������ Ȯ�� ����


4. �ð�
 - ��/��, Ȥ�� Ư�� �ð��� ���� �̵� ���⼺�� �����Ѵٸ�
	�ش� ������ ����Ͽ� Ȯ�� ����

=> ���������� �ð��� ���� �̵� ���⼺ ������ ���� �� �о����


(5. ����)
 - ȭ��, ��ǳ �� �ڿ����ط� ���� �̵� ���⼺ ���
 - ���� ����
 �̴� ��Ȯ�� ������ �����Ƿ� ���Ŀ� ���


6. ������ (�ټ��� ��ȣ ���ο� ���������� ����)
 - �ֿ� ���������� �̵�, ��Ը� ���� ��
	 �и��� �������� ���� �̵��ϴ� ���⼺�� �߰ߵ� ���
	 ���� ��ġ�κ��� �ش� �������� ���ϴ� ���⿡ ���� Ȯ�� �߰� �ο�


* �ñ�, �ð�, ������ �� ����ȭ ������ ������ ������ ���
 - �ش� ������ �����ͺ��̽��� ����
 - ������Ŀ�� Ȯ������� �� �����ͺ��̽����� �ҷ�����
 - �ð� ������(�ð� �� ������ �������� ���ǽ� �̿�)
 - ���� ������(�������� ���� ��ǥ)
 - Ȯ�� ����(������Ŀ�� ��ٷ� ������ֱ� ����)

*/

#pragma once
#include "db_origin.hpp"
#include "db_organism.hpp"
#include "db_environment.hpp"

class Preference
{
private:
	LOCALSTATE movable[3] = {NONE, NONE, NONE}; // prefetr to go somewhere
	std::vector<std::string> preyList;			
										// Prey List which organism can eat and like to eat. 
	
	/*
		�˰��� ���ο��� �� ���� ������ <=> Organism ������ Preference ��. 
	*/

public:
	// Constructor
	Preference();

	// Destructor
	~Preference();

	// Setter
	void setLocalState(const LOCALSTATE* localState);
	void setPreyList(std::string prey);

	// Getter
	bool checkLocalState(LOCALSTATE localstate);
	bool checkPreyList(const std::string prey);

};

#pragma region Preference_Constructor
Preference::Preference()
{

}

#pragma endregion

#pragma region Preference_Destructor
Preference::~Preference()
{

}

#pragma endregion

#pragma region Preference_Setter
void Preference::setLocalState(const LOCALSTATE* localState)
{
	int ix = 0;
	for (auto& ls : movable)
		ls = localState[ix++];
}

void Preference::setPreyList(std::string prey)
{
	preyList.push_back(prey);
}

#pragma endregion

#pragma region Preference_Getter
bool Preference::checkLocalState(LOCALSTATE localstate)
{
	if (localstate == GROUND && (movable[0] == GROUND)) return true;
	else if (localstate == SEA && (movable[1] == SEA)) return true;
	else if (localstate == AIR && (movable[2] == AIR)) return true;
	else return false;
}

bool Preference::checkPreyList(const std::string prey)
{
	for (auto& item : preyList)
	{
		if (item == prey)
			return true;
	}
	return false;
}

#pragma endregion

