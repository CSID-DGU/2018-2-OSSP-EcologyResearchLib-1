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
    
    std::vector<RandomWalk> m_randomWalk;   // ������Ŀ �迭 = ������ �̵� ���
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
	void addWalker();                   // ������Ŀ ��ü 1�� �߰�
	
	//void calculateByPreference();       // Ư�� ��ȣ ��ҿ� ���� �� ������ �̵�Ȯ�� ���

	//void updateLocalInfo();             // �̵� ���� ���� ��, m_localInfo ��ġ �̵�

	void timeElapse();                  // ���� �ð� ����

	Direction decideDirection();        // ���� ���� ������ ������Ŀ ��ü�κ��� �̵�Ȯ���� �о�, �̵� ���� ����

	void transformRWArray();            // ������Ŀ �迭 -> ����ȭ �迭 ��ȯ

	std::vector<RWOutput> getRWOutput();    // ����ȭ �迭 ��ȯ

	void randomGenerate(std::vector<int>& rVec);

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
	// ������Ŀ �迭�� 0�� ��ü �ʱ�ȭ
	m_randomWalk.push_back(RandomWalk(m_point, m_timer));

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

void HumpbackWhaleMP::calculate()
{
	// ��� : ���� ���� ��Ŀ ������ ������ ��ü
	// 9���� ������ ���� �̵� Ȯ���� ����Ͽ� ������Ŀ ��ü�� ������Ʈ
     
    int     targetPossibility[3][3] = { 0, }; // 9�� ��ġ�� Ȯ��
    Point     targetPoint[3][3];    // 9�� ��ġ�� ��ǥ ��
    LocalInfo targetInfo[3][3];     // 9�� ��ġ�� Local ����
    STATUS    targetStatus = m_targetOrganism->getOrgStatus();  // Ÿ�� ����ü�� ����

    // Ȯ�� ����ġ
    int warmTemperatureWeight;
    int coldTemperatureWeight;
    int preyWeight;

    // 9���� ��ǥ ��, �߽� ��ǥ ��������
    targetPoint[1][1] = m_targetOrganism->getOrgPoint();
    
    // ������ 9���� ��ǥ ���
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
            targetPoint[i][j].xpos = targetPoint[1][1].xpos + (i - 1);
            targetPoint[i][j].ypos = targetPoint[1][1].ypos + (j - 1);
        }

    // 9���� LocalInfo ��������
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            targetInfo[i][j] = m_location->getLocalInfo(targetPoint[i][j]);
        }

    /* ���� ��ҵ��� �̿��� ����ġ ���*/

    if(targetStatus == BREEDING)
    {
        warmTemperatureWeight = 7;
        coldTemperatureWeight = 2;
        preyWeight = 3;
    }
    else
    {
        warmTemperatureWeight = 1;
        coldTemperatureWeight = 3;
        preyWeight = 6;
    }

    // �߾� ��ġ�� �µ� ��
    int centerTemerature = m_location->getWaterTemperature(targetPoint[4][4]);

    // ����
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (const auto& orgMember : targetInfo[i][j].localOrganisms)
            {
                // 1. �ش� ��ġ�� ũ�� ���찡 ���� ���
                if(orgMember->getOrganismName() == "Krill")
                    targetPossibility[i][j] += preyWeight;   // ����ġ ����

                // 2. �µ�
                if(targetStatus == BREEDING)
                {
                    // �ֺ��� �µ��� �߾Ӻ��� ���� ���
                    if (m_location->getWaterTemperature(targetPoint[i][j]) > centerTemerature)
                    {
                        targetPossibility[i][j] += warmTemperatureWeight;   // ����ġ ����
                    }
                }
                else    // NONBREEDING
                {
                    // �ֺ��� �µ��� �߾Ӻ��� ���� ���
                    if (m_location->getWaterTemperature(targetPoint[i][j]) < centerTemerature)
                    {
                        targetPossibility[i][j] += coldTemperatureWeight;   // ����ġ ����
                    }
                }

                
            }

	// LAST. �ֺ� ���� �̵� ���ɼ� �Ǵ� (�̵� �Ұ��� : 0 �ʱ�ȭ)
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            // �ش� ���� ��ġ�� �ٴٰ� �ƴ� ��� : �̵� Ȯ���� 0���� �ʱ�ȭ
            if(targetInfo[i][j].localState[2] != SEA)
                targetPossibility[i][j] = 0;
        }

	// Ȯ�� ���
	std::vector<int> randVec;
	int arrNum = 0;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			int randNum = targetPossibility[i][j];
			
			while (randNum--)
				randVec.push_back(arrNum);

			arrNum++;
		}

	// �̵� ��ǥ ����
	randomGenerate(randVec);
	
	
}

void HumpbackWhaleMP::addWalker()
{
	// ���ͷ����� : ���� ������ ���� ���ܿ� �ִ� ���� ��Ŀ
	const RandomWalk& iterator = m_randomWalk[m_numberOfWalkers - 1];


    /* 2018.12.16 ~ TODO ***********************************
     *
     * 1. ���� �߻����Ѽ� �̵��� ���� ����
     * 2. ������ �������� �̵� (moveWalker(����) �޼ҵ� ���� �� ȣ��)
     * 3. �̵��� �������� ���ο� ������Ŀ ��ü ����(���� ���ܿ� push_back)
     * 4. ~�ݺ��Ͽ� ������Ŀ ���Ͱ� ������
     * 5. ������ ���͸� ����ȭ �迭�� ��ȯ(�����Ǿ�����, ���� �ʿ�) => ����ȭ �迭 ��ȯ
     *
     * ******************************************************
     */


    // ���� ������Ŀ�� 9���� �̵� Ȯ���� �а�, �������� ���� ����


	// ������ �������� �̵�
    // moveWalker(direction);

	// ���� �ð� ����
	timeElapse();

    // �̵��� ��ǥ�� ����, �ش� ���� ������ �ǽð����� ������Ʈ
	// ������Ŀ ���Ϳ� ��ü �ϳ� �߰�, ��ü �� ����
	m_randomWalk.push_back(RandomWalk(m_point, m_timer));
	m_numberOfWalkers++;
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
		// m_rwOutput.push_back(RWOutput(walker.getLocalInfo().pos, walker.getTimer().getTimeString()));
	}
}

// ����ȭ �迭 ��ȯ
std::vector<RWOutput> HumpbackWhaleMP::getRWOutput()
{
	return m_rwOutput;
}

void HumpbackWhaleMP::randomGenerate(std::vector<int>& rVec)
{
	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(rVec.begin(), rVec.end(), g);
}
#pragma endregion

