#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

vector<int> sol(int n, vector<vector<pair<int, int>>>& graph, int start) {
    //dijkstra's algo
    vector<int> dist(n,INT_MAX);
    dist[start] = 0;

    set<pair<int,int>> s;
    //dist frm src, destination
    s.insert({0,start}); //as from start to start dist is 0

    while(!s.empty()){
        pair<int,int> temp = *s.begin();
        s.erase( s.begin() );

        int d = temp.first;
        int node = temp.second;

        //going to node's nbrs
        for(auto nbr:graph[node]){
            int n = nbr.first;
            int wt = nbr.second;

            if( d+wt < dist[n] ){
                s.erase({dist[n],n});
                dist[n] = d+wt;
                s.insert({dist[n],n});
            }
        }  
    }

    for(int i=0;i<n;i++){
        if(dist[i]==INT_MAX){
            dist[i]=-1;
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    int start;
    cin >> start;
// please don't modify the main function
    vector<int> result = sol(n, graph, start);

    for(int i = 0; i < n; i++) {
        if(i == n - 1) {
            cout << result[i];
        } else {
            cout << result[i] << " ";
        }
    }
    
    return 0;
}