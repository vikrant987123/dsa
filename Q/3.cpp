#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }

        // Find the maximum frequency in the array
        int maxFreq = max_element(freq.begin(), freq.end(), 
            [](const pair<int, int>& p1, const pair<int, int>& p2) {
                return p1.second < p2.second;
            })->second;

        // If k is already the most frequent
        if (freq[k] >= maxFreq) {
            cout << 0 << endl;
            continue;
        }

        // Find all positions of k
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (a[i] == k) pos.push_back(i);
        }

        bool canRemoveOne = false;

        // Check if removing prefix works
        unordered_map<int, int> freqPrefix = freq;
        for (int i = 0; i < n; i++) {
            if (a[i] == k) break;
            freqPrefix[a[i]]--;
        }

        int maxFreqPrefix = max_element(freqPrefix.begin(), freqPrefix.end(),
            [](const pair<int, int>& p1, const pair<int, int>& p2) {
                return p1.second < p2.second;
            })->second;

        if (freqPrefix[k] >= maxFreqPrefix) {
            canRemoveOne = true;
        }

        // Check if removing suffix works
        unordered_map<int, int> freqSuffix = freq;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == k) break;
            freqSuffix[a[i]]--;
        }

        int maxFreqSuffix = max_element(freqSuffix.begin(), freqSuffix.end(),
            [](const pair<int, int>& p1, const pair<int, int>& p2) {
                return p1.second < p2.second;
            })->second;

        if (freqSuffix[k] >= maxFreqSuffix) {
            canRemoveOne = true;
        }

        if (canRemoveOne) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    }

    return 0;
}
