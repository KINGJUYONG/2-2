#include <car.h>
// int Car::count = 0; // count가 중복 초기화되어 해당 부분은 주석처리 해주었습니다.

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
	cout << "속도 : " << speed << " 기어 : " << gear << " 색상 : ";
	cout << color << " 객체수 : " << Car::count << endl;
}

// ******************************주석타임******************************

Car createCar() {
	Car tmp = Car(0, 1, "metal");
	return tmp;
}

int Car::count = 0;

int main() {

	cout << "지금까지 생성된 자동차 수 = " << Car::count << endl;
	createCar().print();
	
	cout << "지금까지 생성된 자동차수 = " << Car::count << endl;

	Car c1(100, 0, "blue");
	Car c2(0, 0, "white");
	cout << "지금까지 생성된 자동차수 = " << Car::count << endl;

	Car c3(0, 0, "red");
	cout << "지금까지 생성된 자동차수 = " << c1.count << endl;
	cout << "지금까지 생성된 자동차수 = " << c2.count << endl;

	return 0;
}