// LeetCode 3217 => ** Delete Nodes From Linked List Present in Array **

// Optimal Solution => Hash Set + Linked List Traversal
// Time Complexity : O(m + n)
// Space Complexity : O(m)
// where, m = nums.size()
//        n = linked list length
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode* temp = head;
        ListNode* pre = NULL;
        while(temp != NULL){
            if(st.find(temp -> val) != st.end()){
                ListNode* temp1 = temp;
                if(pre == NULL){
                    head = head -> next;
                    temp = head;
                }
                else{
                    pre -> next = temp -> next;
                    temp = temp -> next;
                }
                delete temp1;
                continue;
            }
            pre = temp;
            temp = temp -> next;
        }
        return head;
    }
};
// Store all values from nums
// in a hash set
// for O(1) lookup.
//
// Traverse the linked list.
// If the current node's value
// exists in the hash set,
// delete the node;
// otherwise,
// move to the next node.
//
// Return the updated head.