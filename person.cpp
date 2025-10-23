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
	yogurt_count = 0;

	isHungry = 1;


	BankClass::clients++;
}

int person::get_ex()
{
	return exLvl;
}

short person::get_protein()
{
	return protein;
}

short person::get_carbon()
{
	return carbons;
}

short person::get_fat()
{
	return fats;
}

bool person::get_hunger()
{
	return isHungry;
}

void person::print_money()
{
	cout << money;
}

float person::getMoney()
{
	return money;
}

void person::to_work(BankClass& bank)
{
	if (exLvl == 3) { SetColor(4, 0); cout << "�� ����� ������ � ������ �� ������ ��������. . ." << endl; SetColor(15, 0); return; }
	if (protein < 20 or carbons < 20 or fats < 20) { SetColor(4, 0); cout << "�� ������� ��������, ����� ��������. ��� ������, ��� ����� ������" << endl; SetColor(15, 0); return; }

	protein -= 5;
	carbons -= 5;
	fats -= 5;

	float mtmp = bank.salary();
	money += mtmp;

	cout << "����������: "; SetColor(2, 0); cout << mtmp << endl; SetColor(15, 0);
	exLvl++;
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
	if (yogurt_count > 0)
	{
		cout << "������: " << yogurt_count << endl;
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

		carbons += rand() % 10 + 6; // 6 - 15
		fats += rand() % 3; // 0 - 2
		protein += rand() % 2; // 0 - 1
		
	}
	else if (inp == "����" or inp == "����")
	{
		meat_count--;
		isHungry = 0;

		protein += rand() % 11 + 15; // 15 - 25
		fats += rand() % 14 + 3; // 3 - 13
		carbons += rand() % 3; // 0 - 2
	}
	else if (inp == "�������" or inp == "�������")
	{
		lemonade_count--;
		isHungry = 0;

		carbons += rand() % 11 + 3; // 3 - 10
		
	}
	else if (inp == "����" or inp == "����")
	{
		coffe_count--;
		isHungry = 0;
		
		//��������� ����
		exLvl -= 2;
		protein += 10;
		fats += 10;
		carbons += 10;

	}
	else if (inp == "������" or inp == "������")
	{
		yogurt_count--;
		isHungry = 0;

		protein += rand() % 3;;
		fats += rand() % 11 + 15;
		carbons += rand() % 4;

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

void person::sleep()
{
	if (isHungry)
	{
		show_inv(2);
	}
	system("cls");
	
	protein -= 10;
	carbons -= 10;
	fats -= 10;

	exLvl = 0;
	SetColor(2, 0); cout << "��������� ����� ����, �� ����� ���!" << endl; SetColor(15, 0);
}

person person::operator-=(float n)
{
	money -= n;
	return person();
}
