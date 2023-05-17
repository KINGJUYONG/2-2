#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE	15	// 탐색키의 최대길이  
#define TABLE_SIZE	10	// 해싱 테이블의 크기=소수 

typedef struct
{
	char key[KEY_SIZE];
	char phone[KEY_SIZE];
	// 다른 필요한 필드들 
} element;

element hash_table[TABLE_SIZE];		// 해싱 테이블 
void init_table(element ht[])
{
	int i;
	for (i = 0; i < TABLE_SIZE; i++) {
		ht[i].key[0] = NULL;
	}
}
// 문자로 된 키를 숫자로 변환
int transform1(char* key)
{
	long int number = 0;
	while (*key)
		number = number + *key++;
	return number;
}
// 제산 함수를 사용한 해싱 함수
int hash_function(char* key)
{
	// 키를 자연수로 변환한 다음 테이블의 크기로 나누어 나머지를 반환
	return transform1(key) % TABLE_SIZE;
}
int hash_function2(char* key) // **********이중 해싱 함수입니다.**********
{							  // 기존의 해싱 함수로는 10개의 테이블을 채우지 못해 새로 작성해주었습니다.
	return (7 - (transform1(key)%7) % TABLE_SIZE);
}
#define empty(item) (strlen(item.key)==0)
#define equal(item1, item2) (!strcmp(item1.key,item2.key))

void hash_dh_add(element item, element ht[])
{
	long int i, hash_value, inc;
	hash_value = i = hash_function(item.key);
	inc = hash_function2(item.key);
	while (!empty(ht[i])) {
		if (equal(item, ht[i])) {
			fprintf(stderr, "탐색키가 중복되었습니다\n");
			return;//exit(1);
		}
		i = (i + inc) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "테이블이 가득찼습니다\n");
			return;//exit(1);
		}
	}
	ht[i] = item;
}

void hash_dh_search(element item, element ht[])
{
	int i, hash_value, inc;
	hash_value = i = hash_function(item.key);
	inc = hash_function2(item.key);
	while (!empty(ht[i]))
	{
		if (equal(item, ht[i])) {
			fprintf(stderr, "탐색 : %s 성공 %s\n", item.key, item.phone);
			return;
		}
		i = (i + inc) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "찾는 값이 테이블에 없음\n");
			return;
		}
	}
	fprintf(stderr, "찾는 값이 테이블에 없음\n");
}

// 해싱 테이블의 내용을 출력
void hash_print(element ht[])
{
	int i;
	printf("\n===============================\n");
	for (i = 0; i < TABLE_SIZE; i++)
		printf("[%d]	%s\n", i, ht[i].key);
	printf("===============================\n\n");
}

// 해싱 테이블을 사용한 예제 
int main(void)
{
	char* s[10] = { "Hong", "Kim", "Lee", "Nam", "Cheon", "Ahn", "Park", "Shin", "Oh", "Gu"};
	char* p[15] = { "010-1234-0001", "010-1234-0002", "010-1234-0003", "010-1234-0004", "010-1234-0005", "010-1234-0006", "010-1234-0007", "010-1234-0008", "010-1234-0009", "010-1234-0010" };
	element e;

	for (int i = 0; i < 10; i++) {
		strcpy(e.key, s[i]);
		strcpy(e.phone, p[i]);
		hash_dh_add(e, hash_table);
		hash_print(hash_table);
	}

	for (int i = 0; i < 10; i++) {
		strcpy(e.key, s[i]);
		strcpy(e.phone, p[i]);
		hash_dh_search(e, hash_table);
	}
	return 0;
}