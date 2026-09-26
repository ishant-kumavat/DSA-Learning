// LeetCode 1807 => ** Evaluate the Bracket Pairs of a String **

// 1). Brute Force Approach => 
//     Time Complexity : O(n * m)
//     Space Complexity : O(1) auxiliary

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans = "";
        int n = s.length();
        int m = knowledge.size();
        for(int i = 0; i < n; i++){
            if(s[i] != '(') ans += s[i];
            else{
                string x = "";
                i++;
                while(s[i] != ')'){
                    x += s[i];
                    i++;
                }
                int flag = 0;
                for(int j = 0; j < m; j++){
                    if(knowledge[j][0] == x) {flag = 1; ans += knowledge[j][1]; break;}
                }
                if(flag == 0) ans += "?";
            }
        }
        return ans;
    }
};

// 2). Optimal Approach => Hash Map + String Parsing
//     Time Complexity : O(n + m)
//     Space Complexity : O(m)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans = "";
        int n = s.length();
        int m = knowledge.size();
        unordered_map<string, string> mpp;
        for(int i = 0; i < m; i++)
            mpp[knowledge[i][0]] = knowledge[i][1];
        for(int i = 0; i < n; i++){
            if(s[i] != '(') ans += s[i];
            else{
                string x = "";
                i++;
                while(s[i] != ')'){
                    x += s[i];
                    i++;
                }
                ans += (mpp.find(x) != mpp.end()) ? mpp[x] : "?" ;
            }
        }
        return ans;
    }
};

// Store all key-value pairs in a hash map
// for average O(1) key lookup.
//
// Traverse the string:
// - Normal characters are directly added to the answer.
// - For a bracket pair, extract the key.
// - Search the key in the hash map.
// - If found, append its value.
// - Otherwise, append '?'.
//
// Using a hash map avoids searching through
// all knowledge pairs for every bracket pair.