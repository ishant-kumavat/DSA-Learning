// LeetCode 796 => ** Rotate String **

// 1). Brute Force Approach => Using rotate function
//     Time Complexity : O(n^2)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        if(n != m) return false;
        for(int i = 0; i < n; i++){
            rotate(s.begin(), s.begin() + 1, s.end());
            if(s == goal) return true;
        }
        return false;
    }
};
// rotate(first, middle, last)
// 'middle' becomes the new first element.

// 2). Optimal Solution =>  
//     Time Complexity : O(n)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        if(n != m) return false;
        if((s + s).find(goal) != string::npos) return true;
        return false;
    }
};
// Concatenate the string with itself.
// Every possible rotation of the string
// appears as a substring of (s + s).