// LeetCode 1901 => ** Find a Peak Element II **

// 1). Brute Force Approach =>
//     Time Complexity : O(n * m)
//     Space Complexity : O(1)

// Brute Force is straightforward.
// Traverse every element and check all four neighbours.
// If an element is greater than all its valid neighbours, return its index.

// 2). Alternative Approach : Find Largest element and return it's indices. 
//     Time Complexity : O(n * m)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = -1, st = -1, ed = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] > ans){
                    ans = mat[i][j];
                    st = i; ed = j;
                }
            }
        }
        return {st, ed};
    }
};

// 3). Optimal Approach : Binary Search 
//     Time Complexity : O(n * log m)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Find_Idx(vector<vector<int>>& mat, int n, int m, int mid){
        int ans = INT_MIN, idx = -1;
        for(int i = 0; i < n; i++){
            if(mat[i][mid] > ans){
                ans = mat[i][mid];
                idx = i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            int idx = Find_Idx(mat, n, m, mid);
            int left = ((mid - 1) >= 0) ? mat[idx][mid - 1] : -1;
            int right = ((mid + 1) < m) ? mat[idx][mid + 1] : -1;
            if(left < mat[idx][mid] && right < mat[idx][mid]) return {idx, mid};
            else if(left > mat[idx][mid]) high = mid - 1;
            else low = mid + 1;
        }
        return {-1, -1};
    }
};

// Apply Binary Search on columns.
// For every middle column, find the row having the maximum element.
// Compare this element with its left and right neighbours.
// If it is greater than both, it is a peak.
// Otherwise move towards the larger neighbour.