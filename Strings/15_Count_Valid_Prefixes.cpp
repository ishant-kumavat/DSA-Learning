// LeetCode 4006 => ** Count Valid Prefixes **

// 1). Brute Force Approach => Using nested loops
//     Time Complexity : O(n ^ 2)
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countValidPrefixes(string s) {
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            int one = 0, zero = 0;
            for(int j = 0; j <= i; j++){
                if(s[j] == '0') zero ++;
                else one ++;
            }
            if((i + 1) % 2 == 0 && zero == one) ans ++;
            if((i + 1) % 2 != 0 && (zero - 1 == one || one - 1 == zero)) ans ++; 
        }
        return ans;
    }
};
// For every prefix,
// count the number
// of zeros and ones
// using a nested loop.
//
// A prefix is valid
// if the counts are equal
// for even length,
// or differ by exactly one
// for odd length.
//
// Count all such prefixes.

// 2). Optimal Solution => Running Frequency Count
//     Time Complexity : O(n)
//     Space Complexity : O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countValidPrefixes(string s) {
        int zero = 0, one = 0;
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '0') zero ++;
            else one ++;
            if(abs(zero - one) <= 1) ans++;
        }
        return ans;
    }
};
// Traverse the string once.
// Keep track of
// the running count
// of zeros and ones.
//
// For each prefix,
// compute the absolute
// difference between
// their counts.
//
// If the difference
// is at most 1,
// the prefix is valid.
//
// Count all valid prefixes.