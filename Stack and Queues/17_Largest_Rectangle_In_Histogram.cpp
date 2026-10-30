// LeetCode 84 => ** Largest Rectangle in Histogram **

// 1). Better Solution => Two-Pass Monotonic Stack
//     Time Complexity : O(n)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> find_next_smaller_to_right(vector<int>& arr, int n){
        stack<int> st;
        vector<int> res(n, n);
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()) res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    
    vector<int> find_next_smaller_to_left(vector<int>& arr, int n){
        stack<int> st;
        vector<int> res(n, -1);
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()) res[i] = st.top();
            st.push(i);
        }
        return res;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        vector<int> arr1 = find_next_smaller_to_right(heights, n);
        vector<int> arr2 = find_next_smaller_to_left(heights, n);

        for(int i = 0; i < n; i++){
            int width = (arr1[i] - arr2[i] - 1);
            int height = heights[i];
            ans = max(ans, (width * height));
        }
        return ans;
    }
};

// 2). Optimal Solution => One-Pass Monotonic Stack
//     Time Complexity : O(n)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int ele = heights[st.top()];
                st.pop();
                int nsl = (!st.empty()) ? st.top() : -1;
                int nsr = i;
                ans = max(ans, (ele * (nsr - nsl - 1)));
            }
            st.push(i);
        }

        while(!st.empty()){
            int nsr = n;
            int ele = heights[st.top()];
            st.pop();
            int nsl = (!st.empty()) ? st.top() : -1;
            ans = max(ans, (ele * (nsr - nsl - 1)));
        }

        return ans;
    }
};

// Maintain a monotonic increasing stack of indices.
//
// Traverse the histogram from left to right.
// If the current height is smaller than the height
// at the stack's top, pop the index and calculate its area.
//
// The popped element's height is the rectangle height.
// The current index is the Next Smaller to Right (NSR).
// The new stack top is the Next Smaller to Left (NSL).
// If the stack is empty, NSL = -1.
//
// After traversal, process all remaining indices
// by considering n as the right boundary.
//
// Update the maximum rectangle area at each step.
//
// Time Complexity : O(n)
// Space Complexity : O(n)