#include <iostream>
#include <stdlib.h>

using namespace std;

class Array
{
    private : 
        int *A;
        int size;
        int length;
        void swap(int *x, int *y);
    
    public : 
        Array(){
            size = 10;
            length = 0;
            A = new int[size];
        }
        Array(int size, int length){
            this->size = size;
            this->length=length;
            A = new int[size];
        }
        int get_element(int index);
        void set_element(int index, int element);
        int max_element();
        int min_element();
        int sum();
        int average();
        void display();
        void append(int x);
        void insert(int index, int x);
        void del(int index);
        int linear_search(int key);
        int binary_search(int key);
        void reverse();
        void left_rotate();
        void right_rotate();
        void insert_sort(int element);
        bool is_sorted();
        void rearrange();
        Array * merge(Array arr);
        Array * union_set(Array *arr);
        Array * intersection_set(Array *arr);
        Array * difference_set(Array *arr);
};

int Array :: get_element(int index){
    if(index >= 0 && index < length)
        return A[index];
    cout<<"Index not valid "<<endl;
    return -1;
}

void Array :: set_element(int index, int element){
    if(index >= 0 && index < length)
        A[index] = element;
    else
        cout<<"Index not valid "<<endl;
}

int Array :: max_element(){
    int max = A[0];
    for(int i=1; i<length; i++){
        if(A[i] > max)
            max = A[i];
    }
    return max;
}

int Array :: min_element(){
    int min = A[0];
    for(int i=1; i<length; i++){
        if(A[i] < min)
            min = A[i];
    }
    return min;
}

int Array :: sum(){
    int sum = 0;
    for(int i=0; i<length; i++){
        sum += A[i];
    }
    return sum;
}

int Array :: average(){
    int sum = 0;
    for(int i=0; i<length; i++){
        sum += A[i];
    }
    return sum/length;
}

