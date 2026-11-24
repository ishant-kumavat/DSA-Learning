// LeetCode 2810 => ** Faulty Keyboard **

// 1). Brute Force Approach => Repeated Reversal
//     Time Complexity : O(n ^ 2)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reverse(string &ans, int st, int ed){
        while(st <= ed){
            swap(ans[st], ans[ed]);
            
            st ++;
            ed --;
        }
    }

    string finalString(string s) {
        int n = s.length();
        string ans = "";

        for(int i = 0; i < n; i++){
            if(s[i] == 'i'){
                int count_i = 0;
                
                while(i < n && s[i] == 'i') {count_i ++; i++;}
                i--;
                
                if(count_i % 2 == 0) continue;
                
                else reverse(ans, 0, ans.length() - 1);
            }

            else ans += s[i];
        }

        return ans;
    }
};

// 2). Optimal Approach => Deque + Direction Flag
//     Time Complexity : O(n)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string finalString(string s) {
        deque<int> dq;
        string ans = "";

        int flag = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] != 'i') {
                if(!flag) dq.push_back(s[i]);
                else dq.push_front(s[i]);
            }
            else flag = !flag;
        }

        while(!dq.empty()){
            if(flag == 0) {
                ans += dq.front();
                dq.pop_front();
            }
            else{
                ans += dq.back();
                dq.pop_back();
            }
        }

        return ans;
    }
};

// Use a deque and a direction flag.
//
// Initially, insert characters at the back.
// Whenever 'i' appears, toggle the direction flag.
//
// If flag is 0, insert characters at the back.
// If flag is 1, insert characters at the front.
//
// Finally, construct the answer by removing elements
// from the front or back according to the final direction.