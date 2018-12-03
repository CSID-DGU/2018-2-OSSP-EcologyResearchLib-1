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
- �˰��� �ʿ��� ȯ�� ���� ���� Ŭ����
- Location Ŭ������ subset

<To do>
- RandomWalk Ŭ�������� Ȥ����� ������ ������ �� �� waterTemperature Ȱ��
- �ܿ￡�� ������ ������ �̵��� ����Ȱ�� => �������� ���������� �̵��� ���İ� ��������
   ==> season Ȱ��

*/

#pragma once
#include "db_watertemperature.hpp"

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
	WaterTemperatureDB waterTemperature; // ����
	//int wind_speed;  // ǳ��
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
