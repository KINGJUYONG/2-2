#include "Manager.cpp" // main�� manager.cpp��, manager.cpp�� manager.h�� manager.h�� Employee.cpp�� Employee.h�� �����մϴ�.
int main() {
	cout << "20184102 ���ֿ�" << endl << endl;
	int x, y;
	Manager m; // �θ� Ŭ������ ��ӹ��� ManagerŬ������ ��ü�� �����մϴ�.
	m.setSalary(2000); // ���� �ش� ��ü�� ���� �θ� Ŭ������ �Լ����� �ҷ��� ����մϴ�.
	cout << "�ֹι�ȣ�� �Է��ϼ��� : ";
	cin >> x;
	m.setrrn(x);
	m.display();
	m.modify(1000, 500);
	cout << "�ֹι�ȣ�� �Է��ϼ��� : ";
	cin >> y;
	m.setrrn(y);
	m.display();
}