#include <iostream>
using namespace std;

// Exact same thing will happen with global variable too. i.e. a single copy will be created for them.
int fun(int n){
    static int x = 1;
    if(n > 0){
        x++;
        return fun(n - 1) + x;
    }
    return 0;
}
int main()
{
    int x = 3;
    cout<<fun(x)<<endl;

    return 0;
}