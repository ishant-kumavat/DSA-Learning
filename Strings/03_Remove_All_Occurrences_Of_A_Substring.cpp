// LeetCode 1910 => ** Remove All Occurrences of a Substring **

// 1). Optimal Solution :  Using find() and erase()
//     Time Complexity : O(n^2)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length() > 0 && s.find(part) < s.length()){
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

// Keep removing the first occurrence of 'part'
// until it no longer exists in the string.