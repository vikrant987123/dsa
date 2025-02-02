#include<bits/stdc++.h>
using namespace std;

//sum of n terms

//approach
/*we take n and tot as variable 
where n= no fo terms
      tot=0
now decrement n at each recur.
and add a that to tot    ---till n>1*/
void add(int n,int s){

    //base
    if(n<1){
        cout<<s<<endl;
        return;

    }

    int s=0;
    s+=n;

    add(n-1,s+i);
}


int main(){
     int s=0,n=0;
     cin>>n;
     

     add(n,s);

     return 0;
}
