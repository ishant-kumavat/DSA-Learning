// LeetCode 328 => ** Odd Even Linked List **

// 1). Better Approach => Store Values in Vector
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr || head -> next -> next == nullptr) return head;
        vector<int> nums;
        ListNode* temp = head;
        while(temp != nullptr && temp -> next != nullptr){
            nums.push_back(temp -> val);
            temp = temp -> next -> next;
        }
        if(temp != nullptr) nums.push_back(temp -> val);
        temp = head -> next;
        while(temp != nullptr && temp -> next != nullptr){
            nums.push_back(temp -> val);
            temp = temp -> next -> next;
        }
        if(temp != nullptr) nums.push_back(temp -> val);
        int i = 0;
        temp = head;
        while(temp != nullptr){
            temp -> val = nums[i];
            temp = temp -> next;i++;
        }
        return head;
    }
};

// 2). Optimal Approach => Rearranging Links
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr || head -> next -> next == nullptr) return head;
        ListNode* odd = head;
        ListNode* even = head -> next;
        ListNode* temp = even;
        while(even != nullptr && even -> next != nullptr){
            odd -> next = odd -> next -> next;
            even -> next = even -> next -> next;

            odd = odd -> next;
            even = even -> next;
        }
        odd -> next = temp;
        return head;
    }
};
// Maintain two separate chains:
// one for odd-position nodes
// and one for even-position nodes.
//
// Rearrange the next pointers
// to separate both chains.
//
// Finally, connect the odd chain
// with the even chain.
//
// No extra data structure is used.