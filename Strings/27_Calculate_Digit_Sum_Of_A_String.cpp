// LeetCode 2243 => ** Calculate Digit Sum of a String **

// Optimal Solution => Simulation + String Processing
// Time Complexity : O(n)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string round(string s, int k){
        int x = 0, cnt = 0;
        string ans = "";
        
        for(auto it : s){
            if(cnt == k){
                ans += to_string(x);
                cnt = 0, x = 0;
            }
            x += (it - '0');
            cnt ++;
        }
        
        ans += to_string(x);
        
        return ans;
    }

    string digitSum(string s, int k) {
        if(k == 1) return s;
    
        string temp = s;
        
        while(temp.length() > k){
            temp = round(temp, k);
        }
        
        return temp;
    }
};

// Simulation + String Processing
//
// Divide the string into groups of k consecutive digits.
// Calculate the sum of digits in each group and append
// the sum to a new string.
//
// Repeat this process until the string length
// becomes less than or equal to k.
//
// Return the final string.