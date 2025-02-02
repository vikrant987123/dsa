#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        int count=0;

        for(auto ch:s){
            if(ch=='1'){
                count++;
            }
        }

        cout<<count<<endl;
    }
    return 0;
}