// LeetCode 503 => ** Next Greater Element II **

// Optimal Solution =>
// Time Complexity : O(n)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);
        for(int i = 2 * n - 1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i % n]) st.pop();
            if(!st.empty() && i < n) ans[i] = nums[st.top()];
            st.push(i % n);
        }
        return ans;
    }
};

// Traverse the array twice to simulate
// the circular nature of the array.
//
// Use a monotonic decreasing stack
// to find the next greater element.
//
// `i % n` maps the virtual index back
// to the original array index.
//
// Traverse from right to left:
// - Remove all smaller or equal elements.
// - Stack top becomes the next greater element.
// - For the second traversal, only update
//   the actual answer indices (i < n).