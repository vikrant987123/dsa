#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root) {
    cout << "Enter data" << endl;
    int d;
    cin >> d;

    if (d == -1) {
        return NULL;
    }

    root = new node(d);

    cout << "enter data for LEFT of " << d << endl;
    root->left = buildTree(root->left);

    cout << "enter data for RIGHT of " << d << endl;
    root->right = buildTree(root->right);

    return root; // Return the root after building the tree
}

void lvlOrderTraversal(node* root) {
    if (root == NULL) {
        return; // If root is NULL, no traversal is needed
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";

            if (temp->left) {
                q.push(temp->left);
            }

            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void inOrder( node* root ){

    if( root == NULL ){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder( node* root ){

    if( root == NULL ){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder( node* root ){

    if( root == NULL ){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main() {
    node* root = NULL;

    // Creating a tree
    root = buildTree(root);

    cout<<root->data<<" ";
    // Performing level order traversal
    lvlOrderTraversal(root);

    cout<<"inorder:- "<<endl;
    // Performing inorder traversal
    inOrder(root);

    cout<<"preorder:- "<<endl;
    // Performing inorder traversal
    preOrder(root);

    cout<<"postorder"<<endl;
    // Performing inorder traversal
    postOrder(root);

    return 0;
}
