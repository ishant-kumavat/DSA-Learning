// LeetCode 1047 => ** Remove All Adjacent Duplicates In String **

// 1). Approach 1 => Stack
//     Time Complexity : O(n)
//     Space Complexity : O(n) 

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(auto &it : s){
            if(!st.empty() && st.top() == it) st.pop();
            else st.push(it);
        }
        string ans = "";
        while(!st.empty()) {ans.push_back(st.top()); st.pop();}
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// 2). Approach 2 => String as Stack
//     Time Complexity : O(n)
//     Space Complexity : O(n) 

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        for(auto &it : s){
            if(!ans.empty() && ans.back() == it) ans.pop_back();
            else ans += it;
        }
        return ans;
    }
};

// Treat the string `ans` as a stack.
//
// If the current character matches the last character
// of `ans`, remove the last character.
//
// Otherwise, add the current character to `ans`.
//
// This automatically removes adjacent duplicates,
// including duplicates formed after previous removals.