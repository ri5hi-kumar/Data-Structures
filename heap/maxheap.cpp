#include <iostream>
#include <vector>
using namespace std;

class heap
{
    vector<int> arr;

public:
    heap() {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }
    }

    int parent(int i);
    int leftChild(int i);
    int rightChild(int i);
    void printheap();
    void shiftdown(int i);
    void shiftup(int i);
    int top();
    void pop();
    void changePriority(int index, int new_priority);
    void buildheap();
};

int heap::parent(int i){
    return (i - 1)/2;
}

int heap::leftChild(int i){
    return 2*i+1;
}

int heap::rightChild(int i){
    return 2*i+2;
}

void heap::printheap(){
    printf("\nheap is as follows:\n");
    for (int i = 0; i < arr.size(); i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void heap::shiftup(int i){
    while (i > 0 && arr[parent(i)] < arr[i])
    {
        int temp = arr[parent(i)];
        arr[parent(i)] = arr[i];
        arr[i] = temp;
        i = parent(i);
    }
}

void heap::shiftdown(int i){
    int max_index = i;
    int left = leftChild(i);
    if (left < arr.size() && arr[left] > arr[max_index])
    {
        max_index = left;
    }
    int rigarrt = rightChild(i);
    if (rigarrt < arr.size() && arr[rigarrt] > arr[max_index])
    {
        max_index = rigarrt;
    }
    
    if (i != max_index)
    {
        int temp = arr[i];
        arr[i] = arr[max_index];
        arr[max_index] = temp;
        shiftdown(max_index);
    }
}

int heap::top() {
    return arr[0];
}

void heap::pop(){
    if (arr.empty())
    {
        printf("Heap Empty!\n");
    }
    arr[0] = arr[arr.size() - 1];
    shiftdown(0);
    arr.pop_back();
}

void heap::changePriority(int i, int n){
    if (i > arr.size() - 1)
    {
        printf("Out of bound!\n");
        return;
    }
    int old = arr[i];
    arr[i] = n;

    if(n > old){
        shiftup(i);
    }
    else{
        shiftdown(i);
    }
}

void heap::buildheap(){
    for (int i = (arr.size()-1)/2; i >= 0 ; i--)
    {
        shiftdown(i);
    }
}

int main()
{
    heap h;
    h.buildheap();
    h.printheap();
    cout << h.top() << endl;
    h.pop();
    cout << h.top() << endl;
    h.pop();
    h.printheap();
    return 0;
}