#include "Employee.h"

class Manager : public Employee {
	int bonus;
public:
	Manager(int b = 0) : bonus(b) {	}
	void modify(int s, int b);
	void display();
};