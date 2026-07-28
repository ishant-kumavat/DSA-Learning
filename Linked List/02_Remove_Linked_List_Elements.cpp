// LeetCode 203 => ** Remove Linked List Elements **

// Optimal Solution => Iterative Traversal
// Time Complexity : O(n)
// Space Complexity : O(1)
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        ListNode* temp = head;
        ListNode* pre = NULL;
        while(temp != NULL){
            if(temp -> val == val){
                if(pre == NULL){
                    ListNode* temp1 = temp;
                    head = head -> next;
                    temp = head;
                    delete temp1;
                    continue;
                }
                ListNode* temp1 = temp;
                pre -> next = temp -> next;
                temp = temp -> next;
                delete temp1;
                continue;
            }
            pre = temp;
            temp = temp -> next;
        }
        return head;
    }
};

// Traverse the linked list
// using two pointers.
// If the current node
// matches the target value,
// remove it by updating
// the previous node's link.
// If the head node
// contains the target value,
// move the head forward.
// Return the updated head.