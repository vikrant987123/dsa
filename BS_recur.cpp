#include <bits/stdc++.h>
using namespace std;

bool bs(int *arr,int s,int e,int key){
    int mid = s+(e-s)/2;

    if(s>e){
        return false;
    }

    if(arr[mid]==key){
        return true;
    }
    else if(arr[mid]>key){
        return bs(arr,s,mid-1,key);
    }

    return bs(arr,mid+1,e,key);
}

int main(){
    int arr[]={1,3,5,6,10};

    int key=6;
    int size= sizeof(arr)/sizeof(int);
    int s=0;
    int e=size-1;

    bool result=bs(arr,s,e,key);

    if(result){
        cout<<"key is found"<<endl;
    }
    else{
        cout<<"key is not found"<<endl;   
    }
    
}