// LeetCode 451 => ** Sort Characters By Frequency **

// Using unordered_map
// Time Complexity : O(n + k log k)
// Space Complexity : O(k)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char, int> mpp;
        for(int i = 0; i < n; i++){
            mpp[s[i]]++;
        }
        vector<pair<char, int>> vec(mpp.begin(), mpp.end());
        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });
        string res = ""; 
        for(auto it : vec){
            if(it.second > 0){
                char ch = it.first;
                int frq = it.second;
                string temp = string(frq, ch);
                res += temp;
            }
        }
        return res;
    }
}; 

// Using Frequency Hashing + Sorting
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        vector<pair<char, int>> vec(123);
        for(char &ch : s){
            int frq = vec[ch].second;
            vec[ch] = {ch, frq + 1}; 
        }
        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });
        string res = ""; 
        for(auto it : vec){
            if(it.second > 0){
                char ch = it.first;
                int frq = it.second;
                string temp = string(frq, ch);
                res += temp;
            }
        }
        return res;
    }
};
// Count the frequency of each character.
// Sort characters in decreasing order of frequency.
// Repeat each character according to its frequency
// to construct the final string.