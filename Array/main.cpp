#include <iostream>
#include <stdlib.h>

using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

int get_element(struct Array arr, int index){
    if(index >= 0 && index < arr.length)
        return arr.A[index];
    cout<<"Index not valid "<<endl;
    return -1;
}

void set_element(struct Array *arr, int index, int element){
    if(index >= 0 && index < arr->length)
        arr->A[index] = element;
    else
        cout<<"Index not valid "<<endl;
}

int max_element(struct Array arr){
    int max = arr.A[0];
    for(int i=1; i<arr.length; i++){
        if(arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int min_element(struct Array arr){
    int min = arr.A[0];
    for(int i=1; i<arr.length; i++){
        if(arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

int sum(struct Array arr){
    int sum = 0;
    for(int i=0; i<arr.length; i++){
        sum += arr.A[i];
    }
    return sum;
}

int average(struct Array arr){
    int sum = 0;
    for(int i=0; i<arr.length; i++){
        sum += arr.A[i];
    }
    return sum/arr.length;
}

void display(struct Array arr){
    for(int i=0; i<arr.length; i++){
        cout<<arr.A[i]<<" ";
    }
    cout<<endl;
}

void append(struct Array *arr, int x){
    if(arr->length < arr->size){
        arr->A[arr->length] = x;
        arr->length ++;
    }else{
        cout<<"Array size exceeded"<<endl;
    }
    cout<<"Element "<<x<<" appended successfully"<<endl;
}

void insert(struct Array *arr, int index, int x){
    if(!(index >=0 && index < arr->length)){
        cout<<"Invalid Index"<<endl;
        return;
    }
    if(arr->length < arr->size){
        int i;
        for(i=arr->length; i>index; i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[i] = x;
        arr->length++;

    }else{
        cout<<"Array size exceeded"<<endl;
    }
}

void del(struct Array *arr, int index){
    if(index < 0 || index >= arr->length){
        cout<<"Invalid Index for deletion"<<endl;
        return;
    }
    int i;
    for(i=index; i<arr->length - 1;i++){
        arr->A[i] = arr->A[i+1];
    }
    // arr->A[arr->length] = 0;
    arr->length--;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int linear_search(struct Array *arr, int key){
    for(int i=0; i<arr->length; i++){
        if(arr->A[i] == key){
            // swap(&arr->A[i], &arr->A[i-1]);     // Transposition
            swap(&arr->A[i], &arr->A[0]);          // Move to Front/Head
            return i;
        }
    }
    cout<<"Element not found "<<endl;
    return -1;
}

int binary_search(struct Array arr, int key){
    int low=0;
    int high = arr.length - 1;
    
    while(low <= high){
        int mid = (low + high)/2;
        if(arr.A[mid] == key)
            return mid;
        else if(arr.A[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout<<"Element not found"<<endl;
    return -1;
}

void reverse(struct Array *arr){
    for(int i=0, j=arr->length-1; i<j; i++, j--){
        swap(&arr->A[i], &arr->A[j]);
    }
}

void left_rotate(struct Array *arr){
    int temp = arr->A[0];
    for(int i=0; i<arr->length; i++){
        arr->A[i] = arr->A[i+1];
    }
    arr->A[arr->length-1] = temp;
}

void right_rotate(struct Array *arr){
    int temp = arr->A[arr->length - 1];
    for(int i=arr->length - 1; i > 0; i--){
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = temp;
}

void insert_sort(struct Array *arr, int element){
    if(arr->length >= arr->size){
        cout<<"Arrays length has exceeded the size"<<endl;
        return;
    }
    int i=arr->length-1;
    while(i>=0 && element < arr->A[i]){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = element;
    arr->length++;
}

bool is_sorted(struct Array arr){
    for(int i=0; i<arr.length-1; i++){
        if(arr.A[i] > arr.A[i+1])
            return false;
    }
    return true;
}

void rearrange(struct Array *arr){
    int i=0; 
    int j=arr->length-1;
    while(i < j){
        while(arr->A[i] < 0)
            i++;
        while(arr->A[j] >= 0)
            j--;
        if(i < j)
            swap(&arr->A[i], &arr->A[j]);
    }
}

struct Array * merge(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = new struct Array;
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else   
            arr3->A[k++] = arr2->A[j++];
    }
    while(i < arr1->length)
        arr3->A[k++] = arr1->A[i++];
    while(j < arr2->length)
        arr3->A[k++] = arr2->A[j++];

    arr3->length = arr1->length + arr2->length;
    arr3->size = arr1->size + arr2->size;

    return arr3;
} 

struct Array * union_set(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = new struct Array;
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr1->A[i] > arr2->A[j])   
            arr3->A[k++] = arr2->A[j++];
        else{
            arr3->A[k++] = arr1->A[i++];
            j++;
        }     
    }
    while(i < arr1->length)
        arr3->A[k++] = arr1->A[i++];
    while(j < arr2->length)
        arr3->A[k++] = arr2->A[j++];

    arr3->length = k;
    arr3->size = arr1->size + arr2->size;

    return arr3;
}

struct Array * intersection_set(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = new struct Array;
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j])
            i++;
        else if(arr1->A[i] > arr2->A[j])   
            j++;
        else{
            arr3->A[k++] = arr1->A[i++];
            j++;
        }     
    }

    arr3->length = k;
    arr3->size = arr1->size + arr2->size;

    return arr3;
}

struct Array * difference_set(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = new struct Array;
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr1->A[i] > arr2->A[j])   
            j++;
        else{
            i++;
            j++;
        }     
    }
    while(i < arr1->length)
        arr3->A[k++] = arr1->A[i++];

    arr3->length = k;
    arr3->size = arr1->size + arr2->size;

    return arr3;
}

int main()
{   
    // struct Array arr = {{1,2,-3,4,-5}, 10, 5};

    // display(arr);
    // append(&arr, 100);
    // display(arr);
    // insert(&arr, 2, 577);
    // display(arr);

    // del(&arr,6);
    // display(arr);
    // cout<<linear_search(&arr, 5)<<endl;
    // display(arr);
    // cout<<binary_search(arr, 5)<<endl;

    // cout<<"Get : "<<get_element(arr, 2)<<endl;
    // set_element(&arr, 2, 100);
    // cout<<"Max : "<<max_element(arr)<<endl;
    // cout<<"Min : "<<min_element(arr)<<endl;
    // cout<<"Sum : "<<sum(arr)<<endl;
    // cout<<"Average : "<<average(arr)<<endl;

    // reverse(&arr);
    // left_rotate(&arr);
    // right_rotate(&arr);

    // insert_sort(&arr, 0);
    // cout<<"Sorted : "<<is_sorted(arr)<<endl;
    // rearrange(&arr);
    // display(arr);

    struct Array arr1 = {{2, 4, 5, 10, 12, 14}, 10, 6};
    struct Array arr2 = {{1, 3, 10, 14, 16}, 10, 5};
    // struct Array *arr3 = merge(&arr1, &arr2);

    struct Array *arr3 = union_set(&arr1, &arr2);
    struct Array *arr4 = intersection_set(&arr1, &arr2);
    struct Array *arr5 = difference_set(&arr1, &arr2);

    display(arr1);
    display(arr2);
    display(*arr3);
    display(*arr4);
    display(*arr5);

    return 0;
}