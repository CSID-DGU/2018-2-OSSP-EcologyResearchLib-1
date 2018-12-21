/* 

******************************************************
					MIT License
			Copyright (c) 2018 CSID-DGU
******************************************************


Coded by : Sa Min Hong
Last Updated : 18-11-05

[ Timer ]

<Explanation>

�⺻ ���� : int[6] �迭

0 - YEAR
1 - MONTH
2 - DAY
3 - HOUR
4 - MINUTE
5 - SECOND

<<���>>

*. ���� ������ ���� private �Լ��� ����(���� ����)

	���� public �Լ���

1. int �迭 �Ű�����, 6���� int �Ű�����, string �Ű�����
	�� ������ ������ ����

2. 1�� ���� �� ������ Setter

3. int �迭�� �����ϴ� Getter
4. ��¥(YYYY-MM-DD) ��Ʈ���� �����ϴ� Getter
5. �ð�(hh:mm:ss) ��Ʈ���� �����ϴ� Getter
6. ��¥+�ð� (YYYY-MM-DD hh:mm:ss) ��Ʈ���� �����ϴ� Getter

7. ��, ��, ��, ��, ��, �� ������ Add, Sub ���� �Լ� ����

8. ǥ�� ����(YYYY-MM-DD hh:mm:ss)�� ȭ�鿡 �ﰢ ����ϴ�
	show() �Լ� ����

9. std::cout�� ���� << ������ �����ε�
10. �� �ð��� ��ġ���θ� �Ǵ��ϱ� ���� ==, != ������ �����ε�



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
    int* time = nullptr;                                            // ��-��-�� ��:��:��

    // �ش� ���� �ϼ� : 0���� 12���� ����, 31�Ϸ� ����(Subtraction ���� ���)
    const int daysOfMonth[13] = { 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    bool isDigit    (char ch){ return ('0' <= ch && ch <= '9'); }   // �ش� ���ڰ� �������� �˻�
    bool isLeapYear () { return (this->time[YEAR] % 4 == 0); }      // ���� �˻�

    int  wrapCycle  (int, int, int);                                // ����,������ ����� ������ ������ �̿���
    //                                                                 ���� ������ ���ƿ����� �ϴ� ��ȯ�� Wrapper
    int  getDaysOfMonth();                                          // �ش� ���� �ϼ� ����
    int  getDaysOfLastMonth();                                      // ���� ���� �ϼ� ����

    void zeroConcat (std::string&, char, int&, std::string);        // ��¥ �� �ð� ��Ʈ�� ����� �Լ�
    void timeAssert ();                                             // ������� �˻�
    void timeCycle  (int&, int&, int, int);                         // arrangeTime�� ����, ��¥ ����/���� ���� �Լ�
    void arrangeTime(bool repeat = true);                           // �ð� ��� ��, ������ �°� ���� ����

public:
    Timer() { this->time = new int[TIMER_SIZE] { 2000, 01, 01, 00, 00, 00 }; }  // �⺻ ������
    Timer(int time[]);                                                          // �迭 �Ű����� ������
    Timer(int year, int month, int day, int hour, int minute, int second);      // ���� �Ű����� ������
    Timer(std::string time);                                                    // ��Ʈ�� �Ű����� ������
    ~Timer() { if(this->time != nullptr) delete [] this->time; }                // �Ҹ���

    void setTime(int time[]);             // Setter
    void setTime(int year, int month, int day, int hour, int minute, int second);
    void setTime(std::string time);

    int* getTime() { return this->time; } // Getter
    std::string getDateString();          // ��¥(YYYY-MM-DD) ����
    std::string getTimeString();          // �ð�(hh:mm:ss) ����
    std::string getString();              // ��¥+�ð� (YYYY-MM-DD hh:mm:ss) ����

    void show() { std::cout << getString() << std::endl; }

    void addYear  (int year   = 1);           // Addition
    void addMonth (int month  = 1);
    void addDay   (int day    = 1);
    void addHour  (int hour   = 1);
    void addMinute(int minute = 1);
    void addSecond(int second = 1);

    void addDate(std::string dateString);     // �ʿ��ϸ� ������ ���� 1
    void addTime(std::string timeString);

    void subYear  (int year   = 1);           // Subtraction
    void subMonth (int month  = 1);
    void subDay   (int day    = 1);
    void subHour  (int hour   = 1);
    void subMinute(int minute = 1);
    void subSecond(int second = 1);

    void subDate(std::string dateString);     // �ʿ��ϸ� ������ ���� 2
    void subTime(std::string timeString);

    // Operators overloading
    friend std::ostream& operator << (std::ostream& os, Timer& timer);
    bool   operator == (Timer& timer);
    bool   operator != (Timer& timer);
    Timer& operator += (std::string timerString);   // �ʿ��ϸ� ������ ���� 3
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

    if(repeat)  // ���� ��, ������ 1ȸ
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
        if(isDigit(ch))                     // ������ ���
        {
            strTime[timeIterator] += ch;    // �ش� TIME ������ ��Ʈ�� �̾���̱�
            nextIter = true;
        }
        else                               // ���ڰ� �ƴϸ� ����
        {
            if(nextIter)
            {
                nextIter = false;
                timeIterator++;            // ���� TIME ���ҷ� �̵�
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
        if (this->time[i] != timer.time[i])  // �ٸ� �� �߰��ϸ� false ���� ����
            return false;

    return true;
}

bool Timer::operator != (Timer& timer)
{
    for (int i = YEAR; i < TIMER_SIZE; i++)
        if (this->time[i] != timer.time[i])  // �ٸ� �� �߰��ϸ� true ���� ����
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