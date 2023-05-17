/*


    순천향대학교 컴퓨터공학과
    20184102 신주용


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
    int n;   // 정점의 개수
    int adj_list[MAX_VERTICES];
} GraphType;

// 그래프 초기화 
void init(GraphType* g)
{
    int v;
    g->n = 0;
    for (v = 0; v < MAX_VERTICES; v++) { // for문을 통해 adj_list[v]의 값이 초기화되는 부분입니다. 
        g->adj_list[v] = NULL; // v가 MAX_VERTICES가 될 때까지 해당 값에 NULL을 대입합니다.
    }
}
// 정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
    if (((g->n) + 1) > MAX_VERTICES) { // g의 n요소, 즉 정점의 개수+1이 MAX_VERTICES가 될 경우
        fprintf(stderr, "그래프 : 정점의 개수 초과\n"); // 정점의 개수 초과를 출력합니다.
        return;
    }
    g->n++; // 이후 정점의 개수를 1 늘립니다.
}
// 간선 삽입 연산, v를 u의 인접 리스트에 삽입한다.
void insert_edge(GraphType* g, int u, int v)
{                            // 시작   끝
    GraphNode* node;
    if (u >= g->n || v >= g->n) { // 정점의 개수가 u, 즉 시작과 같거나 그보다 작거나 v보다 작거나 그것과 같다면
        fprintf(stderr, "그래프 :정점 번호 오류\n"); // 정점 번호 오류를 출력합니다.
        return;
    }
    node = (GraphNode*)malloc(sizeof(GraphNode));
    node->vertex = v; // node의 vertex에 v를 대입하고
    node->link = g->adj_list[u]; // link에는 adj_list의 u번째 값을 대입합니다.
    g->adj_list[u] = node; // 이후 node값을 adj_list의 u번째에 대입합니다.
}
// 인접 리스트 출력 함수
void print_adj_list(GraphType* g)
{
    for (int i = 0; i < g->n; i++) {
        GraphNode* p = g->adj_list[i];
        printf("정점 %d의 인접 리스트", i);
        while (p != NULL) { // p가 NULL값을 반환할 때까지
            printf(" -> %d", p->vertex); // p의 vertex값을 출력합니다.
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

    for (int i = 0; i < 4; i++) { // 1번에서 크기가 4인 정점을 사용했으므로 해당 값만큼의 정점을 삽입하고
        insert_vertex(g, i); 
    }
    insert_edge(g, 0, 2);
    insert_edge(g, 2, 0); // 1번에서 얻은 값들을 간선 삽입하여
    insert_edge(g, 0, 3);
    insert_edge(g, 3, 0);
    insert_edge(g, 1, 2);
    insert_edge(g, 2, 1);
    insert_edge(g, 1, 3);
    insert_edge(g, 3, 1);
    print_adj_list(g); // 연결 리스트를 출력합니다.

    free(g);
    return 0;
}