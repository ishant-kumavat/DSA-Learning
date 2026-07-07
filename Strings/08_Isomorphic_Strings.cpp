// LeetCode 205 => ** Isomorphic Strings **

// 1). Using Map
//     Time Complexity : O(n)
//     Space Complexity : O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length(), m = t.length();
        if(n != m) return false;
        unordered_map<char, char> mpp1;
        unordered_map<char, char> mpp2;
        mpp1[s[0]] = t[0];
        mpp2[t[0]] = s[0];
        for(int i = 0; i < n; i++){
            if(mpp1.count(s[i])){
                char x = mpp1[s[i]];
                if(x != t[i]) return false;
            }
            if(mpp2.count(t[i])){
                char x = mpp2[t[i]];
                if(x != s[i]) return false;
            }
            mpp1[s[i]] = t[i];
            mpp2[t[i]] = s[i];
        }
        return true;
    }
};
// Maintain two mappings:
// s -> t and t -> s.
// If either mapping becomes inconsistent,
// the strings are not isomorphic.

// 2). Using Hash Array
//     Time Complexity : O(n)
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int>arr1(128, -1);
        vector<int>arr2(128, -1);
        for(int i = 0; i < s.length(); i++){
            if(arr1[s[i]] != arr2[t[i]]) return false;
            arr1[s[i]] = arr2[t[i]] = i;
        }
        return true;
    }
};
// Store the last seen index of every character.
// If the last occurrence of s[i] and t[i]
// does not match, the mapping is invalid.