#pragma once

//�������� �������
#define NOMINMAX
#include <windows.h>
#include <iomanip>
#include <iostream>

//���������� �����
#include "person.h"
#include "shopClass.h"

using namespace std;

//����
void enter_num(short& num);

void to_work(person& p);

//������� ��������
int work_act(short wpd, person& pers);
//void shopping_act();
int sleep_act(int wpd, shopClass & shop, person& pers);

void shop_sleep(shopClass& shop);

//void show_shop();

void taxes(shopClass & shop, person& pers);

bool isGameLost(person& pers, shopClass& shop);

//main header