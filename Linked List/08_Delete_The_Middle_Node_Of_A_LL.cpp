// LeetCode 2095 => ** Delete the Middle Node of a Linked List **

// 1). Brute Force Approach => Two Traversals
//     Time Complexity : O(n)
//     Space Complexity : O(1)

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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return nullptr;
        int len = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            len ++;
            temp = temp -> next;
        }
        temp = head;
        len /= 2;
        while(temp != nullptr){
            len --;
            if(len == 0){
                ListNode* temp1 = temp -> next; 
                temp -> next = temp -> next ->next;
                temp1 -> next = nullptr;delete temp1;
                break;
            }
            temp = temp -> next;
        }
        return head;
    }
};


// 2). Optimal Approach => Tortoise and Hare
//     Time Complexity : O(n)
//     Space Complexity : O(1)

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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast -> next != nullptr){
            if(fast != head) slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* temp = slow -> next;
        slow -> next = slow -> next -> next;
        delete temp;
        return head;
    }
};
// Find the node just before
// the middle using slow and fast pointers.
// Move slow one step
// and fast two steps.
// When fast reaches the end,
// slow points to the node
// before the middle.
// Remove the middle node
// by updating slow's next pointer.