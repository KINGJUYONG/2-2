#include <iostream>
using namespace std;

class Animal {
public:
	Animal(); // 생성자와 소멸자 선언
	~Animal();
	virtual void eat() { cout << "EAT\n"; }; // 가상함수 eat, move, speak 선언과 정의
	virtual void move() { cout << "MOVE\n"; };
	virtual void speak() { cout << "SPEAK\n"; };
};

class Mammal : public Animal { // Animal클래스를 상속하는 추상클래스 Mammal
public:
	Mammal();
	~Mammal();
};

class Lion : public Mammal { // Mammal클래스를 상속하는 Lion클래스
public:
	Lion();
	~Lion();
};