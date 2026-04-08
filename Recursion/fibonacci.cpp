#include <iostream>
using namespace std;

int fib(int n)
{
    if(n <= 1)
        return n;
    return fib(n-2) + fib(n-1);
}
// Using memoization : 
int F[10];
int fib_new(int n)
{
    if(n <= 1){ 
        F[n] = n;
        return n;
    }
    else{
        if(F[n-2] == -1)
            F[n-2] = fib_new(n-2);
        if(F[n-1] == -1)
            F[n-1] == fib_new(n-1);
        F[n] = F[n-2] + F[n-1];
        return F[n];
    }
}

int main()
{
    int ans = fib(7);
    cout<<"Fibonacci : "<<ans<<endl;

    for(int i=0; i<10; i++)
        F[i] = -1;
    int ans_new = fib_new(7);
    cout<<"Fibonacci using memoization : "<<ans_new<<endl;

    return 0;
}