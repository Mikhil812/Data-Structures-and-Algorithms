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

int Delete(int A[], int n){
    int x = A[1];
    A[1] = A[n];
    A[n] = x;           // Storing the deleted element at the last vacant place, its not part of the heap

    int i=1, j=2*i;
    while(j < n-1){
        if(A[j+1] > A[j])   // if right child is greater than left child
            j = j+1;
        if(A[i] < A[j]){    // if parent is smaller than the max child, then we swap
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;

            i = j;
            j = 2*i;
        }else
            break;
    }   
    return x;
}

void heapSort(int A[], int n){
    for(int i=n; i>1; i--){
        Delete(A, i);
    }
}

void heapify(int A[], int n){
    // Number of leaf nodes : ceil(n/2) ~ (n+1)/2
    // First parent : n/2
    for(int i=n/2; i>=1; i--){
        int k = i;
        int j = 2*i;
        // Deletion logic used for insertion : 
        while(j <= n){
            if(j < n && A[j+1] > A[j])
                j++;                // move to the right child
            if(A[k] < A[j]){        // compare parent and max child
                int temp = A[k];
                A[k] = A[j];
                A[j] = temp;

                k = j;
                j = 2*k;
            }
            else
                break;
        }
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

    // cout<<"Min Heap : "<<endl;
    // createHeap(A, heapSize, "min");     // This is performing on the max heap array, not on the original array
    // Print(A, heapSize);

    cout<<"Deleting an Element : "<<endl;
    // cout<<Delete(A, heapSize)<<endl;
    Print(A, heapSize);

    cout<<"Heap Sort : "<<endl;
    heapSort(A, heapSize);          // Calling delete in a loop
    Print(A, heapSize);
    
    cout<<"2nd Orignal Array (1-based indexing): "<<endl;
    int B[] = {0, 10, 20, 30, 25, 5, 40, 35};      
    int heapSize2 = sizeof(B)/sizeof(B[0]) - 1;
    Print(B, heapSize2);

    cout<<"Heapify : "<<endl;
    heapify(B, heapSize2);
    Print(B, heapSize2);

    return 0;
}