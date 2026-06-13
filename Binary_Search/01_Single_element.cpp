// LeetCode 540 -> **Single Element in a Sorted Array**

// 1). Brute Force Approach => Linear Search
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i+=2){
            if(nums[i]!=nums[i+1]) return nums[i];
        }
        return nums[n-1];
    }
};

// 2). Better Approach => Using xor
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    int xr=0;
    for(int i=0;i<nums.size();i++) xr^=nums[i];
    return xr;
    }
};

// 3). Optimal Approach => Using Binary Search Method
//     Time Complexity : O(log n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int low=1,high=n-2;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]) return nums[mid];
            else if(((mid%2)==0 && nums[mid]==nums[mid+1]) || ((mid%2)!=0 && nums[mid]==nums[mid-1])) low=mid+1;
            else high=mid-1;
        }
        return -1;//Dummy state.
    }
};

// Before the single element:
// first occurrence is at even index,
// second occurrence is at odd index.
// After the single element:
// this pattern gets disturbed.