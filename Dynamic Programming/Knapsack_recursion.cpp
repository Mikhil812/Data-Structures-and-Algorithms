#include <iostream>
using namespace std;

// Global variables : 
int profit[] = {0, 6, 5, 3, 8};
int weight[] = {0, 1, 2, 1, 2};

int Knap(int n, int m){
    if(n == 0 || m == 0)
        return 0;

    if(weight[n] <= m){
        int no = Knap(n-1, m);
        int yes = Knap(n-1, m- weight[n]) + profit[n];
        return no > yes ? no : yes;
    }else{
        return Knap(n-1, m);
    }
}

int main() {

    int max_profit = Knap(4, 5);
    cout<<"Maximum Profit for 0/1 Knapsack using recursion : "<<endl;
    cout<<max_profit<<endl;

    return 0;
}