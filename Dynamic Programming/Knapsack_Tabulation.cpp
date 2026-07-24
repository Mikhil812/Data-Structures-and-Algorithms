#include <iostream>
using namespace std;

int profit[] = {0, 6, 5, 3, 8};
int weight[] = {0, 1, 2, 1, 2};

int max(int a, int b){
    return a > b ? a : b;
}

// 1. Initialize T ka 0th row and 0th column with 0's :
// 2. With this declaration, entire T is already initialized to 0
int T[4+1][5+1];
int Knap(){
    int n = 4; 
    int m = 5;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(weight[i] <= j){
                T[i][j] = max(T[i-1][j], T[i-1][j - weight[i]] + profit[i]);
            }
            else{
                T[i][j] = T[i-1][j];
            }
        }
    }

    return T[n][m];
}

void display(){
    for(int i=1; i<=4; i++){
        for(int j=1; j<=5; j++){
            cout<<T[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {

    // display();
    int max_profit = Knap();
    cout<<"Maximum Profit for 0/1 Knapsack using Tabulation : "<<endl;
    cout<<max_profit<<endl;

    return 0;
}