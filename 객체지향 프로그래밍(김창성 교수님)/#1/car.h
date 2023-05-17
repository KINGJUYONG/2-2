#include<iostream>
#include<string>
using namespace std;

class Car {
	int speed;//속도
	int gear;// 기어
	string color;// 색상
public:
	static int count;
	explicit Car(int s = 0, int g = 1, string c = "white");
	~Car();
	int getSpeed();
	void setSpeed(int speed);
	void print();
	Car(const Car & copy);
};