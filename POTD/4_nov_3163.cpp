#include <bits/stdc++.h>
using namespace std;

//need to maintain order
//freq. counts till 9 only
//only adjacent freq. is counted here


void update(map<char,int> mpp, string &ans){
    for(auto p : mpp){
        ans+=(to_string(p.second));
        ans.push_back(p.first);
    }
}

string compString(string word){
    map<char,int> mpp;
    string ans = "";
    for(int i=0;i<word.length();i++){
        mpp[word[i]]++;
        if(mpp[word[i]]==9){
            update(mpp,ans);
            mpp.clear();
        }
    }
    update(mpp,ans);

    return ans;
}

int main(){
    string s = "aaaaaaaaaaaaaabb";

    cout<<compString(s)<<endl;

    return 0;
}





// #include <unordered_map>
// #include <string>
// #include <iostream>
// using namespace std;

// void update(const map<char, int> &mpp, string &ans) {
//     for (auto p : mpp) {
//         ans += to_string(p.second);  // Append frequency as a string
//         ans.push_back(p.first);       // Append character
//     }
// }

// string compString(const string &word) {
//     map<char, int> mpp;
//     string ans = "";

//     for (int i = 0; i < word.length(); i++) {
//         mpp[word[i]]++;
//         if (mpp[word[i]] == 9) {  // Update and clear map when frequency hits 9
//             update(mpp, ans);
//             mpp.clear();
//         }
//     }
//     update(mpp, ans);  // Update remaining characters

//     return ans;
// }

// int main() {
//     string s = "aaaaaaaaaaaaaaabb";
//     cout << compString(s) << endl;

//     return 0;
// }
