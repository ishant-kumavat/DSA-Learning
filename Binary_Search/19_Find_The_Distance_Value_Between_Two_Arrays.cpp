// LeetCode 1385 => ** Find the Distance Value Between Two Arrays **

// 1). Brute Force Approach =>
//     Time Complexity : O(n * m)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;

        for(int i = 0; i < arr1.size(); i++){
            int flag = 1;
            for(int j = 0; j < arr2.size(); j++){
                int x = abs(arr1[i] - arr2[j]);
                if(x <= d) { flag = 0; break;}
            }
            if(flag) ans ++;
        }
        return ans;
    }
};