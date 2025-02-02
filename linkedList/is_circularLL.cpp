#include <bits/stdc++.h>
using namespace std;

// this class use to form a node
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

 void insertAtPos( node* &head, int val, int pos){
    //if pos == 1, then add at HEAD
    if(pos==1){
        insertAtHead( head,val );
        return;
    }


    //counting variable
    int curr_pos=1;

    //creating node to add
    node* temp = new node(val);

    // traverse through LL
    node* trav = new node(0);
    trav=head;



    //1. curr_pos go till pos-1
    //2. put temp ka nxt as pos-1 ka nxt
    //3. put pos-1 ka nxt as temp

    while(curr_pos != pos-1){
        curr_pos ++ ;
        trav = trav -> next;
    }
    //reached pos-1
    temp -> next = trav -> next;
    trav -> next = temp;

 }

 void display( node* &head ){

    node* temp = new node(0);

    temp = head;


    while(temp != NULL){
        cout<< temp->data << " ";
        temp = temp -> next;
    }
    cout<<endl;
 }

 bool isCircular( node* head ){
    //for head = null
    if(head==NULL){
        return true;
    }

    //for single node
    // if(head->next == NULL){
    //     return false;
    // }
    // if(head->next == head){
    //     return true;
    // }

    //for more than 1 node
    node* temp = head->next;
    while( temp->next != NULL /*for straight LL*/  &&  temp != head /*for circular*/){
        temp = temp->next;
    }
    if(temp == head){
        return true;
    }
    return false;
 }


int main(){
    node* head = new node(5);

    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,0);


    
    cout<<"linked list :-"<<endl;
    display(head);

    

    return 0;
}