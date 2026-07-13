// LeetCode 8 => ** String to Integer (atoi) **

// Optimal Solution =>
// Time Complexity : O(n)
// Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        if(n == 0) return 0;
        int j;
        for(j = 0; j < n; j++){
            if(s[j] == ' ') continue;
            else break;
            
        }
        if(j == n) return 0;
        int sign = 1;
        if(s[j] == '-') sign = -1; 
        int i = (s[j] == '-' || s[j] == '+') ? (j+ 1) : j;
        long long ans = 0;
        while(i < n){
            if(s[i] >= '0' && s[i] <= '9'){
                ans = (ans * 10) + (s[i] - '0');
                if(ans > INT_MAX && sign == -1) return INT_MIN;
                if(ans > INT_MAX && sign == 1) return INT_MAX;
            }
            else break;
            i++;
        }
        if(sign == -1) return int(-ans);
        return int(ans);
    }
};
// Skip leading spaces.
// Check for an optional sign (+/-).
// Convert consecutive digits into an integer.
// Stop at the first non-digit character.
// Clamp the result if it exceeds the integer range.