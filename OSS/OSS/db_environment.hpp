/* 

******************************************************
					MIT License
			Copyright (c) 2018 CSID-DGU
******************************************************

Coded by : Jong Ha Sin
Last Updated : 18-12-11


[ Environment ] 

<Explanation>
- �˰��� �ʿ��� ȯ�� ���� ���� Ŭ����
- Location Ŭ������ subset

<To do>
- RandomWalk Ŭ�������� Ȥ����� ������ ������ �� �� waterTemperature Ȱ��
- �ܿ￡�� ������ ������ �̵��� ����Ȱ�� => �������� ���������� �̵��� ���İ� ��������
   ==> season Ȱ��

*/

#pragma once
// ���� ����
//enum WEATHERSTATUS
//{
//	SUNNEY, CLOUDY, RAINY, SNOWY
//};

//enum SEASON
//{
//	SPRING, SUMMER, FALL, WINTER
//};

class Environment
{
	//int airTemperature; // ���
	int waterTemperature; // ����
	//int wind_speed;  // ǳ��
	//WEATHERSTATUS status; 
	//SEASON season;
	

public:
	Environment() {}
	~Environment() {}

	//void setAirTemperature(int temp) { airTemperature = temp; }
	//int getAirTemperature() { return airTemperature; }

	// Setter
	void setWaterTemperature(int temp);

	// Getter 
	int getWaterTemperature();
};

#pragma region Environment_Setter
void Environment::setWaterTemperature(int temp)
{
	waterTemperature = temp;
}
#pragma endregion

#pragma region Environment_Getter
int Environment::getWaterTemperature()
{
	return waterTemperature;
}
#pragma endregion