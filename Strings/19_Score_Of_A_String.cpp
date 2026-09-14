// LeetCode 3110 => ** Score of a String **

// Optimal Solution => Adjacent Character Difference   
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int scoreOfString(string s) {
        int ans = 0;
        int n = s.length();
        for(int i = 0; i < n - 1; i++){
            ans += abs(s[i] - s[i + 1]);
        }
        return ans;
    }
};

// Traverse through adjacent characters.
//
// Calculate the absolute difference
// between consecutive characters.
//
// Add each difference to the total score.
//
// Return the total score.