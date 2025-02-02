#include <bits/stdc++.h>
using namespace std;

class treeNode{
    public:
        int data;
        treeNode* left;
        treeNode* right; 
    public:
        treeNode(int d){
            this->data = d;
            this->left = nullptr;
            this->right = nullptr;
        }

};

treeNode* formBST(treeNode* root, int d){
    if(root==nullptr){
        root = new treeNode(d);
        return root;
    }

    if(d > root->data){
        root->right=formBST(root->right,d);
    }
    if(d < root->data){
        root->left=formBST(root->left,d);
    }
    
    return root;
}

int main(){
    int n;
    cin>>n;

    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    treeNode* root = NULL;

    for (int i = 0; i < n; i++)
    {
        root = formBST(root,v[i]);
    }

    cout<<root->right->data<<endl;
    


    return 0;
}