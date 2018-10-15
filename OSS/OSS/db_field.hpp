// 작성자 : 신종하

#pragma once
#include "db_origin.hpp"

class FieldDataBase : public DataBase
{
	enum WHETHERSTATUS
	{
		SUNNEY, CLOUDY, RAINY, SNOWY
	};

	struct Whether
	{
		int temperature;
		int wind_speed;
		WHETHERSTATUS status;
	};

private:
	
public:
	std::vector<Position> coordinate;
	Whether whether;
};