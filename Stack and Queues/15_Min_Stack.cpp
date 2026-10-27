// LeetCode 155 => ** Min Stack **

// 1). Better Solution => Single Stack with Pair
//     Time Complexity : O(1) per operation
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {
        
    }
    
    void push(int value) {
        if(!st.empty()) st.push({value, min(st.top().second, value)});
        else st.push({value, value});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


// Store each element as a pair:
// first  = current element
// second = minimum element up to the current level.
//
// On push, calculate the minimum between the current
// element and the previous minimum, then store both.
//
// On pop, remove the top pair.
//
// top() returns the current element.
// getMin() returns the minimum element in O(1) time.
//
// Time Complexity : O(1) per operation
// Space Complexity : O(n)