// LeetCode 14 => ** Longest Common Prefix **

// 1). Brute Force Approach =>
//     Time Complexity : O(n * m)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        char ch = strs[0][0];
        int m = strs[0].length();  
        for(int i = 1; i < n; i++){
            m = min(m, int(strs[i].length()));
            if(strs[i][0] != ch) return "";
        }
        string word;
        for(int i = 0; i < m; i++){
            char ch = strs[0][i];
            bool flag = true;
            for(int j = 0; j < n; j++){
                if(strs[j][i] != ch){
                    flag = false;break;
                }
            }
            if(flag == false) return word;
            else word += ch; 
        }
        return word;
    }
};

// 2). Optimal Solution => Using Sort Technique
//     Time Complexity : O(n log n * m)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end());
        int m = min(strs[0].length(), strs[n - 1].length());
        string word = "";
        for(int i  = 0; i < m; i++){
            if(strs[0][i] != strs[n - 1][i]) return word;
            word += strs[0][i];
        }
        return word;
    }
};

// After sorting, only the first and last strings
// need to be compared.
// Their common prefix is the common prefix of all strings.