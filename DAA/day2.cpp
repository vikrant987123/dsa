#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

// Enum for node colors
enum Color { RED, BLACK };

// Node structure
struct Node {
    int data;           // Value stored in the node
    bool color;         // RED or BLACK
    Node *left, *right, *parent;

    // Constructor for creating a new node
    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

// Class for Red-Black Tree
class RedBlackTree {
private:
    Node* root; // Pointer to the root of the tree

    // Function to perform a left rotation
    void rotateLeft(Node*& root, Node*& node) {
        Node* nodeRight = node->right; // Get the right child of the current node
        node->right = nodeRight->left; // Move left subtree of the right child to the right of the current node

        if (node->right != nullptr)
            node->right->parent = node;

        nodeRight->parent = node->parent;

        if (node->parent == nullptr)
            root = nodeRight; // Update root if necessary
        else if (node == node->parent->left)
            node->parent->left = nodeRight; // Update parent's left child
        else
            node->parent->right = nodeRight; // Update parent's right child

        nodeRight->left = node;
        node->parent = nodeRight;
    }

    // Function to perform a right rotation
    void rotateRight(Node*& root, Node*& node) {
        Node* nodeLeft = node->left; // Get the left child of the current node
        node->left = nodeLeft->right; // Move right subtree of the left child to the left of the current node

        if (node->left != nullptr)
            node->left->parent = node;

        nodeLeft->parent = node->parent;

        if (node->parent == nullptr)
            root = nodeLeft; // Update root if necessary
        else if (node == node->parent->left)
            node->parent->left = nodeLeft; // Update parent's left child
        else
            node->parent->right = nodeLeft; // Update parent's right child

        nodeLeft->right = node;
        node->parent = nodeLeft;
    }

    // Fix violations of Red-Black Tree properties after insertion
    void fixInsert(Node*& root, Node*& node) {
        Node* parent = nullptr;
        Node* grandparent = nullptr;

        // Continue fixing until node is the root or properties are restored
        while (node != root && node->color == RED && node->parent->color == RED) {
            parent = node->parent;
            grandparent = parent->parent;

            // Case: Parent is left child of grandparent
            if (parent == grandparent->left) {
                Node* uncle = grandparent->right;

                // Case 1: Uncle is RED (Recoloring)
                if (uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                } else {
                    // Case 2: Node is right child (Left Rotate)
                    if (node == parent->right) {
                        rotateLeft(root, parent);
                        node = parent;
                        parent = node->parent;
                    }
                    // Case 3: Node is left child (Right Rotate)
                    rotateRight(root, grandparent);
                    swap(parent->color, grandparent->color);
                    node = parent;
                }
            }
            // Case: Parent is right child of grandparent
            else {
                Node* uncle = grandparent->left;

                // Case 1: Uncle is RED (Recoloring)
                if (uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                } else {
                    // Case 2: Node is left child (Right Rotate)
                    if (node == parent->left) {
                        rotateRight(root, parent);
                        node = parent;
                        parent = node->parent;
                    }
                    // Case 3: Node is right child (Left Rotate)
                    rotateLeft(root, grandparent);
                    swap(parent->color, grandparent->color);
                    node = parent;
                }
            }
        }
        root->color = BLACK; // Ensure the root is always BLACK
    }

