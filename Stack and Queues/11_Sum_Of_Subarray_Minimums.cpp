// LeetCode 907 => ** Sum of Subarray Minimums **

// 1). Brute Force Approach => Generate All Subarrays and compute their sum
//     Time Complexity : O(n ^ 2)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        const long long MOD = 1e9 + 7;

        for(int i = 0; i < n; i++){
            int mn = INT_MAX;
            for(int j = i; j < n; j++){
                mn = min(mn, arr[j]);
                ans += mn;
            }
        }
        
        return (int)(ans % MOD);
    }
};

// 2). Optimal Approach => Using monotonic stack
//     Time Complexity : O(n)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> right_most_minimum(vector<int> &right, vector<int> &arr, int n){
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return right;
    }
    vector<int> left_most_minimum(vector<int> &left, vector<int> &arr, int n){
        stack<int> st;
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] > arr[i]){
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return left;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        const long long MOD = 1e9 + 7;
        vector<int> left(n, -1);
        vector<int> right(n, n);
            
        left_most_minimum(left, arr, n);
        right_most_minimum(right, arr, n);

        for(int i = 0; i < n; i++){
            ans += ((long long) arr[i] * (i - left[i]) * (right[i] - i));
        }
        return int(ans % MOD);
    }
};

// For each element arr[i]:
//
// (i - left[i])  = number of choices for starting index
// (right[i] - i) = number of choices for ending index
//
// Therefore, arr[i] is the minimum in
// (i - left[i]) * (right[i] - i) subarrays.
//
// Contribution =
// arr[i] * (i - left[i]) * (right[i] - i)

// We use:
// Left  -> previous smaller element
// Right -> next smaller or equal element
//
// This asymmetric comparison handles duplicate values
// correctly and avoids double counting.