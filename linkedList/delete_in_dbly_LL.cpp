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

// delete head
/*
1. create trav to point head ka nxt & temp to point head
2. do temp ka nxt is NULL
3. do trav ka prev is NULL
4. make trav new head
5. delete temp
*/
void deleteAtHead(node* &head){
    //1.
    node* trav = head->next;
    node* temp = head;
    

    //2. 
    temp->next = NULL;

    //3.
    trav->prev = NULL;

    //4.
    head = trav;

    //5.
    delete temp;
}

//delete tail
/*
1.node temp pointiong to last node
2. node trav pointing to II last node
3. trav is until trav ka nxt ka nxt is NULL
4. do temp = trav ka nxt
5. do trav ka nxt null
6. do temp ka prev null
7. delete temp
*/
void deleteAtTail(node* &head){
    //1., 2., 3., 4.
    node* temp = new node(NULL);
    node* trav = head;

    while( trav->next->next != NULL){
        trav=trav->next;
    }

    temp = trav -> next;

    //5. 
    trav -> next = NULL;

    //6.
    temp -> prev = NULL;

    //7.
    delete temp;


}

// delete at Pos
/*
    {if pos == 1 call delete at head}
1. trav to pos-1  &  temp to pos
    {if temp ka nxt is null call delete at tail}
2. do trav ka nxt = temp ka nxt
3. do temp ka nxt ka prev = trav
4. do temp ka nxt = null
5. do temp ka prev = null
6. delete temp
*/
void deleteAtPos(node* &head, int pos){
    //1.
    node* trav = head;
    node* temp = new node(NULL);

    if( pos==1 ){
        deleteAtHead(head);
        return ;
    }

    int curr_pos=1;

    while(curr_pos != pos-1 ){
        trav = trav -> next ;
        curr_pos ++ ;
    }

    temp = trav -> next ; 

    if(temp->next == NULL){
        deleteAtTail(head);
        return;
    }

    //2. 
    trav -> next = temp -> next;

    //3.
    temp -> next -> prev = trav;

    //4.
    temp -> next = NULL;

    //5.
    temp -> prev = NULL;

    //6.
    delete temp;
}



/*-----------------------------------------------------*/

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

    cout<<"inseting 6 at tail : "<<endl;
    insertAtTail(node1, 6);
    display(node1);
    cout<<endl;

    cout<<"inseting 7 at tail : "<<endl;
    insertAtTail(node1, 7);
    display(node1);
    cout<<endl;
    
    cout<<"inseting 0 at 1st pos : "<<endl;
    insertAtPos(node1, 0, 1);
    display(node1);
    cout<<endl;

    cout<<"deleting head : "<<endl;
    deleteAtHead(node1);
    display(node1);
    cout<<endl;

    cout<<"deleting tail : "<<endl;
    deleteAtTail(node1);
    display(node1);
    cout<<endl;

    cout<<"deleting last : "<<endl;
    deleteAtPos(node1, 3);
    display(node1);
    cout<<endl;

    return 0;
}