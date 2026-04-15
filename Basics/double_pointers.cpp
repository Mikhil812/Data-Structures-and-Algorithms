#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int *b = &a;

    cout<<"&a : "<<&a<<endl;
    cout<<"b : "<<b<<endl;
    cout<<endl;
    int **c = &b;
    cout<<"&b : "<<&b<<endl;
    cout<<"c : "<<c<<endl;

    cout<<**c<<endl;

    return 0;
}