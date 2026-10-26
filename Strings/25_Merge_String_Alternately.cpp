// LeetCode 1768 => ** Merge Strings Alternately **

// Optimal Solution => Two Pointers
// Time Complexity : O(n + m)
// Space Complexity : O(n + m)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1 = word1.size();   
        int n2 = word2.size();   
        int i = 0, j = 0;

        string res = "";

        while(i < n1 || j < n2){
            if(i < n1) res += word1[i++];
            if(j < n2) res += word2[j++];
        }
        
        return res;
    }
};

// Use two pointers to track positions in both strings.
//
// Append one character from `word1`, if available.
// Then append one character from `word2`, if available.
//
// The `||` condition continues the loop until
// both strings are completely processed.
//
// The boundary checks prevent accessing characters
// beyond the end of either string.
// Return the merged string.