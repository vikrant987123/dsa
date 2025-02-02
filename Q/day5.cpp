#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool canBePalindrome(string s) {
    int left = 0, right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            // Try skipping left or right character
            return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
        }
        left++;
        right--;
    }
    return true;  // Already a palindrome
}

int main() {
    string s;
    cin >> s; 
    cout << (canBePalindrome(s) ? "YES" : "NO");
    return 0;
}
