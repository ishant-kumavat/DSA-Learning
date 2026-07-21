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
//     Time Complexity : O(log n) Average, O(n) Worst Case
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target) return true;
            else if(nums[low] == nums[high]){
                if(nums[low] == target) return true;
                low++;high--;
            }
            else if(nums[low] <= nums[mid]){
                if(nums[low] <= target && nums[mid] >= target) high = mid - 1;
                else low = mid + 1;
            }
            else{
                if(nums[mid] <= target && nums[high] >= target) low = mid + 1;
                else high = mid - 1;
            } 
        }
        return false;
    }
};
// Apply binary search as in
// Search in Rotated Sorted Array I.
// At each step, identify
// the sorted half and
// discard the other half.
// If nums[low] == nums[mid] == nums[high],
// duplicates make it impossible
// to identify the sorted half,
// so shrink the search space
// using low++ and high--.