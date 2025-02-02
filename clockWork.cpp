#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }

        bool flag = false;

        for(int i=0;i<n;i++){
            int ele = vec[i];
            int left = i*2;
            int right = (n-i-1)*2;

            if(left>= ele || right>=ele){
                flag = true;
                break;
            }
        }

        if(flag){
            cout<<"no"<<endl;
        }
        else{
            cout<<"yes"<<endl;
        }

    }
    return 0;
}