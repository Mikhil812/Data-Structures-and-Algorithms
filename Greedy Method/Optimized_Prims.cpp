#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

void display(const vector<vector<pair<int, int>>> &adj){
    cout << "Adjacency List:\n";
    for(int i = 0; i < adj.size(); i++){
        cout << i << " -> ";

        for(auto edge : adj[i]){
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << '\n';
    }
}

int Prims(const vector<vector<pair<int, int>>> &adj){
    int V = adj.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(V, false);
    int sumCost = 0;

    pq.push({0, 1});            // (weight, vertex)

    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();

        int wt = p.first;
        int u = p.second;

        if(visited[u] == true)
            continue;

        sumCost += wt;
        visited[u] = true;

        for(auto &pai: adj[u]){
            int v = pai.first;
            int weight = pai.second;

            if(visited[v] == false){
                pq.push({weight, v});
            }
        }
    }
    return sumCost;
}

int main() {

    vector<vector<pair<int, int>>> adj(8);
    adj[1] = {{2, 28}, {6, 10}};
    adj[2] = {{1, 28}, {3, 16}, {7, 14}};
    adj[3] = {{2, 16}, {4, 12}};
    adj[4] = {{3, 12}, {5, 22}, {7, 18}};
    adj[5] = {{4, 22}, {6, 25}, {7, 24}};
    adj[6] = {{1, 10}, {5, 25}};
    adj[7] = {{2, 14}, {4, 18}, {5, 24}};

    display(adj);

    int MST_Cost = Prims(adj);
    cout<<"Minimum Cost Spanning Tree Cost : "<<MST_Cost<<endl;

    return 0;
}