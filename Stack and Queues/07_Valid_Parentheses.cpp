// LeetCode 20 => ** Valid Parentheses **

// Optimal Solution =>
// Time Complexity : O(n)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
// LeetCode 20 => ** Valid Parentheses **

// Optimal Solution =>
// Time Complexity : O(n)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto &it : s){
            if(it == '(' || it == '[' || it == '{') st.push(it);
            else {
                if(!st.empty() && ((st.top() == '(' && it == ')') || (st.top() == '[' && it == ']') || (st.top() == '{' && it == '}'))) st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};

// Push every opening bracket into the stack.
//
// For every closing bracket:
// - If the stack is empty -> invalid.
// - If the top bracket matches -> pop it.
// - Otherwise -> invalid.
//
// At the end, the stack must be empty
// for the parentheses to be valid.