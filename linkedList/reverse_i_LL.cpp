#include <bits/stdc++.h>
using namespace std;


class node{

    public:
    int data;
    node* next;

    node( int d ){
        this->data = d;
        this->next = NULL;
    }
};

void display( node* &head ){

    node* trav = head;

    while(trav != NULL){
        cout<< trav->data <<" ";
        trav = trav->next;
    }
    cout<<endl;
}

//making a function to add node at the head
void insertAtHead( node* &head, int val ) 
 /*giving the reference value to change at same memory*/
 {
    //form a node with data = val
    node* temp = new node(val);

    /*
    1. now use head as temp ka nxt
    2. and assign temp as head
    */
    temp -> next = head;
    head = temp;
 }

node* reverseLL(node* head) {
    node* prev = NULL;
    node* curr = head;
    node* nxt;

    while (curr != NULL) {
        nxt = curr->next; // Move nxt to the next node
        curr->next = prev; // Reverse the link
        prev = curr; // Move prev to current
        curr = nxt; // Move curr to next node
    }

    return prev;
}

int main(){

    node* n = new node(5);

    insertAtHead(n,4);
    insertAtHead(n,3);
    insertAtHead(n,2);
    insertAtHead(n,1);

    cout<<"initial LL"<<endl;
    display(n);

    cout<<endl;

    node* h = reverseLL(n);
    cout<<"reversed LL"<<endl;
    display(h);




    //reversing

    return 0;
    
}