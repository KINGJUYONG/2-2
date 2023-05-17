#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES	100	
#define INF	1000000	/* 무한대 (연결이 없는 경우) */

typedef struct GraphType {
	int n;	// 정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES];/* 시작정점으로부터의 최단경로 거리 */
int found[MAX_VERTICES];		/* 방문한 정점 표시 */

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
	int fulldistance = 0; // 가중치의 합을 더해주기 위해 미리 선언해준 변수입니다.

	for (i = 0; i < g->n; i++) /* 초기화 */
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE;    /* 시작 정점 방문 표시 */
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
	for (int i = 0; i < g->n; i++) { // 가중치의 합을 모두 더해주는 부분입니다.
		fulldistance += distance[i];
	}
	printf("가중치의 합 : %d", fulldistance);
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
	shortest_path(&g, 0);
	return 0;
}