#include "lib_manager.hpp"
#include "db_timer.hpp"

#include <iostream>

int main()
{
    Timer timer(new int[6]{2018, 2, 28, 4, 59, 55});
    timer.show();

    timer.setTime(1993, 01, 02, 10, 20, 30);
    timer.show();

    timer.setTime("1903��10��22��----,,,;';��`[��20��59��2�ʤǤǤ�");
    timer.show();

    timer.setTime("2000 - 12 - 1      01 : 10: 55");
    timer.show();

    std::cout << std::endl;

    // �ð� ��� ���� : 2000�� 12�� 1�� -> ����� ����� ����� �ּ��� ��� -> ���α׷� ������ ���� ��

    timer.subDay(980);
    timer.show();   //  1998�� 3�� 27���� ������ ����

    timer.subMonth(800);
    timer.show();   //  1931�� 7�� 27���� ������ ����


    //timer.subYear(200); // year ����� ���� ����

    timer.addDay(997);
    timer.show();   //  1934�� 4�� 19���� ������ ����

    timer.addMonth(979);
    timer.show();   //  2015�� 11�� 19���� ������ ����


    std::cout << std::endl; // �� �� �� ����� �𸨴ϴ�... �׳� �ð� �˸°� ����ϴ����� Ȯ��

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

    std::cout.setf(std::ios::boolalpha);    // bool -> true/false ǥ��

    std::cout << (timeOne == timeTwo) << std::endl;     // true
    std::cout << (timeOne != timeTwo) << std::endl;     // false
    std::cout << (timeOne == timeThree) << std::endl;   // false
    std::cout << (timeOne != timeThree) << std::endl;   // true

	return 0;
}