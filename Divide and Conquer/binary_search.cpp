#include <iostream>
using namespace std;

int A[] = {-12, -8, -6, -1, 3, 6, 8, 11, 14, 17, 20, 22, 25, 29, 31};

int BinarySearch(int low, int high, int key){
    if(low > high)
        return -1;
    
    int mid = (low + high)/2;
    if(key == A[mid])
        return mid;
    else if(key < A[mid])
        return BinarySearch(low, mid - 1, key);
    else
        return BinarySearch(mid + 1, high, key);
}

int main() {

    int index = BinarySearch(0, 14, 6);
    cout<<"Key element found at : "<<index<<endl;

    return 0;
}