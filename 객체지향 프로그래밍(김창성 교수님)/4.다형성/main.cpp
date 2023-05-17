#include "Animal.h"

int main() {
	Animal* a1 = new Lion(); // 하향 형변환, 부모 클래스를 가리키는 포인터가
	Lion* a2 = (Lion*)a1; // 자식 클래스를 가리키도록 형 변환

	a2->eat(); // 위의 과정을 통해 형변환된 포인터를 사용하여 부모 클래스의 함수 호출
	a2->move();
	a2->speak();

	delete a2;
}