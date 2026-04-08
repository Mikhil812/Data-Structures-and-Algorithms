#include <iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

struct Rectangle * fun(){
    struct Rectangle *p;
    p = new struct Rectangle;

    p->length = 15;
    p->breadth = 20;

    return p;
}
int main()
{
    struct Rectangle *ptr = fun();
    cout<<ptr->length<<" "<<ptr->breadth<<endl;
    ptr->length = 45;
    ptr->breadth = 45;
    cout<<ptr->length<<" "<<ptr->breadth<<endl;

    return 0;
}