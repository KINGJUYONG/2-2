#include <iostream>
#include <string>
using namespace std;

class Calc {
	long double num1; // Ŭ���� ��� �����Դϴ�.
	long double num2;
public:
	static long double memory; // �޸� �ʵ�� ����� �������� memory�� �������ݴϴ�.
	Calc(long double x = 0, long double y = memory); // �����ڿ� �Ҹ��ڸ� �������ݴϴ�.
	~Calc();
	long double add(long double x, long double y); // �ش� Ŭ�������� ����� ��� �Լ����Դϴ�. �ߺ����Ǹ� �Ͽ� �ڷ����� �°� �˾Ƽ� ����ϰ� �˴ϴ�.
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