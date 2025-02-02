//  0 1 1 2 3 5 8 13 21...
#include <bits/stdc++.h>
using namespace std;

int fibb(int n){

    //base condition
    if( n==0) return 0;
    if(n==1 ) return 1;

    //if(n<0) return;
    int ans=fibb(n-1)+fibb(n-2);
    //cout<<ans<<endl;

    return ans;
}

int main(){
    //takes no,\. of integer to print

    int n;
    cin>>n;

    int f=fibb(n);

    cout<<f<<endl;

    return 0;
}