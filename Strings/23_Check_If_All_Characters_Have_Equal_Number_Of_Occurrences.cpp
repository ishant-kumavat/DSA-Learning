// LeetCode 1941 => ** Check if All Characters Have Equal Number of Occurrences **

// Optimal Solution => Hash Table
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> hasharr(26, 0);
        for(char it : s) hasharr[it - 'a'] ++;
        int x = 0;
        for(auto &it : hasharr){
            if(it == 0) continue;
            if(x == 0) x = it;
            else if(x != it) return false;
        }
        return true;
    }
};

// Count the frequency of each lowercase character
// using a fixed-size array of 26 elements.
//
// Ignore characters whose frequency is zero.
//
// Store the first non-zero frequency in `x`.
// Compare every other non-zero frequency with `x`.
//
// If any frequency differs, return false.
// Otherwise, return true.