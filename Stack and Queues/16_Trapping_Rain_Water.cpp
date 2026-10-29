// LeetCode 42 => ** Trapping Rain Water **

// Optimal Solution => Two Pointers
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l = 0, r = n - 1;
        int left_max = 0, right_max = 0;

        while(l < r){
            left_max = max(left_max, height[l]);
            right_max = max(right_max, height[r]);

            if(left_max < right_max){
                ans += (left_max - height[l]);
                l++;
            }
            else{
                ans += (right_max - height[r]);
                r--;
            }
        } 
        return ans;
    }
};

// Use two pointers: `l` and `r`.
// `left_max` stores the maximum height seen from the left.
// `right_max` stores the maximum height seen from the right.
//
// Update both maximum heights in each iteration.
//
// If `left_max < right_max`, calculate trapped water
// at index `l` and move `l` forward.
// Otherwise, calculate trapped water at index `r`
// and move `r` backward.
//
// Time Complexity : O(n)
// Space Complexity : O(1)