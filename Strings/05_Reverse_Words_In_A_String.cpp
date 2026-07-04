// LeetCode 151 => ** Reverse Words in a String **

// 1). Brute Force Approach =>
//     Time Complexity :
//     Space Complexity :

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        stringstream st(s);
        string token ="";
        string res = "";
        while(st >> token){
            res = token + " " + res;
        }
        res.pop_back();
        return res;
    }
};

// 2). Optimal Solution =>
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
