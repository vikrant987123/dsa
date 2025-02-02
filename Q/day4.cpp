#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node{
    string page;
    node* prev;
    node* next;

    node(string s){
        page = s;
        prev = NULL;
        next = NULL;
    }
};



// you just need to implement the BrowserHistory class below
class BrowserHistory {
    // your code here
private:
    node* current;

public:
    BrowserHistory(string homepage) {
       // your code here
       current = new node(homepage); 
    }

    void visit(string url) {
        // your code here
        node* newPage = new node(url);
        if(current->next){
            delete current->next;
            current->next = nullptr;
        }
        
        current->next = newPage;
        newPage->prev = current;

        current = newPage;
    }

    string back(int steps) {
        // your code here
        while(steps-- > 0 && current->prev){
            current = current->prev;
        }
        return current->page;
    }

    string forward(int steps) {
        // your code here
        while(steps-- && current->next){
            current = current->next;
        }
        return current->page;
    }
};

int main() {
    int n;
    cin >> n; 
    string operation, url;
    int steps;

    // please do not change below code
    BrowserHistory browserHistory("chaicode.com");
    
    string result = "chaicode.com ";
    for (int i = 0; i < n; i++) {
        cin >> operation;

        if (operation == "visit") {
            cin >> url;
            browserHistory.visit(url);
            result += url + " ";
        } else if (operation == "back") {
            cin >> steps;
            result += browserHistory.back(steps) + " ";
        } else if (operation == "forward") {
            cin >> steps;
            result += browserHistory.forward(steps) + " ";
        }
    }
    
    cout << result.substr(0, result.size() - 1);

    return 0;
}