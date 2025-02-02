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
};

//insert at head
/*
1. create a node (temp) which is to be insert
2. temp ke nxt me head dalo
3. head ke prev me temp dalo
4. make temp new head
*/
void insertAtHead(node* &head, int val){

    if( head == NULL){
        node* temp = new node(val);
        head = temp;
    }
    else{
        //1.
        node* temp = new node(val);

        //2.
        temp -> next = head;

        //3.
        head -> prev = temp;

        //4.
        head=temp;
            
    }
    
}


// insert at tail
/*
1. create a node (temp) which is to be insert
2. trev. node until trev ka nxt is null
3. make trev. ka nxt temp
4. make temp ka prev is trev
*/
void insertAtTail(node* &head, int val){
    if( head == NULL){
        node* temp = new node(val);
        head = temp;
    }
    else{
        // 1.
        node* temp = new node(val);

        // 2.
        node* trav = new node(0);
        trav = head;
        while( trav -> next != NULL){
            trav = trav -> next;
        }
        //trav reached at tail

        // 3.
        trav -> next = temp;

        // 4.
        temp -> prev = trav;
    }
   
}

// insert at any pos
/*
1. create node(temp) which is to be inserted
2. create a node trav which travers to pos-1
3. temp ka nxt = trav ka nxt
5. trav ka nxt = temp
4. trav ka nxt ka prev = temp
6. temp ka prev = trav
*/
void insertAtPos(node* &head, int val, int pos){
    // to insert at head
    if(pos == 1){
        insertAtHead(head, val);
        return;
    }

    //1.
    node* temp =new node(val);

    //2.
    node* trav =new node(0);
    int curr_pos=1;

    trav = head;

    while( curr_pos != pos-1 ){
        curr_pos ++;
        trav = trav->next;
    }
    //to insertAtTail
    if( trav->next == NULL){
        insertAtTail(head, val);
        return;
    }

    //3.
    temp->next = trav->next;

    //4.
    trav->next->prev = temp;

    //5.
    trav->next = temp;

    //6.
    temp->prev = trav;
    
}


void display(node* head){
    node* trev = new node(0);
    trev = head;

    while( trev != NULL ){
        cout<< trev -> data <<" ";
        trev = trev -> next;
    }
    cout<<endl;

}

int main(){
    node* node1 = new node(NULL);

    cout<<"linkedlist is : "<<endl;
    display(node1);
    cout<<endl;

    cout<<"inserting 1 at head : "<<endl;
    insertAtHead(node1, 1);
    display(node1);
    cout<<endl;

    // cout<<"inseting 6 at tail : "<<endl;
    // insertAtTail(node1, 6);
    // display(node1);
    // cout<<endl;

    // cout<<"inseting 7 at tail : "<<endl;
    // insertAtTail(node1, 7);
    // display(node1);
    // cout<<endl;
    
    // cout<<"inseting 0 at 1st pos : "<<endl;
    // insertAtPos(node1, 0, 1);
    // display(node1);
    // cout<<endl;

    return 0;
}