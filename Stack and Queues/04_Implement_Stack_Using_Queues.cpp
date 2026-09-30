// LeetCode 225 => ** Implement Stack using Queues **

// Optimal Approach => Single Queue + Costly Push
// Time Complexity :
//     Push  : O(n)
//     Pop   : O(1)
//     Top   : O(1)
//     Empty : O(1)
// Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        int n = q.size();
        q.push(x);

        // Move all previous elements behind the new element.
        // This makes the newly pushed element come to the front,
        // so the queue behaves like a stack (LIFO).

        for(int i = 0; i < n; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */