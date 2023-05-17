#include "Employee.h"

void Employee::setSalary(int salary) {
	this->salary = salary;
}
int Employee::getSalary() {
	return salary;
}

void Employee::setrrn(int x) {
	Employee::rrn = x; // Employee의 rrn을 수정해주는 함수입니다.
}

int Employee::getrrn() {
	return Employee::rrn;
}