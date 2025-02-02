#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    // Function to calculate Prim's MST
    vector<pair<pair<int, int>, int>> calcPrimsMST(int n, vector<pair<pair<int, int>, int>> edge) {
        // Create adjacency list
        unordered_map<int, list<pair<int, int>>> adj;
        for (auto &e : edge) {
            int u = e.first.first;
            int v = e.first.second;
            int w = e.second;

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<int> key(n, INT_MAX);  // To store minimum weights
        vector<bool> mst(n, false);  // To mark visited nodes
        vector<int> parent(n, -1);   // To store parent nodes

        // Start with the first node (node 0)
        key[0] = 0;

        for (int i = 0; i < n; i++) {
            // Find the minimum key value among unvisited nodes
            int mini = INT_MAX; //to find minimum value
            int u = -1; //that node of this min. value
            for (int v = 0; v < n; v++) {
                if (!mst[v] && key[v] < mini) { //if the node is not traversed and it is mini.
                    u = v;
                    mini = key[v];
                }
            }

            if (u == -1) break; // No more nodes to process
            mst[u] = true;

            // Update adjacent nodes
            for (auto &it : adj[u]) {
                int v = it.first;
                int w = it.second;

                if (!mst[v] && w < key[v]) { //if its nbr is not traversed and the wt it is giving is less then oly update the nbr wt
                    parent[v] = u;
                    key[v] = w;
                }
            }
        }

        // Prepare the result
        vector<pair<pair<int, int>, int>> result;
        for (int i = 1; i < n; i++) { // Skip the root node (node 0)
            if (parent[i] != -1) {
                result.push_back({{parent[i], i}, key[i]});
            }
        }

        return result;
    }
};

int main() {
    // Input edges (0-based indexing)
    vector<pair<pair<int, int>, int>> edg = {
        {{0, 1}, 2}, {{0, 3}, 6}, {{3, 1}, 8}, {{1, 4}, 5}, {{1, 2}, 3}, {{2, 4}, 7}
    };

    Graph g;
    vector<pair<pair<int, int>, int>> mst = g.calcPrimsMST(5, edg);

    // Output the MST
    cout << "Edges in the MST:\n";
    for (auto &e : mst) {
        cout << e.first.first << " - " << e.first.second << " with weight " << e.second << endl;
    }

    return 0;
}
