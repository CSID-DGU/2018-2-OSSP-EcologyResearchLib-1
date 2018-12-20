/*

******************************************************
					MIT License					
			Copyright (c) 2018 CSID-DGU					
******************************************************

 Coded by : Sa Min Hong
 Last Updated : 18-12-13


 [ MovementPrediction ] 

 <Explanation>
 - ������ �ൿ�� "����"�ϴ� �˰����� �ֻ��� Ŭ����
 - �Է� : �ʵ�, ���� ����(�з�, ����, ���ݱ����� �̵� ���), ������ �Ⱓ
 - ���� : ���� ������ ref�� �Է¹޾� ������ �Ⱓ��ŭ�� �̵� ��θ� �����Ͽ�
		���� ���� �� �̵� ��ο� �߰�
 - ��� : ����

 <To do>
 - ��� Ŭ�������� "�̵� ��� ����" ����
 - Organism�� ���� ��ü��(ex> ��)�� �Է¹޾Ƽ� 
   ���ݱ����� �����͵��� �������� �������� �����͸� �����Ͽ� ����
 - ������ �ð� �������� ����� �����͵��� ��������
   ���� ������ �ð� ���� ���� �����͸� �߰�(&�� �����Ͽ� ������Ʈ)
   
   ���� ���, 1�� 2�� 3���� ������ ���� �־����� 
   �ܼ� �޼ҵ� ȣ�� �� 4���� ���� �ϳ��� ����
   1, 2, 3�� ���� ���� ���¿��� 8���� ������ ��� ������
   4, 5, 6, 7, 8���� ���� ��� �����Ͽ� ��ü�� ����

*/

#pragma once

#include "location_origin.hpp"
#include "al_randomwalk.hpp"

#define UPDATE_DAY 3

// ���� �̵���� ���� �˰���
// �������̽��� �����ϸ�,
// ���� �˰����� �� �������� �����Ѵ�.


class MovementPrediction
{
public:

    /* Procedure
     * 
     * ������ ���� : initiate()�� ���� �ʱ� Location(��ǥ, �ð�, ���� ��) ����
     * 
     * predict() : 1ȸ�� ���� ��ƾ (predictCount��ŭ �ݺ�)
     * 
     */

    // �⺻ ������
	MovementPrediction() {};

	// Destructor
	virtual ~MovementPrediction() {};

    // ù ��ü �ʱ�ȭ (���� ���� �ƴ�, �����ϴ� �����͸� �ʱ� ������ �����´�.)
	virtual void initiate() = 0;

    // predict �޼ҵ�� Prediction Ŭ������ �ٽ� ��ƾ����,
    // predictCount Ƚ����ŭ �ݺ������� ����ȴ�.
	virtual void predict() = 0;

	virtual void run() = 0;

	// Setter
	virtual bool setLocation(Location* loc) { return true; };
	virtual bool setTarget(std::string& orgName) { return true; };

	// Getter
	virtual std::string getTagetName() { return nullptr; };

	// Check
	virtual bool isTargetOrganism(Organism* org) { return true; };
	virtual bool isPredictionEnd() { return true; };	// ������ ���� ��ƾ ���� Ƚ���� �����ߴ��� �˻�

};

////////////////////////////////////////////////////////////////////////////////

/*
 Coded by : Sa Min Hong
 Last Updated : 18-12-16

 [ HumpbackWhaleMP ]

 <Explanation>
 - �浿 �� �̵� ��� ���� �˰���. [ MovementPrediction ] Ŭ���� ���

 <To do>
 - RandomWalk Ŭ���� ������ ��.

*/

class HumpbackWhaleMP : public MovementPrediction
{
private:

    // DB pointer
    Organism* m_targetOrganism;	// target Organism to predict
    Location* m_location;			// target Location for algorithm
    
	RandomWalk* randomWalk;					// ���� ��ũ
    std::vector<RWOutput> m_rwOutput;       // ����� ����ȭ �迭
    
    int m_predictCount;                     // ���� ��ƾ ���� Ƚ��
    int m_numberOfWalkers;                  // ���� ������Ŀ ��
    
    Timer m_timer;                          // ������Ŀ�� ���� �ð�
    Point m_point;                          // ������Ŀ�� ��ġ
    
public:

	HumpbackWhaleMP();      // �⺻ ������
	~HumpbackWhaleMP();

	// ������ : Target���κ��� �ʱ� �ð��� �޾� ����� ����, ���� Ƚ�� ����
	HumpbackWhaleMP(Timer timer, int predictCount)
		: m_timer(timer), m_predictCount(predictCount)
	{}

	// ���� ���� = initiate + (predict * count)
	
	// Overridings
    virtual void run()  override;
	virtual void initiate() override;
	virtual void predict() override;

	// 9������ Ȯ�� ��� �޼ҵ�
	void calculate();
	void update();                     // Location DB ������Ʈ 
	
	//void calculateByPreference();       // Ư�� ��ȣ ��ҿ� ���� �� ������ �̵�Ȯ�� ���

	//void updateLocalInfo();             // �̵� ���� ���� ��, m_localInfo ��ġ �̵�

	void timeElapse();                  // ���� �ð� ����

	Point decideDirection(int direction, Point p);
						// ���� ���� ������ ������Ŀ ��ü�κ��� �̵�Ȯ���� �о�, �̵� ���� ����

	std::vector<RWOutput> getRWOutput();    // ����ȭ �迭 ��ȯ

	// input
	void inputPredictCount(const int& count);

	// setter
	virtual bool setLocation(Location* loc);
	virtual bool setTarget(std::string& orgName);

	// getter
	virtual std::string getTagetName();

	// check
	virtual bool isTargetOrganism(Organism* org);
	virtual bool isPredictionEnd();
};

