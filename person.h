#pragma once


class person
{
	int rub; int pen;
	short bread_count;
	short meat_count;

public:

	person() : rub(100), pen(0), bread_count(0), meat_count(0){}

	int get_b();
	int get_m();
	void print_money();

	//друзья
	friend void to_work(person& p);
	
};

