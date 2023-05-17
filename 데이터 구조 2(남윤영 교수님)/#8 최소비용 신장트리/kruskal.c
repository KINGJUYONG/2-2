#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];		// �θ� ���
int finalweight = 0; // ����ġ�� ��� �ջ����ֱ� ���� �̸� ������ �����Դϴ�.
int finalline = 0; // 
							
void set_init(int n) // �ʱ�ȭ �Լ�
{
	for (int i = 0; i < n; i++)
		parent[i] = -1;
}
// curr�� ���ϴ� ������ ��ȯ�Ѵ�.
int set_find(int curr)
{
	if (parent[curr] == -1)
		return curr; 			// ��Ʈ 
	while (parent[curr] != -1) curr = parent[curr];
	return curr;
}

// �ΰ��� ���Ұ� ���� ������ ��ģ��.
void set_union(int a, int b)
{
	int root1 = set_find(a);	// ��� a�� ��Ʈ�� ã�´�. 
	int root2 = set_find(b);	// ��� b�� ��Ʈ�� ã�´�. 
	if (root1 != root2) 	// ���Ѵ�. 
		parent[root1] = root2;
}

struct Edge {			// ������ ��Ÿ���� ����ü
	int start, end, weight;
};

typedef struct GraphType {
	int n;	// ������ ����
	struct Edge edges[2 * MAX_VERTICES];
} GraphType;

// �׷��� �ʱ�ȭ 
void graph_init(GraphType* g)
{
	g->n = 0;
	for (int i = 0; i < 2 * MAX_VERTICES; i++) {
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}
// ���� ���� ����
void insert_edge(GraphType* g, int start, int end, int w)
{
	g->edges[g->n].start = start;
	g->edges[g->n].end = end;
	g->edges[g->n].weight = w;
	g->n++;
	if (start > finalline) {
		finalline = start;
	}

	if (end > finalline) {
		finalline = end;
	}
}
// qsort()�� ���Ǵ� �Լ�
int compare(const void* a, const void* b)
{
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;
	return (x->weight - y->weight);
}

// kruskal�� �ּ� ��� ���� Ʈ�� ���α׷�
void kruskal(GraphType* g)
{
	int edge_accepted = 0;	// ������� ���õ� ������ ��	
	int uset, vset;			// ���� u�� ���� v�� ���� ��ȣ
	struct Edge e;

	set_init(g->n);				// ���� �ʱ�ȭ
	qsort(g->edges, g->n, sizeof(struct Edge), compare);

	int i = 0;
	while (edge_accepted < finalline)//(g->n - 1))	// ������ �� < (n-1)
	{
		e = g->edges[i];
		uset = set_find(e.start);		// ���� u�� ���� ��ȣ 
		vset = set_find(e.end);		// ���� v�� ���� ��ȣ
		if (uset != vset) {			// ���� ���� ������ �ٸ���
			printf("(%d,%d)\n", e.start, e.end);
			edge_accepted++;
			finalweight += e.weight; // ������ ����ġ�� finalweight�� �����ݴϴ�.
			set_union(uset, vset);	// �ΰ��� ������ ��ģ��.
		}
		i++;
	}
	printf("\n%d", finalweight);
}
int main(void)
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	graph_init(g);

	insert_edge(g, 0, 1, 35);
	insert_edge(g, 1, 2, 123);
	insert_edge(g, 2, 3, 117);
	insert_edge(g, 0, 4, 245);
	insert_edge(g, 4, 5, 87);
	insert_edge(g, 1, 5, 154);
	insert_edge(g, 5, 2, 165);
	insert_edge(g, 5, 6, 155);
	insert_edge(g, 2, 6, 222);
	insert_edge(g, 6, 7, 164);
	insert_edge(g, 4, 8, 98);
	insert_edge(g, 5, 8, 122);

	kruskal(g);
	free(g);

	printf("\n��ǻ�Ͱ��а� 20184102 ���ֿ�");
	return 0;
}