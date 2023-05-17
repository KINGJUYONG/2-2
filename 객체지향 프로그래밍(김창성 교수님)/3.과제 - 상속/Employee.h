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
	void setrrn(int x);  // private변수인 rrn을 수정해주기 위해 함수를 선언해줍니다.
	int getrrn();
};