// LeetCode 12 => ** Integer to Roman **

// 1). Greedy Approach
//     Time Complexity : O(1)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        vector<int>val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string>sym{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ans;
        for(int i = 0; i < 13; i++){
            if(num == 0) break;
            int temp = num / val[i];
            while(temp--){
                ans += sym[i];
            }
            num %= val[i];
        }
        return ans;
    }
};
// Store Roman values and their corresponding symbols.
// Always choose the largest possible value.
// Append its symbol as many times as possible,
// then reduce the remaining number.