#include "person.h"
#include "mh.h"

void person::print_money()
{
	cout << rub << "." << pen << endl;
}

person person::operator-=(float n)
{
	rub -= n;
	return person();
}
