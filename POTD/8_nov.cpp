#include <bits/stdc++.h>
using namespace std;

vector<int> getMaximumXor(vector<int> &nums, int maximumBit){
    //for k array
    int last = pow(2,maximumBit);
    vector<int> k_arr;
    for(int i=0;i<last;i++){
        k_arr.push_back(i);
    }

    vector<int> ans;

    while(nums.size()){
        // do xor of all elements of nums
        int x = 0;
        for(int i=0;i<nums.size();i++){
            x = x^nums[i];
        }

        // do xor with every ele of k_arr and find max_o/p
        int maxi = INT_MIN;
        int ele = 0;
        for(int i=0;i<k_arr.size();i++){
            if(x^k_arr[i]>maxi){
                maxi = x^k_arr[i];
                ele = k_arr[i];
            }
        }

        //store the k_arr ele from which max_o/p is generated in ans
        ans.push_back(ele);

        //delete the last ele of nums
        nums.pop_back();
    }
    return ans;

}

int main(){
    vector<int> nums = {0,1,1,3};
    int mB = 2;

    vector<int> soln = getMaximumXor(nums,mB);

    for(auto ele : soln){
        cout<<ele<<" ";
    }
    
    return 0;
}