    // Fix violations of Red-Black Tree properties after deletion
    void fixDelete(Node*& root, Node*& node) {
        Node* sibling;
        Node* parent;

        while (node != root && (node == nullptr || node->color == BLACK)) {
            parent = node->parent;

            if (node == parent->left) {
                sibling = parent->right;

                // Case 1: Sibling is RED
                if (sibling != nullptr && sibling->color == RED) {
                    sibling->color = BLACK;
                    parent->color = RED;
                    rotateLeft(root, parent);
                    sibling = parent->right;
                }

                // Case 2: Sibling's children are BLACK
                if ((sibling->left == nullptr || sibling->left->color == BLACK) &&
                    (sibling->right == nullptr || sibling->right->color == BLACK)) {
                    if (sibling != nullptr)
                        sibling->color = RED;
                    node = parent;
                } else {
                    // Case 3: Sibling's right child is BLACK
                    if (sibling->right == nullptr || sibling->right->color == BLACK) {
                        if (sibling->left != nullptr)
                            sibling->left->color = BLACK;
                        sibling->color = RED;
                        rotateRight(root, sibling);
                        sibling = parent->right;
                    }

                    // Case 4: Sibling's right child is RED
                    if (sibling != nullptr)
                        sibling->color = parent->color;

                    parent->color = BLACK;
                    if (sibling->right != nullptr)
                        sibling->right->color = BLACK;

                    rotateLeft(root, parent);
                    node = root;
                }
            } else {
                sibling = parent->left;

                // Similar cases as above but mirrored for right child
                if (sibling != nullptr && sibling->color == RED) {
                    sibling->color = BLACK;
                    parent->color = RED;
                    rotateRight(root, parent);
                    sibling = parent->left;
                }

                if ((sibling->left == nullptr || sibling->left->color == BLACK) &&
                    (sibling->right == nullptr || sibling->right->color == BLACK)) {
                    if (sibling != nullptr)
                        sibling->color = RED;
                    node = parent;
                } else {
                    if (sibling->left == nullptr || sibling->left->color == BLACK) {
                        if (sibling->right != nullptr)
                            sibling->right->color = BLACK;
                        sibling->color = RED;
                        rotateLeft(root, sibling);
                        sibling = parent->left;
                    }

                    if (sibling != nullptr)
                        sibling->color = parent->color;

                    parent->color = BLACK;
                    if (sibling->left != nullptr)
                        sibling->left->color = BLACK;

                    rotateRight(root, parent);
                    node = root;
                }
            }
        }

        if (node != nullptr)
            node->color = BLACK; // Restore BLACK property
    }

    // Helper function for BST-style insertion
    Node* BSTInsert(Node* root, Node* node) {
        if (root == nullptr)
            return node;

        if (node->data < root->data) {
            root->left = BSTInsert(root->left, node);
            root->left->parent = root;
        } else if (node->data > root->data) {
            root->right = BSTInsert(root->right, node);
            root->right->parent = root;
        }
        return root;
    }

    // Helper function to find the minimum value in a subtree
    Node* getMinimum(Node* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    // Helper function for in-order traversal
    void inorderHelper(Node* root) {
        if (root == nullptr)
            return;

        inorderHelper(root->left);
        cout << root->data << (root->color == RED ? "(R) " : "(B) ");
        inorderHelper(root->right);
    }

    // Helper function to print the tree in a branched structure
    void printTreeHelper(Node* root, string indent, bool isRight) {
        if (root == nullptr)
            return;

        cout << indent;
        if (isRight) {
            cout << "R----";
            indent += "   ";
        } else {
            cout << "L----";
            indent += "|  ";
        }

        cout << root->data << "(" << (root->color == RED ? "R" : "B") << ")" << endl;
        printTreeHelper(root->left, indent, false);
        printTreeHelper(root->right, indent, true);
    }

public:
    RedBlackTree() : root(nullptr) {}

    // Public function to insert a value into the Red-Black Tree
    void insert(int data) {
        Node* node = new Node(data);
        root = BSTInsert(root, node);
        fixInsert(root, node);
    }

    // Public function to delete a value from the Red-Black Tree
    void deleteNode(int data) {
        Node* node = root;
        Node* parent = nullptr;

        while (node != nullptr && node->data != data) {
            parent = node;
            if (data < node->data)
                node = node->left;
            else
                node = node->right;
        }

        if (node == nullptr)
            return;  // Data not found

        if (node->left == nullptr || node->right == nullptr) {
            fixDelete(root, node);
        } else {
            Node* successor = getMinimum(node->right);
            int successorData = successor->data;
            deleteNode(successorData);
            node->data = successorData;
        }
    }

    // Public function to print the tree in a branched structure
    void printTree() {
        if (root == nullptr) {
            cout << "Tree is empty." << endl;
            return;
        }
        printTreeHelper(root, "", false);
    }

    // Public function to perform in-order traversal
    void inorder() {
        inorderHelper(root);
        cout << endl;
    }
};

// Main function to test the Red-Black Tree implementation
int main() {
    RedBlackTree rbTree;

    rbTree.insert(10);
    rbTree.insert(20);
    rbTree.insert(15);
    rbTree.insert(25);
    rbTree.insert(5);

    cout << "Red-Black Tree in branched structure:" << endl;
    rbTree.printTree();

    cout << "\nInorder traversal:" << endl;
    rbTree.inorder();

    rbTree.deleteNode(15);

    cout << "\nTree after deleting 15:" << endl;
    rbTree.printTree();

    return 0;
}
