#include <bits/stdc++.h>
using namespace std;

string longCommPrefix(vector<string> &v,int n){
    string ans;

    //traversing all char. of I string
    for(int i=0;i<v[0].length();i++){
        char ch = v[0][i];
        bool match = true;

        for(int j=1;j<n;j++){
            if(v[j].size()<i || ch!=v[j][i]){
                match = false;
                break;
            }
        }
        if(match==false){
            break;
        }
        else{
            ans.push_back(ch);
        }
    }
    return ans;
}

int main(){
    vector<string> s = {"code","coding","coder","codingninga"};
    cout<<longCommPrefix(s,4);
    return 0;
}