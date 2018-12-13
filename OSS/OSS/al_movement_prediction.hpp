/*

******************************************************
					MIT License					
			Copyright (c) 2018 CSID-DGU					
******************************************************

 Coded by : Sa Min Hong
 Last Updated : 18-12-11


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

#include "location_origin.hpp"
#include "al_randomwalk.hpp"


// ���� �̵���� ���� �˰���
// �������̽��� �����ϸ�,
// ���� �˰����� �� �������� �����Ѵ�.


class MovementPrediction
{
protected:
    //int m_predictCount;   // ���� ��ƾ ���� Ƚ��
	Organism* targetOrganism;	// target Organism to predict
	Location* location;	// target Location for algorithm

public:

    /* Procedure
     * 
     * ������ ���� : initiate()�� ���� �ʱ� Location(��ǥ, �ð�, ���� ��) ����
     * 
     * predict() : 1ȸ�� ���� ��ƾ (predictCount��ŭ �ݺ�)
     * 
     */

    // �⺻ ������
	MovementPrediction();

	// Destructor
	virtual ~MovementPrediction();

    // ù ��ü �ʱ�ȭ (���� ���� �ƴ�, �����ϴ� �����͸� �ʱ� ������ �����´�.)
	virtual void initiate() {};

    // predict �޼ҵ�� Prediction Ŭ������ �ٽ� ��ƾ����,
    // predictCount Ƚ����ŭ �ݺ������� ����ȴ�.
	virtual void predict() {};

	// Setter
	bool setLocation(Location* loc);
	bool setTarget(std::string& orgName);

	// Getter
	std::string getTagetName();

	// Check
	bool isTargetOrganism(Organism* org);

};


#pragma region MovementPrediction_Constructor
MovementPrediction::MovementPrediction()
{

}
#pragma endregion

#pragma region MovementPrediction_Destructor
MovementPrediction::~MovementPrediction()
{
	delete[] targetOrganism;
	delete[] location;
}
#pragma endregion

#pragma region MovementPredcitor_Setter
bool MovementPrediction::setLocation(Location* loc)
{
	if (loc != nullptr)
	{
		location = loc;
		return true;
	} return false;
}

bool MovementPrediction::setTarget(std::string& orgName)
{
	//debug
	std::cout << "Find org Name = " << orgName << std::endl;

	if (isTargetOrganism(location->getTarget(orgName)))
	{
		this->targetOrganism = location->getTarget(orgName);
		return true;
	} return false;
}

bool MovementPrediction::isTargetOrganism(Organism* org)
{
	if (org != nullptr)
		return true;
	else
		return false;
}

#pragma endregion


#pragma region MovementPrediction_Getter
std::string MovementPrediction::getTagetName()
{
	assert(targetOrganism != nullptr && "Target is NULLPTR!!");
	return targetOrganism->getOrganismName();
}
#pragma endregion



////////////////////////////////////////////////////////////////////////////////

/*
 Coded by : Sa Min Hong
 Last Updated : 18-11-05

 [ HumpbackWhaleMP ]

 <Explanation>
 - �浿 �� �̵� ��� ���� �˰���. [ MovementPrediction ] Ŭ���� ���

 <To do>
 - RandomWalk Ŭ���� ������ ��.

*/

//#include "al_algorithm.hpp"

// Ȥ���(Humpback Whale) �̵���� ����(MP) �˰���
class HumpbackWhaleMP : public MovementPrediction
{
	/*
	protected:
		int m_predictCount;   // ���� ��ƾ ���� Ƚ��
	*/

private:
	// ������Ŀ �迭 = ������ �̵� ���
	std::vector<RandomWalk> m_randomWalk;
	// ����� ����ȭ �迭
	std::vector<RWOutput> m_rwOutput;
	// ���� ��ƾ ���� Ƚ��
	int m_predictCount;
	// ���� ������Ŀ ��
	int m_numberOfWalkers;

	// ������Ŀ ��ü�� ��ġ�� ��ǥ��, �ش� ��ǥ�� ��ġ ����
	// �˰��� ���� ��, Target���κ��� LocalInfo �޾ƿ�(������)
	// ���� ������ ������, ������Ʈ�Ͽ� ������ ������Ŀ�� ������ ��� ��
	LocalInfo m_localInfo;
	// �ð� : localInfo�� ��Ʈ
	Timer m_timer;

	// ������ ���� ��ƾ ���� Ƚ���� �����ߴ��� �˻�
	bool isPredictionEnd();


public:

	HumpbackWhaleMP();

	// ������ : Target���κ��� LocalInfo, �ʱ� �ð��� �޾� ����� ����, ���� Ƚ�� ����
	HumpbackWhaleMP(LocalInfo localInfo, Timer timer, int predictCount)
		: m_localInfo(localInfo), m_timer(timer), m_predictCount(predictCount) {}

