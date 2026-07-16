#include <iostream>
#include <climits>
using namespace std;

class Disjoint_Subset{
    private:
        int* parent_A;
    public:
        Disjoint_Subset(int n){
            parent_A = new int[n+1];
            for(int i=0; i<n+1; i++) 
                parent_A[i] = -1;
        }

        ~Disjoint_Subset(){
            delete []parent_A;
        }

        int Find(int u){
            int x = u;
            while(parent_A[x] > 0)
                x = parent_A[x];
            return x;
        }

        void Union(int u, int v){
            if(parent_A[u] < parent_A[v]){
                parent_A[u] = parent_A[u] + parent_A[v];
                parent_A[v] = u;
            }else{
                parent_A[v] = parent_A[v] + parent_A[u];
                parent_A[u] = v;
            }
        }

        void Display(int n){
            for(int i=0; i<n; i++){
                cout<<parent_A[i]<<" ";
            }
            cout<<endl;
        }
};

int Kruskal(int edges[][3], int numVertices, int numEdges){
    bool *selected = new bool[numEdges];
    for(int i=0; i<numEdges; i++)
        selected[i] = false;
    
    int minCost = 0;
    int edgeCount = 0;

    Disjoint_Subset ds(numVertices);
    int min, index;
    while(edgeCount < numVertices - 1){
        min = INT_MAX;
        // Find Minimum :
        for(int i=0; i<numEdges; i++){
            if(selected[i] == false && edges[i][2] < min){
                min = edges[i][2];
                index = i;
            }
        }
        // Check for cycle:
        int u = edges[index][0], v = edges[index][1];
        if(ds.Find(u) != ds.Find(v)){
            minCost += edges[index][2];
            selected[index] = true;
            edgeCount++;
            ds.Union(ds.Find(u), ds.Find(v));   // Important
        }else{
            selected[index] = true;
        }
    }
    return minCost;
}

int main() {
    // Edge List : 
    int edges[][3] ={{1, 2, 28}
                    ,{1, 6, 10}
                    ,{2, 3, 16}
                    ,{2, 7, 14}
                    ,{3, 4, 12}
                    ,{4, 5, 22}
                    ,{4, 7, 18}
                    ,{5, 6, 25}
                    ,{5, 7, 24}};

    int MST_Cost = Kruskal(edges, 7, 9);
    cout<<"Minimum Cost Spanning Tree Cost : "<<MST_Cost<<endl;
    
    return 0;
}