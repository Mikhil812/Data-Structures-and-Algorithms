#include <iostream>
using namespace std;

double e(int x, int n){
    static double p = 1;
    static double f = 1;

    if(n == 0)
        return 1;
    
    double r = e(x, n-1);
    p = p*x;
    f = f*n;
    return r + p/f;
}   

// Using horners rule : 
double e_new(double x, double n){
    static double s = 1;
    if(n == 0)
        return s;
    s = 1 + ((x/n) * s);
    return e_new(x, n-1);
}

int main()
{   
    double ans = e(2, 10);
    cout<<"Taylor Series answer : "<<ans<<endl;

    double ans2 = e_new(2, 10);
    cout<<"Taylor Series answer using horners rule : "<<ans2<<endl;

    return 0;
}