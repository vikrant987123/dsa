#include <bits/stdc++.h>
using namespace std;

bool isSafe(int newX,int newY, vector<vector<bool>> &visited, vector<vector<int>> &arr, int n){
    if( (newX>=0 && newX<n) &&
    (newY>=0 && newY<n) &&
    (visited[newX][newY]!=1) &&
    (arr[newX][newY]==1)){
        return true;
    }
    return false;
}

void solve(int x,int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &visited, string path){
    //base case 
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }

    //4 movement :- D,L,R,U

    //FOR DOWN

    if( isSafe(x+1,y,visited,arr,n) ){
        visited[x][y] = 1;
        solve(x+1,y,arr,n,ans,visited,path+'D');
        visited[x][y] = 0;
    }

    //left
    if( isSafe(x,y-1,visited,arr,n) ){
        visited[x][y] = 1;
        solve(x,y-1,arr,n,ans,visited,path+'L');
        visited[x][y] = 0;
    }

    //right
    if( isSafe(x,y+1,visited,arr,n) ){
        visited[x][y] = 1;
        solve(x,y+1,arr,n,ans,visited,path+'R');
        visited[x][y] = 0;
    }

    //up
    if( isSafe(x-1,y,visited,arr,n) ){
        visited[x][y] = 1;
        solve(x-1,y,arr,n,ans,visited,path+'U');
        visited[x][y] = 0;
    }
}

vector<string> searchMaze(vector<vector<int>> &arr){
    int n = arr.size();
    vector<string> ans;
    vector<vector<bool>> visited(n,vector<bool> (n,0));

    string path ="";

    solve(0,0,arr,n,ans,visited,path);

    return ans;
}

int main(){

    int n = 3;
    vector<vector<int>> arr = {{1,0,0,0},
                               {1,1,0,0},
                               {1,1,0,0},
                               {0,1,1,1}};

    vector<string> a = searchMaze(arr);

    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    //cout<<endl;



    return 0;
}