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


void enter_num(short& num);

void to_work(person& p);

//main header