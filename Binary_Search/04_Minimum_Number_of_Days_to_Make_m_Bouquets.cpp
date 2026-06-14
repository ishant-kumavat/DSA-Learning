// LeetCode 1482 -> ** Minimum Number of Days to Make m Bouquets **

// 1). Brute Force Approach => Using Linear Search method
//     Time Complexity : O((mx - mn + 1) * n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Cal_Min_Day(vector<int>& bloomDay,int m, int k,int mid){
        int x=0;
        int count=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid) count++;
            if(bloomDay[i]>mid) count=0;
            if(count==k) {
                x++;
                count=0;
            }
            if(x==m) return 1;
        }
        return 0;
    }
    vector<int> Maxi_ele(vector<int>& bloomDay){
        int ans1=INT_MIN;
        int ans2=INT_MAX;
        for(int i=0;i<bloomDay.size();i++){
            ans1=max(ans1,bloomDay[i]);
            ans2=min(ans2,bloomDay[i]);
        }
        return {ans1,ans2};
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        vector<int>arr=Maxi_ele(bloomDay);
        int mx=arr[0],mn=arr[1];
        if((n/k)<m) return -1;
        for(int i=mn;i<=mx;i++){
            int x=Cal_Min_Day(bloomDay,m,k,i);
            if(x==1) return i;
        }
        return -1;
    }
};

// 2). Optimal Solution => Using Binary Search method
//     Time Complexity : O(n + n * log(mx - mn))
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Cal_Min_Day(vector<int>& bloomDay,int m, int k,int mid){
        int x=0;
        int count=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid) count++;
            if(bloomDay[i]>mid) count=0;
            if(count==k) {
                x++;
                count=0;
            }
            if(x==m) return 1;
        }
        return 0;
    }
    vector<int> Maxi_ele(vector<int>& bloomDay){
        int ans1=INT_MIN;
        int ans2=INT_MAX;
        for(int i=0;i<bloomDay.size();i++){
            ans1=max(ans1,bloomDay[i]);
            ans2=min(ans2,bloomDay[i]);
        }
        return {ans1,ans2};
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((n/k)<m) return -1;
        vector<int>arr=Maxi_ele(bloomDay);
        int low=arr[1],high=arr[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            int x=Cal_Min_Day(bloomDay,m,k,mid);
            if(x==1) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};