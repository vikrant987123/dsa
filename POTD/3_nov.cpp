#include <bits/stdc++.h>
using namespace std;

//IF THE SAME CHAR COMES THEN IT WILL CREATE POBLEM
/* TO SOLVE THOS ADD THE SAME STRING IN THE "S" AND FIND THE GOAL IS SUBSTRING OD S OR NOT*/

bool rotateString(string s, string goal){
    queue<char> q;

    for(int i=0;i<s.length();i++){
        q.push(s[i]);
    }

    while(q.front()!=goal[0]){
        char ch = q.front();
        q.pop();

        q.push(ch);
    }

    string ans = "";

    while(!q.empty()){
        char ch = q.front();
        q.pop();

        ans.push_back(ch);
    }

    return ans==goal;
}

int main(){
    string s = "abcde";
    string g = "abced";

    cout<<rotateString(s,g)<<endl;

    return 0;
}