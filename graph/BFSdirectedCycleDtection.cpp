#include <bits/stdc++.h>
using namespace std;

/* used kahan's algorithm for BFS*/

bool detectCycle(int vertex, vector<pair<int,int>>& edges){
    unordered_map<int, list<int>> adj;
    for(auto p:edges){
        int u = p.first;
        int v = p.second;

        adj[u].push_back(v);
    }

    //for inDegree
    vector<int> inDegree(vertex);
    for(auto a:adj){
        for(auto ele:a.second){
            inDegree[ele]++;
        }
    }

    queue<int> q;
    for(int i=0;i<vertex;i++){
        if(inDegree[i]==0)
            q.push(i);
    }

    int count=0;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        count++;
        //now update inDeg

        for(auto ele:adj[front]){
            inDegree[ele]--;
            if(inDegree[ele]==0)
                q.push(ele);
        }
    }
    
    return count!=vertex;
}

int main(){
    int v = 5;
    vector<pair<int,int>> p = {
        {0,1},{1,2},{3,1},{2,3},{3,4}
    };

    bool a = detectCycle(v,p);

    cout << (a ? "Cycle detected!" : "No cycle detected!") << endl;


    return 0;
}