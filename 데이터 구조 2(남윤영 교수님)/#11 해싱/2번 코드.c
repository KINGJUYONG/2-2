#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// �ؽ� ���̺��� ������ ���
#define TABLE_SIZE	10	// �ؽ� ���̺��� ũ��=�Ҽ� 

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

// ���� �Լ��� ����� �ؽ� �Լ�
int hash_function(char *key)
{
	return (transform1(key) % TABLE_SIZE);
}

// ���ڷ� �� Ű�� ���ڷ� ��ȯ
int transform1(char *key)
{
	int number = 0;
	while (*key)
		number = number + *key++;
	return number;
}

// ü�ι��� �̿��Ͽ� ���̺� Ű�� ����
void hash_chain_add(element item, struct list* ht[])
{
	int hash_value = hash_function(item.key);
	struct list* ptr;
	struct list* node_before = NULL, * node = ht[hash_value];
	for (; node; node_before = node, node = node->link) {
		if (node->item.key == item.key) {
			fprintf(stderr, "�̹� Ž��Ű�� ����Ǿ� ����\n");
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

// ü�ι��� �̿��Ͽ� ���̺� ����� Ű�� Ž��
void hash_chain_search(element item, struct list* ht[])
{
	struct list* node;

	int hash_value = hash_function(item.key);
	for (node = ht[hash_value]; node; node = node->link) {
		if (*node->item.key == *item.key) { // ������ if������ ������� �ʾ� �����͸� �߰��Ͽ��־����ϴ�.
			fprintf(stderr, "Ž�� %s ���� %s \n", item.key, item.phone);
			return;
		}
	}
	printf("Ű�� ã��������\n");
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

// �ؽ� ���̺��� ����� ���� 
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