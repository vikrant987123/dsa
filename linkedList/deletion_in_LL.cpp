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

/*TODO:
1. delete at head:- 
    i. store head in temp
    ii. assign head to temp ka nxt
    iii. free temp

2. delete last node:-
    i. traverse until trev ka nxt ka nxt is NULL
    ii. temp = trev ka nxt
    iii. assign trev ka nxt == NULL
    iv. free temp

3. delete at any pos:-
(make temp and trev)
    i. traverse the trev to pos-1
    ii. temp = trev ka nxt
    iii. trev ka nxt == temp ka nxt
    iv. free temp
*/

void deleteAtHead(node* &head){

    node* temp = new node(0);
    temp = head;

    head = temp -> next;

    free(temp);
}

void deleteAtTail(node* &head){
    node* trev = new node(0);
    node* temp = new node(0);

    trev=head;

    while( trev->next->next != NULL ){
        trev = trev->next;
    }

    temp = trev -> next;

    trev->next = NULL;

    free(temp); 
}

void deleteAtPos(node* &head, int pos){
    //if pos==1 call deleteAtHead
    if(pos==1){
        deleteAtHead(head);
        return;
    }

    node* trev = new node(0);
    node* temp = new node(0);

    trev=head;

    int curr_pos=1;
    while(curr_pos != pos-1){
        curr_pos ++;
        trev = trev->next;
    }

    if(trev->next->next == NULL){
        deleteAtTail(head);
        return;
    }

    temp=trev->next;
    trev -> next = temp -> next;

    free(temp);

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
        cout<< temp->data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
 }

int main(){

    node* new_node = new node(1);
    

    cout<<"node data 1 : "<< new_node->data << endl;
    cout<<"node next 1 : "<< new_node->next << endl;

    insertAtHead( new_node , 2);
    insertAtHead( new_node , 3);
    insertAtHead( new_node , 4);
    insertAtHead( new_node , 5);

    insertAtPos(new_node, 2, 1);
    insertAtPos(new_node, 0, 7);
    cout<<"intial LL : "<<endl;
    display(new_node);

    cout<<endl;
    cout<<endl;

    deleteAtHead(new_node);
    cout<<"after deleting head : "<<endl;
    display(new_node);

    cout<<endl;
    cout<<endl;

    deleteAtTail(new_node);
    cout<<"after deleting tail : "<<endl;
    display(new_node);

    cout<<endl;
    cout<<endl;

    deleteAtPos(new_node, 2);
    cout<<"after deleting 2 node : "<<endl;
    display(new_node);








    return 0;
    
}