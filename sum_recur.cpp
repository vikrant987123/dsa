#include <bits/stdc++.h>
using namespace std;

int add(vector<int> nums,int n,int s,int i){

    //base case
    if(i==n) return s;
    else{
        return add(nums,n,s+nums[i],i+1);
    }
}

int main(){
    vector<int> nums={3,2,5,1,16};
    int n=nums.size();

    int i=0;
    int s=0;
    int a=add(nums,n,s,i);
    cout<<a<<endl;

    return 0;

}