// LeetCode 2586 => ** Count the Number of Vowel Strings in Range **

// Optimal Solution => Linear Scan + Vowel Check
// Time Complexity : O(right - left + 1)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool IsVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
        return false;
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int cnt = 0;
        for(int i = left; i <= right; i++){
            if(IsVowel(words[i].front()) && IsVowel(words[i].back())) cnt ++;
        }
        return cnt;
    }
};

// Traverse only the given range [left, right].
//
// For every word:
// - Check its first character.
// - Check its last character.
//
// If both are vowels,
// the word is a valid vowel string.
//
// Increment the count.
//
// Return the total count.