// LeetCode 277 => ** Find then Celebrity **

// 1). Brute Force Approach =>
//     Time Complexity : O(n ^ 2)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        
        for(int i = 0; i < n; i++){

            int flag = 1; 

            for(int j = 0; j < n; j++){
                
                if(i == j) continue;
                
                if(mat[i][j] != 0 || mat[j][i] != 1){
                    flag = 0; break;
                }
            }

            if(flag) return i;
        }

        return -1;
    }
};

// 2). Optimal Approach => Stack + Elimination
//     Time Complexity : O(n)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        
        stack<int> st;

        for(int i = 0; i < n; i++) st.push(i);

        while(st.size() > 1){
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();

            if(mat[x][y] == 0) st.push(x);
            else st.push(y);
        }

        int ans = st.top();

        for(int i = 0; i < n; i++){
            if(ans == i) continue;
            if(mat[ans][i] != 0 || mat[i][ans] != 1) return -1;
        }

        return st.top();
    }
};

// 3). Optimal Approach => Two Pointers
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int st = 0, ed = n - 1;

        while(st < ed){
            if(mat[st][ed] == 0) ed --;
            else st ++;
        }

        for(int j = 0; j < n; j++){
            if(st == j) continue;

            if(mat[st][j] != 0 || mat[j][st] != 1){
                return -1;
            }
        }

        return st;
    }
};

// Use two pointers to find the potential celebrity.
//
// If st knows ed, st cannot be the celebrity.
// Otherwise, ed cannot be the celebrity.
//
// Continue until only one potential candidate remains.
//
// Verify that the candidate knows nobody and
// everyone else knows the candidate.
//
// Return the candidate if valid; otherwise, return -1.