// LeetCode 125 => ** Valid Palindrome **

// 1). Optimal Solution => Two Pointers
//     Time Complexity :O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0, ed = s.length() - 1;
        while(st < ed){
            if(!isalnum(s[st])){
                st++;continue;
            }
            if(!isalnum(s[ed])){
                ed--;continue;
            } 
            if(tolower(s[st]) != tolower(s[ed])) return false;
            st++;ed--;
        }
        return true;
    }
};

// Use two pointers from both ends of the string.
// Skip all non-alphanumeric characters.
// Compare the remaining characters after converting them to lowercase.
// If any pair does not match, return false.

// tolower(ch)  => Converts a character to lowercase.
// isalnum(ch)  => Checks whether a character is alphanumeric.