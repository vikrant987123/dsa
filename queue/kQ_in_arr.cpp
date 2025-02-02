#include <bits/stdc++.h>
using namespace std;

class kQueue
{
private:
    /* data */
public:
    int n;
    int k;
    int *front;
    int *rear;
    int *next;
    int *arr;
    int freeSpot;

    kQueue(int n, int k){
        this->n=n;
        this->k=k;

        front= new int[k];
        rear= new int[k];

        for(int i=0;i<k;i++){
            front[i]=-1;
            rear[i]=-1;
        }

        next= new int[n];

        for (int i = 0; i < n; i++)
        {
            /* code */
            next[i]=i+1;
        }
        next[n-1]=-1;
        

        arr= new int[n];

        int freeSpot=0;
    }

    ~kQueue();

    void enQ(int data, int qn){
        //overflow
        if(freeSpot==-1){
            cout<<"no free space is available"<<endl;
            return;
        }

        //find first index
        int index = freeSpot;

        //update freeSpot
        freeSpot=next[index];

        //check weather first ele
        if(front[qn-1]==-1){
            front[qn-1]=index;
        }
        else{
            next[ rear[qn-1] ] = index;
            //linking new element to the prev element
        }

        //update next
        next[index]=-1;

        //update rear
        rear[qn-1]=index;

        arr[index]=data;
    }

    int dQ(int qn){
        //underflow
        if(front[qn-1]==-1){
            cout<<"underflow"<<endl;

            return -1;
        }

        //find index to pop
        int index=front[qn-1];

        //front move to next ele in the respective /Q
        front[qn-1]=next[index];

        //ab new freeSpot bna hai to usse manage kro
        next[index]=freeSpot; //ab free to index hai aur uske baad jo free tha, un dono ko link kiya gya hai
        freeSpot=index;

        
        return arr[index];



    }
};

kQueue::kQueue(int n, int k){

}
{
}

kQueue::~kQueue()
{
}


int main(){
    return 0;
}