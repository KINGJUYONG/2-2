#include "calc.h" // calc.h

Calc::Calc(long double x, long double y) : num1(x), num2(y) { // 생성자와 소멸자의 정의는 클래스 외부에서 해줍니다. 모두 해당 수를 0으로 초기화해줍니다.
	num1 = 0;
	num2 = 0;
}
Calc::~Calc() {
	num1 = 0;
	num2 = 0;
}

long double Calc::memory = 0; // memory의 값을 0으로 초기화해줍니다.

long double Calc::add(long double x, long double y){ // 함수를 정의하는 부분입니다. 해당 부분은 단순 연산 구현이므로 생략하도록 하겠습니다.
	auto z = x + y;
	Calc::memory = z; // memory에 z값을 입력해준 후에 z값을 return합니다. 매번 연산이 이루어질 때마다 memory의 값이 변경됩니다.
	return z;
}
long double Calc::cmp(long double x, long double y) {
	auto z = x - y;
	Calc::memory = z;
	return z;
}
long double Calc::mul(long double x, long double y) {
	auto z = x * y;
	Calc::memory = z;
	return z;
}
long double Calc::mod(long double x, long double y) {
	int a = x / y;
	long double b = a * y;
	long double z = x - b;
	Calc::memory = z;
	return z;
}
long double Calc::div(long double x, long double y) {
	auto z = x / y;
	Calc::memory = z;
	return z;
}
int Calc::add(int x, int y) {
	auto z = x + y;
	Calc::memory = z;
	return z;
}
int Calc::cmp(int x, int y) {
	auto z = x - y;
	Calc::memory = z;
	return z;
}
int Calc::mul(int x, int y) {
	auto z = x * y;
	Calc::memory = z;
	return z;
}
int Calc::mod(int x, int y) {
	int a = x / y;
	auto b = a * y;
	auto z = x - b;
	Calc::memory = z;
	return z;
}
int Calc::div(int x, int y) {
	auto z = x / y;
	Calc::memory = z;
	return z;
}

int main() {
	Calc calc;

	while (1) { 
		long double input1, input2; //cin을 통해 사용자가 입력한 값을 받고, Calc클래스의 함수들을 통해 해당 값을 연산하여 메모리에 저장한 다음 출력합니다.
		char select, calculate;
		cout << "종료를 원하면 Q를 입력해주세요" << endl << "메모리를 불러오려면 M을 입력하세요" << endl << "진행을 원하시면 Q,M을 제외한 아무 키나 입력하세요" << endl;
		cin >> select;
		if (select == 'Q') {
			break;
		}
		else if (select == 'M') {
			input1 = calc.memory;
		}
		else {
			cout << "첫번째 수를 입력하세요 : ";
			cin >> input1;
		}
		cout << "+ - * % /등 연산자를 입력하세요 : ";
		cin >> calculate;
		cout << "두번째 수를 입력하세요 : ";
		cin >> input2;

		if (calculate == '+') {
			auto result = calc.add(input1, input2); // 해당 부분에서는 result의 자료형을 auto로 사용해주었는데,
			cout << result<<endl<<endl;				// 결과값이 정수와 실수 모두 나올 수 있으므로 .0등의 불필요한 실수를 제거하기 위해 auto를 사용해주었습니다.
		}
		else if (calculate == '-') {
			auto result = calc.cmp(input1, input2);
			cout << result << endl << endl;
		}
		else if (calculate == '*') {
			auto result = calc.mul(input1, input2);
			cout << result << endl << endl;
		}
		else if (calculate == '/') {
			auto result = calc.div(input1, input2);
			cout << result << endl << endl;
		}
		else if (calculate == '%') {
			auto result = calc.mod(input1, input2);
			cout << result << endl << endl;
		}
	}

	return 0;
}