// LeetCode 151 => ** Reverse Words in a String **

// 1). Brute Force Approach => Using StringStream / Using Tokenizer
//     Time Complexity : O(n)
//     Space Complexity : O(n)

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
// stringstream is used to read a string like a stream and
// easily split words or convert between strings and numbers.

// 2). Optimal Solution => Reverse Entire String + Reverse Individual Words
//     Time Complexity : O(n)
//     Space Complexity : O(1) (Ignoring the output string)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        reverse(s.begin(), s.end());
        for(int i = 0; i < s.length(); i++){
            string word = "";
            while(i < s.length() && s[i] != ' '){
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if(word.length() > 0) ans = ans + " " + word;
        }
        return ans.substr(1);
    }
};

// Reverse the entire string first.
// Then extract each word, reverse it individually,
// and append it to the answer while skipping extra spaces.