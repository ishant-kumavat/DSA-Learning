// LeetCode 410 => **  Split Array Largest Sum **

// 1). Brute Force Approach => Linear Search
//     Time Complexity : O((sum - max + 1) * n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Number_Of_Split(vector<int>& nums, long long a){
        int cnt = 1;
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] <= a){
                sum += nums[i];
            }
            else{
                cnt++;
                sum = nums[i];
            }
        }
        return cnt;
    }
    vector<long long> Find_low_high(vector<int>& nums){
        long long low = INT_MIN, high = 0;
        for(int i = 0; i < nums.size(); i++){
            low = max((int)low, nums[i]);
            high += nums[i];
        }
        return {low, high};
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans = Find_low_high(nums);
        long long low = ans[0];
        long long high = ans[1], i;
        for(i = low; i <= high; i++){
            int x = Number_Of_Split(nums, i); 
            if(x <= k) return (int)i;
        }
        return -1;
    }
};

// 2). Optimal Solution => Binary Search
//     Time Complexity : O(n * log (sum - max + 1))
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Number_Of_Split(vector<int>& nums, long long a){
        int cnt = 1;
        long long sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] <= a){
                sum += nums[i];
            }
            else{
                cnt++;
                sum = nums[i];
            }
        }
        return cnt;
    }
    vector<long long> Find_low_high(vector<int>& nums){
        long long low = INT_MIN, high = 0;
        for(int i = 0; i < nums.size(); i++){
            low = max((int)low, nums[i]);
            high += nums[i];
        }
        return {low, high};
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans = Find_low_high(nums);
        long long low = ans[0];
        long long high = ans[1];
        while(low <= high){
            long long mid = low + (high - low) / 2;
            int x = Number_Of_Split(nums, mid);
            if(x > k) low = mid + 1;
            else high = mid - 1; 
        }
        return low;
    }
};

// Same pattern as Book Allocation Problem.
// Minimize the maximum subarray sum.