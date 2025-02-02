#include <iostream>
using namespace std;

class Queue {
public:
    int size;
    int* arr; // Change from int to int* to hold a dynamic array
    int fIndex;
    int rIndex;

    // Constructor
    Queue(int size) {
        this->size = size;
        arr = new int[size];
        fIndex = 0;
        rIndex = 0;
    }

    // Destructor to release allocated memory
    ~Queue() {
        delete[] arr;
    }

    // Functions

    int enQ(int d) {
        if (rIndex < size) {
            arr[rIndex] = d;
            rIndex++;
            return 0; // Indicating success
        } else {
            return -1; // Indicating queue overflow
        }
    }

    void dQ() {
        if (fIndex < rIndex) {
            fIndex++;
        } else {
            cout << "Queue is empty, cannot dequeue." << endl;
        }
    }

    int frnt() {
        if (fIndex < rIndex) {
            return arr[fIndex];
        }
        return -1; // Indicating queue is empty
    }

    bool isEmpty() {
        return (fIndex == rIndex);
    }

    void display() {
        for (int i = fIndex; i < rIndex; i++) {
            cout << arr[i] << endl;
        }
        cout<<endl;
    }
};

int main() {
    Queue q(5);
    q.enQ(2);
    q.enQ(4);
    q.enQ(3);

    q.display();

    q.dQ();
    q.display();

    return 0;
}
