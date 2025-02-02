#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Function to count the number of set bits in an integer
int countSetBits(int num) {
    return __builtin_popcount(num); // GCC built-in function to count set bits
}

// Function to check if the permutation can be sorted by allowed swaps
string canSortBySwapping(vector<int>& P) {
    unordered_map<int, vector<int>> bitGroups;

    // Step 1: Group numbers by their count of set bits
    for (int num : P) {
        int bitCount = countSetBits(num);
        bitGroups[bitCount].push_back(num);
    }

    // Step 2: Sort each group
    for (auto& entry : bitGroups) {
        sort(entry.second.begin(), entry.second.end());
    }

    // Step 3: Reconstruct the sorted array based on groups
    vector<int> sortedP;
    for (int num : P) {
        int bitCount = countSetBits(num);
        sortedP.push_back(bitGroups[bitCount].front()); // Get the smallest number from that group
        bitGroups[bitCount].erase(bitGroups[bitCount].begin()); // Remove it from the group
    }

    // Step 4: Compare with fully sorted array
    vector<int> originalSorted = P;
    sort(originalSorted.begin(), originalSorted.end());

    if (sortedP == originalSorted) {
        return "Yes";
    } else {
        return "No";
    }
}

int main() {
    int N;
    cout << "Enter the length of permutation: ";
    cin >> N;
    
    vector<int> P(N);
    cout << "Enter the elements of permutation: ";
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    cout << canSortBySwapping(P) << endl; // Output "Yes" or "No"
    
    return 0;
}
