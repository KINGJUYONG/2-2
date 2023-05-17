#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES	100	
#define INF	1000000	/* ���Ѵ� (������ ���� ���) */

typedef struct GraphType {
	int n;	// ������ ����
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES];/* �����������κ����� �ִܰ�� �Ÿ� */
int found[MAX_VERTICES];		/* �湮�� ���� ǥ�� */

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}
void print_status(GraphType* g)
{
	static int step = 1;
	printf("{ %d }\n", step++);
	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF)
			printf("INF ");
		else
			printf("%2d ", distance[i]);
		
	}
	printf("\n");
	printf("\n\n");
}
//
void shortest_path(GraphType* g, int start)
{
	int i, u, w;
	int fulldistance = 0; // ����ġ�� ���� �����ֱ� ���� �̸� �������� �����Դϴ�.

	for (i = 0; i < g->n; i++) /* �ʱ�ȭ */
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE;    /* ���� ���� �湮 ǥ�� */
	distance[start] = 0;
	for (i = 0; i < g->n - 1; i++) {
		print_status(g);
		u = choose(distance, g->n, found);
		found[u] = TRUE;
		for (w = 0; w <= g->n; w++)
			if (!found[w])
				if (distance[u] + g->weight[u][w] < distance[w]) {
					distance[w] = distance[u] + g->weight[u][w];
				}
	}
	for (int i = 0; i < g->n; i++) { // ����ġ�� ���� ��� �����ִ� �κ��Դϴ�.
		fulldistance += distance[i];
	}
	printf("����ġ�� �� : %d", fulldistance);
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
	shortest_path(&g, 0);
	return 0;
}