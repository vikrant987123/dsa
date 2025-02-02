#include <bits/stdc++.h>
using namespace std;

//to find the parent of a node
int find(int i, vector<int> &parent){
    if(parent[i]==i){//if someone is parent of itself then fine return it
        return i;
    }
    return parent[i] = find(parent[i],parent); /*if not then find the ultimate parent and 
    by using the concept of PATH COMPRESSION update evry node parnet to the ultimate parent (which is coming in the path)*/
}

void unon(int x,int y,vector<int> &parent,vector<int> rank){
    int x_parent = parent[x];
    int y_parent = parent[y];

    if(x_parent == y_parent) return; // both belong to the same component

    //else combine them in the same component according to the RANK of parent
    if(rank[x_parent] > rank[y_parent]){
        parent[y_parent] = x_parent;
    }else if(rank[x_parent] < rank[y_parent]){
        parent[x_parent] = y_parent;
    }else{
        parent[x_parent] = y_parent;
        rank[y_parent]++;
    }
}

int main(){
    return 0;
}