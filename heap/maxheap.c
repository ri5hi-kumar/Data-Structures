#include<stdio.h>
#include<stdlib.h>

int size;
int n = -1;

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
    for (int i = 0; i <= n; i++)
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
    if (left <= size && heap[left] > heap[max_index])
    {
        max_index = left;
    }
    int right = rightChild(i);
    if (right <= size && heap[right] > heap[max_index])
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
    if (n == -1)
    {
        printf("Heap Empty!");
    }
    int result = heap[0];
    heap[0] = heap[n];
    n--;
    shiftdown(heap, 0);
    return result;
}

void insert(int *heap){
    if (n >= size - 1)
    {
        printf("Heap is full\n");
        return;
    }
    n++;
    scanf("%d", &heap[n]);
    shiftup(heap, n);
}

void removeElement(int *heap, int i){
    if (i > n)
    {
        printf("Out of bound removal!\n");
        return;
    }
    heap[i] = __INT_MAX__;
    shiftup(heap, i);
    extractMax(heap);
}

void changePriority(int *heap, int i, int new){
    if (i > n)
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


// void buildHeap(int *arr, int num){
//     int size = num;
//     for (int i = (size-1)/2; i <= 0 ; i--)
//     {
//         shiftdown(arr, i);
//     }
// }

// void heapSort(int *arr, int num){
//     buildHeap(arr, num);
//     int size = num - 1;
//     while((size)--){
//         int temp = arr[size];
//         arr[size] = arr[0];
//         arr[0] = temp;
//         shiftdown(arr, 0);
//     }
// }


int main(){
    printf("Enter the max size of heap: ");
    scanf("%d", &size);
    int *heap = (int *)malloc(size);

    insert(heap);
    insert(heap);
    insert(heap);
    insert(heap);

    printHeap(heap);

    // printf("Max element is: %d\n", extractMax(heap));
    // printHeap(heap);

    // removeElement(heap, 1);
    // printHeap(heap);

    changePriority(heap, 3, 67);
    printHeap(heap);

    /* sorting testing --> // NOT WORKING // */ 
    // int m;
    // printf("Enter the max size of array: ");
    // scanf("%d", &m);
    // int *arr = (int *)malloc(sizeof(int)*m);

    // for (int i = 0; i < m; i++)
    // {
    //     scanf("%d", &arr[i]);
    // }
    

    // heapSort(arr, m);
    // for (int i = 0; i < m; i++)
    // {
    //     printf("%d\t", arr[i]);
    // }
    // printf("\n");
}