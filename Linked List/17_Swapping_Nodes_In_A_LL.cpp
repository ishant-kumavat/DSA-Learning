// LeetCode 1721 => ** Swapping Nodes in a Linked List **

// 1). Better Approach => Length Calculation + Traversal
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
    int length_LL(ListNode* temp){
        int cnt = 0;
        while(temp != nullptr){
            cnt++;
            temp = temp -> next;
        }
        return cnt; 
    }
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == nullptr || head -> next == nullptr) return head;

        int cnt = length_LL(head);
        ListNode* temp = head;
        int a = k - 1, b = cnt - k;
        ListNode* first = nullptr;
        ListNode* second = nullptr;
        while(temp != nullptr){
            if(a == 0) first = temp;
            if(b == 0) second = temp;
            if(first != nullptr && second != nullptr) break;
            a--;b--;
            temp = temp -> next;
        }
        swap(first -> val, second -> val);
        return head;
    }
};

// 2). Optimal Approach => Two Pointers + One Pass
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p1 = nullptr;
        ListNode* p2 = nullptr;
        ListNode* temp = head;
        while(temp){
            if(p2 != nullptr) p2 = p2 -> next;
            k--;
            if(k == 0) {
                p1 = temp;
                p2 = head;
            }
            temp = temp -> next;
        }
        swap(p1 -> val, p2 -> val);
        return head;
    }
};

// Find the kth node from the beginning
// and the kth node from the end
// using two pointers.
//
// Once the kth node from the beginning
// is found, start p2 from the head.
//
// After finding the kth node,
// move p2 one step for every
// remaining node traversed by temp.
//
// When temp reaches the end,
// p2 reaches the kth node from the end.