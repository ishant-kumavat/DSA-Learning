// LeetCode 85 => ** Maximal Rectangle **

// Optimal Solution => Histogram + Two-Pass Monotonic Stack (NSL + NSR)
// Time Complexity : O(rows * cols)
// Space Complexity : O(cols)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    int next_smaller_ele(vector<int>& vec, int n){
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && vec[st.top()] >= vec[i]) st.pop();
            if(!st.empty()) left[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && vec[st.top()] >= vec[i]) st.pop();
            if(!st.empty()) right[i] = st.top();
            st.push(i);
        }

        int mx = 0;

        for(int i = 0; i < n; i++){
            int width = (i - left[i]) + (right[i] - i) - 1;
            int height = vec[i];

            mx = max(mx, (width * height));
        }

        return mx;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        vector<int> vec(n, 0);
        int ans = 0;

        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '0') vec[j] = 0;
                else vec[j] += 1;  
            }
            int temp = next_smaller_ele(vec, n);
            ans = max(ans, temp);
        } 

        return ans;
    }
};

// Convert each row into a histogram.
//
// For every row:
// If the current cell is '0', reset its height to 0.
// Otherwise, increment its height.
//
// Find Next Smaller to Left (NSL) and
// Next Smaller to Right (NSR) for every histogram bar.
//
// Calculate width = NSR - NSL - 1.
// Calculate area = height * width.
//
// Update the maximum rectangle area for every row.
//
// Return the maximum area.