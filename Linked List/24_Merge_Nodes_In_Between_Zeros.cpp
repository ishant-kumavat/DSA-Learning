// LeetCode 2181 => ** Merge Nodes in Between Zeros **

// 1). Better Solution => New Nodes + Sum
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head;
        ListNode* dummy = new ListNode(0);
        ListNode* cpy = dummy;
        int sum = 0;
        while(temp != nullptr){
            if(temp -> val == 0 && sum != 0) {
                ListNode* newnode = new ListNode(sum);
                cpy -> next = newnode;
                cpy = newnode;
                sum = 0;
            }
            else sum += temp -> val;
            temp = temp -> next;
        }
        cpy -> next = nullptr;
        return dummy -> next;
    }
};

// 2). Optimal Solution => In-place Modification + Sum
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head;
        ListNode* curr = head -> next;
        int sum = 0;
        while(curr != nullptr){
            if(curr -> val == 0) {
                temp -> val = sum;
                if(curr -> next != nullptr) temp = temp -> next;
                sum = 0;
            }
            else sum += curr -> val;
            curr = curr -> next;
        }
        temp -> next = nullptr;
        return head;
    }
};

// Traverse the linked list starting
// from the first non-zero node.
//
// Maintain a sum of all nodes between
// two consecutive zero nodes.
//
// When a zero is encountered:
// - Store the calculated sum in the
//   current output node.
// - Move temp to the next output node.
// - Reset sum to 0.
//
// Reuse the existing linked list nodes
// instead of creating new nodes.
//
// Finally, terminate the resulting list
// by setting temp -> next = nullptr.