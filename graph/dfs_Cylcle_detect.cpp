#include <bits/stdc++.h>
using namespace std;

bool isCyclicDFS(int node,int parent, unordered_map<int,bool> &visited, unordered_map<int, list<int>> &adj){
    visited[node] = true;

    for(auto neighbour : adj[node]){
        if( !visited[neighbour] ){
            bool cycleDetect = isCyclicDFS( neighbour, node, visited, adj);
            if(cycleDetect){
                return true;
            }
        }
        else if(neighbour != parent){
            //cycle present
            return true;
        }
    }
    return false;
}

string cycleDetect(vector<vector<int>> &edges, int n, int m){
    //create adj. list
    unordered_map<int, list<int>> adj;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //to handel disconnected components
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans = isCyclicDFS(i, -1,visited,adj);
            if(ans==1)
                return "Yes";
        }
    }
    return "No";
}

int main(){
    vector<vector<int>> edges = {{1,2},{2,3},{1,3}};
    int n = 3;
    int m = 3;

    string s = cycleDetect(edges,n,m);
    cout<<"ans : "<<s<<endl;

    return 0;
}