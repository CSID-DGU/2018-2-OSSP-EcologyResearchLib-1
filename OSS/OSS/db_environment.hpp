// Coded by : Ω≈¡æ«œ

#pragma once

class Environment
{
	enum WHETHERSTATUS
	{
		SUNNEY, CLOUDY, RAINY, SNOWY
	};

	int temperature;
	int wind_speed;
	WHETHERSTATUS status;

public:
	Environment() {}
	~Environment() {}
};
