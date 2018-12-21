/* 

******************************************************
					MIT License
			Copyright (c) 2018 CSID-DGU
******************************************************


Coded by : Sa Min Hong
Last Updated : 18-11-05

[ Timer ]

<Explanation>

기본 형태 : int[6] 배열

0 - YEAR
1 - MONTH
2 - DAY
3 - HOUR
4 - MINUTE
5 - SECOND

<<기능>>

*. 내부 동작을 위한 private 함수들 구현(설명 생략)

	이하 public 함수들

1. int 배열 매개변수, 6개의 int 매개변수, string 매개변수
	세 가지의 생성자 구현

2. 1과 같은 세 가지의 Setter

3. int 배열을 리턴하는 Getter
4. 날짜(YYYY-MM-DD) 스트링을 리턴하는 Getter
5. 시간(hh:mm:ss) 스트링을 리턴하는 Getter
6. 날짜+시간 (YYYY-MM-DD hh:mm:ss) 스트링을 리턴하는 Getter

7. 연, 월, 일, 시, 분, 초 각각의 Add, Sub 연산 함수 구현

8. 표준 형태(YYYY-MM-DD hh:mm:ss)로 화면에 즉각 출력하는
	show() 함수 구현

9. std::cout을 위한 << 연산자 오버로딩
10. 두 시간의 일치여부를 판단하기 위한 ==, != 연산자 오버로딩



<To do>

*/

#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>  // assert

class Timer
{
    enum DateTime
    {
        YEAR, MONTH,  DAY,
        HOUR, MINUTE, SECOND,
        TIMER_SIZE
    };

private:
    int* time = nullptr;                                            // 연-월-일 시:분:초

