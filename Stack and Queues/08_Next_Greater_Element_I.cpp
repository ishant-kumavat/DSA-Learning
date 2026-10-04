// LeetCode 496 => ** Next Greater Element I **

// 1). Brute Force Approach => Linear Search
//     Time Complexity : O(n² + m)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        int n = nums2.size();
        for(int i = 0; i < n; i++){
            bool flag = false;
            for(int j = i + 1; j < n; j++){
                if(nums2[i] < nums2[j]) {mpp[nums2[i]] = nums2[j]; flag = true; break;}
            }
            if(!flag) mpp[nums2[i]] = -1;
        }
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++){
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};

// 2). Optimal Approach => Monotonic Stack
//     Time Complexity : O(n)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int, int> mpp;
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && nums2[st.top()] < nums2[i]) st.pop();
            mpp[nums2[i]] = (!st.empty()) ? nums2[st.top()] : -1 ;  
            st.push(i);
        }
        vector<int> ans;
        for(auto &it : nums1){
            ans.push_back(mpp[it]);
        }
        return ans;
    }
};

// Traverse nums2 from right to left.
//
// Stack stores indices of elements
// that can be the next greater element.
//
// Remove all smaller elements from the stack,
// because they cannot be the next greater element
// for the current element.
//
// After removing smaller elements:
// - Stack empty -> no greater element -> -1
// - Otherwise, stack top is the next greater element.
//
// Store the answer in a hash map for nums1 lookup.