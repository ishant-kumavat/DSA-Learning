// LeetCode 1011 => ** Capacity To Ship Packages Within D Days **

// 1). Brute Force Approach => Using Linear Search
//    Time Complexity : O((sum - mx + 1) * n)
//    Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int i){
        int n = weights.size();
        long long s = 0, cnt = 0;
            for(int j = 0; j < n; j++){
                s += weights[j];
                if(s == i){
                    s = 0;
                    cnt ++;
                }
                else if(s > i){
                    s = weights[j];
                    cnt ++;
                }
            }
            if(s != 0) cnt ++;
            if(days >= cnt) return true;
            return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        long long sum = 0; 
        int mx = INT_MIN;
        for(int i = 0; i < n; i++){
            sum += weights[i];
            mx = max( mx, weights[i] );
        }
        for(int i = mx; i <= sum; i++){
            bool x = isPossible(weights, days, i);
            if(x == true) return i;
        }
        return -1;
    }
};

// 2). Optimal Approach => Using Binary Search
//     Time Complexity : O(n * log(sum - mx + 1))
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible (vector<int>& weights, int days, long long mid){
        int n = weights.size();
        long long s = 0, cnt = 0;
            for(int j = 0; j < n; j++){
                s += weights[j];
                if(s == mid){
                    s = 0;
                    cnt ++;
                }
                else if(s > mid){
                    s = weights[j];
                    cnt ++;
                }
            }
            if(s != 0) cnt ++;
            if(days >= cnt) return true;
            return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        long long sum = 0; 
        int mx = INT_MIN;
        for(int i = 0; i < n; i++){
            sum += weights[i];
            mx = max( mx, weights[i] );
        }
        long long low = mx, high = sum;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            bool flag = isPossible( weights, days, mid);
            if(flag == true) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};

// Minimum capacity lies between:
// max(weights) and sum(weights)