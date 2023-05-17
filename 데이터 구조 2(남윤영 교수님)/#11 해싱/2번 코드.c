#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 해싱 테이블의 내용을 출력
#define TABLE_SIZE	10	// 해싱 테이블의 크기=소수 

typedef struct {
	char key[15];
	char phone[15];
} element;

struct list
{
	element item;
	struct list* link;
};
struct list* hash_table[TABLE_SIZE];

// 제산 함수를 사용한 해싱 함수
int hash_function(char *key)
{
	return (transform1(key) % TABLE_SIZE);
}

// 문자로 된 키를 숫자로 변환
int transform1(char *key)
{
	int number = 0;
	while (*key)
		number = number + *key++;
	return number;
}

// 체인법을 이용하여 테이블에 키를 삽입
void hash_chain_add(element item, struct list* ht[])
{
	int hash_value = hash_function(item.key);
	struct list* ptr;
	struct list* node_before = NULL, * node = ht[hash_value];
	for (; node; node_before = node, node = node->link) {
		if (node->item.key == item.key) {
			fprintf(stderr, "이미 탐색키가 저장되어 있음\n");
			return;
		}
	}
	ptr = (struct list*)malloc(sizeof(struct list));
	ptr->item = item;
	ptr->link = NULL;
	if (node_before)
		node_before->link = ptr;
	else
		ht[hash_value] = ptr;
}

// 체인법을 이용하여 테이블에 저장된 키를 탐색
void hash_chain_search(element item, struct list* ht[])
{
	struct list* node;

	int hash_value = hash_function(item.key);
	for (node = ht[hash_value]; node; node = node->link) {
		if (*node->item.key == *item.key) { // 기존의 if문으로 실행되지 않아 포인터를 추가하여주었습니다.
			fprintf(stderr, "탐색 %s 성공 %s \n", item.key, item.phone);
			return;
		}
	}
	printf("키를 찾지못했음\n");
}

void hash_chain_print(struct list* ht[])
{
	struct list* node;
	int i;
	printf("\n===============================\n");
	for (i = 0; i < TABLE_SIZE; i++) {
		printf("[%d]->", i);
		for (node = ht[i]; node; node = node->link) {
			printf("%s->", node->item.key);
		}
		printf("\n");
	}
	printf("===============================\n");
}

// 해싱 테이블을 사용한 예제 
int main(void)
{
	char* s[10] = { "Hong", "Kim", "Lee", "Nam", "Cheon", "Ahn", "Park", "Shin", "Oh", "Gu" };
	char* p[15] = { "010-1234-0001", "010-1234-0002", "010-1234-0003", "010-1234-0004", "010-1234-0005", "010-1234-0006", "010-1234-0007", "010-1234-0008", "010-1234-0009", "010-1234-0010" };
	element e;

	for (int i = 0; i < TABLE_SIZE; i++) {
		strcpy(e.key, s[i]);
		strcpy(e.phone, p[i]);
		hash_chain_add(e, hash_table);
		hash_chain_print(hash_table);
	}
	for (int i = 0; i < TABLE_SIZE; i++) {
		strcpy(e.key, s[i]);
		strcpy(e.phone, p[i]);
		hash_chain_search(e, hash_table);
	}
	return 0;
}