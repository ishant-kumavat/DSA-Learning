// LeetCode 240 => ** Search a 2D Matrix II **

// 1). Brute Force Approach => Linear Search
//     Time Complexity : O(n * m)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == target) return true;
            }
        } 
        return false;
    }
};

// 2). Better Solution => Binary Search
//     Time Complexity : O(n * log m)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < n; i++){
            int low = 0, high = m - 1;
            while(low <= high){
                int mid = (low + high) / 2;
                if(mat[i][mid] == target) return true;
                else if(mat[i][mid] > target) high = mid - 1;
                else low = mid + 1; 
            }
        }
        return false;
    }
};

// 3). Optimal Solution => Elimination Technique
//     Time Complexity : O(m + n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        int i = 0, j = m - 1;
        while(i < n && j >= 0){
            if(mat[i][j] == target) return true;
            else if(mat[i][j] > target) j--;
            else i++;
        }
        return false;
    }
};

// Matrix is not fully sorted.
// Each row is sorted from left to right,
// and each column is sorted from top to bottom.
// Start from the top-right corner.
// If current element > target, move left.
// If current element < target, move down.
// This eliminates one row or one column in every step.