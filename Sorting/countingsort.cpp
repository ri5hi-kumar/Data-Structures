/*
Countingsort sorts an array in O(n) time, given that all the elements in the input array are integers and in range(0, k). It sorts the
array by making a count of how many elements come before the element x so it can place the element in the next position
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void countingsort(vector<int>& arr, int k) {
    int size = arr.size();

    // k is the max element in arr
    vector<int> map(k+1, 0);

    // sorted array will be stored in this
    vector<int> sorted(size);

    // counting the frequency of the elements 
    for(int i = 0; i < arr.size(); i++) {
        map[arr[i]]++;
    }

    // doing this, map will store how many elements come before the index element
    for(int i = 1; i <= k; i++) {
        map[i] = map[i] + map[i-1];
    }

    // placing the elements at correct position
    for(int i = arr.size() - 1; i >= 0; i--) {
        sorted[map[arr[i]] - 1] = arr[i];
        map[arr[i]]--;
    }

    // copying the sorted array in the given array rather than returning the sorted array
    for(int i = 0; i < arr.size(); i++) {
        arr[i] = sorted[i];
    }

}


int main() {
    int n;
    cout << "Enter the size of the arr: ";
    cin >> n;
    vector<int> arr;
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x > k) k = x;
        arr.push_back(x);
    }

    countingsort(arr, k);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}