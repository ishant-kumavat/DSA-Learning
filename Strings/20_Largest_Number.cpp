// LeetCode 179 => ** Largest Number **

// Optimal Solution => Custom Comparator + Sorting
// Time Complexity : O(n * k * log n)
// Space Complexity : O(n * k)
// where, n = number of elements
//        k = maximum number of digits in a number

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string s;
        vector<string> vec;
        int flag = 0;
        for(auto it : nums) {vec.push_back(to_string(it)); if(it != 0) flag = 1;}

        if(flag == 0) return "0";
        sort(vec.begin(), vec.end(), [](const string& a, const string& b){
            return a + b > b + a;
        });

        for(auto it : vec) s += it;
        return s;
    }
};
// For two numbers `a` and `b`,
// place `a` before `b` if `a + b > b + a`.
//
// This ensures the concatenation
// produces the largest possible number.

// Example: "9" + "34" = "934" > "349" = "34" + "9"
// So "9" should come before "34".