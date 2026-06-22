// ** Book Allocation Problem **

// 1). Brute Force Approach => Linear Search
//     Time Complexity : O((sum - max + 1) * n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int find_stu(vector<int>& nums, int a){
        int stu = 1, tot_pag = 0;
        for(int i = 0; i < nums.size(); i++){
            if(tot_pag + nums[i] <= a){
                tot_pag += nums[i];
            }
            else{
                tot_pag = nums[i];
                stu++;
            }
        }
        return stu;
    }
    vector<int> find_value(vector<int>& nums){
        int low = INT_MIN, high = 0;
        for(int i = 0; i < nums.size(); i++){
            low = max(low, nums[i]);
            high += nums[i];
        }
        return {low, high};
    }
    int findPages(vector<int> &nums, int m)  {
        if(m > nums.size()) return -1;
        vector<int>val = find_value(nums);
        int low = val[0], high = val[1];
        for(int i = low; i <= high; i++){
            int Num_stu = find_stu(nums, i);   
            if(Num_stu <= m){
                return i;
            }
        }
        return -1;
    }
};

// 2). Optimal Approach => Binary Search
//     Time Complexity : O(n * log (max - sum + 1))
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int find_stu(vector<int>& nums, int a){
        int stu = 1, tot_pag = 0;
        for(int i = 0; i < nums.size(); i++){
            if(tot_pag + nums[i] <= a){
                tot_pag += nums[i];
            }
            else{
                tot_pag = nums[i];
                stu++;
            }
        }
        return stu;
    }
    vector<int> find_value(vector<int>& nums){
        int low = INT_MIN, high = 0;
        for(int i = 0; i < nums.size(); i++){
            low = max(low, nums[i]);
            high += nums[i];
        }
        return {low, high};
    }
    int findPages(vector<int> &nums, int m)  {
        if(m > nums.size()) return -1;
        vector<int>val = find_value(nums);
        int low = val[0], high = val[1];
        while(low <= high){
            int mid = low + (high - low) / 2;
            int Num_stu = find_stu(nums, mid);
            if(Num_stu <= m) high = mid - 1; 
            else low = mid + 1;
        }
        return low;
    }
};

// Answer lies between maximum single book pages
// and total pages of all books.