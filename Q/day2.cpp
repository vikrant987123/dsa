#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

// you just need to implement this function
string mostCommonWord(string document) {
    // your code here
    string word;
    unordered_map<string,int> freq;
    cout<<"here"<<endl;
    for(int i=0;i<document.length();i++){
        cout<<"h2"<<endl;
        if(document[i]==' '){
            word="";
            continue;
        }
        cout<<"h3"<<endl;
        word += document[i];
        cout<<"word is: "<<word<<endl;
        freq[word]++;
    
    }

    string ans;
    int maxi=-1;
    for(auto f:freq){
        if(f.second>=maxi){
            maxi = f.second;
            ans = f.first;
        }
    }

    cout<<ans<<endl;
    return ans;
}

int main() {
    string document;
    cin >> document;

    // please do not change the below code
    cout << mostCommonWord(document);
    return 0;
}