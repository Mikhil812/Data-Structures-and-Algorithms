#include <iostream>
using namespace std;

void Print(int A[], int n){
    for(int i=1; i<=n; i++){             // starts from 1 because of 1-based indexing
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void InsertMaxHeap(int A[], int i){
    int temp = A[i];
    while(i>1 && temp > A[i/2]){
        A[i] = A[i/2];
        i=i/2;
    }
    A[i] = temp;
}

void InsertMinHeap(int A[], int i){
    int temp = A[i];
    while(i>1 && temp < A[i/2]){
        A[i] = A[i/2];
        i=i/2;
    }
    A[i] = temp;
}

void createHeap(int A[], int n, string type){
    if(type == "max"){
        for(int i=2; i<=n; i++){
            InsertMaxHeap(A, i);
        }
    }else if(type == "min"){
        for(int i=2; i<=n; i++){
            InsertMinHeap(A, i);
        }
    }else{
        cout<<"Not a valid type : only options are max heap and min heap"<<endl;
    }
    
}

int main() {
    cout<<"Orignal Array (1-based indexing): "<<endl;
    int A[] = {0, 10, 20, 30, 25, 5, 40, 35};      
    int heapSize = sizeof(A)/sizeof(A[0]) - 1;
    Print(A, heapSize);

    cout<<"Max Heap : "<<endl;
    createHeap(A, heapSize, "max");
    Print(A, heapSize);

    cout<<"Min Heap : "<<endl;
    createHeap(A, heapSize, "min");     // This is performing on the max heap array, not on the original array
    Print(A, heapSize);

    return 0;
}