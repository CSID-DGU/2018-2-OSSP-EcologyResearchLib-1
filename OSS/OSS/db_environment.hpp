/* 

******************************************************
					MIT License
			Copyright (c) 2018 CSID-DGU
******************************************************

Coded by : Jong Ha Sin
Last Updated : 18-12-11


[ Environment ] 

<Explanation>
- 알고리즘에 필요한 환경 변수 관리 클래스
- Location 클래스의 subset

<To do>
- RandomWalk 클래스에서 혹등고래의 움직임 예측을 할 때 waterTemperature 활용
- 겨울에는 따뜻한 적도로 이동해 포육활동 => 여름에는 극지방으로 이동해 섭식과 지방축적
   ==> season 활용

*/

#pragma once
// 날씨 상태
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
	//int airTemperature; // 기온
	int waterTemperature; // 수온
	//int wind_speed;  // 풍속
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