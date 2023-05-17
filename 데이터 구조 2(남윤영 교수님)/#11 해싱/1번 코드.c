#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE	15	// Ž��Ű�� �ִ����  
#define TABLE_SIZE	10	// �ؽ� ���̺��� ũ��=�Ҽ� 

typedef struct
{
	char key[KEY_SIZE];
	char phone[KEY_SIZE];
	// �ٸ� �ʿ��� �ʵ�� 
} element;

element hash_table[TABLE_SIZE];		// �ؽ� ���̺� 
void init_table(element ht[])
{
	int i;
	for (i = 0; i < TABLE_SIZE; i++) {
		ht[i].key[0] = NULL;
	}
}
// ���ڷ� �� Ű�� ���ڷ� ��ȯ
int transform1(char* key)
{
	long int number = 0;
	while (*key)
		number = number + *key++;
	return number;
}
// ���� �Լ��� ����� �ؽ� �Լ�
int hash_function(char* key)
{
	// Ű�� �ڿ����� ��ȯ�� ���� ���̺��� ũ��� ������ �������� ��ȯ
	return transform1(key) % TABLE_SIZE;
}
int hash_function2(char* key) // **********���� �ؽ� �Լ��Դϴ�.**********
{							  // ������ �ؽ� �Լ��δ� 10���� ���̺��� ä���� ���� ���� �ۼ����־����ϴ�.
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
			fprintf(stderr, "Ž��Ű�� �ߺ��Ǿ����ϴ�\n");
			return;//exit(1);
		}
		i = (i + inc) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "���̺��� ����á���ϴ�\n");
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
			fprintf(stderr, "Ž�� : %s ���� %s\n", item.key, item.phone);
			return;
		}
		i = (i + inc) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "ã�� ���� ���̺� ����\n");
			return;
		}
	}
	fprintf(stderr, "ã�� ���� ���̺� ����\n");
}

// �ؽ� ���̺��� ������ ���
void hash_print(element ht[])
{
	int i;
	printf("\n===============================\n");
	for (i = 0; i < TABLE_SIZE; i++)
		printf("[%d]	%s\n", i, ht[i].key);
	printf("===============================\n\n");
}

// �ؽ� ���̺��� ����� ���� 
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