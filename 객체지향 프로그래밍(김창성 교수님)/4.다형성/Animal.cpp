#include "Animal.h"

Animal::Animal() {				// �� �����ڿ� �Ҹ��ڵ��� ȣ��Ǵ°��� Ȯ���ϱ� ����
	cout << "Animal ������\n";  // ��� �����ڿ� �Ҹ��ڿ� cout�� ���־����ϴ�.
};
Animal::~Animal() {
	cout << "Animal �Ҹ���\n";
};

Mammal::Mammal() {
	cout << "Mammal ������\n";
};
Mammal::~Mammal() {
	cout << "Mammal �Ҹ���\n";
};


Lion::Lion() {
	cout << "Lion ������\n";
};
Lion::~Lion() {
	cout << "Lion �Ҹ���\n";
};