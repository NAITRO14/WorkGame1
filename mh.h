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

//����
void enter_num(short& num);



//������� ��������
int work_act(short wpd, person& pers, BankClass& bank);
//void shopping_act();
int sleep_act(int wpd, shopClass & shop, person& pers);

void shop_sleep(shopClass& shop);

//void show_shop();

bool isGameLost(person& pers, shopClass& shop);

void set_color(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

//main header