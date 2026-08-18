// LeetCode 82 => ** Remove Duplicates from Sorted List II **

// Optimal Solution => Two Pointers + Duplicate Group Removal
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode* curr = head -> next; 
        ListNode* prev = head;
        ListNode* last = nullptr;
        while(curr != nullptr){
            if(curr -> val == prev -> val){
                while(curr != nullptr && curr -> val == prev -> val){
                    ListNode* temp = curr;
                    curr = curr -> next;
                    delete temp;
                }
                if(last) last -> next = curr;
                else head = curr;
                if(curr == nullptr) return head;
                prev = curr;
                curr = curr -> next;
            }
            else{
                last = prev;
                prev = curr;
                curr = curr -> next;
            }   
        } 
        return head;
    }
};
// Traverse the sorted linked list
// using pointers to identify
// duplicate groups.
//
// If a duplicate group is found,
// remove all its nodes and
// connect the previous unique node
// with the next unique node.
//
// If the duplicate group starts
// from the head, update the head.
//
// Continue until the entire list
// is processed.

// Since the list is sorted,
// duplicates always occur consecutively.
//
// So, duplicate nodes can also be detected by:
// curr -> val == curr -> next -> val
//
// Make sure curr -> next != nullptr
// before accessing curr -> next -> val.