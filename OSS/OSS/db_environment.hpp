// Coded by : ������

#pragma once

class Environment
{
	enum WEATHERSTATUS
	{
		SUNNEY, CLOUDY, RAINY, SNOWY
	};

	int temperature;
	int wind_speed;
	WEATHERSTATUS status;

public:
	Environment() {}
	~Environment() {}
};
