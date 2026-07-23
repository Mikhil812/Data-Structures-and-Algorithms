#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int source){
    int V = adj.size();

    // Min-Heap to store (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Distance array : 
    vector<int> dist(V, INT_MAX);

    dist[source] = 0;
    pq.push({0, source});

    while(!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();
        int min = top.first;              // shortest distance to reach u uptil now
        int u = top.second;             // the vertex which we will explore

        // If this distance not the latest shortest one, skip it
        if (min > dist[u])
            continue;

        for(auto p : adj[u]){
            int v = p.first;
            int cost = p.second;

            if(dist[u] + cost < dist[v]){
                dist[v] = dist[u] + cost;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {

    // Adjacency List : 
    vector<vector<pair<int, int>>> adj(4);
    adj[0] = {{1, 2}, {2, 10}};
    adj[1] = {{0, 2}, {2, 3}};
    adj[2] = {{0, 10}, {1, 3}, {3, 1}};
    adj[3] = {{2, 1}};

    display(adj);

    vector<int> result = dijkstra(adj, 0);
    for(auto d : result)
        cout<<d<<" ";
    cout<<endl;

    return 0;
}