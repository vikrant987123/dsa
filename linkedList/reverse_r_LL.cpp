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

 /*
 APPROACH:-

 agar 1 node ya 1 bhi node nhi hai to stop ho jaao aur wahi cheez return krdo

 reverse the smaller LL and give its chota_head
 make head ka nxt ka nxt = head
 make head ka nxt NULL
 return chota_head

 */

node* reverse_R_LL(node* &head) {

    //base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    node* chota_head = reverse_R_LL( head->next );

    head->next->next = head;
    head->next = NULL;

    return chota_head;

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

    node* temp = new node(0);

    node* h = reverse_R_LL(n);
    cout<<"reversed LL"<<endl;
    display(h);




    //reversing

    return 0;
    
}