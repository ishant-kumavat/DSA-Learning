// LeetCode 162 => ** Find Peak Element **

// 1). Brute Force Approach => Linear Search 
//     Time Complexity : O(n)
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || nums[0] > nums[1]) return 0;
        if(nums[n - 1] > nums[n - 2]) return (n - 1);
        for(int i = 1; i < n - 1; i++){
            if(nums[i] > nums[i + 1] && nums[i] > nums[i - 1]) return i;
        } 
        return -1;
    }
};
// Check the first and last elements separately.
// Then linearly search for an element
// greater than both of its neighbors.

// 2). Optimal Approach => Binary Search 
//     Time Complexity : O(log n)
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || nums[0] > nums[1]) return 0;
        if(nums[n - 1] > nums[n - 2]) return (n - 1);
        int low = 1, high = n - 2;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) return mid;
            else if(nums[mid] < nums[mid + 1]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};
// Check the boundary elements first.
// Use binary search to find a peak.
// If the right neighbor is larger,
// the peak lies on the right;
// otherwise, it lies on the left.