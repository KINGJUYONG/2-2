#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100 // element의 크기를 100으로 정의합니다.

typedef struct {
    int key; // 구조체 멤버 key를 선언합니다.
} element; // typedef를 사용하여 구조체 별칭을 element로 선언합니다.

typedef struct {
    element heap[MAX_ELEMENT + 1]; // element를 사용하여 MAX_ELEMENT의 크기를 가진 heap를 생성하는 함수를 만듭니다. (배열과 다르게 1부터 시작하기 때문에 +1을 해줍니다.)
    int heap_size; // 구조체 멤버 heap_size를 선언합니다.
} HeapType; // typedef를 사용하여 구조체 별칭을 HeapType으로 선언합니다

// 생성 함수
HeapType* create() // 
{
    return (HeapType*)malloc(sizeof(HeapType)); // HeapType을 사용하여 히프 생성 후 malloc을 사용하여 메모리를 할당합니다.
}
// 초기화 함수
void init(HeapType* h)
{
    h->heap_size = 0; //HeapType의 heap_size에 0을 대입합니다.
}

// 삽입 함수, 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
void insert_max_heap(HeapType* h, element item) 
{
    int i;
    i = ++(h->heap_size); // HeapType의 heap_size에 1을 더한 값을 i에 저장합니다.

    while ((i != 1) && (item.key > h->heap[i / 2].key)) { // 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정입니다.
        h->heap[i] = h->heap[i / 2]; // i가 1이 아니고, key값이 i/2번째의 key값보다 클때, heap의 i/2번째 값, 즉 우리가 원하는 i번째 히프의 값을 i에 저장합니다.
        i /= 2;
    }
    h->heap[i] = item; // 새로운 노드를 삽입 이후 item값을 heap의 i번째에 저장합니다.
}

// 삭제 함수
element delete_max_heap(HeapType* h)
{
    int parent, child;
    element item, temp;

    item = h->heap[1]; // item은 heap의 첫번째 값을 가집니다.
    temp = h->heap[(h->heap_size)--]; // temp는 heap size의 -1값을 가집니다.
    parent = 1;
    child = 2;
    while (child <= h->heap_size) { // 현재 노드의 자식노드 중 더 작은 자식노드를 찾습니다.
        if ((child < h->heap_size) && // child의 key값이 heap_size보다 작고, child노드의 키값이 다음 노드보다 작으면
            (h->heap[child].key) < h->heap[child + 1].key) // 
            child++; // child의 값을 하나 더합니다.
        if (temp.key >= h->heap[child].key) break; // temp(heapsize-1)의 키값이 child와 같거나 그보다 크면
        h->heap[parent] = h->heap[child]; // 한 단계 아래로 이동합니다.
        parent = child; // child의 값을 parent에 대입합니다.
        child *= 2; // 이후 child에 2를 곱합니다.
    }
    h->heap[parent] = temp; // temp의 값을 부모 노드에 저장하고
    return item; // item을 반환합니다.
}

int main(void)
{
    element e1, e2; // element 구조체 e1, e2를 선언합니다.
    HeapType* heap; //

    heap = create(); // 히프를 생성합니다.
    init(heap); // 초기화

    while (1) {
        char sel; // 선택한 문자를 저장해줄 문자 sel과 입력한 값을 저장해줄 gap을 선언합니다.
        int gap;

        scanf_s("%c", &sel);

        if (sel == 'I') { // sel에 입력된 값이 I라면
            int h1 = (heap->heap_size == MAX_ELEMENT); // heapsize의 크기가 MAX ELEMENT, 즉 101과 같다면 1을, 아니라면 0을 h1에 저장합니다. 
            if (h1 != 1) { // h1이 1이 아니라면
                scanf_s("%d", &e1.key); // scanf를 통해 e1의 key값에 숫자 하나를 저장하고
                insert_max_heap(heap, e1); // 위에서 정의한 insert_max_heap를 통해 정렬합니다.
            }
            else { // 아니라면, 즉 h1이 1이라면(HEAP의 크기와 MAX ELEMENT가 같다면)
            printf("FULL"); // FULL을 출력합니다.
            }
        }
        else if (sel == 'D') { // sel에 입력된 값이 D라면
            int h2 = (heap->heap_size == 0); // 위와 동일하게 지역변수 h2를 선언하여 heap size와 0이 같은 값인지를 확인합니다.
            if (h2 != 1) { // h2가 1이 아니라면, 즉 heapsize가 0이 아니라면,
                e2 = delete_max_heap(heap); // delete_max_heap를 통해 e2의 값을 지웁니다.
                printf("< %d >\n", e2.key); // 이후 e2의 key값을 출력합니다.
            }
            else { // h2가 1이라면
                printf("EMPTY\n"); // EMPTY를 출력합니다.
            }
        }
        else if (sel == 'Q') { // sel에 입력된 값이 Q라면
            break; // while문 반복을 깨뜨립니다.
        }
    }
    free(heap); // 동적 메모리 할당을 해제합니다. 
    return 0;
}