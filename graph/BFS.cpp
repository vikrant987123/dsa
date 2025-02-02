#include <bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, list<int>> &adjList, vector<pair<int,int>> &edges){
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
}

void bfs(unordered_map<int, list<int>> &adjList, unordered_map<int,bool> &visited, vector<int> &ans, int node){
    queue<int> q;
    q.push(node);
    visited[node]=1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        //store frontNode int ans
        ans.push_back(frontNode);

        //traverse all neighbour into ans
        for(auto ele:adjList[frontNode]){
            if(!visited[ele]){
                q.push(ele);
                visited[ele] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex,vector<pair<int,int>> edges){
    unordered_map<int, list<int>> adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;

    prepareAdjList(adjList,edges);

    //traverse all component of a graph
    for (int i = 0; i < vertex; i++)
    {
        if(!visited[i]){
            bfs( adjList, visited, ans, i);
        }
    }
    return ans;
}

int main(){
    vector<pair<int,int>> edges;
    int vertex;
    cin>>vertex;
    for (int i = 0; i < vertex; i++)
    {
        int u,v;
        cin>>u>>v;

        edges.push_back({u,v});
    }

    vector<int> s = BFS(vertex,edges);

    for(auto i : s){
        cout<<i<<" ";
    }
    
    return 0;
}