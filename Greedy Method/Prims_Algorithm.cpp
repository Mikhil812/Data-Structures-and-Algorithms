#include <iostream>
#include <climits>
#include <iomanip>
using namespace std;

void display(int A[][8], int n)
{
    cout << "    ";
    for(int j = 1; j < n; j++)
        cout << setw(4) << j;
    cout << '\n';
    for(int i = 1; i < n; i++){
        cout << setw(2) << i << " |";
        for(int j = 1; j < n; j++){
            if(A[i][j] == 0)
                cout << setw(4) << '.';
            else
                cout << setw(4) << A[i][j];
        }
        cout << '\n';
    }
}

int Prims(int A[][8], int n){
    int *parent = new int[n+1];
    int *key = new int[n+1];
    bool *included = new bool[n+1];

    for(int i=0; i<n+1; i++){
        key[i] = INT_MAX;
        included[i] = false;
    }
    parent[1] = -1;
    key[1] = 0;

    for(int count=0; count<n; count++){
        // Find minimum key 
        int min = INT_MAX;
        int u = -1;
        for(int i=1; i<=n; i++){
            if(included[i] == false && key[i] < min){
                min = key[i];
                u = i;
            }
        }
        if(u == -1)
            break;
        included[u] = true;
        // Update neighbours :
        for(int v=1; v<=n; v++){
            if(included[v] == false && A[u][v] && A[u][v] < key[v]){
                key[v] = A[u][v];
                parent[v] = u;
            }
        }
    }

    // Calculate Cost : 
    int cost = 0;
    for(int i=2; i<=n; i++){
        cost = cost + A[parent[i]][i];
    }
    return cost;
}

int main() {

    int A[8][8] = {{0, 0, 0 , 0, 0, 0 , 0, 0},
                   {0, 0, 28, 0, 0, 0 ,10, 0},
                   {0, 28, 0, 16,0, 0, 0, 14},
                   {0, 0, 16, 0, 12,0, 0, 0 },
                   {0, 0, 0, 12, 0, 22,0, 18},
                   {0, 0, 0, 0, 22, 0, 25,24},
                   {0, 10, 0, 0, 0, 25,0, 0 },
                   {0, 0, 14, 0, 18,24, 0, 0}};

    display(A, 8);

    int MST_Cost = Prims(A, 7);
    cout<<"Minimum Cost Spanning Tree Cost : "<<MST_Cost<<endl;

    return 0;
}