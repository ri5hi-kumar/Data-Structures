#include<stdio.h>
#include<stdlib.h>

int max_size;
int last_index = -1;

int parent(int i){
    return (i - 1)/2;
}

int leftChild(int i){
    return 2*i+1;
}

int rightChild(int i){
    return 2*i+2;
}

void printHeap(int *heap){
    printf("\nHeap is as follows:\n");
    for (int i = 0; i <= last_index; i++)
    {
        printf("%d\t", heap[i]);
    }
    printf("\n");
}

void shiftup(int *heap, int i){
    while (i > 0 && heap[parent(i)] < heap[i])
    {
        int temp = heap[parent(i)];
        heap[parent(i)] = heap[i];
        heap[i] = temp;
        i = parent(i);
    }
}

void shiftdown(int *heap, int i){
    int max_index = i;
    int left = leftChild(i);
    if (left <= last_index && heap[left] > heap[max_index])
    {
        max_index = left;
    }
    int right = rightChild(i);
    if (right <= last_index && heap[right] > heap[max_index])
    {
        max_index = right;
    }
    
    if (i != max_index)
    {
        int temp = heap[i];
        heap[i] = heap[max_index];
        heap[max_index] = temp;
        shiftdown(heap, max_index);
    }
}

int extractMax(int *heap){
    if (last_index == -1)
    {
        printf("Heap Empty!");
    }
    int result = heap[0];
    heap[0] = heap[last_index];
    last_index--;
    shiftdown(heap, 0);
    return result;
}

void insert(int *heap){
    if (last_index >= max_size - 1)
    {
        printf("Heap is full\n");
        return;
    }
    last_index++;
    scanf("%d", &heap[last_index]);
    shiftup(heap, last_index);
}

void removeElement(int *heap, int i){
    if (i > last_index)
    {
        printf("Out of bound removal!\n");
        return;
    }
    heap[i] = __INT_MAX__;
    shiftup(heap, i);
    extractMax(heap);
}

void changePriority(int *heap, int i, int new){
    if (i > last_index)
    {
        printf("Out of bound!\n");
        return;
    }
    int old = heap[i];
    heap[i] = new;

    if(new > old){
        shiftup(heap, i);
    }
    else{
        shiftdown(heap, i);
    }
}


void buildHeap(int *arr, int arr_size){
    for (int i = (arr_size-1)/2; i >= 0 ; i--)
    {
        shiftdown(arr, i);
    }
}

void heapSort(int *arr, int arr_size){
    buildHeap(arr, arr_size);
    while(last_index > 0){
        int temp = arr[last_index];
        arr[last_index] = arr[0];
        arr[0] = temp;
        last_index--;
        shiftdown(arr, 0);
    }
}


int main(){
    // printf("Enter the max size of heap: ");
    // scanf("%d", &max_size);
    // int *heap = (int *)malloc(max_size);

    // insert(heap);
    // insert(heap);
    // insert(heap);
    // insert(heap);

    // printHeap(heap);

    // printf("Max element is: %d\n", extractMax(heap));
    // printHeap(heap);

    // removeElement(heap, 1);
    // printHeap(heap);

    // changePriority(heap, 1, 67);
    // printHeap(heap);



    /* sorting testing --> // WORKING // */
    printf("Enter the max size of heap: ");
    scanf("%d", &max_size);
    int *arr = (int *)malloc(max_size);

    int m = 10;
    last_index = m - 1;

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    heapSort(arr, m);
    for (int i = 0; i < m; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    
    return 0;
}