	// ���� ���� = initiate + (predict * count)
	void run();

	// Overridings
	virtual void initiate() override;
	virtual void predict() override;

	// 9������ Ȯ�� ��� �޼ҵ� : ������Ŀ ����� 2���� �ʵ� ������ ����
	void calculate(/*int leftX, int topY, int rightX, int bottomY*/);
	// ������Ŀ ��ü 1�� �߰�
	void addWalker();
	// Ư�� ��ȣ ��ҿ� ���� �� ������ �̵�Ȯ�� ���
	void calculateByPreference() {};

	// �̵� ���� ���� ��, m_localInfo ��ġ �̵�
	void updateLocalInfo();

	// ���� �ð� ����
	void timeElapse();

	// ���� ���� ������ ������Ŀ ��ü�κ��� �̵�Ȯ���� �о�, �̵� ���� ����
	Direction decideDirection();

	// ������Ŀ �迭 -> ����ȭ �迭 ��ȯ
	void transformRWArray();

	// ����ȭ �迭 ��ȯ
	std::vector<RWOutput> getRWOutput();
};

#pragma region HumpbackWhaleMP_Constructor
HumpbackWhaleMP::HumpbackWhaleMP()
{

}

#pragma endregion

#pragma region Private Fuctions

bool HumpbackWhaleMP::isPredictionEnd()
{
	if (m_numberOfWalkers > m_predictCount)
		return true;
	else
		return false;
}

#pragma endregion

#pragma region Public Functions

void HumpbackWhaleMP::initiate()
{
	// ������Ŀ �迭�� 0�� ��ü �ʱ�ȭ
	m_randomWalk.push_back(RandomWalk(m_localInfo, m_timer));

	// ���� ������Ŀ�� �� ��
	m_numberOfWalkers = 1;
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
		addWalker();
	}
}

void HumpbackWhaleMP::calculate(/*int leftX, int topY, int rightX, int bottomY*/)
{
	// ��� : ���� ���� ��Ŀ ������ ������ ��ü
	// 9���� ������ ���� �̵� Ȯ���� ����Ͽ� ������Ŀ ��ü�� ������Ʈ


	// TODO !!!!!!!


	/* �� ��ȣ ��Ҹ��� ��� ���� */

	// ��ü ����
	calculateByPreference(/* state */);

	// ����
	calculateByPreference(/* temperature */);

	// LAST. �ֺ� ���� �̵� ���ɼ� �Ǵ� (�̵� �Ұ��� : 0 �ʱ�ȭ)
	calculateByPreference(/* ���� */);
}

void HumpbackWhaleMP::addWalker()
{
	// ���ͷ����� : ���� ������ ���� ���ܿ� �ִ� ���� ��Ŀ
	//const RandomWalk& iterator = m_randomWalk[m_numberOfWalkers - 1];

	// �ٷ� ���� ������Ŀ�� Ȯ���� ���� ��ǥ �̵�
	// �̵��� ��ǥ�� ����, �ش� ���� ������ �ǽð����� ������Ʈ
	updateLocalInfo();
	// ���� �ð� ����
	timeElapse();

	// ������Ŀ ���Ϳ� ��ü �ϳ� �߰�, ��ü �� ����
	m_randomWalk.push_back(RandomWalk(m_localInfo, m_timer));
	m_numberOfWalkers++;
}

void HumpbackWhaleMP::updateLocalInfo()
{
	// ������ ������Ŀ�� Ȯ���κ��� ���� ����Ͽ� ���� ����
	Direction nextDirection = decideDirection();

	/* TODO : ������ ���⿡ ���� m_localInfo ��ġ �̵� */

	/* TODO : localInfo ���� �ǽð� ������Ʈ */
}

void HumpbackWhaleMP::timeElapse()
{
	// ���� �ð� ���� : 3��
	m_timer.addDay(3);
}

Direction HumpbackWhaleMP::decideDirection()
{
	// TODO : ���� �߻� �ʿ�
	// 9������ Ȯ���� ���� �������� ��ġ ����

	/* return Direction::DECIDED_DIRECTION ! */
	return Direction();
}

// ������Ŀ �迭 -> ����ȭ �迭 ��ȯ
void HumpbackWhaleMP::transformRWArray()
{
	for (RandomWalk& walker : m_randomWalk)
	{
		m_rwOutput.push_back(RWOutput(walker.getLocalInfo().pos, walker.getTimer().getTimeString()));
	}
}

// ����ȭ �迭 ��ȯ
std::vector<RWOutput> HumpbackWhaleMP::getRWOutput()
{
	return m_rwOutput;
}

#pragma endregion

