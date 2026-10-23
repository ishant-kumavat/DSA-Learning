// LeetCode 239 => ** Sliding Window Maximum **

// 1). Brute Force Approach => Recalculate Maximum for Every Window
//     Time Complexity : O(n * k)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int find_max_in_given_range(vector<int>& nums, int i, int j){
        int ans = INT_MIN;
    
        for(int k = i; k <= j; k++){
            ans = max(ans, nums[k]);
        }
    
        return ans;
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
    
        for(int i = 0; i < n; i++){
            if((i + k - 1) >= n) break; 
            int x = find_max_in_given_range(nums, i, i + k - 1);
            res.push_back(x);
        }
    
        return res;
    }
};

// 2). Better Approach => Reuse Previous Window Maximum
//     Time Complexity : O(n * k) worst case
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> find_max_in_given_range(vector<int>& nums, int i, int j){
        int mx = INT_MIN, idx = -1;
    
        for(int k = i; k <= j; k++){
            if(nums[k] > mx){
                mx = nums[k];
                idx = k;
            }
        } 
    
        return {mx, idx};
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        int mx_idx = -1, mx = INT_MIN; 
    
        for(int i = 0; i < n; i++){
            if((i + k - 1) >= n) break;
            if(mx_idx == -1 || (i - 1) == mx_idx) {
                vector<int> temp = find_max_in_given_range(nums, i, i + k - 1);
                mx = temp[0];
                mx_idx = temp[1];
            }
            else{
                int idx = i + k - 1;
                if(mx < nums[idx]) {mx = nums[idx]; mx_idx = idx;}
            }
            res.push_back(mx);
        }
    
        return res;
    }
};

// 3). Optimal Approach => Monotonic Deque (Decreasing Order of Values)
//     Time Complexity : O(n)
//     Space Complexity : O(k)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            while(!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            
            dq.push_back(i);
            
            if(i >= k - 1) 
                res.push_back(nums[dq.front()]);
        }
        
        return res;
    }
};

// Store indices in a deque, maintaining decreasing order of values.
// Remove expired indices from the front.
// Remove smaller elements from the back.
// The front of the deque gives the maximum of the current window.