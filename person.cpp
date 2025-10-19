#include "person.h"
#include "mh.h"

person::person()
{
	money = 1500;

	//��������
	bread_count = 1;
	meat_count = 0;
	lemonade_count = 0;
	coffe_count = 0;

	isHungry = 1;


	BankClass::clients++;
}

bool person::get_hunger()
{
	return isHungry;
}

void person::print_money()
{
	cout << money;
}

void person::to_work(person& p, BankClass& bank)
{
	float mtmp = bank.salary();

	money += mtmp;

	cout << "����������: "; SetColor(2, 0); cout << mtmp << endl; SetColor(15, 0);
}

void person::show_inv(short mang)
{
	bool isEmpty = 1;
	system("cls");
	if (mang == 2)
	{
		SetColor(LightRed, 0); cout << "�� ��� �� ���� �������, ���� ���� ��� ����� ������" << endl; SetColor(15, 0);

	}
	cout << "===������===" << endl;
	if (bread_count > 0)
	{
		cout << "����: " << bread_count << endl;
		isEmpty = 0;
	}
	if (meat_count > 0)
	{
		cout << "����: " << meat_count << endl;
		isEmpty = 0;
	}
	if (lemonade_count > 0)
	{
		cout << "�������: " << lemonade_count << endl;
		isEmpty = 0;
	}
	if (coffe_count > 0)
	{
		cout << "����: " << coffe_count << endl;
		isEmpty = 0;
	}

	if (isEmpty)
	{
		cout << "� ��� ������ ���" << endl;
	}

	to_eat(mang);
}

void person::to_eat(short mang)
{
	string inp; bool isIn = 1;
	SetColor(8, 0);
	cout << "---------------------------------------" << endl;
	cout << "������� �������� ��������, ����� ������" << endl;
	if (mang == 1)
	{
		cout << "0 -- ��������� �����" << endl;
	}
	else
	{
		cout << "0 -- �� ����(������)" << endl;
	}
	cout << "---------------------------------------" << endl;
	SetColor(15, 0);
	cout << "����: ";
	cin >> inp;


	if (inp == "0")
	{
		return;
	}
	if (inp == "����" or inp == "����")
	{
		bread_count--;
		isHungry = 0;
		
	}
	else if (inp == "����" or inp == "����")
	{
		meat_count--;
		isHungry = 0;
		
	}
	else if (inp == "�������" or inp == "�������")
	{
		lemonade_count--;
		isHungry = 0;
		
	}
	else if (inp == "����" or inp == "����")
	{
		coffe_count--;
		isHungry = 0;
		exLvl -= 2;

	}
	else
	{
		cout << "��������� ����" << endl;
		system("pause");
		show_inv(mang); //��������� ������ ������
		return; //�������� �������
	}
	if (mang == 1)
	{
		show_inv(mang);
	}
	return;
	
}

person person::operator-=(float n)
{
	money -= n;
	return person();
}
