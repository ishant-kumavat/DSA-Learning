    // LeetCode 2390 => ** Removing Stars From a String **

    // 1). Approach 1 => Stack
    //     Time Complexity : O(n)
    //     Space Complexity : O(n) 

    #include <bits/stdc++.h>
    using namespace std;
    class Solution {
    public:
        string removeStars(string s) {
            stack<char> st;
            for(auto &it : s){
                if(it == '*') st.pop();
                else st.push(it);
            }
            string ans = "";
            while(!st.empty()) {ans.push_back(st.top()); st.pop();}      
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };

    // 2). Approach 2 => String as Stack
    //     Time Complexity : O(n)
    //     Space Complexity : O(n) 

    #include <bits/stdc++.h>
    using namespace std;
    class Solution {
    public:
        string removeStars(string s) {
            string ans = "";
            string ans = "";
            for(char it : s){
                if(it == '*') ans.pop_back();
                else ans.push_back(it);
            }
            return ans;
        }
    };

// Treat the stack or string as a stack.
//
// If the current character is '*',
// remove the last stored character.
//
// Otherwise, add the current character.
//
// This removes the closest non-star character
// to the left of each star.