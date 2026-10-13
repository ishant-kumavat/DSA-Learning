// LeetCode 2828 => ** Check if a String Is an Acronym of Words **

// Optimal Solution =>
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if(words.size() != s.length()) return false;
        for(int i = 0; i < words.size(); i++){
            if(words[i][0] != s[i]) return false;
        } 
        return true;
    }
};

// First, check whether the number of words
// equals the length of the given string.
//
// Then, compare the first character of each word
// with the corresponding character in the string.
//
// If any character does not match, return false.
// If all characters match, return true.