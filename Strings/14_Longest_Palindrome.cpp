// LeetCode 409 => ** Longest Palindrome **

//  Optimal Solution => Character Frequency Counting
//  Time Complexity : O(n)
//  Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        int mx = 0;
        vector<int>hasharr(123, 0);
        for(int i = 0; i < s.length(); i++){
            hasharr[s[i]]++;
        }
        int hasOdd  = 0;
        for(auto it : hasharr){
            if(it % 2 == 0) mx += it;
            else{
                mx += (it - 1);
                hasOdd  = 1; 
            }
        }
        if(hasOdd  == 1) return (mx + 1);
        return mx;
    }
};
// Count the frequency of each character.
// Add all even frequencies completely.
// For odd frequencies, add (frequency - 1).
// If any odd frequency exists,
// place one character at the center.

// Optimal Solution => Frequency Counting (Single Traversal)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        int mx = 0, unpaired = 0;
        vector<int>hasharr(123, 0);
        for(int i = 0; i < s.length(); i++){
            hasharr[s[i]]++;
            if(hasharr[s[i]] % 2 == 0){
                mx += hasharr[s[i]];
                hasharr[s[i]] = 0; unpaired--;
            }
            else unpaired += 1;
        }
        if(unpaired != 0) return (mx + 1);
        return mx;
    }
};
// Count frequencies while traversing the string.
// Whenever a frequency becomes even,
// add the pair to the answer.
// If any unpaired character remains,
// place one at the center.