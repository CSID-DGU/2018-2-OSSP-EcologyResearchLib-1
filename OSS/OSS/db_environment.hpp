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
#include "db_watertemperature.hpp"

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
	WaterTemperatureDB waterTemperature; // 수온
	//int wind_speed;  // 풍속
	//WEATHERSTATUS status; 
	//SEASON season;
	

public:
	Environment() {}
	~Environment() {}

	//void setAirTemperature(int temp) { airTemperature = temp; }
	//int getAirTemperature() { return airTemperature; }

	void setWaterTemperature(int temp) {  }
	WaterTemperatureDB getWaterTemperature() { return waterTemperature; }

};
