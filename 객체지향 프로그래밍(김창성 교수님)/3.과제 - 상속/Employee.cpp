#include "Employee.h"

void Employee::setSalary(int salary) {
	this->salary = salary;
}
int Employee::getSalary() {
	return salary;
}

void Employee::setrrn(int x) {
	Employee::rrn = x; // Employee�� rrn�� �������ִ� �Լ��Դϴ�.
}

int Employee::getrrn() {
	return Employee::rrn;
}