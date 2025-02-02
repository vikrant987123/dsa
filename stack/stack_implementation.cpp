#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    // properties
    int size;
    int topIndex;
    int *arr;

    // constructor
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        topIndex = -1;
    }

    // function to push an element onto the stack
    void push(int x) {
        // check for available space
        if (topIndex == size - 1) {
            cout << "Space is not available" << endl;
        } else {
            topIndex++;
            arr[topIndex] = x;
        }
    }

    // function to pop an element from the stack
    void pop() {
        // check if the stack is empty
        if (topIndex == -1) {
            cout << "Element is not present" << endl;
        } else {
            topIndex--;
        }
    }

    // function to get the top element of the stack
    int top() {
        // check if the stack is empty
        if (topIndex == -1) {
            cout << "Element is not present" << endl;
            return -1;  // return an invalid value when the stack is empty
        } else {
            return arr[topIndex];
        }
    }

    // function to check if the stack is empty
    bool isEmpty() {
        return topIndex == -1;
    }

    // destructor to free allocated memory
    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack st(5);  // Create a stack object with a size of 5

    st.push(2);
    cout << "Top element: " << st.top() << endl;  // Should print 2
    st.pop();
    cout << "Top element: " << st.top() << endl; 
    st.top();

    return 0;
}
