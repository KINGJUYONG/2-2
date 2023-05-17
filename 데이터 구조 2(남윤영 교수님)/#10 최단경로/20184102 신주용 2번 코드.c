#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES	100	
#define INF	1000000	/* 무한대 (연결이 없는 경우) */

typedef struct GraphType {
	int n;	// 정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int A[MAX_VERTICES][MAX_VERTICES];

void printA(GraphType* g)
{
	int i, j;
	for (i = 0; i < g->n; i++) {
		for (j = 0; j < g->n; j++) {
			if (A[i][j] == INF) // 비어있는 경로를 INF로 출력합니다.
				printf("INF ");
			else printf("%3d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void floyd(GraphType* g)
{
	int finaldistance = 0;
	int i, j, k;
	printf("A-1\n"); // A-1단계입니다.
	for (i = 0; i < g->n; i++)
		for (j = 0; j < g->n; j++)
			A[i][j] = g->weight[i][j];
	printA(g);

	for (k = 0; k < g->n; k++) { // for문을 3중으로 사용하여 A0~A5단계를 생성하고 출력합니다.
		printf("A%d\n", k);
		for (i = 0; i < g->n; i++) 
			for (j = 0; j < g->n; j++)
				if (A[i][k] + A[k][j] < A[i][j])
					A[i][j] = A[i][k] + A[k][j];
		printA(g);
	}
	for (int i = 0; i < g->n; i++) {
		finaldistance += A[0][i];
	}

	printf("가중치의 합 : %d", finaldistance);
}

int main(void)
{
	GraphType g = { 6, // 과제의 그래프를 토대로 설정해주었습니다.
	{{ 0,  10,  INF, 30,   100,  INF },
	{ INF,  0, 50,  INF, INF, INF },
	{ INF,  INF, 0,  INF, 10, 5 },
	{ INF,  INF, 20,  0, INF, 15 },
	{ INF,  INF, INF,  60, 0, INF },
	{ INF,  INF, INF,  INF, INF, 0 },}
	};
	floyd(&g);
	return 0;
}