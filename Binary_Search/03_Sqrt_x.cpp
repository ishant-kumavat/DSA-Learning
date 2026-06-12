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