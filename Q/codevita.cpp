#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<string> words(n);
    for(int i=0;i<n;i++){
        cin>>words[i];
    }

    vector<int> cost(n);
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }

    vector<pair<string,string>> contr(m);
    for(int i=0;i<m;i++){
        string a,b;
        cin>>a>>b;
        contr.push_back({a,b});
    }

    int budget;
    cin>>budget;

    vector<vector<int>> possible;
    for(int i=0;i<n;i++){
        string w1 = words[i];
        int c1 = cost[i];
        string restrict = 
        vector<string> part;
        part.push_back(w1);
        
        for(int j=i;j<n;j++){
            if(cost[j]<=budget-c1 && ){

            }
        }

    }
    return 0;
}