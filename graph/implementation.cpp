#include <bits/stdc++.h>
using namespace std;

class graph{
public:
    unordered_map<int, list<int>> adj;

    void addNode(int u, int v, bool direction){ // adding a edge which is from u to v 
        adj[u].push_back(v);
        if(direction==0){//if non directed graph
            adj[v].push_back(u);
        }

    }

    void printAdjList(){
        for(auto i : adj){
            cout<< i.first << "->";
            for(auto j : i.second){
                cout<< j << ",";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of edges"<<endl;
    cin>>m;

    graph g;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //creating an undeirected graph
        g.addNode(u,v,0);
    }

    g.printAdjList();
    return 0;
}