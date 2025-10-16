#pragma once
#define NOMINMAX
#include <windows.h>
#include <iomanip>
#include <iostream>

using namespace std;

class baseClass
{
	int rub; int pen;
	short bread_count;
	short meat_count;

	int get_b();
	int get_m();
	void print_money();
};

void enter_num(short& num);

//main header