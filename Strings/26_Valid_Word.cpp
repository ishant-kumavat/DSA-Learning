// LeetCode 3136 => ** Valid Word **

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string word) {
        int n = word.size();

        if(n < 3) return false;

        int cnt1 = 0, cnt2 = 0;

        for(char &it : word){
            if(!isalnum(it)) return false;
            if(it >= '0' && it <= '9') continue;
            char x = tolower(it);
            if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') cnt1 = 1;
            else cnt2 = 1;
        }

        if(cnt1 && cnt2) return true;
        return false;
    }
};