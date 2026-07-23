#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int optimalMerge(vector<int> &lists){
    priority_queue<int, vector<int>, greater<int>> pq;
    int sumCost = 0;
    for(int i=0; i<lists.size(); i++){
        pq.push(lists[i]);
    }

    while(pq.size() > 1){
        int min = pq.top();
        pq.pop();

        int min2 = pq.top();
        pq.pop();

        int merged = min + min2;
        sumCost += merged;
        pq.push(merged);
    }
    return sumCost;
}

int main() {

    vector<int> lists = {8, 5, 6, 9};
    int total_cost = optimalMerge(lists);
    cout<<"Minimum Cost with Optimal Merging : "<<total_cost<<endl;

    return 0;
}