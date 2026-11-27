// LeetCode 455 => ** Assign Cookies **

// Optimal Approach => Sorting + Greedy (Two Pointers)
// Time Complexity : O(n log n + m log m)
// Space Complexity : O(1) auxiliary space (excluding sorting)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();

        int ans = 0;
        int j = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        for(int i = 0; i < m; i++){
            if(j < n && g[j] <= s[i]){
                ans ++; j++;
            }
            
        }

        return ans;
    }
};

// Sort both arrays in ascending order.
//
// Use two pointers:
// i -> Tracks the current child.
// j -> Tracks the current cookie.
//
// If the current cookie can satisfy the child,
// move i to the next child.
//
// Always move j to the next cookie.
//
// Return the number of satisfied children.