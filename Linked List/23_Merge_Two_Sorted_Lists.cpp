// LeetCode 21 => ** Merge Two Sorted Lists **

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
    void add_node(){
        
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while(temp1 != nullptr && temp2 != nullptr){
            if(temp1 -> val > temp2 -> val){
                ListNode* newnode = new ListNode(temp2 -> val);
                temp -> next = newnode;
                temp = newnode;
                temp2 = temp2 -> next;
            }
            else{
                ListNode* newnode = new ListNode(temp1 -> val);
                temp -> next = newnode;
                temp = newnode;
                temp1 = temp1 -> next;
            }
        }
        while(temp1){
            ListNode* newnode = new ListNode(temp1 -> val);
            temp -> next = newnode;
            temp = newnode;
            temp1 = temp1 -> next;
        }
        while(temp2){
            ListNode* newnode = new ListNode(temp2 -> val);
            temp -> next = newnode;
            temp = newnode;
            temp2 = temp2 -> next;
        }
        temp -> next = nullptr;
        return dummy -> next;
    }
};