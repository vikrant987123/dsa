#include <bits/stdc++.h>
using namespace std;

class graph{
    public:

    // making adj list containg from : (to1,wt1),(to2,wt2)...
    unordered_map<int, list<pair<int,int>>> adj;
    void addEdge(int u, int v, int wt){
        pair<int,int> p = make_pair(v,wt);
        adj[u].push_back(p);
    }

    //to print the adj list
    void print(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<"), ";
            }cout<<endl;
        }
    }

    // it is done in order to make a topo order of nodes
    void dfs(int node, unordered_map<int,bool> &visited, stack<int> &topo){
        visited[node] = true;

        for(auto nbr:adj[node]){
            if(!visited[nbr.first]){
                dfs(nbr.first,visited,topo);
            }
        }
        topo.push(node);
    }

    // now for every node calc mini distance from src node
    void getshortestPath(int src, vector<int> &dist, stack<int> &topo){
        dist[src] = 0;
        while(!topo.empty()){
            int top = topo.top();
            topo.pop();

            if(dist[top]!=INT_MAX){
                for(auto i:adj[top]){
                    if(dist[top]+i.second < dist[i.first]){
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }
    }
};

int main(){
    graph g;

    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    int n =6;

    //topo sort
    unordered_map<int,bool> visited;
    stack<int> s;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.dfs(i,visited,s);
        }
    }

    int src = 1;
    vector<int> dist(n);
    for(int i=0;i<n;i++){
        dist[i] = INT_MAX;
    }

    g.getshortestPath(src,dist,s);

    cout<<"answer : "<<endl;

    for(int i=0;i<dist.size(); i++){
        cout<<dist[i]<<" ";
    }cout<<endl;

    return 0;
}