#include <bits/stdc++.h>
using namespace std;

long long minEnd(int n, int x) {
    if (n <= 1) return x;  // Edge case: if n is 1 or less, return x directly

    vector<int> arr;
    arr.push_back(x);

    int op = x + 1;
    while (arr.size() < n) {
        int o = op & arr.back();
        if (o == x) {
            arr.push_back(op);
        }
        else{
            op = op | arr.back();
            arr.push_back(op);
        }
        op++;
    }

    return arr.back();
}

int main() {
    int n=3,x=4;
    long long soln = minEnd(n,x);
    cout << soln << endl;
    
    return 0;
}
