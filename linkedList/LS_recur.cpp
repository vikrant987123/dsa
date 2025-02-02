#include <bits/stdc++.h>
using namespace std;

bool ls(int *arr,int key,int size){
    if(size==0){
        return false;
    }
    if(arr[0]==key){
        return true;
    }
    return ls(arr+1,key,size-1);
}

int main(){
    int arr[]={1,3,5,6,2,10};

    int key=10;
    int size= sizeof(arr)/sizeof(int);

    bool s=ls(arr,key,size);

    if(s){
        cout<<"key is found"<<endl;
    }
    else{
        cout<<"key is not found"<<endl;   
    }
    
}