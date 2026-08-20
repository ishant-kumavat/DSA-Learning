// LeetCode 24 => ** Swap Nodes in Pairs **

// # (Good Question) #

// Optimal Solution => Iterative Pointer Manipulation
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode* temp = head;
        ListNode* ADnode = nullptr; // ADnode : adjacent node
        ListNode* prev = nullptr;
        while(temp != nullptr){
            ADnode = temp -> next;
            if(ADnode == nullptr){
                prev -> next = temp;
                break;
            }
            ListNode* nextnode = ADnode -> next;
            ADnode -> next = temp;
            temp -> next = nullptr;
            if(prev == nullptr) head = ADnode;
            else prev -> next = ADnode;
            prev = temp;
            temp = nextnode;
        }
        return head;
    }
};

// Traverse the linked list in pairs.
//
// For every pair:
// 1. Store the second node.
// 2. Store the node after the pair.
// 3. Reverse the link between the two nodes.
// 4. Connect the previous pair with the current pair.
// 5. Move to the next pair.
// If only one node is left,
// keep it unchanged.