// LeetCode 3136 => Valid Word

// Optimal Solution => Character Checking
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;

        bool vowel = false, consonant = false;

        for(char ch : word) {
            if(!isalnum(ch)) return false;

            if(isdigit(ch)) continue;

            ch = tolower(ch);

            if(ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u') {
                vowel = true;
            }
            else {
                consonant = true;
            }
        }

        return vowel && consonant;
    }
};

// Check whether the word contains at least 3 characters.
//
// Traverse each character of the string:
// 1. If the character is not alphanumeric, return false.
// 2. If it is a digit, skip it.
// 3. Convert the character to lowercase.
// 4. If it is a vowel, mark vowel = true.
// 5. Otherwise, mark consonant = true.
//
// A valid word must contain at least one vowel
// and at least one consonant.
//
// Return true if both conditions are satisfied.