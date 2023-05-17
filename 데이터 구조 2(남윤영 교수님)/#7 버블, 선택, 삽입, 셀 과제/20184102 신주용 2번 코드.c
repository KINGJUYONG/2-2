#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 1000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

void bubble_sort(int list[], int n) // �������� �Լ�
{
	int i, j, temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++)
			/* �յ��� ���ڵ带 ���� �� ��ü */
			if (list[j] > list[j + 1]) {
				SWAP(list[j], list[j + 1], temp);
			}
	}
}

void insertion_sort(int list[], int n) { // �������� �Լ�
	int i, j, key;
	int wan[MAX_SIZE];
	for (i = 0; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			list[j + 1] = list[j];
		}
		list[j + 1] = key;

		wan[i] = list[i];
	}
}

void selection_sort(int list[], int n) { // �������� �Լ�
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) {
			if (list[j] < list[least]) {
				least = j;
			}
		}
		SWAP(list[i], list[least], temp);
	}
}

// gap ��ŭ ������ ��ҵ��� ���� ����
// ������ ������ first���� last
inc_insertion_sort(int list[], int first, int last, int gap)
{
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && key < list[j]; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}
void shell_sort(int list[], int n)   // �� ���� �Լ�
{
	int i, gap;
	int counter = 1;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++) {		// �κ� ����Ʈ�� ������ gap
			inc_insertion_sort(list, i, n - 1, gap);
			counter++;
		}
	}
}

int main(void) {
	double start, end;
	start = ((double)clock());
	srand(time(NULL)); // ���� ������ ���� srand�� ����մϴ�.
	int list[MAX_SIZE]; // MAX_SIZE(1000)ũ���� �迭�� �����ϰ�
	for (int i = 0; i < MAX_SIZE; i++) {
		list[i] = ((int)(((double)((rand() << 15) | rand())) / ((RAND_MAX << 15 | RAND_MAX) + 1) * (((1000000) + 1) - (0))) + (1)); // 36728�̻��� ���� ����ϱ� ���� rand*rand�� ����մϴ�.
	}
	bubble_sort(list, MAX_SIZE); // ���� ���� �Լ��� ȣ���ϰ�
	end = ((double)clock());
	printf("���� ���� �ҿ�ð� : %lf", (end - start) / CLOCKS_PER_SEC);


	start = ((double)clock());
	srand(time(NULL)); // ���� ������ ���� srand�� ����մϴ�.
	int list2[MAX_SIZE]; // MAX_SIZE(1000)ũ���� �迭�� �����ϰ�
	for (int i = 0; i < MAX_SIZE; i++) {
		list2[i] = ((int)(((double)((rand() << 15) | rand())) / ((RAND_MAX << 15 | RAND_MAX) + 1) * (((1000000) + 1) - (0))) + (1)); // 36728�̻��� ���� ����ϱ� ���� rand*rand�� ����մϴ�.
	}
	insertion_sort(list2, MAX_SIZE); // ���� ���� �Լ��� ȣ���ϰ�
	end = ((double)clock());
	printf("\n\n���� ���� �ҿ�ð� : %lf", (end - start) / CLOCKS_PER_SEC);


	start = ((double)clock());
	srand(time(NULL)); // ���� ������ ���� srand�� ����մϴ�.
	int list3[MAX_SIZE]; // MAX_SIZE(1000)ũ���� �迭�� �����ϰ�
	for (int i = 0; i < MAX_SIZE; i++) {
		list3[i] = ((int)(((double)((rand() << 15) | rand())) / ((RAND_MAX << 15 | RAND_MAX) + 1) * (((1000000) + 1) - (0))) + (1)); // 36728�̻��� ���� ����ϱ� ���� rand*rand�� ����մϴ�.
	}
	selection_sort(list3, MAX_SIZE); // ���� ���� �Լ��� ȣ���ϰ�
	end = ((double)clock());
	printf("\n\n���� ���� �ҿ�ð� : %lf", (end - start) / CLOCKS_PER_SEC);


	start = ((double)clock());
	srand(time(NULL)); // ���� ������ ���� srand�� ����մϴ�.
	int list4[MAX_SIZE]; // MAX_SIZE(1000)ũ���� �迭�� �����ϰ�
	for (int i = 0; i < MAX_SIZE; i++) {
		list4[i] = ((int)(((double)((rand() << 15) | rand())) / ((RAND_MAX << 15 | RAND_MAX) + 1) * (((1000000) + 1) - (0))) + (1)); // 36728�̻��� ���� ����ϱ� ���� rand*rand�� ����մϴ�.
	}
	shell_sort(list4, MAX_SIZE); // ���� ���� �Լ��� ȣ���ϰ�
	end = ((double)clock());
	printf("\n\n�� ���� �ҿ�ð� : %lf", (end - start) / CLOCKS_PER_SEC);





	return 0;
}