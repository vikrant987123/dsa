#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int countK = count(a.begin(), a.end(), k);
        int op = 0;

        // Find first and last occurrence of k
        int f = -1, l = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == k) {
                if (f == -1) f = i;
                l = i;
            }
        }

        if (countK == 1) {
            if (n / 2 == countK || n == countK) {
                cout << 0 << endl;
            } else if ((n + 1) / 2 == f + 1) {
                cout << 2 << endl;
            } else {
                cout << 1 << endl;
            }
        } else {
            unordered_map<int, int> freq;
            for (int i = f; i <= l; i++) {
                freq[a[i]]++;
            }

            // Find the most frequent element between f and l
            int maxFreq = 0;
            for (auto &[num, cnt] : freq) {
                if (num != k) {
                    maxFreq = max(maxFreq, cnt);
                }
            }

            if (maxFreq < countK) {
                cout << 0 << endl; // k is already the most frequent
            } else {
                // Remove elements from the prefix and suffix until k is the most frequent
                int left = f, right = n - l - 1;
                op = 1;
                while (maxFreq >= countK) {
                    if (left <= right) {
                        f++;
                        freq[a[f - 1]]--;
                    } else {
                        l--;
                        freq[a[l + 1]]--;
                    }
                    countK = freq[k];
                    maxFreq = 0;
                    for (auto &[num, cnt] : freq) {
                        if (num != k) {
                            maxFreq = max(maxFreq, cnt);
                        }
                    }
                    op++;
                }
                cout << op << endl;
            }
        }
    }
}
