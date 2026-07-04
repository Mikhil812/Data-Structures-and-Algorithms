#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Object{
    public:
        double profit;
        double weight;
        int index;
        Object(int p, int w, int i){
            this->profit = p;
            this->weight = w;
            this->index = i;
        }
};

bool compare(const Object &A, const Object &B){
    double a1 = A.profit/A.weight;
    double b1 = B.profit/B.weight;

    return a1 > b1;
}

vector<double> fractional_knapsack(vector<Object> &obj, int m){
    int n = obj.size();
    vector<double> result(n, 0.0);

    // Selection Procedure : Sort obj with decreasing value of profit/weight with helper function
    sort(obj.begin(), obj.end(), compare);

    // Scan one by one and include it in solution : 
    for(int i=0; i<n; i++){
        if(obj[i].weight <= m){
            m = m - obj[i].weight;
            result[obj[i].index] = 1.0;
        }else{
            result[obj[i].index] = m / obj[i].weight;
            break;                       // Knapsack complete : i.e. m = 0 here
        }
    }
    return result;
}

double calcProfit(vector<double> &solution, vector<int> &profit){
    double sumProfit = 0.0;
    for(int i=0; i<solution.size(); i++){
        sumProfit += solution[i] * profit[i];
    }

    return sumProfit;
}

int main() {
    vector<Object> p1;

    vector<int> profit = {12, 17, 9, 7, 5, 21, 8};
    vector<int> weight = {2, 5, 7, 3, 1, 4, 1};
    int capacity = 15;
    int n = profit.size();
    
    for(int i=0; i<n; i++){
        p1.push_back(Object(profit[i], weight[i], i));
    }

    vector<double> solution = fractional_knapsack(p1, capacity);
    cout << "Solution array:\n";
    for(double x : solution){
        cout << x << " ";
    }
    cout << endl;

    cout<<"Maximum Profit : "<<endl;
    double maxProfit = calcProfit(solution, profit);
    cout<<maxProfit<<endl;

    return 0;
}