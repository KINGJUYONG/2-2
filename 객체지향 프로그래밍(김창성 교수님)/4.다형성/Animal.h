#include <iostream>
using namespace std;

class Animal {
public:
	Animal(); // �����ڿ� �Ҹ��� ����
	~Animal();
	virtual void eat() { cout << "EAT\n"; }; // �����Լ� eat, move, speak ����� ����
	virtual void move() { cout << "MOVE\n"; };
	virtual void speak() { cout << "SPEAK\n"; };
};

class Mammal : public Animal { // AnimalŬ������ ����ϴ� �߻�Ŭ���� Mammal
public:
	Mammal();
	~Mammal();
};

class Lion : public Mammal { // MammalŬ������ ����ϴ� LionŬ����
public:
	Lion();
	~Lion();
};