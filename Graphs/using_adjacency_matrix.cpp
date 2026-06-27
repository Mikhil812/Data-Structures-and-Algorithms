#include <iostream>
#include "Queue.h"
using namespace std;

void BFS(int A[][8], int starting_vertex, int n){
    Queue q;
    int visited[8] = {0};

    visited[starting_vertex] = 1;
    q.enqueue(starting_vertex);

    while(!q.isEmpty()){
        int i = q.dequeue();
        cout<<i<<" ";                               // process here
        for(int j=1; j<n; j++){
            if(A[i][j] == 1 && visited[j] == 0){
                visited[j] = 1;
                q.enqueue(j);
            }
        }
    }
    cout<<endl;
}

void DFS(int A[][8], int vertex, int n){
    static int visited[8] = {0};

    if(visited[vertex] == 0){
        cout<<vertex<<" ";
        visited[vertex] = 1;

        for(int j=1; j<n; j++){
            if(A[vertex][j] == 1 && visited[j] == 0){
                DFS(A, j, n);
            }
        }
    }
}

int main() {

    // Adjacency Matrix : 
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};

    // Breadth First Search : 
    BFS(A, 4, 8);

    // Depth First Search : 
    DFS(A, 4, 8);

    return 0;
}