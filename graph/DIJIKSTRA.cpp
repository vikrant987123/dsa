#include <bits/stdc++.h>
using namespace std;

class graph{
    public:

    void dijikstra(int v, vector<vector<int>> e,int src){
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i=0;i<v;i++){
            int a = e[i][0];
            int b = e[i][1];
            int wt = e[i][2];

            adj[a].push_back({b,wt});
            adj[b].push_back({a,wt});
        }

        vector<int> dist(v,INT_MAX);
        dist[src] = 0;

        set<pair<int,int>> s;
        s.insert({0,src});

        while(!s.empty()){
            auto f = *s.begin();
            s.erase(s.begin());

            int d = f.first;
            int node = f.second;

            //find nbrs of f node
            for(auto nbrs: adj[node]){
                int nbr = nbrs.first;
                int wt = nbrs.second;
                if(d+wt < dist[nbr]){
                    s.erase({dist[nbr],nbr}); /* IMP step in order to remove the pre existing node in the set with max dist.*/
                    dist[nbr] = d + wt;
                    s.insert({dist[nbr],nbr});
                }
            }

        }

        //print the shortest distance
        for(int i=0;i<v;i++){
            cout<<"from "<<src<<" to "<<i<<" is : ";
            if(dist[i]==INT_MAX){
                cout<<"very much"<<endl;
            }
            else{
                cout<<dist[i]<<endl;
            }
        }
    }
    
};

int main(){
    vector<vector<int>> edges = {
        {0,1,5},{0,2,8},{1,2,9},{1,3,2},{3,2,6}
        };

    graph g;

    g.dijikstra(4,edges,0);



    return 0;
}