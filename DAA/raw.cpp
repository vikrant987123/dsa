#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

// Node structure for the Red-Black Tree
enum Color { RED, BLACK };

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
    Color color;

    Node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr), color(RED) {}
};

// Red-Black Tree class
class RedBlackTree {
private:
    Node* root;
    Node* TNULL; // Null leaf node

    void rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != TNULL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    void rotateRight(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != TNULL) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    void fixInsert(Node* k) {
        Node* u;
        while (k->parent->color == RED) {
            if (k->parent == k->parent->parent->right) {
                u = k->parent->parent->left;
                if (u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rotateRight(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rotateLeft(k->parent->parent);
                }
            } else {
                u = k->parent->parent->right;
                if (u->color == RED) {
                    u->color = BLACK;
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    k = k->parent->parent;
                } else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        rotateLeft(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rotateRight(k->parent->parent);
                }
            }
            if (k == root) {
                break;
            }
        }
        root->color = BLACK;
    }

    void insertNode(int key) {
        Node* node = new Node(key);
        Node* y = nullptr;
        Node* x = root;

        while (x != TNULL) {
            y = x;
            if (node->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        node->parent = y;
        if (y == nullptr) {
            root = node;
        } else if (node->data < y->data) {
            y->left = node;
        } else {
            y->right = node;
        }

        node->left = TNULL;
        node->right = TNULL;
        node->color = RED;

        fixInsert(node);
    }

    void inorderHelper(Node* node) {
        if (node != TNULL) {
            inorderHelper(node->left);
            cout << node->data << " ";
            inorderHelper(node->right);
        }
    }

    void printTreeHelper(Node* root, int space) {
        if (root == nullptr || root == TNULL) return;

        space += 10;

        printTreeHelper(root->right, space);

        cout << endl;
        for (int i = 10; i < space; i++) {
            cout << " ";
        }
        cout << root->data << "(" << (root->color == RED ? "R" : "B") << ")" << endl;

        printTreeHelper(root->left, space);
    }

public:
    RedBlackTree() {
        TNULL = new Node(0);
        TNULL->color = BLACK;
        root = TNULL;
    }

    void insert(int key) {
        insertNode(key);
    }

    void inorder() {
        inorderHelper(root);
        cout << endl;
    }

    void printTree() {
        printTreeHelper(root, 0);
    }

    Node* getRoot() {
        return root;
    }
};

int main() {
    RedBlackTree tree;

    // Insert values
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);

    cout << "Inorder Traversal: ";
    tree.inorder();

    cout << "Red-Black Tree in Pyramid Structure:\n";
    tree.printTree();

    return 0;
}
