#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int,int>> edges, int src, int dest){
    unordered_map<int, list<int>> adj;
    for(auto e:edges){
        int u = e.first;
        int v = e.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //do bfs
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    queue<int> q;
    q.push(src);
    visited[src]=true;

    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        for(auto ele:adj[front]){
            if(!visited[ele]){
                visited[ele] = true;
                parent[ele] = front;
                q.push(ele);
            }
        }
    }

    vector<int> ans;
    int currentNode = dest;
    ans.push_back(currentNode);

    while(currentNode != src){
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    return ans;

}

int main(){
    vector<pair<int,int>> edg = {
        {1,2},{2,5},{5,8},{1,3},{3,8},{1,4},{4,6},{6,7},{7,8}
    };

    vector<int> a = shortestPath(edg, 1, 8);

    for(auto i:a){
        cout<<i<<" ";
    }

    return 0;
}