#include <iostream>
using namespace std;

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(int A[], int n){
    for(int i=0; i<n-1; i++){
        int flag = 0;
        for(int j=0; j<n-1-i; j++){
            if(A[j] > A[j+1]){
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if(flag == 0)       // if after a pass, no swaps are done then its already sorted after that pass, this makes the bubble sort adaptive
            break;
    }
}

void InsertionSort(int A[], int n){
    for(int i=1; i<n; i++){             // i=0, we assume is already inserted
        int x = A[i];                   // element to be inserted
        int j = i-1;

        while(j>=0 && A[j] > x){
            A[j+1] = A[j];              // shifting
            j--;
        }
        A[j+1] = x;
    }
}

void SelectionSort(int A[], int n){
    for(int i=0; i<n-1; i++){
        int j, k;
        for(j=k=i; j<n; j++){
            if(A[j] < A[k]){
                k = j;
            }
        }
        swap(&A[i], &A[k]);
    }
}

void display(int A[], int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main() {

    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(A)/sizeof(A[0]);

    cout<<"Original Array : "<<endl;
    display(A, n);

    cout<<"1. Bubble Sort : "<<endl;
    // BubbleSort(A, n);
    display(A, n);

    cout<<"2. Insertion Sort : "<<endl;
    // InsertionSort(A, n);
    display(A, n);

    cout<<"3. Selection Sort : "<<endl;
    SelectionSort(A, n);
    display(A, n);

    return 0;
}