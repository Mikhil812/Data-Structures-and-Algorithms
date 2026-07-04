#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Basically the method sort compares elements, and here each element is a vector
bool compare(const vector<int> &A, const vector<int> &B){
    double a1 = (double)A[0] / A[1];
    double b1 = (double)B[0] / B[1];
    return a1 > b1;
}

double fractional_knapsack(vector<int> &profit, vector<int> &weight, int m){
    int n = profit.size();
    vector<vector<int>> obj(n, vector<int>(2));

    for(int i = 0; i < n; i++){
        obj[i][0] = profit[i];
        obj[i][1] = weight[i];
    }

    // Selection Procedure : Sort obj with decreasing value of profit/weight with helper function
    sort(obj.begin(), obj.end(), compare);

    // Scan one by one and include it in solution : 
    double sumProfit = 0.0;
    for(int i = 0; i < n; i++){
        if(obj[i][1] <= m){
            sumProfit += obj[i][0];
            m -= obj[i][1];
        }else{
            sumProfit += obj[i][0] * ((double)m / obj[i][1]);
            break;      // Knapsack complete : i.e. m = 0 here
        }
    }

    return sumProfit;
}

int main(){
    vector<int> profit = {12, 17, 9, 7, 5, 21, 8};
    vector<int> weight = {2, 5, 7, 3, 1, 4, 1};
    int capacity = 15;

    double maxProfit = fractional_knapsack(profit, weight, capacity);
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}