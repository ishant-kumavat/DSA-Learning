// LeetCode 1290 => ** Convert Binary Number in a Linked List to Integer **

// Optimal Solution => Reverse Linked List + Binary Conversion
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
    ListNode* reverse_LL(ListNode* temp){
        if(temp == nullptr || temp -> next == nullptr) return temp;
        ListNode* last = temp;
        temp = temp -> next;
        last -> next = nullptr;
        while(temp != nullptr){
            ListNode* front = temp -> next;
            temp -> next = last;
            last = temp;
            temp = front; 
        }
        return last;
    }
    int getDecimalValue(ListNode* head) {
        ListNode* newhead = reverse_LL(head);
        ListNode* temp = newhead;
        int ans = 0;
        int x = 1;
        while(temp != nullptr){
            if(temp -> val != 0) ans = ans + (temp -> val * x);
            x *= 2;
            temp = temp -> next;
        }
        head = reverse_LL(newhead);
        return ans;
    }
};

// Reverse the linked list
// so that the least significant bit
// comes first.
//
// Traverse the reversed linked list
// and calculate the decimal value.
//
// Maintain a multiplier x,
// initially x = 1.
//
// For every node:
// - If the current bit is 1,
//   add x to the answer.
// - If the current bit is 0,
//   nothing is added.
// - Multiply x by 2 for the next bit.
//
// Reverse the linked list again
// to restore its original order.
//
// Return the calculated decimal value.