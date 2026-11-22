// LeetCode 2124 => ** Check if All A's Appears Before All B's **

// 1). Approach 1 => Flag Variables
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkString(string s) {
        int a = 0, b = 0;
        
        for(auto ch : s){
            if(ch == 'a'){
                a = 1;
                if(b == 1) return false;
            }
            else{
                b = 1;
            }
        }

        return true;
    }
};

// 2). Approach 2 => String Find
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkString(string s) {
        string x = "ba";

        if(s.find(x) != string::npos){
            return false;
            
        } else{
            return true;
        }
        
    }
};

// 3). Approach 3 => Adjacent Character Check
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkString(string s) {
        for(int i = 0; i < s.length() - 1; i++){
            if(s[i] == 'b' && s[i + 1] == 'a') return false;
        }

        return true;
    }
};

// Check every adjacent pair of characters.
//
// If 'b' appears immediately before 'a',
// the string violates the required order.
//
// If no "ba" pair exists, all 'a's appear before all 'b's.