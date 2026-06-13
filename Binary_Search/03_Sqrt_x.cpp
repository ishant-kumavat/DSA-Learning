// LeetCode 69 -> **Sqrt(x)**

// 1). Brute Force Approach => Using Linear Search
//     Time Complexity : O(x)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int ans=0;
        for(int i=1;i*i<=x;i++){
            long long sq= 1LL*i*i; // 1LL = trick to force long long arithmetic from the start.
            if(sq<=x) ans=i;
            else break;
        }
        return ans;
    }
};

// 2). Optimal Solution => Using Binary Search
//     Time Complexity : O(log x)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        long long low=1,high=x;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(mid<=x/mid) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};

//  (mid <= x / mid) Safe multiplication technique to avoid overflow in square root problems.

// 3). Also Use Built-In function sqrt to calculate square root.
//     Time and Space Complexity is Constant.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        return sqrt(x);
    }
};