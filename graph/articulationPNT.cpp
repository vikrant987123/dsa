#include <bits/stdc++.h>
using namespace std;

int min(int a,int b){
    if(a<b)
        return a;
    return b;
}

void dfs(int node,int parent,vector<int> &disc, vector<int> &low, unordered_map<int,bool> &vis, unordered_map<int, list<int>> &adj, vector<int> &ap,int &timer){
    vis[node] = true;
    disc[node] = low[node] = timer++;

    int child=0;

    for(auto nbrs: adj[node]){
        if(nbrs==parent)
            continue;
        
        if(!vis[nbrs]){
            dfs(nbrs,node,disc,low,vis,adj,ap,timer);

            low[node] = min( low[node],low[nbrs] );

            //check for articulation pt
            if(low[nbrs] >= disc[node] && parent !=-1 ){
                ap[node]=true;
            }
            child++;
        }
        else{
            low[node] = min( low[node],disc[nbrs] );
        }
    }
    if(parent == -1 && child>1) ap[node] = true;
}


int main(){
    int n=5;
    int e=5;
    vector<pair<int,int>> edgs;
    edgs.push_back({0,3});
    edgs.push_back({0,4});
    edgs.push_back({0,1});
    edgs.push_back({3,4});
    edgs.push_back({1,2});

    unordered_map<int, list<int>> adj;

    for(int i=0;i<edgs.size();i++){
        int u=edgs[i].first;
        int v=edgs[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(n,-1);
    vector<int> low(n,-1);
    unordered_map<int,bool> vis;
    vector<int> ap(n,0); 

    //dfs
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,-1,disc,low,vis,adj,ap,timer);
        }
    }

    //print ap
    cout<<"articulation pts. are: "<<endl;

    for(int i=0;i<n;i++){
        if(ap[i]!=0){
            cout<<i<<" ";
        }
    }cout<<endl;
    
    return 0;
}