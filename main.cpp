#include "mh.h"
#include "shopClass.h"
#include "person.h"
#include "BankClass.h"

int BankClass::clients = 0;
int BankClass::companies = 0;


int main()
{
	setlocale(LC_ALL, "ru"); srand(time(NULL));
	SetConsoleCP(1251); SetConsoleOutputCP(1251);

	shopClass shop; person pers; BankClass bank;
	short man;
	short day = 0; bool isIn = 1;
	

	while (isIn)
	{
		system("cls");
		
		cout << "����� � ��������: "; pers.print_money(); cout << "    ����: " << day; cout << "    ����� � �����: " << bank.get_money() << endl;
		cout << "1|���������� "; cout << "["; if (pers.get_ex() < 3) { for (short i = 3; i > pers.get_ex(); i--) { cout << " # "; } } else {cout << " ! "; } cout << "]";
		cout << "\n2|����� � �������\n3|���� �����\n4|������� ������" << endl;
		
		SetColor(DarkGray, 0);
		cout << "----------------" << endl;
		cout << "1-4 -- ������� ��������" << endl;
		cout << "----------------" << endl;
		SetColor(15, 0);

		cout << "����: "; enter_num(man);

		switch (man)
		{
		case 1:
		{
			pers.to_work(bank);
		}break;
		case 2:
		{
			shop.show_shop(shop, pers);
			continue;
		}break;
		case 3:
		{
			sleep_act(shop, pers);
			bank.taxes(shop, pers);
			isIn = isGameLost(pers, shop, bank);

			day++;
			
		}break;
		case 4:
		{
			pers.show_inv(1);
			continue;
		}break;
		//����� ��������� ����������
		case 1001: //���������� ��������
		{
			cout << "���������� ��������: " << bank.get_clint() << endl;
		}break;
		case 1002: //���������� ��������
		{
			cout << "���������� ��������: " << bank.get_comp() << endl; 
		}break;
		case 1003: //����� � �����
		{
			cout << "����� � �����: " << bank.get_money() << endl;
		}break;
		case 1004: //����� � ��������
		{
			cout << "����� � ��������: " << shop.get_money() << endl;
		}break;
		case 1005: //���������� ���
		{
			SetColor(8, 0);
			cout << "----------------" << endl;
			cout << "�����: " << pers.get_protein() << endl;
			cout << "����:" << pers.get_fat() << endl;
			cout << "��������:" << pers.get_carbon() << endl;
			cout << "----------------" << endl;
			SetColor(15, 0);
		}break;
		}
		system("pause");
	}

}