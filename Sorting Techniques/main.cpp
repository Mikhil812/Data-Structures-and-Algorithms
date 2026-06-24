#include <iostream>
#include <cmath>
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

// Func for quick sort -> returns the partitioning position
int Partition(int A[], int low, int high){
    int pivot = A[low];           // Pivot element for which we find the right position to swap with
    int i = low + 1;              // Responsible for finding elements greater than pivot
    int j = high;                 // Responsible for finding elements smaller than pivot

    while(true){
        while(i<=j && A[i] <= pivot)
            i++;
        while(j>=i && A[j] > pivot)
            j--;
        
        // They have found their respective elements
        if(i < j){
            swap(&A[i], &A[j]);
        }else
            break;
    }

    // i > j for the code to reach here so we found the right position for pivot at j : 
    swap(&A[low], &A[j]);

    return j;
}

void QuickSort(int A[], int low, int high){
    // p = partitioning position
    if(low < high){
        int p = Partition(A, low, high);
        QuickSort(A, low, p - 1);
        QuickSort(A, p + 1, high);
    }
}

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

void IterativeMergeSort(int A[], int n){
    int p;                                      // Responsible for the 2 way merging, skips 2 the first time, then 4 then 8
    for(p=2; p<=n; p=p*2){
        for(int i=0; i+p-1 < n; i = i+p){       // i+p-1 : last index of the internal lists
            int low = i;
            int high = i+p-1;
            int mid = (low + high)/2;

            Merge(A, low, mid, high);
        }
    }
    // If Odd number of elements : last number would be remaining so merge it manually
    if(p/2 < n)
        Merge(A, 0, p/2 - 1, n-1);
}

void RecursiveMergeSort(int A[], int low, int high){
    if(low < high){
        int mid = (low + high)/2;
        RecursiveMergeSort(A, low, mid);        // sort left
        RecursiveMergeSort(A, mid+1, high);         // sort right
        Merge(A, low, mid, high);                   // merge both
    }
}

int findMax(int A[], int n){
    int max = INT32_MIN;
    for(int i=0; i<n; i++){
        if(A[i] > max)
            max = A[i];
    }
    return max;
}

void CountSort(int A[], int n){
    // 1. Find maximum element of A
    int max = findMax(A, n);

    // 2. Make Hash array and assign it to 0
    int *H = new int[max + 1];
    for(int i=0; i< max+1; i++)
        H[i] = 0;

    // 3. Fill hash array 
    for(int i=0; i<n; i++){
        H[A[i]]++;
    }

    // 4. Put sorted value(index) back into og array
    int i=0;        // For A
    int j=0;        // For H
    while(j < max + 1){
        if(H[j] > 0){
            A[i++] = j;
            H[j]--;
        }else
            j++;
    }

    // 5. Delete heap memory : H
    delete [] H;
}

class Node{
    public : 
        int data;
        Node *next;        
};

void Insert(Node **bins, int value){
    Node *temp = new Node();
    temp->data = value;
    temp->next = nullptr;

    if (bins[value] == nullptr)
        bins[value] = temp;
    else
    {
        Node *p = bins[value];
        Node *q = nullptr;
        while (p != nullptr)
        {
            q = p;
            p = p->next;
        }
        q->next = temp;
    }
}

int Delete(Node **bins, int idx){
    Node *p = bins[idx];
    bins[idx] = bins[idx]->next;

    int x = p->data;
    delete p;

    return x;
}

void BinSort(int A[], int n){
    // 1. Find Maximum element 
    int max = findMax(A, n);

    // 2. Create an array of linked lists of size (max + 1)
    Node **Bins = new Node*[max + 1];

    // 3. Initialize that array with NULLs
    for(int i=0; i<max+1; i++)
        Bins[i] = nullptr;
    
    // 4. Fill the Hash array with elements from A
    for(int i=0; i<n; i++){
        Insert(Bins, A[i]);
    }

    // 5. Delete elements from bin in order and copy it back in A
    int i=0, j=0;
    while(j < max + 1){
        while(Bins[j] != nullptr){
            A[i++] = Delete(Bins, j);
        }
        j++;
    }

    // 6. Delete heap memory : bins
    delete [] Bins;
}

int getBinIndex(int x, int idx){
    return (int)(x / pow(10, idx)) % 10;
}

// For radix : value is not stored at hash[value], its stored at hash[digit]
void Insert(Node **bins, int value, int digit){
    Node *temp = new Node();
    temp->data = value;
    temp->next = nullptr;

    if (bins[digit] == nullptr)
        bins[digit] = temp;
    else
    {
        Node *p = bins[digit];
        Node *q = nullptr;
        while (p != nullptr)
        {
            q = p;
            p = p->next;
        }
        q->next = temp;
    }
}

void RadixSort(int A[], int n){
    // Since integer -> radix/base of decimal is 10

    // 1. Find no. of digits of max element : 
    int max = findMax(A, n);
    int count = 0;
    while(max != 0){
        max = max/10;
        count++;
    }

    // 2. Create an array of linked lists of size 10 -> 0 to 9, since decimal
    Node **bins = new Node*[10];

    // 3. Initialize the array with Nulls
    for(int i=0; i<10; i++)
        bins[i] = nullptr;

    // 4. Drop the elements into the appt bins and remove "count" number of times
    for(int pass=0; pass<count; pass++){
        for(int i=0; i<n; i++){
            int digit = getBinIndex(A[i], pass);
            Insert(bins, A[i], digit);          // Different function than bin sort
        }
        int i=0, j=0;
        while(j < 10){
            while(bins[j] != nullptr){
                A[i++] = Delete(bins, j);
            }
            j++;
        }
    }

    // 6. Delete heap memory : bins
    delete [] bins;
}

void ShellSort(int A[], int n){
    // Intuition works on insertion sort with only selected elements seperated by gap

    int gap;
    for(gap = n/2; gap>=1; gap = gap/2){
        for(int i=gap; i<n; i++){
            int temp = A[i];    // element to be inserted to the left
            int j = i - gap;    // element to the left seperated by gap for comparison
            while(j>=0 && A[j] > temp){
                A[j+gap] = A[j];
                j = j-gap;      // this becomes negative so dw 
            }
            A[j+gap] = temp;    // here is where negative gets handled
        }
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
    // SelectionSort(A, n);
    display(A, n);

    cout<<"4. Quick Sort : "<<endl;
    // QuickSort(A, 0, n-1);
    display(A, n);

    cout<<"5 a. Iterative Merge Sort : "<<endl;
    // IterativeMergeSort(A, n);
    display(A, n);

    cout<<"5 b. Recursive Merge Sort : "<<endl;
    // RecursiveMergeSort(A, 0, n-1);
    display(A, n);

    cout<<"6. Count Sort : "<<endl;
    // CountSort(A, n);
    display(A, n);

    cout<<"7. Bucket/Bin Sort : "<<endl;
    // BinSort(A, n);
    display(A, n);

    cout<<"8. Radix Sort : "<<endl;
    // RadixSort(A, n);
    display(A, n);

    cout<<"9. Shell Sort : "<<endl;
    ShellSort(A, n);
    display(A, n);

    return 0;
}