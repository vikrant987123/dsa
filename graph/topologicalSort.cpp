#include <bits/stdc++.h>
using namespace std;

void topoSort(int node,unordered_map<int,list<int>> &adj, unordered_map<int,bool> &visited, stack<int> &st){

    visited[node] = true;

    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            topoSort(neighbour,adj,visited,st);
        }
    }

    //imp
    st.push(node);

}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e){
    //create a adjlist
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }

    // call dfs topo. sort util function for all components
    unordered_map<int,bool> visited;
    stack<int> st;
    vector<int> ans;

    for(int i=0;i<v;i++){
        if(!visited[i]){
            topoSort(i, adj, visited, st);
        }
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

int main(){
    vector<vector<int>> edges = {{0,2},{1,3},{1,2}};
                                        //n,e
    vector<int> a = topologicalSort(edges,4,3);

    for(auto ele : a){
        cout<<ele<<" ";
    }cout<<endl;

    return 0;
}