// LeetCode 1539 => ** Kth Missing Positive Number **

// 1). Brute Force Approach => Linear Search
//     Time Complexity : O(max(nums[n - 1], k))
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int num = 1;
        while(i < n && k > 0){
            if(nums[i] == num) i++;
            else k--;
            num++;
        }
        while(k--) num++;
        return num-1;
    }
};

// 2). Optimal Solution => Using Binary Search
//     Time Complexity : O(log n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            int mis = nums[mid] - (mid + 1);
            if(mis < k) low = mid + 1;
            else high = mid - 1;
        } 
        return (low + k);
    }
};

// Missing numbers before index i = nums[i] - (i+1)