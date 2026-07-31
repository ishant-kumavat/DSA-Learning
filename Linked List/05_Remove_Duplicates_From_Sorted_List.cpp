// LeetCode 83 => ** Remove Duplicates from Sorted List **

// Optimal Solution =>
// Time Complexity : O(n)
// Space Complexity : O(1)

#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head -> next == nullptr) return head;
        ListNode* temp = head -> next;
        ListNode* pre = head;
        while(temp != nullptr){
            if(temp -> val == pre -> val){
                ListNode* temp1 = temp;
                pre -> next = temp -> next;
                temp = temp -> next;
                temp1 -> next = nullptr;
                delete temp1;
                continue;
            }
            pre = temp;
            temp = temp -> next;
        }
        return head;
    }
};
// Traverse the sorted list.
//
// If two consecutive nodes
// have the same value,
// remove the duplicate node.
//
// Otherwise,
// move to the next node.
//
// Return the updated head.