// LeetCode 21 => ** Merge Two Sorted Lists **

// 1). Brute Force Approach => Store + Sort + Rebuild
//     Time Complexity : O((n + m) * log (n + m)) 
//     Space Complexity : O(n + m)

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
    ListNode* Convert_Array_To_LL(vector<int>& nums){
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        for(int i = 0; i < nums.size(); i++){
            ListNode* newnode = new ListNode(nums[i]);
            temp -> next = newnode;
            temp = newnode;
        }
        return dummy -> next;
    }
    vector<int> merge_LL(ListNode* head1, ListNode* head2){
        vector<int> ans;
        ListNode* temp = head1;
        while(temp != nullptr){ans.push_back(temp -> val); temp = temp -> next;}
        temp = head2;
        while(temp != nullptr){ans.push_back(temp -> val); temp = temp -> next;}
        return ans;
    } 
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> ans = merge_LL(list1, list2);
        sort(ans.begin(), ans.end());
        return Convert_Array_To_LL(ans);
    }
};

// 2). Better Solution => Two-Pointer Merge + New Nodes
//     Time Complexity : O(n + m) 
//     Space Complexity : O(n + m)

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

// 3). Optimal Solution => Recursion + In-place Merging
//     Time Complexity : O(n + m)
//     Space Complexity : O(n + m) -> Recursive Call Stack

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr || list2 == nullptr){
            return (list1 == nullptr) ? list2 : list1;
        }
        if(list1 -> val <= list2 -> val){
            list1 -> next = mergeTwoLists(list1 -> next, list2);
            return list1;
        }
        else{
            list2 -> next = mergeTwoLists(list1, list2 -> next);
            return list2;

        }
    }
};

// Both linked lists are already sorted.
//
// Compare the first nodes of both lists.
//
// The node with the smaller value
// becomes the current node of the merged list.
//
// Recursively merge the remaining
// part of the lists.
//
// Connect the selected node's next
// pointer with the result of recursion.
//
// If either list becomes NULL,
// return the remaining list directly.
//
// No new nodes are created.
// Existing nodes are rearranged
// using their next pointers.