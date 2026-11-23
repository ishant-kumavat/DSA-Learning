// LeetCode 557 => ** Reverse Words in a String III **

// 1). Approach 1 => Using Extra Space
//     Time Complexity : O(n)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                reverse(temp.begin(), temp.end());
                ans += temp;
                ans += ' ';
                temp = "";
            } 

            else temp += s[i];
        }

        reverse(temp.begin(), temp.end());
        ans += temp;
        
        return ans;
    }
};

// 2). Approach 2 => Two Pointers
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverse_word(string s, string &ans, int j, int a){
        while(j >= a){
           ans.push_back(s[j]);
            j--;
        }
    }

    string reverseWords(string s) {
        string ans = "";
        int n = s.length();

        int a = -1;

        for(int i = 0; i <= n; i++){
            if(a == -1) a = i;

            if(i == n || s[i] == ' ') {
                reverse_word(s, ans, i - 1, a);
                if(i != n) ans.push_back(' ');
                a = -1;
            }
        }

        return ans;
    }
};

// Use two pointers to identify the starting and ending
// positions of each word.
//
// Traverse the string and identify word boundaries
// using spaces or the end of the string.
//
// Reverse each word by traversing it from right to left
// and append its characters to the answer.
//
// Preserve spaces between words.
//
// Time Complexity : O(n)
// Auxiliary Space : O(1), excluding the output string