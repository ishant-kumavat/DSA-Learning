// LeetCode 81 => ** Search in Rotated Sorted Array II **

// 1). Brute Force Approach => Linear Search
//     Time Complexity : O(n)
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == target) return true;
        }
        return false;
    }
};

// 2). Optimal Approach => Binary Search
//     Time Complexity : O(log n)
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
