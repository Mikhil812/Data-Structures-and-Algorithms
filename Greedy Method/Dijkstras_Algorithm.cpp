#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

void display(int A[][5], int n)
{
    cout << "    ";
    for(int j = 1; j < n; j++)
        cout << setw(15) << j;
    cout << '\n';
    for(int i = 1; i < n; i++){
        cout << setw(2) << i << " |";
        for(int j = 1; j < n; j++){
            if(A[i][j] == 0)
                cout << setw(15) << '.';
            else
                cout << setw(15) << A[i][j];
        }
        cout << '\n';
    }
}

int * Dijkstra(int cost[][5], int n, int source){
    int *dist = new int[n+1];
    bool *selected = new bool[n+1];

    for(int i=0; i<n+1; i++){
        dist[i] = cost[source][i];
        selected[i] = false;
    }

    dist[source] = 0;
    selected[source] = true;

    for(int k=1; k<n; k++){     
        int u=-1;
        int min = INT_MAX;             
        for(int i=1; i<=n; i++){
            if(selected[i] == false && dist[i] < min){
                min = dist[i];
                u = i;                  // u is the vertex
            }
        }
        if(u == -1)
            break;

        selected[u] = true;
        // Relaxation : 
        for(int v=1; v<=n; v++){        // v represents connected vertices
            if(selected[v] == false && cost[u][v] != INT_MAX &&
            dist[u] != INT_MAX && (dist[u] + cost[u][v] < dist[v])){
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    return dist;
}

int main() {

    int cost[5][5] = {{0, 0, 0, 0, 0},
                      {0, 0, 2, 10, INT_MAX},
                      {0, 2, 0, 3, INT_MAX},
                      {0, 10,3, 0, 1},
                      {0, INT_MAX, INT_MAX, 1, 0}
                     };

    display(cost, 5);

    cout<<"Dijkstras Algorithm : Single Source Shortest Path"<<endl;
    int *distance_array = Dijkstra(cost, 4, 1);
    for(int i=1; i<=4; i++){
        cout<<distance_array[i]<<" ";
    }
    cout<<endl;

    return 0;
}