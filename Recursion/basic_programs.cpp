#include <iostream>
#include "basic_programs.h"
using namespace std;

// Sum of N natural numbers: 
int sum(int n){
    if(n == 0)
        return 0;
    return sum(n - 1) + n;
}
// Factorial of a Number : 
int fact(int n){
    if(n == 0)
        return 1;
    return fact(n - 1) * n;
}
// Power of a Number (2nd way):
int pow(int m, int n){
    if(n == 0)
        return 1;
    if(n%2 == 0)
        return pow(m * m, n/2);
    return pow(m*m, (n-1)/2) * m;
}

// int main()
// {
//     int sum_ans = sum(5);
//     cout<<"Sum : "<<sum_ans<<endl;

//     int fact_ans = fact(4);
//     cout<<"Factorial : "<<fact_ans<<endl;

//     int pow_ans = pow(2, 5);
//     cout<<"Power : "<<pow_ans<<endl;

//     return 0;
// }