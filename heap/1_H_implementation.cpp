#include <bits/stdc++.h>
using namespace std;

class heap{
public:
    int arr[100];
    int size = 0;

    void insert(int val){
        size = size+1;
        int index = size;
        arr[index]=val;

        while(index>1){
            int parent = index/2;

            if( arr[parent] < arr[index] ){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }

    void deletion(){
        // Checking if the heap is empty
        if(size == 0){
            cout << "No node to delete" << endl;
            return;
        }

        // Move the last node to the root
        arr[1] = arr[size];
        size--;

        // Heapify down from the root
        int i = 1;
        while(i <= size){
            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;

            // Check if the left child index is within bounds
            if(leftChild > size)
                break; // No more children to compare, exit the loop

            // Determine which child is larger
            int largerChild = leftChild;
            if(rightChild <= size && arr[rightChild] > arr[leftChild]){
                largerChild = rightChild;
            }

            // If the current node is smaller than the larger child, swap them
            if(arr[i] < arr[largerChild]){
                swap(arr[i], arr[largerChild]);
                i = largerChild; // Move to the larger child's index
            } else {
                break; // The heap property is restored, no need to continue
            }
        }
}



void print(){
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
};

void heapify(int arr[],int n,int i){
    int largest = i;
    int leftChild = 2*i;
    int rightChild = 2*i+1;

    if(leftChild <= n && arr[leftChild]>arr[largest]){
        largest = leftChild;
    }
    if(rightChild <= n && arr[rightChild]>arr[largest]){
        largest = rightChild;
    }

    //if largest gets updated then swap it with ith ele
    if(largest != i ){
        swap( arr[largest],arr[i] );
        heapify(arr,n,largest);
    }
}

int main(){

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(3);
    h.insert(71);
    h.insert(9);

    h.print();

    h.deletion();  

    h.print();
    cout<<endl;
    int arr[10]={-1,3,2,3,1,2,4,5,5,6};
    int n = 9;
    for(int i=n/2;i>=1;i--){
        heapify(arr,n,i);
    }

    cout<<"heaped array:- "<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    //heapify(arr,6,)

    return 0;
}