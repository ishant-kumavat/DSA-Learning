// LeetCode 34 => ** Find First and Last Position of Element in Sorted Array **

// 1). Brute Force Approach => Linear Search
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int st = -1, ed = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                if(st == -1) st = i;
                ed = i;
            }
        }
        return {st, ed};
    }
};

// 2). Optimal Approach => Binary Search
//     Time Complexity : O(log n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLast(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return low - 1;
    }
    int findFirst(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        bool f = false;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] < target) low = mid + 1;
            else{
                if(nums[mid] == target) f = true;
                high = mid - 1;
            }
        }
        if(f == false) return -1;
        return high + 1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int st = findFirst(nums, target);
        if(st == -1) return {-1, -1};
        int ed = findLast(nums, target);
        return {st, ed};
    }
};

// Find first occurrence using lower bound logic
// Find last occurrence using upper bound logic