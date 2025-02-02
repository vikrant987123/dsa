#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Custom hash function for pair<int, int>
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2; // XOR combination
    }
};

int solve(int idx, vector<int> &revenue, unordered_map<pair<int, int>, int, pair_hash> &dp, int k) {
    if (idx >= revenue.size() || k == 0) return 0; // Base case

    pair<int, int> key = {idx, k};
    if (dp.count(key)) return dp[key];

    // Take the current element (idx) and move to idx+2 (skip one element)
    int take = revenue[idx] + solve(idx + 2, revenue, dp, k - 1);
    
    // Skip the current element (idx) and move to idx+1
    int skip = solve(idx + 1, revenue, dp, k);

    // Store the best result (taking or skipping)
    return dp[key] = max(take, skip);
}

vector<int> maximizeAdRevenue(const vector<int> &viewer_retention, const vector<int> &ad_value, int k) {
    vector<int> revenue;
    for (int i = 0; i < viewer_retention.size(); i++) {
        revenue.push_back(viewer_retention[i] * ad_value[i]);
    }

    unordered_map<pair<int, int>, int, pair_hash> dp;
    solve(0, revenue, dp, k); // Compute the max revenue

    // Now backtrack to find the actual places (indices) chosen for max revenue
    vector<int> place;
    int idx = 0;
    while (k > 0 && idx < revenue.size()) {
        // If taking the current element is better (i.e., it was part of the optimal solution)
        if (dp[{idx, k}] == revenue[idx] + dp[{idx + 2, k - 1}]) {
            place.push_back(idx);  // Add the index to the place vector
            idx += 2;  // Skip the next element (since we took this one)
            k--;  // Decrease the remaining selections
        } else {
            idx++;  // Skip this element
        }
    }

    // Sorting the indices before returning (if required by the problem)
    sort(place.begin(), place.end());
    return place;
}

int main() {
    vector<int> viewer_retention;
    vector<int> ad_value;
    int k, n;

    cin >> n >> k; // Combined input reading for simplicity
    viewer_retention.resize(n);
    ad_value.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> viewer_retention[i];
    }
    
    for (int i = 0; i < n; ++i) {
        cin >> ad_value[i];
    }

    vector<int> result = maximizeAdRevenue(viewer_retention, ad_value, k);
    
    // Output result
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) cout << " "; // Space between numbers
    }
    
    return 0;
}
