#pragma once

//основные инклуды
#define NOMINMAX
#include <windows.h>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

//включаемые файлы
#include "person.h"
#include "shopClass.h"
#include "BankClass.h"

using namespace std;

//цвета
enum ConsoleColor {
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
inline void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

//позиционирование
inline void GotoXY(int X, int Y)
{
	HANDLE hConsole;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}

//ввод
void enter_num(short& num);

void sleep_act(shopClass & shop, person& pers);
void randomForShop(int count, ...);
bool to_buy(shopClass& shop, person& pers);
bool isGameLost(person& pers, shopClass& shop, BankClass& bank);
