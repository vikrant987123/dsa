#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        for(string s : words){
            bool cond = 1;
            for(char c : s){
                for(char k : allowed){
                    cout<<"char of words "<<c<<" & char of allowed "<<k<<endl;
                }
            }
        }
        
    }
};

int main(){
    vector<string> words = ["ad","aaab","baa","badab"];
    countConsistentStrings("ab", words);
    return 0;
}