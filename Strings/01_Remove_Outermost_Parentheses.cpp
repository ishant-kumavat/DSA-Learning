// LeetCode 1021 => ** Remove Outermost Parentheses **

// 1). Optimal Solution => Parentheses Depth Counting
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        int n = s.length();
        string ans;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){ 
                cnt ++;
                if(cnt == 1) continue;
                ans.push_back(s[i]);
            }
            else{
                cnt --;
                if(cnt == 0) continue;
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};

// Count the current parentheses depth.
// Skip the first '(' of every primitive (depth becomes 1)
// and skip the last ')' of every primitive (depth becomes 0).
// Add all remaining parentheses to the answer.