#pragma region HumpbackWhaleMP_Constructor
HumpbackWhaleMP::HumpbackWhaleMP()
{
	randomWalk = new RandomWalk();
	m_predictCount = 0;
	m_numberOfWalkers = 0;
}

//HumpbackWhaleMP::HumpbackWhaleMP(Timer timer, int predictCount)
//{
//	// ������Ŀ ù ��ü�� ��ġ ����
//	m_point = m_targetOrganism->getOrgPoint();
//}
#pragma endregion

#pragma region HumpbackWhaleMP_Destructor
HumpbackWhaleMP::~HumpbackWhaleMP()
{
	delete[] m_location;
	delete[] m_targetOrganism;
}
#pragma endregion

#pragma region HumpbackWhaleMP_Setter
bool HumpbackWhaleMP::setLocation(Location* loc)
{
	if (loc != nullptr)
	{
		m_location = loc;
		return true;
	} return false;
}

bool HumpbackWhaleMP::setTarget(std::string& orgName)
{
	//debug
	std::cout << "Find org Name = " << orgName << std::endl;

	if (isTargetOrganism(m_location->getTarget(orgName)))
	{
		this->m_targetOrganism = m_location->getTarget(orgName);
		return true;
	} return false;
}


#pragma endregion


#pragma region HumpbackWhaleMP_Getter
std::string HumpbackWhaleMP::getTagetName()
{
	assert(m_targetOrganism != nullptr && "Target is NULLPTR!!");
	return m_targetOrganism->getOrganismName();
}
#pragma endregion


#pragma region HumpbackWhaleMP_Check
bool HumpbackWhaleMP::isPredictionEnd()
{
	if (m_numberOfWalkers > m_predictCount)
		return true;
	else
		return false;
}

bool HumpbackWhaleMP::isTargetOrganism(Organism* org)
{
	if (org != nullptr)
		return true;
	else
		return false;
}
#pragma endregion




#pragma region Public Functions

void HumpbackWhaleMP::run()
{
    initiate();
    predict();
}

void HumpbackWhaleMP::initiate()
{
	// ������Ŀ ��� �迭�� 0�� ��ü �ʱ�ȭ (�ʱ� ������ ��ġ)
	m_rwOutput.push_back(RWOutput(m_location->getTime(), m_targetOrganism->getOrgPoint()));

	// ���� ��Ŀ ��� ����
	m_numberOfWalkers = 1;

	// ���� Ƚ�� �Է�
	int count;
	std::cin >> count;
	inputPredictCount(count);
}

void HumpbackWhaleMP::predict()
{
	// �� �� ����� ������, ���� ��Ŀ ��ü�� �ϳ� �����Ͽ� ���Ϳ� �߰��Ѵ�.
	// Prototype : ������ 3��(3�ϸ��� 1����(110km����)�� �̵�)

	// ���� ��ƾ �ݺ� :  ���� Ƚ���� ������ ��� ����
	while (!isPredictionEnd())
	{
		// ������Ŀ ���� ���� �����ϴ� ������ ��ü�� ���� �̵� Ȯ�� ���
		calculate();

		// ���Ϳ� ���� ��Ŀ ��ü �ϳ� �߰�
		update();
	}
}

void HumpbackWhaleMP::calculate()
{
	/* 2018.12.16 ~ TODO ***********************************
	 *
	 * 1. ���� �߻����Ѽ� �̵��� ���� ����
	 * 2. ������ �������� �̵� (doRandomWalk() �޼ҵ� ���� �� ȣ��)
	 * 3. �̵��� �������� ���ο� ������Ŀ ��� ���� ����(���� ���ܿ� push_back)
	 * 4. ~�ݺ��Ͽ� ������Ŀ ����� �̷���� �迭�� ������
	 * ******************************************************
	 */

	 // ���� ������Ŀ�� 9���� �̵� Ȯ���� �а�, �������� ���� ����
	RWOutput output;
	int direction = randomWalk->doRandomWalk(*m_targetOrganism, *m_location);

	output.time = m_location->getTime();
	output.point = decideDirection(direction, m_targetOrganism->getOrgPoint());

	// ������Ŀ ���Ϳ� ��ü �ϳ� �߰�, ��ü �� ����
	m_rwOutput.push_back(output);
}

void HumpbackWhaleMP::update()
{
	// ���� �ð� ����
	timeElapse();

    // TO DO �̵��� ��ǥ�� ����, �ش� ���� ������ �ǽð����� ������Ʈ

	//m_randomWalk.push_back(RandomWalk(m_point, m_timer));
	m_numberOfWalkers++;
}

void HumpbackWhaleMP::timeElapse()
{
	// ���� �ð� ���� : 3��
	m_location->updateDay(UPDATE_DAY);
}

Point HumpbackWhaleMP::decideDirection(int direction, Point p)
{
	if (direction == 0) { p.xpos -= 1; p.ypos += 1; }
	else if (direction == 1) { p.ypos += 1; }
	else if (direction == 2) { p.xpos += 1; p.ypos += 1; }
	else if (direction == 3) { p.xpos -= 1; }
	else if (direction == 4) { }
	else if (direction == 5) { p.xpos += 1; }
	else if (direction == 6) { p.xpos -= 1; p.ypos -= 1; }
	else if (direction == 7) { p.ypos -= 1; }
	else if (direction == 8) { p.xpos += 1; p.ypos -= 1; }

	return p;
}

// ����ȭ �迭 ��ȯ
std::vector<RWOutput> HumpbackWhaleMP::getRWOutput()
{
	return m_rwOutput;
}

void HumpbackWhaleMP::inputPredictCount(const int& count)
{
	m_predictCount = count;
}
#pragma endregion

