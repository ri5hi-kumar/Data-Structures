// Basic sorting algorithms 

#include<stdio.h>

void bubbleSort(int *array, int n){
    for (int i = 0; i < n-1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}

void selectionSort(int *array, int n){
    for (int i = 0; i < n-1; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        int temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }
}

void insertionSort(int *array, int n){
    for (int i = 1; i < n; i++)
    {
        int value = array[i];
        int hole = i;
        while (hole > 0 && array[hole-1] > value)
        {
            array[hole] = array[hole-1];
            hole--;
        }
        array[hole] = value;
    }
    
}

int main(){
    int array[] = {9, 8 , 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(array)/sizeof(array[0]);

    // bubbleSort(array, size);
    // selectionSort(array, size);
    insertionSort(array, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");

}