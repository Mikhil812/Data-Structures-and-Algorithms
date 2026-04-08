#include <iostream>
#include "basic_programs.h"
using namespace std;

int C(int n, int r)
{
    int n_fact = fact(n);
    int r_fact = fact(r);
    int nr_fact = fact(n-r);

    return (n_fact/(r_fact * nr_fact));
}

// Follows Pascals Triangle
int C_new(int n, int r)
{
    if(r==0 || n==r)
        return 1;
    return C_new(n-1, r-1) + C_new(n-1, r);
}
int main()
{
    int ans = C(4, 2);
    cout<<"Combinations ans : "<<ans<<endl;

    int ans_new = C_new(4, 2);
    cout<<"Combinations ans using Pascals Triangle : "<<ans_new<<endl;

    return 0;
}