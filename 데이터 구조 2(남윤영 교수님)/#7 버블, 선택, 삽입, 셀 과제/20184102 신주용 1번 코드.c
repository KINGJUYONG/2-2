#include<stdio.h>
#include<time.h>

#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
void bubble_sort(int list[], int n) // 버블정렬 함수
{
	int i, j, temp;
	int counter = 1;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++)
			/* 앞뒤의 레코드를 비교한 후 교체 */
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

void insertion_sort(int list[], int n) { // 삽입정렬 함수
	int i, j, key;
	int wan[10];
	for (i = 0; i < n; i++) {
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			list[j + 1] = list[j];
		}
		list[j + 1] = key;

		wan[i] = list[i];
		printf("step %d : ( ", i + 1); // **********여기부터**********
		for (int k = 0; k < i + 1; k++) {
			printf("%d ", list[k]);
		}
		printf(")     ");
		for (int k = i + 1; k < 10; k++) {
			printf("%d ", list[k]);
		}
		printf("   %d 삽입\n", key); // **********여기까지**********
	}
}

void selection_sort(int list[], int n) { // 선택정렬 함수
	int i, j, least, temp;
	printf("step 1 : ( )  ");
	for (i = 0; i < 10; i++) {
		printf("%d ", list[i]);
	} printf("    초기상태\n");
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
		else { printf("step%d : ****다음 노드 %d은(는) 이미 제자리에 있습니다.****\n", i + 2, list[i]); } // 해당 노드가 이미 제자리에 있을 때 안내문구를 출력합니다.
		for (int k = i + 1; k < 10; k++) {
			if (list[i] != list[least]) printf("%d ", list[k]);
		}
		if (list[i] != list[least]) {
			printf("    %d선택후 %d과 교환\n", list[i], list[least]);
		}
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
//
void shell_sort(int list[], int n)   // 쉘 정렬 함수
{
	int i, gap;
	int counter = 1;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0) gap++;
		for (i = 0; i < gap; i++) {		// 부분 리스트의 개수는 gap
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
	printf("--------------------버블 정렬--------------------\n");
	srand(time(NULL)); // 난수 생성을 위해 srand를 사용합니다.
	int list[MAX_SIZE]; // MAX_SIZE(10)크기의 배열을 생성하고
	for (int i = 0; i < MAX_SIZE; i++) {
		list[i] = rand() % 100 + 1; // 1~100까지의 난수를 생성하여 list배열에 값을 삽입합니다.
	}
	bubble_sort(list, MAX_SIZE); // 버블 정렬 함수를 호출하고
	printf("\n정렬 데이터 : "); //정렬된 데이터를 출력합니다.
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", list[i]);
	}

	printf("\n--------------------버블 정렬--------------------\n\n--------------------삽입 정렬--------------------\n");
	int list2[MAX_SIZE]; // MAX_SIZE(10)크기의 배열을 생성하고
	for (int i = 0; i < MAX_SIZE; i++) {
		list2[i] = rand() % 100 + 1; // 1~100까지의 난수를 생성하여 list배열에 값을 삽입합니다.
	}
	insertion_sort(list2, MAX_SIZE); // 삽입 정렬 함수를 호출하고
	printf("\n정렬 데이터 : "); //정렬된 데이터를 출력합니다.
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", list2[i]);
	}

	printf("\n--------------------삽입 정렬--------------------\n\n--------------------선택 정렬--------------------\n");
	int list3[MAX_SIZE]; // MAX_SIZE(10)크기의 배열을 생성하고
	for (int i = 0; i < MAX_SIZE; i++) {
		list3[i] = rand() % 100 + 1; // 1~100까지의 난수를 생성하여 list배열에 값을 삽입합니다.
	}
	selection_sort(list3, MAX_SIZE); // 선택 정렬 함수를 호출하고
	printf("\n정렬 데이터 : "); //정렬된 데이터를 출력합니다.
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", list3[i]);
	}

	printf("\n--------------------선택 정렬--------------------\n\n--------------------쉘 정렬--------------------\n");
	int list4[MAX_SIZE]; // MAX_SIZE(10)크기의 배열을 생성하고
	for (int i = 0; i < MAX_SIZE; i++) {
		list4[i] = rand() % 100 + 1; // 1~100까지의 난수를 생성하여 list배열에 값을 삽입합니다.
	}
	shell_sort(list4, MAX_SIZE); // 쉘 정렬 함수를 호출하고
	printf("\n정렬 데이터 : "); //정렬된 데이터를 출력합니다.
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", list4[i]);
	}
	printf("\n--------------------쉘 정렬--------------------");
	return 0;

}