#include<iostream>
#include<string>
using namespace std;

class Employee {
	int rrn;
protected:
	int salary;
public:
	string name;
	void setSalary(int salary);
	int getSalary();
	void setrrn(int x);  // private������ rrn�� �������ֱ� ���� �Լ��� �������ݴϴ�.
	int getrrn();
};