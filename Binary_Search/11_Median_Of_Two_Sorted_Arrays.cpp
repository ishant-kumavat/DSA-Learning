// LeetCode 4 => ** Median of Two Sorted Arrays **

// 1). Naive Solution : Using sort function
//     Time Complexity : O((n1 + n2) log(n1 + n2))
//     Space Complexity : O(n1 + n2)    

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        vector<int> nums;
        int j = 0;
        for(int i = 0; i < n; i++){
            if(i < n1) nums.push_back(nums1[i]);
            else nums.push_back(nums2[j++]);
        }
        sort(nums.begin(), nums.end());
        if(n % 2 == 1) return (double)nums[n / 2];
        return (double)(nums[n / 2] + nums[(n / 2) - 1]) / 2.0;
    }
};

// 2). Using extra Space : Using Merge Technique (Two Pointers)
//     Time Complexity : O(n1 + n2)
//     Space Complexity : O(n1 + n2)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        vector<int> nums;
        int i = 0, j = 0;
        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]) nums.push_back(nums1[i++]);
            else nums.push_back(nums2[j++]);
        }
        while(i < n1) nums.push_back(nums1[i++]);
        while(j < n2) nums.push_back(nums2[j++]);
        if(n % 2 == 1) return (double)nums[n / 2];
        return (double)(nums[n / 2] + nums[(n / 2) - 1]) / 2.0;
    }
};

// 3). Better Solution : Instead of storing the merged array,
// keep track of only the required median elements.
//     Time Complexity : O(n1 + n2)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;
        int i = 0, j = 0, cnt = 0;
        int idx1 = n / 2, idx2 = (n / 2) - 1;
        int ans1 = -1, ans2 = -1;
        while(i < n1 && j < n2){
            if(ans1 != -1 && ans2 != -1) break;
            else if(nums1[i] > nums2[j]){
                if(idx1 == cnt) ans1 = nums2[j];
                if(idx2 == cnt) ans2 = nums2[j];
                cnt++;
                j++;
            }
            else{
                if(idx1 == cnt) ans1 = nums1[i];
                if(idx2 == cnt) ans2 = nums1[i];
                cnt++;
                i++;
            }
        }
        while(i < n1){
            if(ans1 != -1 && ans2 != -1) break;
            if(idx1 == cnt) ans1 = nums1[i];
            if(idx2 == cnt) ans2 = nums1[i];
            cnt++;
            i++;
        }
        while(j < n2){
            if(ans1 != -1 && ans2 != -1) break;
            if(idx1 == cnt) ans1 = nums2[j];
            if(idx2 == cnt) ans2 = nums2[j];
            cnt++;
            j++;
        }
        if(n % 2 == 1) return (double)ans1;
        return (double)((double)ans1 + (double)ans2) / 2.0; 
    }
};

// 4). Optimal Approach : Using Symmetrical line and Cross Checking elements
//     Time Complexity : O(log(min(n1, n2)))
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);
        int n = (n1 + n2);
        int left =(n + 1) / 2;
        int low = 0, high = n1;
        while(low <= high){
            int mid1 = low + (high - low) / 2;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 < n1) r1 = nums1[mid1]; 
            if(mid2 < n2) r2 = nums2[mid2];
            if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
            if(l1 <= r2 && l2 <= r1){
                if(n % 2 == 1) return max(l1, l2);
                return ((double)max(l1, l2) + (double)min(r1, r2)) / 2.0;
            }
            else if(l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;
        }
        return -1;
    }
};