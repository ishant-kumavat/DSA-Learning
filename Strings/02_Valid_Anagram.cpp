// LeetCode 242 => ** Valid Anagram **

// 1). Brute Force Approach => Use Sort technique
//     Time Complexity : O(n log n)
//     Space Complexity :O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n != m) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t) return true;
        return false;
    }
};

// 2). Optimal Solution => Character Frequency Counting
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n != m) return false;
        vector<int> hashArr(26, 0);
        for(int i = 0; i < n; i++){
            int pos = s[i] - 'a';
            hashArr[pos]++;
        }
        for(int i = 0; i < m; i++){
            int pos = t[i] - 'a';
            hashArr[pos]--;
            if(hashArr[pos] < 0) return false;
        }
        return true;
    }
};

// Here Space Complexity is constant because we are using constant 26 memory space.
// Count the frequency of each character.
// Increment for s and decrement for t.
// If any frequency becomes negative, return false.