#include "Animal.h"

Animal::Animal() {				// 각 생성자와 소멸자들이 호출되는것을 확인하기 위해
	cout << "Animal 생성자\n";  // 모든 생성자와 소멸자에 cout을 해주었습니다.
};
Animal::~Animal() {
	cout << "Animal 소멸자\n";
};

Mammal::Mammal() {
	cout << "Mammal 생성자\n";
};
Mammal::~Mammal() {
	cout << "Mammal 소멸자\n";
};


Lion::Lion() {
	cout << "Lion 생성자\n";
};
Lion::~Lion() {
	cout << "Lion 소멸자\n";
};