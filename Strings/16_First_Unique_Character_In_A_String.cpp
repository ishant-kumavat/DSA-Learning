// LeetCode 387 => ** First Unique Character in a String **

// 1). Better Solution => Hash Map
//     Time Complexity : O(n) 
//     Space Complexity : O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mpp;
        for(auto it : s) mpp[it]++;
        for(int i = 0; i < s.length(); i++){
            if(mpp[s[i]] == 1) return i;
        }
        return -1;
    }
};
// Count the frequency
// of every character
// using a hash map.
//
// Traverse the string again.
// The first character
// with frequency 1
// is the answer.
//
// If no such character exists,
// return -1.

// 2). Optimal Solution => Frequency Array
//     Time Complexity : O(n)
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> hasharr(26, 0);
        int n = s.length();
        for(auto it : s) hasharr[it - 'a']++;
        for(int i = 0; i < n; i++){
            if(hasharr[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
// Count the frequency
// of each lowercase letter
// using a frequency array.
//
// Traverse the string again.
// The first character
// with frequency 1
// is the answer.
//
// If no unique character exists,
// return -1.