void Array :: display(){
    for(int i=0; i<length; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void Array :: append(int x){
    if(length < size){
        A[length] = x;
        length ++;
    }else{
        cout<<"Array size exceeded"<<endl;
    }
    // cout<<"Element "<<x<<" appended successfully"<<endl;
}

void Array :: insert(int index, int x){
    if(!(index >=0 && index <= length)){
        cout<<"Invalid Index"<<endl;
        return;
    }
    if(length < size){
        int i;
        for(i=length; i>index; i--){
            A[i] = A[i-1];
        }
        A[i] = x;
        length++;

    }else{
        cout<<"Array size exceeded"<<endl;
    }
}

void Array :: del(int index){
    if(index < 0 || index >= length){
        cout<<"Invalid Index for deletion"<<endl;
        return;
    }
    int i;
    for(i=index; i<length - 1;i++){
        A[i] = A[i+1];
    }
    // A[length] = 0;
    length--;
}

void Array :: swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Array :: linear_search(int key){
    for(int i=0; i<length; i++){
        if(A[i] == key){
            // swap(&A[i], &A[i-1]);     // Transposition
            swap(&A[i], &A[0]);          // Move to Front/Head
            return i;
        }
    }
    cout<<"Element not found "<<endl;
    return -1;
}

int Array :: binary_search(int key){
    int low=0;
    int high = length - 1;
    
    while(low <= high){
        int mid = (low + high)/2;
        if(A[mid] == key)
            return mid;
        else if(A[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout<<"Element not found"<<endl;
    return -1;
}

void Array :: reverse(){
    for(int i=0, j=length-1; i<j; i++, j--){
        swap(&A[i], &A[j]);
    }
}

void Array :: left_rotate(){
    int temp = A[0];
    for(int i=0; i<length; i++){
        A[i] = A[i+1];
    }
    A[length-1] = temp;
}

void Array :: right_rotate(){
    int temp = A[length - 1];
    for(int i=length - 1; i > 0; i--){
        A[i] = A[i-1];
    }
    A[0] = temp;
}

void Array :: insert_sort(int element){
    if(length >= size){
        cout<<"Arrays length has exceeded the size"<<endl;
        return;
    }
    int i=length-1;
    while(i>=0 && element < A[i]){
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = element;
    length++;
}

bool Array :: is_sorted(){
    for(int i=0; i<length-1; i++){
        if(A[i] > A[i+1])
            return false;
    }
    return true;
}

void Array :: rearrange(){
    int i=0; 
    int j=length-1;
    while(i < j){
        while(A[i] < 0)
            i++;
        while(A[j] >= 0)
            j--;
        if(i < j)
            swap(&A[i], &A[j]);
    }
}

Array* Array :: merge(Array arr){
    int i,j,k;
    i=j=k=0;
    Array *arr_ans = new Array(size + arr.size, length + arr.length);
    while(i<length && j<arr.length){
        if(A[i] < arr.A[j])
            arr_ans->A[k++] = A[i++];
        else   
            arr_ans->A[k++] = arr.A[j++];
    }
    while(i < length)
        arr_ans->A[k++] = A[i++];
    while(j < arr.length)
        arr_ans->A[k++] = arr.A[j++];

    arr_ans->length = length + arr.length;
    arr_ans->size = size + arr.size;

    return arr_ans;
} 

Array * Array :: union_set(Array *arr){
    int i,j,k;
    i=j=k=0;
    Array *arr_ans = new Array(size + arr->size, length + arr->length);
    while(i<length && j<arr->length){
        if(A[i] < arr->A[j])
            arr_ans->A[k++] = A[i++];
        else if(A[i] > arr->A[j])   
            arr_ans->A[k++] = arr->A[j++];
        else{
            arr_ans->A[k++] = A[i++];
            j++;
        }     
    }
    while(i < length)
        arr_ans->A[k++] = A[i++];
    while(j < arr->length)
        arr_ans->A[k++] = arr->A[j++];

    arr_ans->length = k;
    arr_ans->size = size + arr->size;

    return arr_ans;
}

Array * Array :: intersection_set(Array *arr){
    int i,j,k;
    i=j=k=0;
    Array *arr_ans = new Array(size + arr->size, length + arr->length);
    while(i<length && j<arr->length){
        if(A[i] < arr->A[j])
            i++;
        else if(A[i] > arr->A[j])   
            j++;
        else{
            arr_ans->A[k++] = A[i++];
            j++;
        }     
    }

    arr_ans->length = k;
    arr_ans->size = size + arr->size;

    return arr_ans;
}

Array * Array :: difference_set(Array *arr){
    int i,j,k;
    i=j=k=0;
    Array *arr_ans = new Array(size + arr->size, length + arr->length);
    while(i<length && j<arr->length){
        if(A[i] < arr->A[j])
            arr_ans->A[k++] = A[i++];
        else if(A[i] > arr->A[j])   
            j++;
        else{
            i++;
            j++;
        }     
    }
    while(i < length)
        arr_ans->A[k++] = A[i++];

    arr_ans->length = k;
    arr_ans->size = size + arr->size;

    return arr_ans;
}

int main()
{   
    Array arr1(10, 0);
    // int length;
    // cout<<"Enter length and then the elements : "<<endl;
    // cin>>length;

    // int x;
    for(int i=0; i<5; i++){
        // cin >> x;
        arr1.append(i+1);
    }
    arr1.insert(5, 10);
    arr1.del(2);
    arr1.display();

    // cout<<arr1.linear_search(5)<<endl;
    // cout<<arr1.binary_search(5)<<endl;

    // cout<<"Get : "<<arr1.get_element(2)<<endl;
    // arr1.set_element(2, 100);
    // arr1.display();
    // cout<<"Max : "<<arr1.max_element()<<endl;
    // cout<<"Min : "<<arr1.min_element()<<endl;
    // cout<<"Sum : "<<arr1.sum()<<endl;
    // cout<<"Average : "<<arr1.average()<<endl;

    // arr1.reverse();
    // arr1.display();
    // arr1.left_rotate();
    // arr1.display();
    // arr1.right_rotate();
    // arr1.display();

    // arr1.insert_sort(0);
    // cout<<"Sorted : "<<arr1.is_sorted()<<endl;
    // arr1.rearrange();
    // arr1.display();

    Array arr2(10, 0);
    for(int i=0; i<10; i+=2){
        arr2.append(i);
    }
    // arr2.display();
    Array arr3(10, 0);
    for(int i=1; i<10; i+=2){
        arr3.append(i);
    }
    // arr3.display();

    // Array *arr4 = arr2.merge(arr3);
    // arr4->display();

    arr2.insert_sort(10);
    arr3.insert_sort(10);
    arr2.display();
    arr3.display();

    // Array *arr4 = arr2.union_set(&arr3);
    // Array *arr4 = arr2.intersection_set(&arr3);
    // Array *arr4 = arr2.difference_set(&arr3);
    // arr4->display();

    return 0;
}