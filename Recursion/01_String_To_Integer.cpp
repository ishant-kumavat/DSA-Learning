// LeetCode 8 => ** String to Integer (atoi) **

// 1). Optimal Solution => Iterative Solution
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        int sign = 1;
        while(i < n && s[i] == ' ') i++;
        if(i < n && s[i] == '-') {sign = -1; i++;}
        else if(i < n && s[i] == '+') i++;
        int ans = 0;
        while(i < n){
            if(s[i] >= '0' && s[i] <= '9') {
                long long x = ((long long)ans * 10) + int(s[i] - '0');
                if(sign == -1 && -x <= INT_MIN) return INT_MIN;
                if(x > INT_MAX) return INT_MAX;
                ans = x;
            }
            else break;
            i++;
        }
        return ans * sign;
    }
};

// 2). Recursive Approach => Recursive Solution
//     Time Complexity : O(n)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findStringToInt(string &s,int i, long long ans, int sign){
        if(i >= s.length() || !isdigit(s[i])) return int(ans * sign);
        ans = (ans * 10) + (s[i] - '0');
        if(sign == -1 && -ans <= INT_MIN) return INT_MIN;
        if(ans > INT_MAX) return INT_MAX;
        i += 1;
        return findStringToInt(s, i, ans, sign);
    }
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        while(i < n && s[i] == ' ') i++;
        int sign = 1;
        if(i < n && s[i] == '+') i++; 
        else if(i < n && s[i] == '-') {sign = -1; i++;} 
        return findStringToInt(s, i, 0, sign);
    }
};