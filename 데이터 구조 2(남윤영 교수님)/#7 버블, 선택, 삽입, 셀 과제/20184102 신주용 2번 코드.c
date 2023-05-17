#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 1000
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

void bubble_sort(int list[], int n) // 버블정렬 함수
{
	int i, j, temp;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++)
			/* 앞뒤의 레코드를 비교한 후 교체 */
			if (list[j] > list[j + 1]) {
				SWAP(list[j], list[j + 1], temp);
			}
	}
}

void insertion_sort(int list[], int n) { // 삽입정렬 함수
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

void selection_sort(int list[], int n) { // 선택정렬 함수
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

// gap 만큼 떨어진 요소들을 삽입 정렬
// 정렬의 범위는 first에서 last
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
void shell_sort(int list[], int n)   // 쉘 정렬 함수
{
	int i, gap;
	int counter = 1;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++) {		// 부분 리스트의 개수는 gap
			inc_insertion_sort(list, i, n - 1, gap);
			counter++;
		}
	}
}

int main(void) {
	double start, end;
	start = ((double)clock());
	srand(time(NULL)); // 난수 생성을 위해 srand를 사용합니다.
	int list[MAX_SIZE]; // MAX_SIZE(1000)크기의 배열을 생성하고
	for (int i = 0; i < MAX_SIZE; i++) {
		list[i] = ((int)(((double)((rand() << 15) | rand())) / ((RAND_MAX << 15 | RAND_MAX) + 1) * (((1000000) + 1) - (0))) + (1)); // 36728이상의 수를 사용하기 위해 rand*rand를 사용합니다.
	}
	bubble_sort(list, MAX_SIZE); // 버블 정렬 함수를 호출하고
	end = ((double)clock());
	printf("버블 정렬 소요시간 : %lf", (end - start) / CLOCKS_PER_SEC);


	start = ((double)clock());
	srand(time(NULL)); // 난수 생성을 위해 srand를 사용합니다.
	int list2[MAX_SIZE]; // MAX_SIZE(1000)크기의 배열을 생성하고
	for (int i = 0; i < MAX_SIZE; i++) {
		list2[i] = ((int)(((double)((rand() << 15) | rand())) / ((RAND_MAX << 15 | RAND_MAX) + 1) * (((1000000) + 1) - (0))) + (1)); // 36728이상의 수를 사용하기 위해 rand*rand를 사용합니다.
	}
	insertion_sort(list2, MAX_SIZE); // 버블 정렬 함수를 호출하고
	end = ((double)clock());
	printf("\n\n삽입 정렬 소요시간 : %lf", (end - start) / CLOCKS_PER_SEC);


	start = ((double)clock());
	srand(time(NULL)); // 난수 생성을 위해 srand를 사용합니다.
	int list3[MAX_SIZE]; // MAX_SIZE(1000)크기의 배열을 생성하고
	for (int i = 0; i < MAX_SIZE; i++) {
		list3[i] = ((int)(((double)((rand() << 15) | rand())) / ((RAND_MAX << 15 | RAND_MAX) + 1) * (((1000000) + 1) - (0))) + (1)); // 36728이상의 수를 사용하기 위해 rand*rand를 사용합니다.
	}
	selection_sort(list3, MAX_SIZE); // 버블 정렬 함수를 호출하고
	end = ((double)clock());
	printf("\n\n선택 정렬 소요시간 : %lf", (end - start) / CLOCKS_PER_SEC);


	start = ((double)clock());
	srand(time(NULL)); // 난수 생성을 위해 srand를 사용합니다.
	int list4[MAX_SIZE]; // MAX_SIZE(1000)크기의 배열을 생성하고
	for (int i = 0; i < MAX_SIZE; i++) {
		list4[i] = ((int)(((double)((rand() << 15) | rand())) / ((RAND_MAX << 15 | RAND_MAX) + 1) * (((1000000) + 1) - (0))) + (1)); // 36728이상의 수를 사용하기 위해 rand*rand를 사용합니다.
	}
	shell_sort(list4, MAX_SIZE); // 버블 정렬 함수를 호출하고
	end = ((double)clock());
	printf("\n\n쉘 정렬 소요시간 : %lf", (end - start) / CLOCKS_PER_SEC);





	return 0;
}