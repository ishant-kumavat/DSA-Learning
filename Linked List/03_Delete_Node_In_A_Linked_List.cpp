// LeetCode 237 => ** Delete Node in a Linked List **

// ========================================================================================= //

// 1). Better Solution => Value Swapping
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
    void deleteNode(ListNode* node) {
        ListNode* temp = node;
        ListNode* pre = NULL;
        while(temp -> next != NULL){
            swap(temp -> val, temp -> next -> val);
            pre = temp;
            temp = temp -> next;
        }
        pre -> next = NULL;
        delete temp;
    }
};
// Keep swapping the value
// of the current node
// with the next node.
// Continue until
// the last node is reached.
// Remove the last node
// from the linked list.

// ========================================================================================= //

// 2). Optimal Solution => Copy Next Node
//     Time Complexity : O(1)
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
    void deleteNode(ListNode* node) {
        ListNode* temp = node -> next;
        node -> val = temp -> val;
        node -> next = temp -> next;
        delete temp;
    }
};
// Copy the value
// of the next node
// into the current node.
// Bypass the next node
// by updating the link.
// Delete the skipped node.