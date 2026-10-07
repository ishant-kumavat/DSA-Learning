// LeetCode 735 => ** Asteroid Collision **

// 1). Brute Force Approach => Simulation + Erase
//     Time Complexity : O(n ^ 2)
//     Space Complexity : O(1) auxiliary

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int i = 0;
        while(i + 1 < asteroids.size()){
            if(asteroids[i] > 0 && asteroids[i + 1] < 0){
                int idx = (abs(asteroids[i]) > abs(asteroids[i + 1])) ? (i + 1) : i;
                if((abs(asteroids[i]) == abs(asteroids[i + 1]))) asteroids.erase(asteroids.begin() + i, asteroids.begin() + i + 2);
                else asteroids.erase(asteroids.begin() + idx);
                i = 0;
            }
            else i++;
        }
        return asteroids;
    }
};

// 2). Optimal Approach => Stack Simulation
//     Time Complexity : O(n)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(auto &it : asteroids){
            int flag = 0;
            while(!ans.empty() && ans.back() > 0 && it < 0){    
                if(ans.back() < abs(it)) ans.pop_back();
                else if(ans.back() == abs(it)) {ans.pop_back(); flag = 1; break;} 
                else {flag = 1; break;}
            }
            if(flag) continue;
            ans.push_back(it);
        }
        return ans;
    }
};

// Store surviving asteroids in a vector,
// which works like a stack.
//
// Collision can happen only when:
// - Previous asteroid is moving right (+)
// - Current asteroid is moving left (-)
//
// Compare their absolute sizes:
// - Previous is smaller -> pop it and continue collision.
// - Both are equal -> pop previous and destroy current.
// - Previous is larger -> current is destroyed.
//
// If no collision destroys the current asteroid,
// push it into the stack.