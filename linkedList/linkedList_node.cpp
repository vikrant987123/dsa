#include <bits/stdc++.h>
using namespace std;

class node{

    public:
    int data;
    node* next;

    // redefining constructor
    node(int d){
        this->data = d;
        this->next = NULL;
    }

};

int main(){

    node* new_node = new node(5);

    cout<<"node data : "<< new_node->data << endl;
    cout<<"node next : "<< new_node->next << endl;


    return 0;
    
}