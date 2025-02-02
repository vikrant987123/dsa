#include <bits/stdc++.h>
using namespace std;

string rev(string str,int i,int j){
    //base case
    if(i>j){
        return str;
    }

    swap(str[i],str[j]);
    i++;
    j--;

    return rev(str,i,j);


}

int main(){
    string str="babbar";
    int i=0;
    int j=str.length();

    string result=rev(str,i,j-1);

    cout<<result<<endl;
    
}