#pragma once
#include "shopClass.h"
class shopClass; class person;

class BankClass
{
	float money;

	static int clients; // ���������� ��������
	static int companies; // ���������� ��������

public:
	BankClass();
	//�������
	float get_money();
	int get_clint();
	int get_comp();

	//������� �����
	void taxes(shopClass& shop, person& pers);
	float salary();

	//������
	friend class person; friend class shopClass;

	/*friend ostream& operator << (ostream& os, BankClass& bank);*/
};

