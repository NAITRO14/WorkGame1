#pragma once

//�������� �������
#define NOMINMAX
#include <windows.h>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

//���������� �����
#include "person.h"
#include "shopClass.h"
#include "BankClass.h"

using namespace std;

//�����
enum ConsoleColor {
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
inline void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

//����
void enter_num(short& num);

//������� ��������
int work_act(short wpd, person& pers, BankClass& bank);
int sleep_act(int wpd, shopClass & shop, person& pers);
void shop_sleep(shopClass& shop);

bool isGameLost(person& pers, shopClass& shop);



//main header