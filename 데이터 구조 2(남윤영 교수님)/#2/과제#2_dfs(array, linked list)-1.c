/*


    순천향대학교 컴퓨터공학과
    20184102 신주용


*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 10
typedef struct GraphType {
    int n;   // 정점의 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES]; // 행렬이 들어갈 공간
} GraphType;

// 그래프 초기화 
void init(GraphType* g)
{
    int r, c;
    g->n = 0;
    for (r = 0; r < MAX_VERTICES; r++) // for문을 이용하여 모든 행렬값에 0을 대입해주는 함수입니다.
        for (c = 0; c < MAX_VERTICES; c++)
            g->adj_mat[r][c] = 0;
}
// 정점 삽입 연산
void insert_vertex(GraphType* g, int v)
{
    if (((g->n) + 1) > MAX_VERTICES) {
        fprintf(stderr, "그래프: 정점의 개수 초과\n");
        return ;
    }
    g->n++; // g의 n, 정점의 개수를 늘려줍니다.
}
// 간선 삽입 연산
void insert_edge(GraphType* g, int start, int end)
{
    if (start >= g->n || end >= g->n) { // start나 end의 값이 정점의 갯수보다 크거나 같다면
        fprintf(stderr, "그래프: 정점 번호 오류\n"); // 오류 문구를 출력합니다.
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}
// 인접 행렬 출력 함수
void print_adj_mat(GraphType* g)
{
    char alphabet = 'A';
    for (int i = 0; i < g->n; i++) {
        printf("%c : ", alphabet++);
        for (int j = 0; j < g->n; j++) {
                printf("%2d ", g->adj_mat[i][j]);
        }
        printf("\n");
    }
}

int visited[MAX_VERTICES];
// 인접 행렬로 표현된 그래프에 대한 깊이 우선 탐색
void dfs_mat(GraphType* g, int v) {
    int w;
    visited[v] = 1; // 정점 v의 방문 표시
    printf(" %c ", v + 65); // 방문한 정점 출력
    for (w = 0; w < g->n; w++) { // 인접 정점 탐색
        if (g->adj_mat[v][w] && !visited[w]) {
            dfs_mat(g, w); //정점 w에서 DFS 새로 시작
        }
    }
}

void main()
{
    GraphType* g;
    g = (GraphType*)malloc(sizeof(GraphType));
    init(g);

    int j = 0; // 정점의 개수를 입력받을 부분입니다.
    int kan = 0; // 간선의 수를 입력받을 부분입니다.
    srand((unsigned int)time(NULL));

    printf("정점의 개수는 ? ");
    scanf("%d", &j);
    printf("랜덤 연결 그래프 생성\n간선 수 : ");
    scanf("%d", &kan);

    insert_vertex(g, j);

    for (int i = 1; i < j; i++) { // 정점의 수만큼 정점 삽입을 반복합니다.
        insert_vertex(g, j);
    }

    for (int i = 0; i < kan; i++) {
        int SIZE = j;
        int num1 = (rand() % SIZE); // 임의의 값을 num1, num2에 삽입합니다.
        int num2 = (rand() % SIZE);
        if (((g->adj_mat[num1][num2] == 1) || (g->adj_mat[num2][num1] == 1)) || (num1 == num2)){
             --i; // adj_mat의 num1,num2번째 값이 1이거나, num2,num1번째의 값이 1이거나, num1과 num2가 같으면,
        }         // i를 하나 빼주어 다시 for문이 돌아갈 수 있게 합니다.
        else { // 그렇지 않다면, 즉 정상적으로 빈 행렬을 찾았다면
            insert_edge(g, num1, num2); // 간선을 삽입합니다.
        }
    }   
    print_adj_mat(g); // adj_mat함수를 사용하여 행렬을 출력합니다.

    printf("DFS : ");
    dfs_mat(g, 0); // 이후 깊이 우선 탐색 함수를 실행하여 DFS를 출력합니다.

    free(g); // g에 할당된 메모리를 해제하여 메모리 누수를 방지합니다.
    return 0;
}