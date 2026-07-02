#include <iostream>
using namespace std;

void Merge(int A[], int low, int mid, int high){
    int i=low;                                  // 2 - way Merging
    int j = mid + 1;                            // 1st list : 0 to mid    
    int h = high;                               // 2nd list : mid + 1 to high
    
    int *B = new int[high + 1];
    int k = low;                                  // For the auxilary array

    while(i <= mid && j <= h){
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    // When one of the arrays is completed : 
    while(i <= mid)
        B[k++] = A[i++];
    while(j <= h)
        B[k++] = A[j++];

    // Copy the sorted array back into the original array : 
    for(int i=low; i<=high; i++)
        A[i] = B[i];

    delete [] B;
}

void RecursiveMergeSort(int A[], int low, int high){
    if(low < high){
        int mid = (low + high)/2;
        RecursiveMergeSort(A, low, mid);            // sort left
        RecursiveMergeSort(A, mid+1, high);         // sort right
        Merge(A, low, mid, high);                   // merge both
    }
}

void display(int A[], int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main() {

    int A[] = {8, 3, 7, 4, 9, 2, 6};
    int n = sizeof(A)/sizeof(A[0]);

    cout<<"Original Array : "<<endl;
    display(A, n);

    cout<<"Recursive Merge Sort : "<<endl;
    RecursiveMergeSort(A, 0, n-1);
    display(A, n);

    return 0;
}