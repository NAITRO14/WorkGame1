#pragma once
#include "mh.h"

class shopClass
{
	int rub; int pen;
	short bread_count;
	short meat_count;

public:
	struct goods
	{
		string bread;
		string meat;
	};

	shopClass();

	int get_b();
	int get_m();
	void print_money();

};

