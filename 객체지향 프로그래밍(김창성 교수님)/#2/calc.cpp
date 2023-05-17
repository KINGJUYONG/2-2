#include "calc.h" // calc.h

Calc::Calc(long double x, long double y) : num1(x), num2(y) { // �����ڿ� �Ҹ����� ���Ǵ� Ŭ���� �ܺο��� ���ݴϴ�. ��� �ش� ���� 0���� �ʱ�ȭ���ݴϴ�.
	num1 = 0;
	num2 = 0;
}
Calc::~Calc() {
	num1 = 0;
	num2 = 0;
}

long double Calc::memory = 0; // memory�� ���� 0���� �ʱ�ȭ���ݴϴ�.

long double Calc::add(long double x, long double y){ // �Լ��� �����ϴ� �κ��Դϴ�. �ش� �κ��� �ܼ� ���� �����̹Ƿ� �����ϵ��� �ϰڽ��ϴ�.
	auto z = x + y;
	Calc::memory = z; // memory�� z���� �Է����� �Ŀ� z���� return�մϴ�. �Ź� ������ �̷���� ������ memory�� ���� ����˴ϴ�.
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
		long double input1, input2; //cin�� ���� ����ڰ� �Է��� ���� �ް�, CalcŬ������ �Լ����� ���� �ش� ���� �����Ͽ� �޸𸮿� ������ ���� ����մϴ�.
		char select, calculate;
		cout << "���Ḧ ���ϸ� Q�� �Է����ּ���" << endl << "�޸𸮸� �ҷ������� M�� �Է��ϼ���" << endl << "������ ���Ͻø� Q,M�� ������ �ƹ� Ű�� �Է��ϼ���" << endl;
		cin >> select;
		if (select == 'Q') {
			break;
		}
		else if (select == 'M') {
			input1 = calc.memory;
		}
		else {
			cout << "ù��° ���� �Է��ϼ��� : ";
			cin >> input1;
		}
		cout << "+ - * % /�� �����ڸ� �Է��ϼ��� : ";
		cin >> calculate;
		cout << "�ι�° ���� �Է��ϼ��� : ";
		cin >> input2;

		if (calculate == '+') {
			auto result = calc.add(input1, input2); // �ش� �κп����� result�� �ڷ����� auto�� ������־��µ�,
			cout << result<<endl<<endl;				// ������� ������ �Ǽ� ��� ���� �� �����Ƿ� .0���� ���ʿ��� �Ǽ��� �����ϱ� ���� auto�� ������־����ϴ�.
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