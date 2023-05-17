#include<stdio.h>
#include<time.h>

#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
void bubble_sort(int list[], int n) // �������� �Լ�
{
	int i, j, temp;
	int counter = 1;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++)
			/* �յ��� ���ڵ带 ���� �� ��ü */
			if (list[j] > list[j + 1]) {
				SWAP(list[j], list[j + 1], temp);
				printf("step%d :", counter);
				counter++;
				for (int k = 0; k < 10; k++) {
					printf("%d ", list[k]);
				}printf("\n");

			}
	}
}

void insertion_sort(int list[], int n) { // �������� �Լ�
	int i, j, key;
	int wan[10];
	for (i = 0; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			list[j + 1] = list[j];
		}
		list[j + 1] = key;

		wan[i] = list[i];
		printf("step %d : ( ", i + 1); // **********�������**********
		for (int k = 0; k < i + 1; k++) {
			printf("%d ", list[k]);
		}
		printf(")     ");
		for (int k = i + 1; k < 10; k++) {
			printf("%d ", list[k]);
		}
		printf("   %d ����\n", key); // **********�������**********
	}
}

void selection_sort(int list[], int n) { // �������� �Լ�
	int i, j, least, temp;
	printf("step 1 : ( )  ");
	for (i = 0; i < 10; i++) {
		printf("%d ", list[i]);
	} printf("    �ʱ����\n");
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) {
			if (list[j] < list[least]) {
				least = j;
			}
		}
		SWAP(list[i], list[least], temp);
		if (list[i] != list[least]) {
			printf("step%d : (", i + 2);
			for (int k = 0; k < i + 1; k++) {
				printf("%d ", list[k]);
			}
			printf(") ");
		}
		else { printf("step%d : ****���� ��� %d��(��) �̹� ���ڸ��� �ֽ��ϴ�.****\n", i + 2, list[i]); } // �ش� ��尡 �̹� ���ڸ��� ���� �� �ȳ������� ����մϴ�.
		for (int k = i + 1; k < 10; k++) {
			if (list[i] != list[least]) printf("%d ", list[k]);
		}
		if (list[i] != list[least]) {
			printf("    %d������ %d�� ��ȯ\n", list[i], list[least]);
		}
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
//
void shell_sort(int list[], int n)   // �� ���� �Լ�
{
	int i, gap;
	int counter = 1;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++) {		// �κ� ����Ʈ�� ������ gap
			inc_insertion_sort(list, i, n - 1, gap);
			printf("step%d : ", counter);
			for (int k = 0; k < 10; k++) {
				printf("%d ", list[k]);
			}
			printf("\n");
			counter++;
		}
	}
}



int main(void) {
#define MAX_SIZE 10
	printf("--------------------���� ����--------------------\n");
	srand(time(NULL)); // ���� ������ ���� srand�� ����մϴ�.
	int list[MAX_SIZE]; // MAX_SIZE(10)ũ���� �迭�� �����ϰ�
	for (int i = 0; i < MAX_SIZE; i++) {
		list[i] = rand() % 100 + 1; // 1~100������ ������ �����Ͽ� list�迭�� ���� �����մϴ�.
	}
	bubble_sort(list, MAX_SIZE); // ���� ���� �Լ��� ȣ���ϰ�
	printf("\n���� ������ : "); //���ĵ� �����͸� ����մϴ�.
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", list[i]);
	}

	printf("\n--------------------���� ����--------------------\n\n--------------------���� ����--------------------\n");
	int list2[MAX_SIZE]; // MAX_SIZE(10)ũ���� �迭�� �����ϰ�
	for (int i = 0; i < MAX_SIZE; i++) {
		list2[i] = rand() % 100 + 1; // 1~100������ ������ �����Ͽ� list�迭�� ���� �����մϴ�.
	}
	insertion_sort(list2, MAX_SIZE); // ���� ���� �Լ��� ȣ���ϰ�
	printf("\n���� ������ : "); //���ĵ� �����͸� ����մϴ�.
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", list2[i]);
	}

	printf("\n--------------------���� ����--------------------\n\n--------------------���� ����--------------------\n");
	int list3[MAX_SIZE]; // MAX_SIZE(10)ũ���� �迭�� �����ϰ�
	for (int i = 0; i < MAX_SIZE; i++) {
		list3[i] = rand() % 100 + 1; // 1~100������ ������ �����Ͽ� list�迭�� ���� �����մϴ�.
	}
	selection_sort(list3, MAX_SIZE); // ���� ���� �Լ��� ȣ���ϰ�
	printf("\n���� ������ : "); //���ĵ� �����͸� ����մϴ�.
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", list3[i]);
	}

	printf("\n--------------------���� ����--------------------\n\n--------------------�� ����--------------------\n");
	int list4[MAX_SIZE]; // MAX_SIZE(10)ũ���� �迭�� �����ϰ�
	for (int i = 0; i < MAX_SIZE; i++) {
		list4[i] = rand() % 100 + 1; // 1~100������ ������ �����Ͽ� list�迭�� ���� �����մϴ�.
	}
	shell_sort(list4, MAX_SIZE); // �� ���� �Լ��� ȣ���ϰ�
	printf("\n���� ������ : "); //���ĵ� �����͸� ����մϴ�.
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", list4[i]);
	}
	printf("\n--------------------�� ����--------------------");
	return 0;

}