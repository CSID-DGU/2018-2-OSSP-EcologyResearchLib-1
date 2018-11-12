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
Last Updated : 18-11-12


[ Preference ]

<Explanation>
- ������ ���⼺ ������ �����ϴ� DB
- ���� �˰����� ���ȴ�.


<To do>

[���� ��Ŀ �˰����� ���Ǵ� �̵� ��ȣ ����]

1. ����
 - ����/�ٴ�, �̵� ����/�Ұ���, ��ü�� ���� Ư���� ���� ���� Ȯ�� ����
 => ������ ���� ����, ������Ŀ�� Ȯ�� ��� �� �ش� �������� �о����


2. ���Ļ���
 - �ش� ������ �����ϴ� �����ڿ� ���� �̵� Ȯ�� ����,
	���̿� ���� �̵� Ȯ�� ����

 => ���������� ������ ���� ����,
	  ���������� ������ ���� ���Ļ��� ������ ��ȭ�� �ʿ䰡 ����


3. �ñ�
 - ����(Ȥ�� ����)�� ���� �Ը��� �̵� ���⼺�� �ľǵȴٸ�
	�ش� ������ �����Ͽ� Ȯ�� ����
 - ����� �� Ư�� �ñ⿡ ���� ��ǥ ���������� �̵� ���ɼ� ����

 => ������Ŀ Ȯ�� ��� ��
	  1) �ñ⿡ ���� �̵� ���⼺ ���� �о����
		  (���ο� �ڷᱸ�� ���� �ʿ�,
		   �ñ⺰ �ֿ� �̵� ��ǥ�� �Ǵ� ���� �� ����/���� Ȯ���� ���� ������)
	  2) ���� ��ġ�� �ش� ���������� ������ ���
	  3) �ش� ������ Ȯ�� ����


4. �ð�
 - ��/��, Ȥ�� Ư�� �ð��� ���� �̵� ���⼺�� �����Ѵٸ�
	�ش� ������ �����Ͽ� Ȯ�� ����

=> ���������� �ð��� ���� �̵� ���⼺ ������ ���� �� �о����


(5. ����)
 - ȭ��, ��ǳ �� �ڿ����ط� ���� �̵� ���⼺ ����
 - ���� ����
 �̴� ��Ȯ�� ������ �����Ƿ� ���Ŀ� ����


6. ������ (�ټ��� ��ȣ ���ο� ���������� ����)
 - �ֿ� ���������� �̵�, ��Ը� ���� ��
	 �и��� �������� ���� �̵��ϴ� ���⼺�� �߰ߵ� ���
	 ���� ��ġ�κ��� �ش� �������� ���ϴ� ���⿡ ���� Ȯ�� �߰� �ο�


* �ñ�, �ð�, ������ �� ����ȭ ������ ������ ������ ���
 - �ش� ������ �����ͺ��̽��� ����
 - ������Ŀ�� Ȯ������� �� �����ͺ��̽����� �ҷ�����
 - �ð� ������(�ð� �� ������ �������� ���ǽ� �̿�)
 - ���� ������(�������� ���� ��ǥ)
 - Ȯ�� ����(������Ŀ�� ��ٷ� ������ֱ� ����)

*/

#pragma once
#include "db_origin.hpp"
#include "db_organism.hpp"
#include "db_environment.hpp"

class Preference : public DataBase
{
private:
	LOCALSTATE movable; // prefet to go somewhere
	std::vector<Organism>* preylist; // prefer to eat something
	Environment* preferEnvironment; // prefer to be in some environment 
	
public:

};