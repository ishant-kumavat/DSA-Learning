// LeetCode 35 => ** Search Insert Position **

// 1). Brute Force Approach => Linear Search
//     Time Complexity : O(n)
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] >= target) return i;
        }
        return n;
    }
};
// Traverse the array from left to right.
// Return the first index
// where the element is
// greater than or equal to the target.
// If no such index exists,
// return the array size,
// which is the insert position
// at the end.

// 2). Optimal Solution => Lower Bound (Binary Search)
//     Time Complexity : O(log n)
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};
// Use binary search to find
// the first position where
// the target can be inserted.
// The final value of 'low'
// is the required index.