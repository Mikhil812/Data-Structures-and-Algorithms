#include <iostream>
using namespace std;

int profit[] = {0, 6, 5, 3, 8};
int weight[] = {0, 1, 2, 1, 2};

int T[4+1][5+1];
int Knap(int n, int m){
    if(n == 0 || m == 0){
        T[n][m] = 0;
        return 0;
    }
    if(T[n][m] != -1)
        return T[n][m];
    if(weight[n] <= m){
        int no = Knap(n-1, m);
        int yes = Knap(n-1, m - weight[n]) + profit[n];
        T[n][m] = no > yes ? no : yes;
    }else{
        T[n][m] = Knap(n-1, m);
    }
    return T[n][m];
}

int main(){
    // Initialize T with -1;
    for(int i = 0; i <= 4; i++){
        for(int j = 0; j <= 5; j++){
            T[i][j] = -1;
        }
    }

    int max_profit = Knap(4, 5);
    cout<<"Maximum Profit for 0/1 Knapsack using memoization : "<<endl;
    cout<<max_profit<<endl;

    return 0;
}