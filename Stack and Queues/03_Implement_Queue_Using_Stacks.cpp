// LeetCode 232 => ** Implement Queue using Stacks **

// 1). Approach => Costly Push
//     Push : O(n)
//     Pop  : O(1)
//     Peek : O(1)
//     Empty: O(1)
//     Space: O(n)

#include <bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        st1.push(x);
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }

    }
    
    int pop() {
        int x = st1.top();
        st1.pop();
        return x;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};

// 2). Optimal Approach => Costly Pop/Peek
//     Push : O(1)
//     Pop  : O(n) worst case, O(1) amortized
//     Peek : O(n) worst case, O(1) amortized
//     Empty: O(1)
//     Space: O(n)

#include <bits/stdc++.h>
using namespace std;
class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int x;
        if(!st2.empty()) {x = st2.top(); st2.pop();}
        else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            x = st2.top();
            st2.pop();
        }
        return x;
    }
    
    int peek() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }
    
    bool empty() {
        return (st1.empty() && st2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


// Keep newly pushed elements in st1.
//
// st2 stores elements in queue order,
// with the front element at the top.
//
// When st2 is empty, transfer all elements
// from st1 to st2.
//
// This reverses their order and makes the
// oldest element available at the top.
//
// Once transferred, elements remain in st2
// until they are popped.