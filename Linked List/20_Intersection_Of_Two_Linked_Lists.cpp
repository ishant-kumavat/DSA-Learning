// LeetCode 160 => ** Intersection of Two Linked Lists **

// 1). Brute Force Approach => Using Unordered Set
//     Time Complexity : O(n)
//     Space Complexity : O(n)

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> st;
        ListNode* temp = headA;
        while(temp != nullptr){
            st.insert(temp);
            temp = temp -> next;
        }
        temp = headB;
        while(temp != nullptr){
            if(st.count(temp)) return temp;
            temp = temp -> next;
        }
        return nullptr;
    }
};

// 2). Optimal Solution => Length Difference + Two Pointers
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
    int find_length(ListNode* temp){
        int cnt = 0;
        while(temp != nullptr){
            cnt++;
            temp = temp -> next;
        }
        return cnt;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int cnt1 = find_length(headA);  
        int cnt2 = find_length(headB);
        if(cnt1 < cnt2) {
            swap(headA, headB);
            swap(cnt1, cnt2);
        }
        int x = cnt1 - cnt2;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while(x){
            x--;temp1 = temp1 -> next;
        }
        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1 == temp2) return temp1;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        return nullptr;
    }
};

// Find the lengths of both linked lists.
//
// Calculate the difference between
// their lengths.
//
// Move the pointer of the longer list
// forward by the length difference,
// so both pointers have the same
// number of nodes remaining.
//
// Now move both pointers together
// one step at a time.
//
// If both pointers point to the
// same node, that node is the
// intersection point.
//
// If both become NULL,
// the lists do not intersect.