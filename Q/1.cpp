#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric> // For iota
using namespace std;

bool isDivisibleSubarray(vector<int>& nums, int divisor) {
    unordered_map<int, int> remainderMap; // To store remainders
    remainderMap[0] = 1; // Handle case where cumulative sum is directly divisible
    int cumulativeSum = 0;

    for (int num : nums) {
        cumulativeSum += num;
        int remainder = cumulativeSum % divisor;
        if (remainder < 0) remainder += divisor; // Handle negative remainders

        // Check if this remainder was seen before
        if (remainderMap.find(remainder) != remainderMap.end()) {
            return true; // Subarray sum divisible by divisor exists
        }
        remainderMap[remainder]++;
    }
    return false;
}

vector<int> generatePermutation(int n, int divisor) {
    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 1); // Fill with 1, 2, ..., n

    // Rearrange such that no subarray sum is divisible by divisor
    for (int i = 0; i < n; ++i) {
        nums[i] = (i * 2 + 1) % divisor;
    }

    return nums;
}

int main() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "n must be odd." << endl;
        return 0;
    }

    int divisor = n + 1;
    vector<int> nums = generatePermutation(n, divisor);

    if (isDivisibleSubarray(nums, divisor)) {
        cout << "Error: Found a subarray whose sum is divisible by " << divisor << "." << endl;
    } else {
        cout << "Generated permutation: ";
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
        cout << "No subarray sum is divisible by " << divisor << "." << endl;
    }

    return 0;
}
