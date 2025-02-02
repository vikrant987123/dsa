#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        // Create adjacency list
        unordered_map<int, list<int>> adj;
        for (auto& p : prerequisites) {
            int course = p.first;
            int prerequisite = p.second;
            adj[prerequisite].push_back(course);
        }

        // Calculate in-degrees
        vector<int> inDegree(numCourses, 0);
        for (auto& p : adj) {
            for (auto& course : p.second) {
                inDegree[course]++;
            }
        }

        // Initialize queue with courses having zero in-degree
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform BFS
        vector<int> order;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            order.push_back(current);

            for (auto& neighbor : adj[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Check if all courses can be completed
        if (order.size() != numCourses) {
            return {}; // Cycle detected
        }

        return order;
    }
};

int main() {
    int numCourses = 5;
    vector<pair<int, int>> prerequisites = {
        {0, 1}, {1, 2}, {3, 1}, {2, 3}, {3, 4}
    };

    Solution solution;
    vector<int> order = solution.findOrder(numCourses, prerequisites);

    if (order.empty()) {
        cout << "No valid order exists (cycle detected)." << endl;
    } else {
        for (auto course : order) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}
