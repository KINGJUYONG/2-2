#include <iostream>
#include <string>
using namespace std;

class Calc {
	long double num1; // 클래스 멤버 변수입니다.
	long double num2;
public:
	static long double memory; // 메모리 필드로 사용할 전역변수 memory를 선언해줍니다.
	Calc(long double x = 0, long double y = memory); // 생성자와 소멸자를 선언해줍니다.
	~Calc();
	long double add(long double x, long double y); // 해당 클래스에서 사용할 멤버 함수들입니다. 중복정의를 하여 자료형에 맞게 알아서 사용하게 됩니다.
	long double cmp(long double x, long double y);
	long double mul(long double x, long double y);
	long double mod(long double x, long double y);
	long double div(long double x, long double y);
	int add(int x, int y);
	int cmp(int x, int y);
	int mul(int x, int y);
	int mod(int x, int y);
	int div(int x, int y);
};