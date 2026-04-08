#include <iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

int main()
{
    int A[5] = {1,2,3,4,5};
    int *p1 = A; // or int *p1 = &A[0]
    for(int i=0; i<5; i++){
        cout<<p1[i]<<" ";
    }
    cout<<endl;

    int *p2 = new int[5];
    p2[0] = 31;
    for(int i=0; i<5; i++){
        cout<<p2[i]<<" ";
    }
    cout<<endl;

    int *p3;
    char *p4;
    struct Rectangle *p5;

    cout<<sizeof(p1)<<endl;
    cout<<sizeof(p2)<<endl;
    cout<<sizeof(p3)<<endl;
    cout<<sizeof(p4)<<endl;
    cout<<sizeof(p5)<<endl;

    // Reference : 
    int a = 10;
    int &r = a;     // declaration and initialization together
 
    a++;
    cout<<r<<" "<<a<<endl;

    // Pointer to structure : 
    p5 = new Rectangle;
    p5->length = 3;  // or (*p).length = 3
    p5->breadth = 5;

    cout<<p5->length<<endl;
    cout<<p5->breadth<<endl;

    return 0;
}