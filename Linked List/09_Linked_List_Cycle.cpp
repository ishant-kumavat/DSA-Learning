// LeetCode 141 => ** Linked List Cycle **

// 1). Better Solution => Hash set
//     Time Complexity : O(n) (average)
//     Space Complexity : O(n)

#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> st;
        ListNode* temp = head;
        while(temp != nullptr){
            if(st.count(temp)) return true;
            st.insert(temp);
            temp = temp -> next;
        } 
        return false;
    }
};
// Store the address of every visited node
// in a hash set.
//
// If the same node is visited again,
// a cycle exists.
//
// If NULL is reached,
// the linked list has no cycle.

// 2). Optimal Solution => Tortoise and Hare
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) return true;
        }
        return false;
    }
};

// Slow moves one step
// and fast moves two steps.
//
// If there is no cycle,
// fast eventually reaches NULL.
//
// If a cycle exists,
// both pointers enter the cycle.
//
// Inside the cycle, fast gains
// one node on slow in every iteration.
//
// Therefore, the distance between them
// keeps changing by one and eventually
// becomes zero.
//
// When slow == fast,
// a cycle is confirmed.