// LeetCode 74 => ** Search a 2D Matrix **

// 1). Brute Force Approach : Linear Search in each row.
//     Time Complexity : O(n * m)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == target) return true;
            }
        }
        return false;
    }
};

// 2). Better Solution : Apply Binary Search in each row 
//     Time Complexity : O(n * log m)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++){
            int low = 0, high = m - 1;
            while(low <= high){
                int mid = (low + high) / 2;
                if(matrix[i][mid] == target) return true;
                else if(matrix[i][mid] > target) high = mid - 1;
                else low = mid + 1;
            }
        }
        return false;
    }
};

// 3). Optimal Solution : Using small observation
//     Time Complexity : O(n + log m)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < n; i++){
            if(matrix[i][0] <= target && target <= matrix[i][m - 1]){
                int low = 0, high = m - 1;
                while(low <= high){
                    int mid = (low + high) / 2;
                    if(matrix[i][mid] == target) return true;
                    else if(matrix[i][mid] > target) high = mid - 1;
                    else low = mid + 1;
                }
                return false;
            }
        }
        return false;
    }
};

// 4). Most Optimal Approach : Apply Binary Search on entire Array
//     Time Complexity : O(log(m * n))
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0, high = (n * m) - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int row = mid / m, col = mid % m;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};