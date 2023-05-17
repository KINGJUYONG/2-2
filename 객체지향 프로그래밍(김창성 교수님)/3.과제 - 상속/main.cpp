#include "Manager.cpp" // main은 manager.cpp를, manager.cpp는 manager.h를 manager.h와 Employee.cpp는 Employee.h를 참조합니다.
int main() {
	cout << "20184102 신주용" << endl << endl;
	int x, y;
	Manager m; // 부모 클래스를 상속받은 Manager클래스의 객체를 생성합니다.
	m.setSalary(2000); // 이후 해당 객체를 통해 부모 클래스의 함수들을 불러와 사용합니다.
	cout << "주민번호를 입력하세요 : ";
	cin >> x;
	m.setrrn(x);
	m.display();
	m.modify(1000, 500);
	cout << "주민번호를 입력하세요 : ";
	cin >> y;
	m.setrrn(y);
	m.display();
}