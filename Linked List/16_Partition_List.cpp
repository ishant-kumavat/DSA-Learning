// LeetCode 86 => ** Partition List **

// Optimal Solution => Two Separate Lists + Pointer Manipulation
// Time Compleixty : O(n)
// Space Compleixty : O(1)

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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode* temp = head;
        ListNode* st_small = nullptr;
        ListNode* st_large = nullptr;
        ListNode* temp_small = nullptr;
        ListNode* temp_large = nullptr;
        while(temp != nullptr){
            if(temp -> val >= x){
                if(st_large == nullptr) st_large = temp;
                else temp_large -> next = temp;
                temp_large = temp;
            }
            else{
                if(st_small == nullptr) st_small = temp;
                else temp_small -> next = temp;
                temp_small = temp;
            }
            temp = temp -> next;
        }
        if(st_small == nullptr) return st_large;
        temp_small -> next = st_large;
        if(temp_large) temp_large -> next = nullptr;
        return st_small;
    }
};

// Maintain two separate linked lists:
//
// 1. Small list -> nodes having value < x
// 2. Large list -> nodes having value >= x
//
// Preserve the original relative order
// of nodes in both lists.
//
// Traverse the original linked list once
// and place each node into the appropriate list.
//
// Connect the small list with the large list.
//
// Finally, terminate the large list with NULL
// to avoid creating an unwanted cycle.