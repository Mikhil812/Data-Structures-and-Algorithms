#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet {
private:
    vector<int> parent;

public:
    DisjointSet(int n) {
        parent.assign(n + 1, -1);
    }

    int Find(int u) {
        if (parent[u] < 0)
            return u;
        return parent[u] = Find(parent[u]);   // Path Compression
    }

    void Union(int u, int v) {
        u = Find(u);
        v = Find(v);

        if (u == v)
            return;

        // Union by Size
        if (parent[u] < parent[v]) {
            parent[u] += parent[v];
            parent[v] = u;
        } else {
            parent[v] += parent[u];
            parent[u] = v;
        }
    }
};

struct Edge {
    int u;
    int v;
    int weight;
};

int Kruskal(vector<Edge>& edges, int numVertices) {

    sort(edges.begin(), edges.end(),
         [](const Edge& a, const Edge& b) {
             return a.weight < b.weight;
         });

    DisjointSet ds(numVertices);

    int mstCost = 0;
    int edgesTaken = 0;

    for (const Edge& edge : edges) {

        if (ds.Find(edge.u) != ds.Find(edge.v)) {

            ds.Union(edge.u, edge.v);

            mstCost += edge.weight;
            edgesTaken++;

            cout << edge.u << " - "
                 << edge.v << " : "
                 << edge.weight << '\n';

            if (edgesTaken == numVertices - 1)
                break;
        }
    }

    return mstCost;
}

int main() {

    vector<Edge> edges = {
        {1, 2, 28},
        {1, 6, 10},
        {2, 3, 16},
        {2, 7, 14},
        {3, 4, 12},
        {4, 5, 22},
        {4, 7, 18},
        {5, 6, 25},
        {5, 7, 24}
    };

    int mstCost = Kruskal(edges, 7);

    cout << "\nMinimum Cost = " << mstCost << endl;

    return 0;
}