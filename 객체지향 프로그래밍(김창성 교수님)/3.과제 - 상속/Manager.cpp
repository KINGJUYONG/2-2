#include "Manager.h"

void Manager::modify(int s, int b) {
	salary = s;
	bonus = b;
}

void Manager::display()
{
	cout << "���� : " << salary << " ���ʽ� : " << bonus << " �ֹε�Ϲ�ȣ : " << getrrn() << endl;
}