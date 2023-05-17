#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES	100	
#define INF	1000000	/* ���Ѵ� (������ ���� ���) */

typedef struct GraphType {
	int n;	// ������ ����
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int A[MAX_VERTICES][MAX_VERTICES];

void printA(GraphType* g)
{
	int i, j;
	for (i = 0; i < g->n; i++) {
		for (j = 0; j < g->n; j++) {
			if (A[i][j] == INF) // ����ִ� ��θ� INF�� ����մϴ�.
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
	printf("A-1\n"); // A-1�ܰ��Դϴ�.
	for (i = 0; i < g->n; i++)
		for (j = 0; j < g->n; j++)
			A[i][j] = g->weight[i][j];
	printA(g);

	for (k = 0; k < g->n; k++) { // for���� 3������ ����Ͽ� A0~A5�ܰ踦 �����ϰ� ����մϴ�.
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

	printf("����ġ�� �� : %d", finaldistance);
}

int main(void)
{
	GraphType g = { 6, // ������ �׷����� ���� �������־����ϴ�.
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