// LeetCode 1283 => ** Find the Smallest Divisor Given a Threshold **

// 1). Brute Force Approach : Linear Search
//     Time Complexity : O(mx * n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int mx = INT_MIN; 
        for(int i = 0; i < n; i++) mx = max(mx, nums[i]); 
        for(int i = 1; i <= mx; i++){
            long long add = 0;
            for(int j = 0; j < n; j++){
                add = add + ceil((double)nums[j] / (double)i);
            }
            if(add <= threshold) return i;
        }
        return -1;
    }
};

// 2). Optimal Solution => Binary Search
//     Time Complexity : O(n * log(mx))
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int cal_cnt(vector<int>& nums, long long mid){
        long long add = 0;
        for(int i = 0; i < nums.size(); i++){
            add = add + ceil((double)nums[i] / (double)mid);
        }
        return (int)add;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int mx = INT_MIN; 
        for(int i = 0; i < n; i++) mx = max(mx, nums[i]); 
        long long low = 1, high  = mx;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            int cnt = cal_cnt(nums, mid);
            if(cnt > threshold) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};

// ceil(a / b) = (a + b - 1) / b

// The answer lies between 1 and the maximum element.
// If a divisor satisfies the threshold,
// every larger divisor will also satisfy it.
// Hence, Binary Search can be applied.