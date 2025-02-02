#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

string can_make_score_odd(const string &A, const string &B) {
    // Count the number of '1's in both strings
    int count_A = count(A.begin(), A.end(), '1');
    int count_B = count(B.begin(), B.end(), '1');

    // Calculate the total number of '1's
    int total_count = count_A + count_B;

    // Check if the total count is odd
    return (total_count % 2 == 1) ? "YES" : "NO";
}

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        string A,B;
        cin>>A>>B;
    
        cout << can_make_score_odd(A, B) << endl;  // Output: YES
    
        return 0;
    }
}
