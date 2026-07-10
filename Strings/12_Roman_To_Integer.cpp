// LeetCode 13 => ** Roman to Integer **

// Optimal Solution =>
// Time Complexity : O(n)
// Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        vector<int>hasharr(91, 0);
        hasharr['I'] = 1;
        hasharr['V'] = 5;
        hasharr['X'] = 10;
        hasharr['L'] = 50;
        hasharr['C'] = 100;
        hasharr['D'] = 500;
        hasharr['M'] = 1000;
        int res = 0;
        int prev = 0;
        for(int i = n - 1; i >= 0; i--){
            int temp = hasharr[s[i]];
            if(temp < prev) res -= temp;
            else res += temp;
            prev = temp;
        }
        return res;
    }
};
// Traverse the Roman numeral from right to left.
// If the current symbol is smaller than the previous symbol,
// subtract its value; otherwise, add it.
// This handles cases like IV, IX, XL, CM, etc.