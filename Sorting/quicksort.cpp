/*
Quicksort sorts an array in O(n*logn) time. The worst case time of quicksort is O(n^2) when the array is already sorted we have to partion
for every element that is already at the right place.
Quicksort average running time is also O(n*logn) which comes more often than the wrost case running time. If we choose the partion which
divides the array in 75-25 split at max than the running time is good. We achive it by choosing a pivot on random.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int partion(vector<int>& arr, int l, int r) {
    int pivot = arr[r];     // we change this to choose a random pivot
    int i = l - 1;
    
    for(int j = l; j < r; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[j], arr[i]);
        }
    }

    swap(arr[i+1], arr[r]);
    return i+1;
}

void quicksort(vector<int>& arr, int l, int r) {
    if(l <= r) {
        int q = partion(arr, l, r);
        quicksort(arr, l, q-1);
        quicksort(arr, q+1, r);
    }
}


int main() {
    int n;
    cout << "Enter the size of the arr: ";
    cin >> n;
    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    quicksort(arr, 0, arr.size() - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}