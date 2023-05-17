#include <car.h>
// int Car::count = 0; // count�� �ߺ� �ʱ�ȭ�Ǿ� �ش� �κ��� �ּ�ó�� ���־����ϴ�.

Car::Car(const Car& copy) : Car(copy.count) {
	count = copy.count;
}

Car::Car(int s, int g, string c) : speed(s), gear(g), color(c) {
	count++;
}

Car::~Car() {
	count--;
}

void Car::print() {
	cout << "�ӵ� : " << speed << " ��� : " << gear << " ���� : ";
	cout << color << " ��ü�� : " << Car::count << endl;
}

// ******************************�ּ�Ÿ��******************************

Car createCar() {
	Car tmp = Car(0, 1, "metal");
	return tmp;
}

int Car::count = 0;

int main() {

	cout << "���ݱ��� ������ �ڵ��� �� = " << Car::count << endl;
	createCar().print();
	
	cout << "���ݱ��� ������ �ڵ����� = " << Car::count << endl;

	Car c1(100, 0, "blue");
	Car c2(0, 0, "white");
	cout << "���ݱ��� ������ �ڵ����� = " << Car::count << endl;

	Car c3(0, 0, "red");
	cout << "���ݱ��� ������ �ڵ����� = " << c1.count << endl;
	cout << "���ݱ��� ������ �ڵ����� = " << c2.count << endl;

	return 0;
}