    // 해당 월의 일수 : 0월은 12월로 간주, 31일로 세팅(Subtraction 연산 고려)
    const int daysOfMonth[13] = { 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    bool isDigit    (char ch){ return ('0' <= ch && ch <= '9'); }   // 해당 문자가 숫자인지 검사
    bool isLeapYear () { return (this->time[YEAR] % 4 == 0); }      // 윤년 검사

    int  wrapCycle  (int, int, int);                                // 상한,하한을 벗어나면 나머지 연산을 이용해
    //                                                                 기준 값으로 돌아오도록 하는 순환형 Wrapper
    int  getDaysOfMonth();                                          // 해당 월의 일수 리턴
    int  getDaysOfLastMonth();                                      // 지난 달의 일수 리턴

    void zeroConcat (std::string&, char, int&, std::string);        // 날짜 및 시간 스트링 연결용 함수
    void timeAssert ();                                             // 제약사항 검사
    void timeCycle  (int&, int&, int, int);                         // arrangeTime을 위한, 날짜 상한/하한 루프 함수
    void arrangeTime(bool repeat = true);                           // 시간 계산 시, 범위에 맞게 각각 조정

public:
    Timer() { this->time = new int[TIMER_SIZE] { 2000, 01, 01, 00, 00, 00 }; }  // 기본 생성자
    Timer(int time[]);                                                          // 배열 매개변수 생성자
    Timer(int year, int month, int day, int hour, int minute, int second);      // 개별 매개변수 생성자
    Timer(std::string time);                                                    // 스트링 매개변수 생성자
    ~Timer() { if(this->time != nullptr) delete [] this->time; }                // 소멸자

    void setTime(int time[]);             // Setter
    void setTime(int year, int month, int day, int hour, int minute, int second);
    void setTime(std::string time);

    int* getTime() { return this->time; } // Getter
    std::string getDateString();          // 날짜(YYYY-MM-DD) 리턴
    std::string getTimeString();          // 시간(hh:mm:ss) 리턴
    std::string getString();              // 날짜+시간 (YYYY-MM-DD hh:mm:ss) 리턴

    void show() { std::cout << getString() << std::endl; }

    void addYear  (int year   = 1);           // Addition
    void addMonth (int month  = 1);
    void addDay   (int day    = 1);
    void addHour  (int hour   = 1);
    void addMinute(int minute = 1);
    void addSecond(int second = 1);

    void addDate(std::string dateString);     // 필요하면 구현할 예정 1
    void addTime(std::string timeString);

    void subYear  (int year   = 1);           // Subtraction
    void subMonth (int month  = 1);
    void subDay   (int day    = 1);
    void subHour  (int hour   = 1);
    void subMinute(int minute = 1);
    void subSecond(int second = 1);

    void subDate(std::string dateString);     // 필요하면 구현할 예정 2
    void subTime(std::string timeString);

    // Operators overloading
    friend std::ostream& operator << (std::ostream& os, Timer& timer);
    bool   operator == (Timer& timer);
    bool   operator != (Timer& timer);
    Timer& operator += (std::string timerString);   // 필요하면 구현할 예정 3
    Timer& operator -= (std::string timerString);
    Timer  operator +  (std::string timerString);
    Timer  operator -  (std::string timerString);

    // Getters
    int getYear()   { return this->time[YEAR];   }
    int getMonth()  { return this->time[MONTH];  }
    int getDay()    { return this->time[DAY];    }
    int getHour()   { return this->time[HOUR];   }
    int getMinute() { return this->time[MINUTE]; }
    int getSecond() { return this->time[SECOND]; }
};




/* Implementation */


#pragma region Constructors

Timer::Timer(int time[])
{
    setTime(time);
}

Timer::Timer(int year, int month, int day, int hour, int minute, int second)
{
    setTime(year, month, day, hour, minute, second);
}

Timer::Timer(std::string time)
{
    setTime(time);
}

#pragma endregion

#pragma region private functions

int Timer::wrapCycle(int value, int min, int max)
{
    while(value < min)
        value += max;

    return value % max;
}

int Timer::getDaysOfMonth()
{
    int month = wrapCycle(this->time[MONTH], 1, 12);

    return (isLeapYear() && month == 2) ? 29 : daysOfMonth[month];
}

int Timer::getDaysOfLastMonth()
{
    int lastMonth = wrapCycle(this->time[MONTH] - 1, 1, 12);

    return (isLeapYear() && lastMonth == 2) ? 29 : daysOfMonth[lastMonth];
}

void Timer::zeroConcat(std::string& originalString, char token, int& value, std::string valueString)
{
    originalString += token + (value > 9 ? valueString : "0" + valueString);
}

void Timer::timeAssert()
{
    assert(this->time[YEAR]   >= 0 &&                                          "Wrong YEAR value");
    assert(this->time[MONTH]  >= 1 && this->time[MONTH] <= 12 &&               "Wrong MONTH value");
    assert(this->time[DAY]    >= 1 && this->time[DAY]   <= getDaysOfMonth() && "Wrong DAY value");

    assert(this->time[HOUR]   >= 0 && this->time[HOUR]   < 24 && "Wrong HOUR value");
    assert(this->time[MINUTE] >= 0 && this->time[MINUTE] < 60 && "Wrong MINUTE value");
    assert(this->time[SECOND] >= 0 && this->time[SECOND] < 60 && "Wrong SECOND value");
}

void Timer::timeCycle(int& value, int& next, int lowerLimit, int upperLimit)
{
    while(value >= upperLimit)
    {
        value -= upperLimit;
        next++;
    }

    while(value < lowerLimit)
    {
        value += upperLimit;
        next--;
    }
}

void Timer::arrangeTime(bool repeat)
{
    timeCycle(this->time[SECOND], this->time[MINUTE], 0, 60);    // second -> minute
    timeCycle(this->time[MINUTE], this->time[HOUR],   0, 60);    // minute -> hour
    timeCycle(this->time[HOUR],   this->time[DAY],    0, 24);    // hour -> day

    while (this->time[DAY] > getDaysOfMonth())   // day -> month, month -> year
    {
        this->time[DAY] -= getDaysOfMonth();
        this->time[MONTH]++;

        if(this->time[MONTH] > 12)
        {
            this->time[MONTH] -= 12;
            this->time[YEAR]++;
        }
    }
    
    while (this->time[DAY] < 1)
    {
        this->time[DAY] += getDaysOfLastMonth();
        this->time[MONTH]--;

        if (this->time[MONTH] < 1)
        {
            this->time[MONTH] += 12;
            this->time[YEAR]--;
        }
    }

    while (this->time[MONTH] > 12)   // month -> year
    {
        this->time[MONTH] -= 12;
        this->time[YEAR]++;
    }

    while (this->time[MONTH] < 1)
    {
        this->time[MONTH] += 12;
        this->time[YEAR]--;
    }

    if(repeat)  // 조정 후, 재조정 1회
        arrangeTime(false);
}

#pragma endregion


/* public functions */

#pragma region Setter

void Timer::setTime(int time[])
{
    this->time = new int[TIMER_SIZE];

    for (int i = YEAR; i < TIMER_SIZE; i++)
        this->time[i] = time[i];

    timeAssert();
}

void Timer::setTime(int year, int month, int day, int hour, int minute, int second)
{
    this->time = new int[TIMER_SIZE];

    this->time[YEAR]   = year;
    this->time[MONTH]  = month;
    this->time[DAY]    = day;
    this->time[HOUR]   = hour;
    this->time[MINUTE] = minute;
    this->time[SECOND] = second;

    timeAssert();
}

void Timer::setTime(std::string time)
{
    this->time = new int[TIMER_SIZE];

    std::string strTime[TIMER_SIZE] = { "", };
    int         timeIterator        = YEAR;
    bool        nextIter            = false;

    for(const auto& ch : time)
    {
        if(isDigit(ch))                     // 숫자인 경우
        {
            strTime[timeIterator] += ch;    // 해당 TIME 원소의 스트링 이어붙이기
            nextIter = true;
        }
        else                               // 숫자가 아니면 무시
        {
            if(nextIter)
            {
                nextIter = false;
                timeIterator++;            // 다음 TIME 원소로 이동
            }
        }
    }
    
    for(int i = YEAR; i < TIMER_SIZE; i++)
        this->time[i] = std::stoi(strTime[i]);

    timeAssert();
}

#pragma endregion

#pragma region Getter

std::string Timer::getDateString()
{
    std::string dateString = std::to_string(time[YEAR]);

    zeroConcat(dateString, '-', time[MONTH], std::to_string(time[MONTH]));
    zeroConcat(dateString, '-', time[DAY],   std::to_string(time[DAY]));

    return dateString;
}

std::string Timer::getTimeString()
{
    std::string timeString = time[HOUR] > 9 ? 
                std::to_string(time[HOUR]) : "0" + std::to_string(time[HOUR]);

    zeroConcat(timeString, ':', time[MINUTE], std::to_string(time[MINUTE]));
    zeroConcat(timeString, ':', time[SECOND], std::to_string(time[SECOND]));

    return timeString;
}

std::string Timer::getString()
{
    return getDateString() + " " + getTimeString();
}

#pragma endregion

#pragma region Calculations

void Timer::addYear(int year)
{
    this->time[YEAR] += year;

    arrangeTime();
}

void Timer::addMonth(int month)
{
    this->time[MONTH] += month;

    arrangeTime();
}

void Timer::addDay(int day)
{
    this->time[DAY] += day;

    arrangeTime();
}

void Timer::addHour(int hour)
{
    this->time[HOUR] += hour;

    arrangeTime();
}

void Timer::addMinute(int minute)
{
    this->time[MINUTE] += minute;

    arrangeTime();
}

void Timer::addSecond(int second)
{
    this->time[SECOND] += second;

    arrangeTime();
}
/*
void Timer::addDate(std::string dateString);
void Timer::addTime(std::string timeString);
*/

void Timer::subYear(int year)
{
    this->time[YEAR] -= year;

    arrangeTime();
}

void Timer::subMonth(int month)
{
    this->time[MONTH] -= month;

    arrangeTime();
}

void Timer::subDay(int day)
{
    this->time[DAY] -= day;

    arrangeTime();
}

void Timer::subHour(int hour)
{
    this->time[HOUR] -= hour;

    arrangeTime();
}

void Timer::subMinute(int minute)
{
    this->time[MINUTE] -= minute;

    arrangeTime();
}

void Timer::subSecond(int second)
{
    this->time[SECOND] -= second;

    arrangeTime();
}


/*
void Timer::subDate(std::string dateString);
void Timer::subTime(std::string timeString);
*/
#pragma endregion

#pragma region Operators Overloading

std::ostream& operator << (std::ostream& os, Timer& timer)
{
    os << timer.getString();

    return os;
}

bool Timer::operator == (Timer& timer)
{
    for (int i = YEAR; i < TIMER_SIZE; i++)
        if (this->time[i] != timer.time[i])  // 다른 것 발견하면 false 조기 리턴
            return false;

    return true;
}

bool Timer::operator != (Timer& timer)
{
    for (int i = YEAR; i < TIMER_SIZE; i++)
        if (this->time[i] != timer.time[i])  // 다른 것 발견하면 true 조기 리턴
            return true;

    return false;
}
/*
Timer& Timer::operator += (std::string timerString);
Timer& Timer::operator -= (std::string timerString);
Timer Timer::operator + (std::string timerString);
Timer Timer::operator - (std::string timerString);
*/

#pragma endregion