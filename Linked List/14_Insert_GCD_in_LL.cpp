// LeetCode 2807 => ** Insert Greatest Common Divisors in Linked List **

// Optimal Solution => GCD + In-place Insertion
// Time Complexity : O(n log V), where V is the maximum node value.
// Space Complexity : O(1) auxiliary space

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
    int cal_gcd(int a, int b){
        while(b){
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode* curr = head -> next;
        ListNode* prev = head;
        while(curr != nullptr){
            int data = cal_gcd(curr -> val, prev -> val);
            ListNode* newnode = new ListNode(data, curr);
            prev -> next = newnode;
            prev = curr;
            curr = curr -> next;
        }
        return head;
    }
};
// Traverse the linked list
// using two pointers.
//
// For every adjacent pair,
// calculate their GCD.
//
// Create a new node containing
// the GCD and insert it
// between the two nodes.
//
// Move to the next original node.