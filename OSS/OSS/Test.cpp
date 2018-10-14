#include "lib_manager.hpp"
#include "db_timer.hpp"

#include <iostream>

int main()
{
    Timer timer(new int[6]{2018, 2, 28, 4, 59, 55});
    timer.show();

    timer.setTime(1993, 01, 02, 10, 20, 30);
    timer.show();

    timer.setTime("1903년10월22일----,,,;';ㅣ`[ㅣ20시59분2초ㅗㅗㅗ");
    timer.show();

    timer.setTime("2000 - 12 - 1      01 : 10: 55");
    timer.show();

    std::cout << std::endl;

    // 시간 계산 기준 : 2000년 12월 1일 -> 계산기로 계산한 결과를 주석에 기록 -> 프로그램 실행을 통해 비교

    timer.subDay(980);
    timer.show();   //  1998년 3월 27일이 나오면 맞음

    timer.subMonth(800);
    timer.show();   //  1931년 7월 27일이 나오면 맞음


    //timer.subYear(200); // year 계산은 굳이 안함

    timer.addDay(997);
    timer.show();   //  1934년 4월 19일이 나오면 맞음

    timer.addMonth(979);
    timer.show();   //  2015년 11월 19일이 나오면 맞음


    std::cout << std::endl; // 시 분 초 계산은 모릅니다... 그냥 시간 알맞게 출력하는지만 확인

    timer.addHour(100000);
    timer.show();

    timer.addMinute(123456);
    timer.show();

    timer.addSecond(2345553);
    timer.show();


    std::cout << std::endl;

    timer.subHour(200000);
    timer.show();

    timer.subMinute(66666);
    timer.show();

    timer.subSecond(9999999);
    timer.show();

    std::cout << std::endl;

    Timer timeOne("2018 10 14 01 2 3");
    Timer timeTwo(2018, 10, 14, 1, 2, 3);
    Timer timeThree(new int[6] {2018, 10, 14, 1, 2, 4});

    std::cout.setf(std::ios::boolalpha);    // bool -> true/false 표현

    std::cout << (timeOne == timeTwo) << std::endl;     // true
    std::cout << (timeOne != timeTwo) << std::endl;     // false
    std::cout << (timeOne == timeThree) << std::endl;   // false
    std::cout << (timeOne != timeThree) << std::endl;   // true

	return 0;
}