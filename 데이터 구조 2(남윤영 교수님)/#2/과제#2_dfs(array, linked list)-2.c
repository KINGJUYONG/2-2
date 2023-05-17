/*


    ��õ����б� ��ǻ�Ͱ��а�
    20184102 ���ֿ�


*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 50
typedef struct GraphNode {
    int vertex;
    struct GraphNode* link;
}GraphNode;

typedef struct GraphType {
    int n;   // ������ ����
    int adj_list[MAX_VERTICES];
} GraphType;

// �׷��� �ʱ�ȭ 
void init(GraphType* g)
{
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTICES; v++) { // for���� ���� adj_list[v]�� ���� �ʱ�ȭ�Ǵ� �κ��Դϴ�. 
        g->adj_list[v] = NULL; // v�� MAX_VERTICES�� �� ������ �ش� ���� NULL�� �����մϴ�.
    }
}
// ���� ���� ����
void insert_vertex(GraphType* g, int v)
{
    if (((g->n) + 1) > MAX_VERTICES) { // g�� n���, �� ������ ����+1�� MAX_VERTICES�� �� ���
        fprintf(stderr, "�׷��� : ������ ���� �ʰ�\n"); // ������ ���� �ʰ��� ����մϴ�.
        return;
    }
    g->n++; // ���� ������ ������ 1 �ø��ϴ�.
}
// ���� ���� ����, v�� u�� ���� ����Ʈ�� �����Ѵ�.
void insert_edge(GraphType* g, int u, int v)
{                            // ����   ��
    GraphNode* node;
    if (u >= g->n || v >= g->n) { // ������ ������ u, �� ���۰� ���ų� �׺��� �۰ų� v���� �۰ų� �װͰ� ���ٸ�
        fprintf(stderr, "�׷��� :���� ��ȣ ����\n"); // ���� ��ȣ ������ ����մϴ�.
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v; // node�� vertex�� v�� �����ϰ�
    node->link = g->adj_list[u]; // link���� adj_list�� u��° ���� �����մϴ�.
    g->adj_list[u] = node; // ���� node���� adj_list�� u��°�� �����մϴ�.
}
// ���� ����Ʈ ��� �Լ�
void print_adj_list(GraphType* g)
{
    for (int i = 0; i < g->n; i++) {
        GraphNode* p = g->adj_list[i];
        printf("���� %d�� ���� ����Ʈ", i);
        while (p != NULL) { // p�� NULL���� ��ȯ�� ������
            printf(" -> %d", p->vertex); // p�� vertex���� ����մϴ�.
            p = p->link;
        }
        printf("\n");
    }
}

void main()
{
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);

    for (int i = 0; i < 4; i++) { // 1������ ũ�Ⱑ 4�� ������ ��������Ƿ� �ش� ����ŭ�� ������ �����ϰ�
        insert_vertex(g, i); 
    }
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 0); // 1������ ���� ������ ���� �����Ͽ�
    insert_edge(g, 0, 3);
    insert_edge(g, 3, 0);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 1, 3);
    insert_edge(g, 3, 1);
    print_adj_list(g); // ���� ����Ʈ�� ����մϴ�.

    free(g);
    return 0;
}