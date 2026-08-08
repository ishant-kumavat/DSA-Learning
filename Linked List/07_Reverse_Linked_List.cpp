// LeetCode 206 => ** Reverse Linked List **

// 1). Brute Force Approach => Store values in vector
//     Time Complexity : O(n)
//     Space Complexity : O(n)

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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        vector<int> nums;
        while(temp != nullptr){
            nums.push_back(temp -> val);
            temp = temp -> next;
        }
        temp = head;
        int i = nums.size() - 1;
        while(temp != nullptr){
            temp -> val = nums[i--];
            temp = temp -> next;
        }
        return head;
    }
};
// Store all node values in a vector.
// Traverse the linked list again
// and replace each node's value
// using the values in reverse order.

// 2). Optimal Solution => Recursive Approach
//     Time Complexity : O(n)
//     Space Complexity : O(n) -> recursive call stack

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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode* newHead  = reverseList(head -> next);
        ListNode* temp = head -> next;
        temp -> next = head;
        head -> next = nullptr;
        return newHead;
    }
};
// Recursively reverse the remaining list.
// Attach the current node
// after its next node.
// Set current node's next to NULL
// and return the new head.

// 3). Optimal Solution => Iterative Approach
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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        ListNode* pre = nullptr;
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* front = curr -> next;
            curr -> next = pre;
            pre = curr;
            curr = front; 
        }
        return pre;
    }
};
// Reverse the links of the list
// using three pointers:
// prev, curr, and next.
// Store the next node,
// reverse the current link,
// then move all pointers forward.
// Finally, prev becomes
// the new head of the reversed list.