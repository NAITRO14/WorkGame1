#include "person.h"
#include "mh.h"

void person::print_money()
{
	cout << money;
}

person person::operator-=(float n)
{
	money -= n;
	return person();
}
