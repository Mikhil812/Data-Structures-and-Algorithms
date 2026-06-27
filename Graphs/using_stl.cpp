#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(vector<vector<int>> &A, int starting_vertex){
    int n = A.size();
    vector<bool> visited(n, false);
    queue<int> q;
    vector<int> res;

    visited[starting_vertex] = true;
    q.push(starting_vertex);

    while(!q.empty()){
        int vertex = q.front();
        q.pop();
        res.push_back(vertex);

        for(int x : A[vertex]){
            if(visited[x] == false){
                visited[x] = true;
                q.push(x);
            }
        }
        
    }
    return res;
}

void dfsRecursive(vector<vector<int>> &A, int vertex, vector<int> &res){
    int n = A.size();
    static vector<bool> visited(n,false);

    visited[vertex] = true;
    res.push_back(vertex);

    for(int x : A[vertex]){
        if(visited[x] == false)
            dfsRecursive(A, x, res);
    }
}

vector<int> dfs(vector<vector<int>> &A, int vertex) {
    vector<int> res;
    dfsRecursive(A, vertex, res);

    return res;
}

void addEdge(vector<vector<int>> &A, int u, int v){
    A[u].push_back(v);
    A[v].push_back(u);
}

void display(vector<vector<int>> &A){
    for(int i = 0; i < A.size(); i++){
        cout << i << " -> ";

        for(int val : A[i]){
            cout << val << ", ";
        }

        cout << endl;
    }
}

int main() {

    int n = 7;
    vector<vector<int>> A(n);

    // Creating Adjacency List : 
    addEdge(A, 0, 1);
    addEdge(A, 0, 2);
    addEdge(A, 0, 3);
    addEdge(A, 1, 2);
    addEdge(A, 2, 3);
    addEdge(A, 2, 4);
    addEdge(A, 3, 4);
    addEdge(A, 4, 5);
    addEdge(A, 4, 6);

    cout<<"Graph : "<<endl;
    display(A);

    cout<<"BFS : "<<endl;
    vector<int> res = bfs(A, 3);
    for(int val : res){
        cout<<val<<" ";
    }
    cout<<endl;

    cout<<"DFS : "<<endl;
    vector<int> res2 = dfs(A, 3);
    for(int val : res2){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}