// LeetCode 1903 => ** Largest Odd Number in String **

// 1). Optimal Solution =>
//     Time Complexity : O(n)
//     Space Complexity :O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        for(int i = n - 1; i >= 0; i--){
            if((num[i] - '0') % 2 != 0){
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};

// Traverse the string from right to left.
// The first odd digit found marks the end of the largest odd-numbered prefix.
// Return the substring from index 0 to that position.
// If no odd digit exists, return an empty string.