#include "mh.h"

void enter_num(short& num)
{
	while (true) {
		if (cin >> num) {  // ���� ���� ����������
			break;         // ����� �� �����
		}
		else {
			cout << "������ �����. ������� ����� ������." << endl;
			cout << "����: ";
			cin.clear(); // ������� ������
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // �������� �����
		}
	}
}

void to_work(person& p)
{
	short rtmp = rand() % 4001 + 1000;
	short ptmp = rand() % 100 + 1;
	p.rub += rtmp;
	p.pen += ptmp;

	cout << "����������: " << rtmp << "." << ptmp << endl;
	
}
