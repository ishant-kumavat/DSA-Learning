// LeetCode 42 => ** Trapping Rain Water **

// Optimal Solution => Two Pointers
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int st = 0, ed = 0;
        while(st < n && height[st] == 0) st ++;
        if(st >= n) return 0;
        ed = st + 1;
        while(st < n && ed < n){
            int cnt = 0;
            int nextgreater = INT_MIN, me = -1;
            while(ed < n && height[st] > height[ed]) {
                cnt += (height[st] - height[ed]);
                if(height[ed] >= nextgreater){nextgreater = height[ed]; me = ed;}
                ed ++;
            }
            if(ed < n){
                ans += cnt;
                st = ed++;
            }
            else{
                ed = st + 1;
                while(ed != me){
                    ans += (nextgreater - height[ed]);
                    ed ++;
                }
                st = me;
            }
        }
        return ans;
    }
};