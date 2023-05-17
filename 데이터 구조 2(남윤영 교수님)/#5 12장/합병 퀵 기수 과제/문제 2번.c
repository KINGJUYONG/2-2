#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
int n = 9;
int list[MAX_SIZE] = { 5,3,8,4,9,1,6,2,7 };
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;
	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (low <= right && list[low] < pivot);
		do
			high--;
		while (high >= left && list[high] > pivot);
		for (int i = 0; i < 9; i++) {
			printf("%d  ", list[i]);
		} printf("\n");
		printf("\nlow : %d high : %d\n\n", list[low], list[high]);
		for (int i = 0; i < low; i++) {
			printf("    ");
		}printf("low\n");
		for (int i = 0; i < high; i++) {
			printf("    ");
		}printf("high\n");
		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);

	SWAP(list[left], list[high], temp);
	return high;
}

void quick_sort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		list[i] = rand() % 100;
	}
	quick_sort(list, 0, n - 1);
	for (int i = 0; i < 9; i++) {
		printf("%d ", list[i]);
	}

	return 0;
}