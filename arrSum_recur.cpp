#include <bits/stdc++.h>
using namespace std;

int tot(int *arr,int sum,int size){
    if(size==0){
        return sum;
    }
    else{
        sum=sum+arr[0];
        tot(arr+1,sum,size-1);
    }
}

int main(){
    int arr[]={1,3,5,6,2,10};

    int sum=0;
    int size= sizeof(arr)/sizeof(int);

    int s=tot(arr,sum,size);

    cout<<"sum is : "<<s<<endl;
    
}