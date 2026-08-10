// LeetCode 680 => ** Valid Palindrome II **

// Optimal Solution => Two Pointer
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.length();
        int i = 0, j = n - 1;
        while(i < j){
            if(s[i] != s[j]){
                if(isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1)) return true;
                else return false;
            }
            i++;j--;
        }
        return true;
    }
};
// Compare characters from both ends
// using two pointers.
//
// If characters match,
// move both pointers inward.
//
// If a mismatch occurs,
// we are allowed to delete
// at most one character.
//
// Try skipping either the left
// or the right character.
//
// If either remaining substring
// is a palindrome, return true.
//
// If neither is a palindrome,
// return false.