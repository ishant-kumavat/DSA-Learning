// LeetCode 2490 => ** Circular Sentence **

// Optimal Solution => String Traversal + Character Comparison
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length();

        for(int i = 0; i < n; i++){
            if(sentence[i] == ' '){
                if(sentence[i - 1] != sentence[i + 1]) return false;
            }
        }

        return sentence[0] == sentence[n - 1];
    }
};

// Traverse the sentence and find every space.
//
// Compare the last character of the previous word
// with the first character of the next word.
//
// If both characters are different, return false.
//
// Finally, compare the first character of the sentence
// with the last character to check circularity.