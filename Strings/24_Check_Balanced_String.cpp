// LeetCode 3340 => ** Check Balanced String **

// Optimal Solution => Even–Odd Index Sum
// Time Complexity : O(n) 
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isBalanced(string num) {
        int even = 0; 
        int odd = 0;
        for(int i = 0; i < num.length(); i++){
            if(i % 2 == 0) even += int(num[i] - '0');
            else odd += int(num[i] - '0');
        } 
        return (even == odd);
    }
};

// Traverse the string and convert each character
// into its numeric digit by subtracting '0'.
//
// Add digits at even indices to `even`.
// Add digits at odd indices to `odd`.
//
// If both sums are equal, return true.
// Otherwise, return false.