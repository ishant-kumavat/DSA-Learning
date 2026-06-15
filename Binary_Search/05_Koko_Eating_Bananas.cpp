// LeetCode 875 -> ** Koko Eating Bananas **

// 1). Brute Force Approach => Using Linear Search
//     Time Complexity : O(mxi * n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long cal_h(vector<int>& piles,int mid){
        long long x = 0;
        for(int i = 0;i < piles.size();i++){
            long long a = (piles[i] + mid - 1) / mid;
            x += a;
        }
        return x;
    }
    int lar_el(vector<int>& piles){
        int ans = INT_MIN;
        for(int i = 0;i < piles.size();i++) ans = max(ans,piles[i]);
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int mxi = lar_el(piles);
        for(int i = 1;i <= mxi;i++){
            long long x = cal_h(piles , i);
            if(x <= h) return i;
        }
        return -1;
    }
};

// 2). Optimal Solution => Using Binary Search
//     Time Complexity : O(N logM)
//     Space Complexity : O(1)    
//Where: N = number of piles
//       M = max pile size

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long cal_h(vector<int>& piles,int mid){
        long long x = 0;
        for(int i = 0;i < piles.size();i++){
            long long a = (piles[i] + mid - 1) / mid;
            x += a;
        }
        return x;
    }
    int lar_el(vector<int>& piles){
        int ans = INT_MIN;
        for(int i = 0;i < piles.size();i++) ans = max(ans,piles[i]);
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int mxi = lar_el(piles);
        int low = 1,high = mxi;
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long a = cal_h(piles,mid);
            if(a > h) low = mid+1;
            else high = mid - 1;
        }
        return low;
    }
};