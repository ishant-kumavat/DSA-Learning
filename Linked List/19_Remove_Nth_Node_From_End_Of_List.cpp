// LeetCode 19 => ** Remove Nth Node From End of List **

// 1). Better Approach => Length Calculation + Traversal
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    int Length_LL(ListNode* temp){
        int cnt = 0;
        while(temp != nullptr){cnt++; temp = temp -> next;}
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;
        int cnt = Length_LL(head);
        if(cnt == n) {
            ListNode* newhead = head -> next;
            delete head;
            return newhead;
        }
        cnt -= n;
        ListNode* temp = head;
        while(temp != nullptr){
            cnt--;
            if(cnt == 0){
                ListNode* del = temp -> next;
                temp -> next = del -> next;
                del -> next = nullptr;
                delete del;
                return head;
            }
            temp = temp -> next;
        }
        return head;
    }
};

// Traverse the linked list once
// to calculate its length.
//
// If the head itself is the
// Nth node from the end,
// remove the head.
//
// Otherwise, traverse again
// to reach the node just before
// the target node.
//
// Remove the Nth node from the end
// by updating the previous node's
// next pointer.

// 2). Optimal Solution => Two Pointers + One Pass
//     Time Complexity : O(n)
//     Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        while(n){
            n--;
            fast = fast -> next;
        }
        if(fast == nullptr) {
            ListNode* newhead = head -> next;
            delete head;
            return newhead;
        }
        ListNode* slow = head;
        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next;
        }
        ListNode* del = slow -> next;
        slow -> next = del -> next;
        del -> next = nullptr;delete del;
        return head;
    }
};

// Move the fast pointer N steps ahead.
//
// If fast becomes NULL,
// the head itself is the Nth node
// from the end, so remove the head.
//
// Otherwise, move both slow and fast
// together until fast reaches the last node.
//
// Now slow is at the node just before
// the node that needs to be removed.
//
// Remove slow -> next and return the head.