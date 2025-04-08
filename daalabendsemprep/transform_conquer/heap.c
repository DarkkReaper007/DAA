#include<stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyUp(int index){
    int parent = (index- 1) / 2;
    while(index > 0 && heap[index] > heap[parent]){
        swap(&heap[index], &heap[parent]);
        index = parent;
        parent = (index -1) / 2;
    }
}

void insert(int value){
    if(size >= MAX){
        printf("Heap is full!\n");
        return;
    }
    heap[size] = value;
    heapifyUp(size);
    size++;
}

void displayHeap(){
    printf("Heap array");
    for(int i=0; i<size; i++){
        printf("%d ", heap[i]);
    }
    printf("\n");
}