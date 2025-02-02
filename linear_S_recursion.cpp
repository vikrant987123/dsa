#include <bits/stdc++.h>
using namespace std;

//APProach- compare first term equal to target if not neglect first term and then from next do same with size--

bool isPresent(int arr[],int n, int target){

    if(n==0) return 0;

    if(arr[0]==target) return 1;
    else{
        return isPresent(arr+1,n-1,target);
    }
}

int main(){
    int arr[]= {2,4,5,3,9,6};
    int n=sizeof(arr)/sizeof(arr[0]);

    int target=10;

    int ans =  isPresent(arr,n,target);
    cout<<ans<<endl;

    return 0;
    
}