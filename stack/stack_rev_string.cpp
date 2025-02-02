#include <bits/stdc++.h>
#include<stack>
using namespace std;

int main(){
    stack<char> st;

    string name="vikrant";
    string rev="";

    for(int i=0;i<name.length();i++){
        st.push(name[i]);
    }
    while(!st.empty()){
        rev = rev+st.top();
        st.pop();
    }

    cout<<rev<<endl;
    return 0;
}