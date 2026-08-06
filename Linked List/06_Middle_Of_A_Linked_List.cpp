// LeetCode 876 => ** Middle of the Linked List **

// 1). Better Approach => Two Traversals
//     Time Complexity : O(n)
//     Space Complexity : O(1)

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
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            cnt++;
            temp = temp -> next;
        }
        int mid = cnt / 2;
        cnt = 0;
        temp = head;
        while(cnt != mid){
            cnt++;
            temp = temp -> next;
        }
        return temp;
    }
};
// Traverse the linked list
// once to count
// the total number of nodes.
//
// Compute the middle index.
//
// Traverse the list again
// until the middle index
// and return that node.

// 2). Optimal Solution => Tortoise and Hare
//     Time Complexity : O(n)
//     Space Complexity : O(1)

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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast =fast -> next -> next;
        }
        return slow;
    }
};
// Use two pointers:
// slow and fast.
//
// Move slow
// one step
// and fast
// two steps
// at a time.
//
// When fast reaches
// the end,
// slow points
// to the middle node.