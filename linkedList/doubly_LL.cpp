#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node* next;

    //redefining Constructor
    node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~node(){
        int val = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }

        cout<<"memory freed with data : "<<val<<endl;
    }
};

void display(node* head){
    node* trev = new node(0);
    trev = head;

    while( trev != NULL ){
        cout<< trev -> data <<endl;
        trev = trev -> next;
    }

}

int main(){
    
    return 0;
}