#include <bits/stdc++.h>
using namespace std;

void print(int n){
    cout<<n<<" ";

    n--;
    if(n==0) return;

    print(n);
}

int main(){
    int n;
    cin>>n;

    print(n);
}