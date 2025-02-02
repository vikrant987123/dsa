#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>

using namespace std;

enum Color {RED, BLACK};

struct Node {
    int data;
    Color color;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val) {
        data = val;
        color = RED;
        left = right = parent = nullptr;
    }
};

class RedBlackTree {
private:
    Node* root;
    Node* TNULL;

    // Function to print the tree in a pyramid-like structure
    void printTreePyramid(Node* node, int level, int indentSpaces) {
        if (node != TNULL) {
            if (node->right != TNULL) {
                printTreePyramid(node->right, level + 1, indentSpaces + 4);
            }

            // Print the current node's data and color with spaces to form a pyramid
            string color = (node->color == RED) ? "R" : "B";
            cout << setw(indentSpaces) << " " << node->data << "(" << color << ")" << endl;

            if (node->left != TNULL) {
                printTreePyramid(node->left, level + 1, indentSpaces + 4);
            }
        }
    }

    // Balance the tree after insertion
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
                        rightRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    leftRotate(k->parent->parent);
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
                        leftRotate(k);
                    }
                    k->parent->color = BLACK;
                    k->parent->parent->color = RED;
                    rightRotate(k->parent->parent);
                }
            }
            if (k == root) break;
        }
        root->color = BLACK;
    }

    // Rotate left
    void leftRotate(Node* x) {
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

    // Rotate right
    void rightRotate(Node* x) {
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

    // Insert a new node
    void insertNode(int key) {
        Node* node = new Node(key);
        node->parent = nullptr;
        node->data = key;
        node->left = TNULL;
        node->right = TNULL;
        node->color = RED;

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

        if (node->parent == nullptr) {
            node->color = BLACK;
            return;
        }

        if (node->parent->parent == nullptr) {
            return;
        }

        fixInsert(node);
    }

    // Level order traversal to print the tree along with color
    void levelOrderTraversal() {
        if (root == TNULL) return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            // Print the node's value and its color
            string color = (node->color == RED) ? "R" : "B";
            cout << node->data << "(" << color << ") ";

            if (node->left != TNULL) {
                q.push(node->left);
            }
            if (node->right != TNULL) {
                q.push(node->right);
            }
        }
        cout << endl;
    }

public:
    RedBlackTree() {
        TNULL = new Node(0);
        TNULL->color = BLACK;
        root = TNULL;
    }

    // Insert multiple values from vector
    void insertFromVector(const vector<int>& values) {
        for (int value : values) {
            insertNode(value);
        }

        // After all insertions, print the tree in pyramid structure
        cout << "Tree after insertions in pyramid structure:" << endl;
        printTreePyramid(root, 0, 10);  // Adjust the spacing to form the pyramid
        cout << endl;

        // Perform level order traversal and print nodes with their colors
        cout << "Level order traversal with colors:" << endl;
        levelOrderTraversal();
    }
};

int main() {
    RedBlackTree tree;
    // Vector containing the values to be inserted into the tree
    vector<int> values = {20, 15, 25, 10, 5};

    // Insert values from the vector and print the tree
    tree.insertFromVector(values);

    return 0;
}
