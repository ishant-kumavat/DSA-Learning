// LeetCode 142 => ** Linked List Cycle II **

// 1). Better Solution => Hash Set
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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> st;
        ListNode* temp = head;
        while(temp != nullptr){
            if(st.count(temp)) return temp;
            st.insert(temp);
            temp = temp -> next;
        } 
        return nullptr;
    }
};

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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(fast == slow){
                slow = head;
                while(fast != slow){
                    slow = slow -> next;
                    fast = fast -> next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
// First, use slow and fast pointers
// to detect whether a cycle exists.
//
// When slow and fast meet,
// reset slow to the head.
//
// Move both pointers one step at a time.
//
// They will meet again at the
// starting node of the cycle.
//
// Return that meeting node.