#pragma once

//основные инклуды
#define NOMINMAX
#include <windows.h>
#include <iomanip>
#include <iostream>

//включаемые файлы
#include "person.h"
#include "shopClass.h"

using namespace std;

//ввод
void enter_num(short& num);

void to_work(person& p);

//функции действий
int work_act(short wpd, person& pers);
void shopping_act();
int sleep_act(int wpd, shopClass & shop);

void shop_sleep(shopClass& shop);

void show_shop();

//main header