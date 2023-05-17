#include "Manager.h"

void Manager::modify(int s, int b) {
	salary = s;
	bonus = b;
}

void Manager::display()
{
	cout << "봉급 : " << salary << " 보너스 : " << bonus << " 주민등록번호 : " << getrrn() << endl;
}