#include <bits/stdc++.h>
#include<queue>
using namespace std;

int main(){
    queue<int> q;

    q.push(11);

    q.push(15);

    q.push(17);

    cout<<"size 1: "<<q.size()<<endl;
    cout<<"front "<<q.front()<<endl;
    //cout<<"rear "<<q.r()<<endl;

    q.pop();

    cout<<"size 2: "<<q.size()<<endl;
}